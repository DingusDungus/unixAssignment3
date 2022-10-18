#include "calc3.h"
#include "y.tab.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static int lbl;
static char registers[8][10] = {"eax", "ecx", "edx", "ebx",
                                "ebp", "esi", "edi", "none"};
static char var2reg[256][10];
static int regCount;

void resetRegCount() {
  regCount++;
  if (regCount == 7) {
    regCount = 0;
  }
}

bool checkIfVarAlreadyTaken(int index) {
  for (int i = 0; i < 8; i++) {
    if (strcmp(registers[i], var2reg[index]) == 0) {
      return true;
    }
  }
  return false;
}

void assignVariable(int index) {
  if (checkIfVarAlreadyTaken(index) == false) {
    strcpy(var2reg[index], registers[regCount]);
    resetRegCount();
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
    assignVariable(p->id.i + 'a');
    char registerVar[10] = "%";
    strcat(registerVar, var2reg[p->id.i + 'a']);
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
