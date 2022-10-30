#include "calc3.h"
#include "y.tab.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char reg[10];
  char variable;
} reg;

static int lbl;
static int varLbl;
static char registers[16][10] = {"r12", "r13", "r14", "r15","rcx",
                                "rbx", "rsi", "rdi", "rax"};
static reg var2reg[4];
static reg loopReg;
static reg loopRegs[4];
static reg ifRegs[4];
static bool declared[256];
static bool full = false;
static const char PREFIX = 37; // asci for %

int const WORK_REGS_NR = 5;

static int regCount;

void resetRegCount() { regCount = 0; }

bool isFull() {
  if (regCount >= WORK_REGS_NR) {
    regCount = 0;
    return true;
  }
  full = true;
  return false;
}

void printArray() {
  for (int i = 0; i < WORK_REGS_NR; i++) {
    printf("Variable: %c, index: %d\n", var2reg[i].variable, i);
  }
}

int isInArray(char variable) {
  for (int i = 0; i < WORK_REGS_NR; i++) {
    if (var2reg[i].variable == variable) {
      return i;
    }
  }
  return -1;
}

void storeDynamicRegs(reg *regs) {
  for (int i = 0; i < WORK_REGS_NR; i++) {
    if (var2reg[i].variable < 61 && var2reg[i].variable > 122) {
      break;
      ;
    }
    strcpy(loopRegs[i].reg, var2reg[i].reg);
    regs[i].variable = var2reg[i].variable;
  }
}

void restoreAndStoreDynamic(int i, reg * regs) {
  // Store throwout variable
  declared[var2reg[i].variable] = true;
  var2reg[i].variable = regs[i].variable;
  // Restore variable from asm array
  if (declared[regs[i].variable]) {
    printf("\tmovq\tvars+%d(%crip), %c%s\n", regs[i].variable * 8, PREFIX,
           PREFIX, var2reg[i].reg);
  }
}

void restoreDynamicRegs(reg * regs) {
  for (int i = 0; i < WORK_REGS_NR; i++) {
    if (var2reg[i].variable < 61 || var2reg[i].variable > 122) {
      break;
      ;
    }
    restoreAndStoreDynamic(i, regs);
  }
}

void restoreAndStore(char variable) {
  // Store throwout variable
  // printf("Change from %c to %c\n", var2reg[regCount].variable, variable);
  declared[var2reg[regCount].variable] = true;
  var2reg[regCount].variable = variable;
  // Restore variable from asm array
  if (declared[variable]) {
    printf("\tmovq\tvars+%d(%crip), %c%s\n", variable * 8, PREFIX, PREFIX,
           var2reg[regCount].reg);
  }
}

int assignVariable(char variable) {
  if (regCount == WORK_REGS_NR) {
    regCount = 0;
    full = true;
  }
  int index = isInArray(variable);
  if (index != -1) {
    return index;
  }

  if (full) {
    restoreAndStore(variable);
    regCount++;
  } else {
    var2reg[regCount].variable = variable;
    strcpy(var2reg[regCount].reg, registers[regCount]);
    regCount++;
  }
  // printf("regcount: %d\n", regCount);
  return (regCount - 1);
}

void operation(char *command) {
  printf("\tpopq\t%crsi\n", PREFIX);
  printf("\tpopq\t%crdi\n", PREFIX);
  printf("\t%s\t%crsi, %crdi\n", command, PREFIX, PREFIX);
  printf("\tpushq\t%crdi\n", PREFIX);
}

void arithmeticOperation(char *command) {
  printf("\tpopq\t%crsi\n", PREFIX);
  printf("\tpopq\t%crdi\n", PREFIX);
  printf("\tcmpq\t%crsi, %crdi\n", PREFIX, PREFIX);
  printf("\t%s", command);
}

void divOperation() {
  printf("\tmovq\t$0, %crdx\n", PREFIX);
  printf("\tpopq\t%crsi\n", PREFIX);
  printf("\tpopq\t%crax\n", PREFIX);
  printf("\tidivq\t%crsi\n", PREFIX);
  printf("\tpushq\t%crax\n", PREFIX);
}

void maintainVar2Text(char variable)
{
  int index = isInArray(variable);
  printf("\tmovq\t%c%s, vars+%d(%crip)\n", PREFIX, var2reg[index].reg,
         var2reg[index].variable * 8, PREFIX);
}

int ex(nodeType *p) {
  int lbl1 = 0, lbl2 = 0;
  int index, operator1, operator2;
  bool isImmediate1 = false;
  bool isImmediate2 = false;
  if (!p)
    return 0;
  switch (p->type) {
  case typeCon:
    printf("\tpushq\t$%d\n", p->con.value);
    break;
  case typeId:
    operator1 = assignVariable(p->id.i + 'a');
    printf("\tmovq\t%c%s, %crbx\n", PREFIX, var2reg[operator1].reg, PREFIX);
    printf("\tpushq\t%crbx\n", PREFIX);

    break;
  case typeOpr:
    switch (p->opr.oper) {
    case WHILE:
      storeDynamicRegs(loopRegs);
      printf("L%03d:\n", lbl1 = lbl++);
      ex(p->opr.op[0]);
      printf("\tL%03d\n", lbl2 = lbl++);
      ex(p->opr.op[1]);
      restoreDynamicRegs(loopRegs);
      printf("\tjmp\tL%03d\n", lbl1);
      printf("L%03d:\n", lbl2);

      break;
    case IF:
      storeDynamicRegs(ifRegs); // Maintain if-regs, ensure that they have been declared
                       // in the dynamic array (vars)
      restoreDynamicRegs(ifRegs);
      ex(p->opr.op[0]);
      if (p->opr.nops > 2) {
        /* if else */
        printf("\tL%03d\n", lbl1 = lbl++);
        ex(p->opr.op[1]);
        printf("\tjmp\tL%03d\n", lbl2 = lbl++);
        printf("L%03d:\n", lbl1);
        ex(p->opr.op[2]);
        printf("L%03d:\n", lbl2);
      } else {
        /* if */
        storeDynamicRegs(ifRegs);
        restoreDynamicRegs(ifRegs);
        printf("\tL%03d\n", lbl1 = lbl++);
        ex(p->opr.op[1]);
        printf("L%03d:\n", lbl1);
      }
      break;
    case PRINT:
      ex(p->opr.op[0]);
      // printf("\tmovq	%c%s, -8(%crbp)\n", PREFIX, var2reg[operator1].reg,
      // PREFIX);

      printf("\tmovl\t$formatString, %cedi\n", PREFIX);
      printf("\tpopq\t%crsi\n", PREFIX);
      printf("\txor\t%crax, %crax\n", PREFIX, PREFIX);
      printf("\tcall\tprintf\n");
      break;
    case '=':
      ex(p->opr.op[1]);
      operator1 = assignVariable(p->opr.op[0]->id.i + 'a');
      printf("\tpopq\t%c%s\n", PREFIX, var2reg[operator1].reg);
      maintainVar2Text(p->opr.op[0]->id.i + 'a');
      // printf("Assign var: %c\n", p->opr.op[0]->id.i + 'a');
      break;
    case UMINUS:
      ex(p->opr.op[0]);
      printf("\tpopq\t%crdi\n", PREFIX);
      printf("\tneg\t%crdi\n", PREFIX);
      printf("\tpushq\t%crdi\n", PREFIX);
      break;
    case FACT:
      ex(p->opr.op[0]);
      printf("\tpopq\t%crdi\n", PREFIX);
      printf("\tcall fact_func\n");
      printf("\tpushq\t%crax\n", PREFIX);
      break;
    case LNTWO:
      ex(p->opr.op[0]);
      printf("\tpopq\t%crdi\n", PREFIX);
      printf("\tcall lntwo_func\n");
      printf("\tpushq\t%crax\n", PREFIX);
      break;
    default:
      ex(p->opr.op[0]);
      ex(p->opr.op[1]);
      switch (p->opr.oper) {
      case GCD:
        printf("\tpopq\t%crsi\n", PREFIX);
        printf("\tpopq\t%crdi\n", PREFIX);
        printf("\tcall gcd_func\n");
        printf("\tpushq\t%crax\n", PREFIX);
        break;
      case '+':
        operation("addq");
        break;
      case '-':
        operation("subq");
        break;
      case '/':
        divOperation();
        break;
      case '*':
        operation("imulq");
        break;
      case '<':
        arithmeticOperation("jge");
        break;
      case '>':
        arithmeticOperation("jle");
        break;
      case GE:
        arithmeticOperation("jl");
        break;
      case LE:
        arithmeticOperation("jg");
        break;
      case NE:
        arithmeticOperation("je");
        break;
      case EQ:
        arithmeticOperation("jne");
        break;
      }
    }
  }
  return 0;
}
