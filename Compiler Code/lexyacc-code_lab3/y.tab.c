/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20210328

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "calc3.y"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
int sym[26];                    /* symbol table */
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 19 "calc3.y"
typedef union YYSTYPE {
    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEGER 257
#define VARIABLE 258
#define WHILE 259
#define IF 260
#define PRINT 261
#define IFX 262
#define ELSE 263
#define GE 264
#define LE 265
#define EQ 266
#define NE 267
#define GCD 268
#define LNTWO 269
#define FACT 270
#define UMINUS 271
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    4,    4,    1,    1,    1,    1,    1,    1,    1,
    1,    3,    3,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    1,    2,    3,    4,    5,    5,    7,
    3,    1,    2,    1,    1,    2,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         3,
    0,    0,   14,    0,    0,    0,    0,    0,    0,    0,
    4,    0,    0,    2,    0,    0,    0,    0,   15,    0,
   16,   18,   17,    0,   12,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    0,    6,   30,   11,   13,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   22,   23,    7,    0,    0,    8,
    0,    0,   10,
};
static const YYINT yydgoto[] = {                          1,
   14,   15,   26,    2,
};
static const YYINT yysindex[] = {                         0,
    0,  -34,    0,  -59,  -37,  -19,  -25,  -25,  -25,  -25,
    0,  -25,  -34,    0,   60,  -25,  -25,  -25,    0,   68,
    0,    0,    0,  -15,    0,  -40,  -25,  -25,  -25,  -25,
  -25,  -25,  -25,  -25,  -25,  -25,  -25,    0,   89,    8,
   16,    0,    0,    0,    0,  -29,  -29,  -29,  -29,  -29,
  -29,  -35,  -38,  -38,    0,    0,    0,  -34,  -34,    0,
 -241,  -34,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,   23,    0,   95,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -24,   84,  100,  104,  109,
  115,   39,   28,   34,    0,    0,    0,    0,    0,    0,
    1,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  126,  376,    0,    0,
};
#define YYTABLESIZE 413
static const YYINT yytable[] = {                         12,
    9,   16,   17,   36,    8,   12,   36,   34,   37,   35,
    8,   37,   36,   34,   12,   35,   26,   37,   11,    8,
   18,   62,    1,    0,   11,   43,   36,   34,    0,   35,
    0,   37,    0,    0,   26,   26,    0,   26,    0,    0,
    9,    0,    0,    0,   32,    9,   31,    0,   58,   36,
   34,    0,   35,    0,   37,    0,   59,   36,   34,    9,
   35,    0,   37,    0,    0,    0,    0,   32,   20,   31,
   20,    0,   20,    0,   21,   32,   21,   31,   21,   19,
    0,    0,   13,    0,   44,    0,   20,   20,   13,   20,
    0,    0,   21,   21,    0,   21,    0,   19,   19,    0,
   19,   36,   34,    0,   35,    0,   37,    0,    0,   36,
   34,    0,   35,    0,   37,    0,    0,    0,   38,   32,
    0,   31,    0,    9,   27,    9,   42,   32,    0,   31,
   36,   34,    0,   35,    0,   37,   15,   15,   25,   15,
   29,   15,   27,   27,   28,   27,    0,   57,   32,   25,
   31,   45,    0,   15,   15,   24,   15,    0,   29,   29,
    0,   29,   28,   28,    0,   28,    0,   25,   25,    0,
   25,    0,    0,   24,   24,    0,   24,    0,    0,    0,
    0,    0,    0,   60,   61,    0,    0,   63,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    4,    5,    6,
    7,    0,    3,    4,    5,    6,    7,    0,    9,   10,
    0,    3,   19,    0,    9,   10,    0,    0,   33,   26,
   26,   26,   26,    9,   10,    0,    0,    0,   27,   28,
   29,   30,   33,    0,    0,    0,    0,    9,    9,    9,
    9,    9,    0,    0,    0,    0,    0,    0,    0,    9,
    9,   27,   28,   29,   30,   33,    0,    0,    0,   27,
   28,   29,   30,   33,    0,    0,    0,    0,    0,    0,
    0,   20,   20,   20,   20,   20,    0,   21,   21,   21,
   21,   21,   19,   19,   19,   19,   19,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   27,   28,   29,   30,   33,    0,    0,
    0,   27,   28,   29,   30,   33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   27,   27,   27,
   27,    0,   27,   28,   29,   30,   33,    0,   15,   15,
   15,   15,   15,   29,   29,   29,   29,   28,   28,   28,
   28,    0,   25,   25,   25,   25,    0,    0,   24,   24,
   24,   24,   20,   21,   22,   23,    0,   24,    0,    0,
    0,   39,   40,   41,    0,    0,    0,    0,    0,    0,
    0,    0,   46,   47,   48,   49,   50,   51,   52,   53,
   54,   55,   56,
};
static const YYINT yycheck[] = {                         40,
    0,   61,   40,   42,   45,   40,   42,   43,   47,   45,
   45,   47,   42,   43,   40,   45,   41,   47,   59,   45,
   40,  263,    0,   -1,   59,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,
   40,   -1,   -1,   -1,   60,   45,   62,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   41,   42,   43,   59,
   45,   -1,   47,   -1,   -1,   -1,   -1,   60,   41,   62,
   43,   -1,   45,   -1,   41,   60,   43,   62,   45,   41,
   -1,   -1,  123,   -1,  125,   -1,   59,   60,  123,   62,
   -1,   -1,   59,   60,   -1,   62,   -1,   59,   60,   -1,
   62,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   59,   60,
   -1,   62,   -1,  123,   41,  125,   59,   60,   -1,   62,
   42,   43,   -1,   45,   -1,   47,   42,   43,   13,   45,
   41,   47,   59,   60,   41,   62,   -1,   59,   60,   41,
   62,   26,   -1,   59,   60,   41,   62,   -1,   59,   60,
   -1,   62,   59,   60,   -1,   62,   -1,   59,   60,   -1,
   62,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   58,   59,   -1,   -1,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,   -1,  257,  258,  259,  260,  261,   -1,  269,  270,
   -1,  257,  258,   -1,  269,  270,   -1,   -1,  268,  264,
  265,  266,  267,  269,  270,   -1,   -1,   -1,  264,  265,
  266,  267,  268,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  270,  264,  265,  266,  267,  268,   -1,   -1,   -1,  264,
  265,  266,  267,  268,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  264,  265,  266,  267,  268,   -1,  264,  265,  266,
  267,  268,  264,  265,  266,  267,  268,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  264,  265,  266,  267,  268,   -1,   -1,
   -1,  264,  265,  266,  267,  268,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,
  267,   -1,  264,  265,  266,  267,  268,   -1,  264,  265,
  266,  267,  268,  264,  265,  266,  267,  264,  265,  266,
  267,   -1,  264,  265,  266,  267,   -1,   -1,  264,  265,
  266,  267,    7,    8,    9,   10,   -1,   12,   -1,   -1,
   -1,   16,   17,   18,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   27,   28,   29,   30,   31,   32,   33,   34,
   35,   36,   37,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#define YYUNDFTOKEN 278
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,"';'",
"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"INTEGER","VARIABLE","WHILE","IF","PRINT","IFX","ELSE","GE","LE",
"EQ","NE","GCD","LNTWO","FACT","UMINUS",0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : function",
"function : function stmt",
"function :",
"stmt : ';'",
"stmt : expr ';'",
"stmt : PRINT expr ';'",
"stmt : VARIABLE '=' expr ';'",
"stmt : WHILE '(' expr ')' stmt",
"stmt : IF '(' expr ')' stmt",
"stmt : IF '(' expr ')' stmt ELSE stmt",
"stmt : '{' stmt_list '}'",
"stmt_list : stmt",
"stmt_list : stmt_list stmt",
"expr : INTEGER",
"expr : VARIABLE",
"expr : '-' expr",
"expr : FACT expr",
"expr : LNTWO expr",
"expr : expr GCD expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr EQ expr",
"expr : '(' expr ')'",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 88 "calc3.y"

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)

nodeType *con(int value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) +
        (nops - 1) * sizeof(nodeType*);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
#line 405 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 43 "calc3.y"
	{ exit(0); }
break;
case 2:
#line 47 "calc3.y"
	{ ex(yystack.l_mark[0].nPtr); freeNode(yystack.l_mark[0].nPtr); }
break;
case 4:
#line 52 "calc3.y"
	{ yyval.nPtr = opr(';', 2, NULL, NULL); }
break;
case 5:
#line 53 "calc3.y"
	{ yyval.nPtr = yystack.l_mark[-1].nPtr; }
break;
case 6:
#line 54 "calc3.y"
	{ yyval.nPtr = opr(PRINT, 1, yystack.l_mark[-1].nPtr); }
break;
case 7:
#line 55 "calc3.y"
	{ yyval.nPtr = opr('=', 2, id(yystack.l_mark[-3].sIndex), yystack.l_mark[-1].nPtr); }
break;
case 8:
#line 56 "calc3.y"
	{ yyval.nPtr = opr(WHILE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 9:
#line 57 "calc3.y"
	{ yyval.nPtr = opr(IF, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 10:
#line 58 "calc3.y"
	{ yyval.nPtr = opr(IF, 3, yystack.l_mark[-4].nPtr, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 11:
#line 59 "calc3.y"
	{ yyval.nPtr = yystack.l_mark[-1].nPtr; }
break;
case 12:
#line 63 "calc3.y"
	{ yyval.nPtr = yystack.l_mark[0].nPtr; }
break;
case 13:
#line 64 "calc3.y"
	{ yyval.nPtr = opr(';', 2, yystack.l_mark[-1].nPtr, yystack.l_mark[0].nPtr); }
break;
case 14:
#line 68 "calc3.y"
	{ yyval.nPtr = con(yystack.l_mark[0].iValue); }
break;
case 15:
#line 69 "calc3.y"
	{ yyval.nPtr = id(yystack.l_mark[0].sIndex); }
break;
case 16:
#line 70 "calc3.y"
	{ yyval.nPtr = opr(UMINUS, 1, yystack.l_mark[0].nPtr); }
break;
case 17:
#line 71 "calc3.y"
	{ yyval.nPtr = opr(FACT, 1, yystack.l_mark[0].nPtr); }
break;
case 18:
#line 72 "calc3.y"
	{ yyval.nPtr = opr(LNTWO, 1, yystack.l_mark[0].nPtr); }
break;
case 19:
#line 73 "calc3.y"
	{ yyval.nPtr = opr(GCD, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 20:
#line 74 "calc3.y"
	{ yyval.nPtr = opr('+', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 21:
#line 75 "calc3.y"
	{ yyval.nPtr = opr('-', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 22:
#line 76 "calc3.y"
	{ yyval.nPtr = opr('*', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 23:
#line 77 "calc3.y"
	{ yyval.nPtr = opr('/', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 24:
#line 78 "calc3.y"
	{ yyval.nPtr = opr('<', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 25:
#line 79 "calc3.y"
	{ yyval.nPtr = opr('>', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 26:
#line 80 "calc3.y"
	{ yyval.nPtr = opr(GE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 27:
#line 81 "calc3.y"
	{ yyval.nPtr = opr(LE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 28:
#line 82 "calc3.y"
	{ yyval.nPtr = opr(NE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 29:
#line 83 "calc3.y"
	{ yyval.nPtr = opr(EQ, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 30:
#line 84 "calc3.y"
	{ yyval.nPtr = yystack.l_mark[-1].nPtr; }
break;
#line 720 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
