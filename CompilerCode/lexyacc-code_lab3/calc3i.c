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
static char registers[8][10] = {"rax", "rcx", "rdx", "rbx",
                                "rbp", "rsi", "rdi", "none"};
static reg var2reg[4];
static bool declared[256];
static bool full = false;
static const char PREFIX = 37; // asci for %

static int regCount;

void resetRegCount() { regCount = 0; }

bool isFull() {
  if (regCount >= 4) {
    regCount = 0;
    return true;
  }
  full = true;
  return false;
}

void shiftElements() {
  for (int i = 2; i >= 0; i--) {
    var2reg[i + 1].variable = var2reg[i].variable;
  }
}

void printArray() {
  for (int i = 0; i < 4; i++) {
    printf("Variable: %c, index: %d\n", var2reg[i].variable, i);
  }
}

int isInArray(char variable) {
  for (int i = 0; i < 4; i++) {
    if (var2reg[i].variable == variable) {
      return i;
    }
  }
  return -1;
}

void restoreAndStore(char variable) {
  // Store throwout variable
  printf("\tmovq\t%c%s, vars+%d(%crip)\n", PREFIX, var2reg[regCount].reg,
         (variable * 8), PREFIX);
  declared[var2reg[regCount].variable] = true;
  var2reg[regCount].variable = variable;
  // Restore variable from asm array
  if (declared[variable]) {
    printf("\tmovq\tvars+%d(%crip), %c%s\n", variable + 8, PREFIX, PREFIX,
           var2reg[regCount].reg);
  }
}

int assignVariable(char variable) {
  if (regCount == 4) {
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
  return (regCount - 1);
}

int ex(nodeType *p) {
  int lbl1 = 0, lbl2 = 0;
  int index, operator1, operator2;
  if (!p)
    return 0;
  switch (p->type) {
  case typeCon:
    printf("\tpushq\t$%d\n", p->con.value);
    break;
  case typeId:
    assignVariable(p->id.i + 'a');
    break;
  case typeOpr:
    switch (p->opr.oper) {
    case WHILE:
      printf("L%03d:\n", lbl1 = lbl++);
      ex(p->opr.op[0]);
      printf("\tL%03d\n", lbl2 = lbl++);
      ex(p->opr.op[1]);
      printf("\tjmp\tL%03d\n", lbl1);
      printf("L%03d:\n", lbl2);
      break;
    case IF:
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
        printf("\tL%03d\n", lbl1 = lbl++);
        ex(p->opr.op[1]);
        printf("L%03d:\n", lbl1);
      }
      break;
    case PRINT:
      ex(p->opr.op[0]);
      printf("\tprint\n");
      break;
    case '=':
      ex(p->opr.op[1]);
      index = assignVariable(p->opr.op[0]->id.i + 'a');
      printf("\tpopq\t%c%s\n", PREFIX, var2reg[index].reg);
      break;
    case UMINUS:
      ex(p->opr.op[0]);
      printf("\tneg\n");
      break;
    case FACT:
      ex(p->opr.op[0]);
      printf("\tfact\n");
      break;
    case LNTWO:
      ex(p->opr.op[0]);
      printf("\lntwo\n");
      break;
    default:
      /*
      ex(p->opr.op[0]);
      ex(p->opr.op[1]);
      */
      operator1 = assignVariable(p->opr.op[0]->id.i + 'a');
      operator2 = assignVariable(p->opr.op[1]->id.i + 'a');
      switch (p->opr.oper) {
      case GCD:
        printf("\tgcd\n");
        break;
      case '+':
        printf("\taddq %c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tpushq\t%c%s\n", PREFIX, var2reg[operator1].reg);
        break;
      case '-':
        printf("\tsubq\t%c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tpushq\t%c%s\n", PREFIX, var2reg[operator1].reg);
        break;
      case '*':
        printf("\timulq\t%c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tpushq\t%c%s\n", PREFIX, var2reg[operator1].reg);
        break;
      case '/':
        printf("\tidivq\t%c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tpushq\t%c%s\n", PREFIX, var2reg[operator1].reg);
        break;
      case '<':
        printf("\tcmpq\t%c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("jg");
        break;
      case '>':
        printf("\tcmpq %c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tjl");
        break;
      case GE:
        printf("\tcmpq %c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tjle");
        break;
      case LE:
        printf("\tcmpq %c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tjge");
        break;
      case NE:
        printf("\tcmpq %c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tje");
        break;
      case EQ:
        printf("\tcmpq %c%s, %c%s\n", PREFIX, var2reg[operator2].reg, PREFIX,
               var2reg[operator1].reg);
        printf("\tjne");
        break;
      }
    }
  }
  return 0;
}
