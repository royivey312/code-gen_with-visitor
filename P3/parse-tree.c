#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <stack>

extern FILE *yyin;
extern int yyparse(void);

std::stack<char*>  idStack;
std::stack<int>    intConstStack;
std::stack<double> realConstStack;

char *txt;

tree root;

FILE *outfile;

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "%s: Insufficient Arguments\n", argv[0]);
		exit(1);
	}

	if ((yyin = fopen (argv[1], "r")) == 0L)
	{
		fprintf (stderr, "%s: Can't open Input File %s\n", argv[0], argv[1]);
		exit(1);
	}
	yyparse();
	printTree(root);
	
	fclose(yyin);
}