%{
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <string.h>
#include <stack>

extern tree root; // declared in the driver program
extern int yylex(void);
extern int yyerror (char const *s);
extern char *yytext;
extern char *txt;
extern std::stack<char*>  idStack;
extern std::stack<int>    intConstStack;
extern std::stack<double> realConstStack;

%}

%token <s> Ident 1
%token <i> IntConst 2
%token     Exit  3 When 4 Begin   5  Bind 6  Record  7
%token     Mod   8 Put  9 Assert 10  Then 12 End    13
%token     While 14 Do 15 Else 16 ElseIf 17 Loop 18 To 19 TAssign 20
%token     Assign 21 LParen 22 RParen 23 Plus 24 Minus 25 Star 26 Slash 27
%token     Eq 28 Ne 29 Lt 30 Le 31 Gt 32 Ge 33 Var 41 Integer 42 Boolean 43
%token     Prog 44 Comma 45 Dot 46
%token <f> Real 47

%token     Not 48 And 49 Or 50 If 51 SColon 52 RealT 53 Div 54

%start program

%union { int i; tree t; char *s; double d; }

%type <t> pStateDeclSeq idlist type field_list state_decls declaration statement
%type <t> ref end_if expr and_expr not_expr rel_expr bool_expr sum prod factor basic

%%
program: pStateDeclSeq { root = $1; };

pStateDeclSeq: { $$ = NULL; }
             | statement SColon pStateDeclSeq
                        { $$ = $1; $$->next=$3;}
             | Var idlist TAssign type SColon pStateDeclSeq
                        { $$ = buildTree(TAssign, $2, $4, NULL); $$->next=$6; }
             ;

idlist       : Ident              
                        { $$ = buildStrTree(Ident, idStack.top()); idStack.pop(); }
             | Ident Comma idlist 
                        { $$ = buildStrTree(Ident, idStack.top()); idStack.pop(); $$->next = $3;};

type         : Integer { $$ = buildStrTree(Integer, strdup("integer")); }
             | RealT   { $$ = buildStrTree(RealT  , strdup("real")); }
             | Boolean { $$ = buildStrTree(Boolean, strdup("boolean")); }
             | Record field_list End Record { $$ = buildTree(Record, $2, NULL, NULL); }
             ;

field_list   : idlist TAssign type                    
                        { $$ = buildTree(TAssign, $1, $3, NULL); }
             | idlist TAssign type SColon field_list 
                        { $$ = buildTree(TAssign, $1, $3, $5);}
             ;

state_decls  : { $$ = NULL;  }
             | statement SColon state_decls   { $$ = $1; $$->next = $3; }
             | declaration SColon state_decls { $$ = $1; $$->next = $3; }
             ;

declaration : Var idlist TAssign type 
                        { $$ = buildTree(TAssign, $2, $4, NULL); }
             | Bind Ident To ref      
                        { 
                          $$ = buildTree(Bind, buildStrTree(Ident, idStack.top()), $4, NULL);
                          if (idStack.top() != NULL) { idStack.pop(); }
                        }
             | Bind Var Ident To ref  
                        { $$ = buildTree(Bind, buildStrTree(Ident, idStack.top()), $5, NULL); 
                          if (idStack.top() != NULL) { idStack.pop(); }
                        }
             ;

statement    : ref Assign expr
                        { $$ = buildTree(Assign, $1, $3, NULL); }
             | Assert bool_expr
                        { $$ = buildTree(Assert, $2, NULL, NULL); }
             | Begin state_decls End Loop
                        { $$ = buildTree(Begin, $2, NULL, NULL); }
             | Loop state_decls End Loop
                        { $$ = buildTree(Loop, $2, NULL, NULL); }
             | Exit 
                        { $$ = buildTree(Exit, NULL, NULL, NULL); }
             | Exit When bool_expr
                        { $$ = buildTree(Exit, $3, NULL, NULL); }
             | If bool_expr Then state_decls end_if
                        { $$ = buildTree(If, $2, buildTree(Then, $4, NULL, NULL), $5); }
             ;

ref          : Ident { $$ = buildStrTree(Ident, idStack.top()); idStack.pop(); }
             | Ident Dot Ident 
                        {
                              char * rhs = idStack.top();
                              if (idStack.top() != NULL) { idStack.pop(); }
                              char * lhs = idStack.top();
                              if (idStack.top() != NULL) { idStack.pop(); }
                              $$ = buildTree(Dot, buildStrTree(Ident, lhs)
                                            , buildStrTree(Ident, rhs)
                                            , NULL);
                        }
             ;


end_if       : End If 
                        { $$ = NULL; }
             | Else state_decls End If
                        { $$ = buildTree(Else, $2, NULL, NULL); }
             | ElseIf bool_expr Then state_decls end_if
                        { $$ = buildTree(ElseIf, $2, $4, $5); }
             ;

expr         : expr Or and_expr
                        { $$ = buildTree(Or, $1, $3, NULL); }
             | not_expr;

and_expr     : and_expr And not_expr
                        { $$ = buildTree(And, $1, $3, NULL); }
             | not_expr;

not_expr     : Not not_expr { $$ = buildTree(Not, $2, NULL, NULL); }
             | rel_expr     { $$ = $1; }
             ;

rel_expr     : sum 
             | rel_expr Eq sum 
                        { $$ = buildTree(Eq, $1, $3, NULL); }
             | rel_expr Ne sum
                        { $$ = buildTree(Ne, $1, $3, NULL); }
             | rel_expr Lt sum
                        { $$ = buildTree(Lt, $1, $3, NULL); }
             | rel_expr Le sum
                        { $$ = buildTree(Le, $1, $3, NULL); }
             | rel_expr Gt sum 
                        { $$ = buildTree(Gt, $1, $3, NULL); }
             | rel_expr Ge sum
                        { $$ = buildTree(Ge, $1, $3, NULL); }
             ;

bool_expr    : expr;

sum          : prod 
             | sum Plus prod
                        { $$ = buildTree(Plus, $1, $3, NULL); }
             | sum Minus prod
                        { $$ = buildTree(Minus, $1, $3, NULL); }
             ;

prod         : factor
             | prod Star factor
                        { $$ = buildTree(Star, $1, $3, NULL); }
             | prod Slash factor
                        { $$ = buildTree(Slash, $1, $3, NULL); }
             | prod Div factor
                        { $$ = buildTree(Div, $1, $3, NULL); }
             | prod Mod factor
                        { $$ = buildTree(Mod, $1, $3, NULL); }
             ;

factor       : Plus basic  { $$ = $2; }
             | Minus basic { $$ = $2; }
             | basic       { $$ = $1; }
             ;

basic        : ref
             | LParen expr RParen { $$ = $2; }
             | IntConst           { $$ = buildIntTree(IntConst, intConstStack.top());
                                    intConstStack.pop(); }
             | Real               { $$ = buildDoubleTree(Real, realConstStack.top());
                                    realConstStack.pop(); }
             ;
%%