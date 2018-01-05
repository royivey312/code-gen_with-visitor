#include <stdio.h>
#include "tree.h"
#include <stack>

std::stack<int>   intConstStack;
std::stack<char*> idStack;
std::stack<double> realConstStack;

int main ()
{
	int tok;
	extern char *yytext;
	extern int yylex();

	while ((tok = yylex()) != 0) {
		printf ("%d\t%s\n", tok, yytext);
		}
	printf ("%d\t<eof>\n", tok);
}
