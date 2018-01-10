#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>

#include "tree.h"
#include "Symbol.h"
#include "NodeVisitor.h"

extern FILE *yyin;
extern int yyparse(void);

stack<char*>  idStack;
stack<int>    intConstStack;
stack<double> realConstStack;

char *txt;

tree root;

FILE *outfile;

void generateByteCode(Visitor *, tree t);
void evalStatement(Visitor *, tree t);

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

	STConstuctor tcon{root};
	SymbolTable * symtab = tcon.buildSymbolTables();
	cout << endl;
	//cout << *symtab << endl;
	//printTree(root);	
	//cout << *symtab << endl;


	Visitor * v = new NodeVisitor{symtab};
	generateByteCode(v, root);
	
}

void generateByteCode(Visitor * v, tree t)
{
	tree iter = t;
	vector<Element*> statements;

	while (iter != nullptr)
	{
		statements.emplace_back(iter);
		iter = iter->next;
	}

	for (Element * n : statements) { n->accept(v); }
}