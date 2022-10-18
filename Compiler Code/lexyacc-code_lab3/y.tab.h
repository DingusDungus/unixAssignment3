#include "calc3.h"

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
