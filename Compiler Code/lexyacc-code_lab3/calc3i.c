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
static char registers[8][10] = {"eax", "ecx", "edx", "ebx",
                                "ebp", "esi", "edi", "none"};
static reg var2reg[4];
static bool declared[256];

static int regCount;

void resetRegCount() { regCount = 0; }

bool isFull() {
  if (regCount == 4) {
    return true;
  }
  return false;
}

void shiftElements() {
  for (int i = 0; i < 3; i++) {
    var2reg[i + 1] = var2reg[i];
  }
}

void assignVariable(char variable, nodeType *p) {
  if (isFull()) {
    reg throwOutReg = var2reg[3];
    shiftElements();
    printf("movq %(vars), %rbp\n");
    printf("movq %s, %d(%", throwOutReg.reg, throwOutReg.variable + 8);
    printf("%s)\n", "rbp");
    var2reg[0].variable = variable;
    strcpy(var2reg[0].reg, throwOutReg.reg);
    if (declared[variable]) {
      printf("movq %d(%rbp), %" "%s", throwOutReg.variable + 8, var2reg[0].reg);
    }
}

int ex(nodeType *p) {
  int lbl1, lbl2;

  if (!p)
    return 0;
  switch (p->type) {
  case typeCon:
    printf("\tpushq\t$%d\n", p->con.value);
    break;
  case typeId:
    assignVariable(p->id.i + 'a', p);
    char registerVar[10] = "%";
    strcat(registerVar, var2reg[p->id.i + 'a'].reg);
    printf("\tpushq\t%s\n", registerVar);
    break;
  case typeOpr:
    switch (p->opr.oper) {
    case WHILE:
      printf("L%03d:\n", lbl1 = lbl++);
      ex(p->opr.op[0]);
      printf("\tjz\tL%03d\n", lbl2 = lbl++);
      ex(p->opr.op[1]);
      printf("\tjmp\tL%03d\n", lbl1);
      printf("L%03d:\n", lbl2);
      break;
    case IF:
      ex(p->opr.op[0]);
      if (p->opr.nops > 2) {
        /* if else */
        printf("\tjz\tL%03d\n", lbl1 = lbl++);
        ex(p->opr.op[1]);
        printf("\tjmp\tL%03d\n", lbl2 = lbl++);
        printf("L%03d:\n", lbl1);
        ex(p->opr.op[2]);
        printf("L%03d:\n", lbl2);
      } else {
        /* if */
        printf("\tjz\tL%03d\n", lbl1 = lbl++);
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
      assignVariable(p->opr.op[0]->id.i + 'a');
      char registerVar[10] = "%";
      strcat(registerVar, var2reg[p->opr.op[0]->id.i + 'a']);
      printf("\tpopq\t%s\n", registerVar);
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
      ex(p->opr.op[0]);
      ex(p->opr.op[1]);
      switch (p->opr.oper) {
      case GCD:
        printf("\tgcd\n");
        break;
      case '+':
        printf("\taddq\n");
        break;
      case '-':
        printf("\tsubq\n");
        break;
      case '*':
        printf("\tmulq\n");
        break;
      case '/':
        printf("\tdiv1\n");
        break;
      case '<':
        printf("\tcompLT\n");
        break;
      case '>':
        printf("\tcompGT\n");
        break;
      case GE:
        printf("\tcompGE\n");
        break;
      case LE:
        printf("\tcompLE\n");
        break;
      case NE:
        printf("\tcompNE\n");
        break;
      case EQ:
        printf("\tcompEQ\n");
        break;
      }
    }
  }
  return 0;
}
