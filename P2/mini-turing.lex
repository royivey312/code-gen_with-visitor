%{
#include <stdio.h>
#include <string.h>
#include <stack>
#include "tree.h"
#include "y.tab.h"

int line_no = 0;
int yyerror(char const *s);
extern std::stack<char *> idStack;
extern std::stack<int>    intConstStack;
extern std::stack<double> realConstStack;
%}

%option noyywrap
%option noinput

D [0-9]
A [a-zA-Z]
U _


ID      {A}({A}|{D}|{U})*
INT     {D}+
REAL_1  ({INT}\.{INT})
REAL_3  ({INT}\.e({PLUS}|{MINUS}){INT})
REAL_2  ({REAL_1}\*\ {INT})
REAL    {REAL_1}|{REAL_2}|{REAL_3}

TASSIGN ":"
ASSIGN  ":="
INTEGER "int"
BOOLEAN "boolean"
VAR     "var"
REALT   "real"

IF      "if"
THEN    "then"
END     "end"
ELSE    "else"
ELSEIF  "elsif"

LPAREN  "("
RPAREN  ")"

PLUS    "+"
MINUS   "-"
STAR    "*"
SLASH   "/"
DIV     "div"

EQ      "="
NE      "not="
LT      "<"
LE      "<="
GT      ">"
GE      ">="

DOT     "."
COMMA   ","
SCOLON  ";"

MOD     "mod"
PUT     "put"
ASSERT  "assert"
NOT     "not"
AND     "and"
OR      "or"

LOOP    "loop"
TO      "to"

EXIT    "exit"
WHEN    "when"
BEGIN   "begin"
BIND    "bind"
RECORD  "record"

%%
[ \t]     {}
{TASSIGN} { return TAssign;  }
{ASSIGN}  { return Assign;   }
{INTEGER} { return Integer;  }
{BOOLEAN} { return Boolean;  }
{VAR}     { return Var;      }
{REALT}   { return RealT;    }

{EXIT}    { return Exit;     }
{WHEN}    { return When;     }
{BEGIN}   { return Begin;    }
{BIND}    { return Bind;     }
{RECORD}  { return Record;   }
{LOOP}    { return Loop;     }
{TO}      { return To;       }

{IF}      { return If;       }
{THEN}    { return Then;     }
{END}     { return End;      }
{ELSE}    { return Else;     }
{ELSEIF}  { return ElseIf;   }

{LPAREN}  { return LParen;   }
{RPAREN}  { return RParen;   }

{PLUS}    { return Plus;     }
{MINUS}   { return Minus;    }
{STAR}    { return Star;     }
{SLASH}   { return Slash;    }
{DIV}     { return Div;      }

{EQ}      { return Eq;       }
{NE}      { return Ne;       }
{LT}      { return Lt;       }  
{LE}      { return Le;       }  
{GT}      { return Gt;       } 
{GE}      { return Ge;       }  

{MOD}     { return Mod;      }
{PUT}     { return Put;      }
{ASSERT}  { return Assert;   }
{NOT}     { return Not;      }
{AND}     { return And;      }
{OR}      { return Or;       }

{DOT}     { return Dot;      }
{COMMA}   { return Comma;    }
{SCOLON}  { return SColon;   }

{ID}      { idStack       .push(strdup(yytext));         return Ident;    }
{INT}     { intConstStack .push(atoi(yytext));           return IntConst; }
{REAL}    { realConstStack.push( (double)atof(yytext) ); return Real;     }

%%

int yyerror(char const *s)
{
   fprintf(stderr, "%s in line %d, token %s\n", s, line_no, yytext);
   return -1;
}

