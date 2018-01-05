/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Ident = 1,
    IntConst = 2,
    Exit = 3,
    When = 4,
    Begin = 5,
    Bind = 6,
    Record = 7,
    Mod = 8,
    Put = 9,
    Assert = 10,
    Then = 12,
    End = 13,
    While = 14,
    Do = 15,
    Else = 16,
    ElseIf = 17,
    Loop = 18,
    To = 19,
    TAssign = 20,
    Assign = 21,
    LParen = 22,
    RParen = 23,
    Plus = 24,
    Minus = 25,
    Star = 26,
    Slash = 27,
    Eq = 28,
    Ne = 29,
    Lt = 30,
    Le = 31,
    Gt = 32,
    Ge = 33,
    Var = 41,
    Integer = 42,
    Boolean = 43,
    Prog = 44,
    Comma = 45,
    Dot = 46,
    Real = 47,
    Not = 48,
    And = 49,
    Or = 50,
    If = 51,
    SColon = 52,
    RealT = 53,
    Div = 54
  };
#endif
/* Tokens.  */
#define Ident 1
#define IntConst 2
#define Exit 3
#define When 4
#define Begin 5
#define Bind 6
#define Record 7
#define Mod 8
#define Put 9
#define Assert 10
#define Then 12
#define End 13
#define While 14
#define Do 15
#define Else 16
#define ElseIf 17
#define Loop 18
#define To 19
#define TAssign 20
#define Assign 21
#define LParen 22
#define RParen 23
#define Plus 24
#define Minus 25
#define Star 26
#define Slash 27
#define Eq 28
#define Ne 29
#define Lt 30
#define Le 31
#define Gt 32
#define Ge 33
#define Var 41
#define Integer 42
#define Boolean 43
#define Prog 44
#define Comma 45
#define Dot 46
#define Real 47
#define Not 48
#define And 49
#define Or 50
#define If 51
#define SColon 52
#define RealT 53
#define Div 54

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "mini-turing.y" /* yacc.c:1909  */
 int i; tree t; char *s; double d; 

#line 153 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
