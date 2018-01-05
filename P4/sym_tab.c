#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>

#include "tree.h"
#include "Symbol.h"

extern FILE *yyin;
extern int yyparse(void);

stack<char*>  idStack;
stack<int>    intConstStack;
stack<double> realConstStack;

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
	fclose(yyin);

	cout << "Checking..." << endl;

	STConstuctor tcon{root};
	SymbolTable * symtab = tcon.buildSymbolTables();
	cout << *symtab << endl;
	

	//printTree(root);
	
}