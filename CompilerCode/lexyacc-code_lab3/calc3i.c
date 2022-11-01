#include "calc3.h"
#include "y.tab.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static int lbl;
static const char PREFIX = 37; // asci for %

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
    printf("\tmovq\tvars+%d(%crip), %crdi\n", (p->id.i + 'a') * 8, PREFIX, PREFIX);
    printf("\tpushq\t%crdi\n", PREFIX);
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
      // printf("\tmovq	%c%s, -8(%crbp)\n", PREFIX, var2reg[operator1].reg,
      // PREFIX);

      printf("\tmovl\t$formatString, %cedi\n", PREFIX);
      printf("\tpopq\t%crsi\n", PREFIX);
      printf("\txor\t%crax, %crax\n", PREFIX, PREFIX);
      printf("\tcall\tprintf\n");
      break;
    case '=':
      ex(p->opr.op[1]);
      printf("\tpopq\t%crdi\n", PREFIX);
      printf("\tmovq\t%crdi, vars+%d(%crip)\n", PREFIX,
             (p->opr.op[0]->id.i + 'a') * 8, PREFIX);
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
