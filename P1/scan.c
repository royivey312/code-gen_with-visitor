#include <stdio.h>
#include "y.tab.h"

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
