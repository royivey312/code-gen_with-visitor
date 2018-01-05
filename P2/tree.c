#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "y.tab.h"

tree buildTree (int kind, tree one, tree two, tree three)
{
	tree p = (tree)malloc(sizeof (node));
	p->kind = kind;
	p->first = one;
	p->second = two;
	p->third = three;
	p->next = NULL;
	p->name = NULL;
	return p;
}

tree buildIntTree (int kind, int val)
{
	tree p = (tree)malloc(sizeof (node));
	p->kind = kind;
	p->value = val;
	p->first = p->second = p->third = NULL;
	p->next = NULL;
	p->name = NULL;
	return p;
}

tree buildStrTree (int kind, char* name)
{
	tree p = (tree)malloc(sizeof (node));
	p->kind = kind;
	p->value = 0;
	p->first = p->second = p->third = NULL;
	p->next = NULL;
	p->name = name;
	return p;
}

tree buildDoubleTree(int kind, double rval)
{
	tree p = (tree)malloc(sizeof (node));
	p->kind = kind;
	p->value = 0;
	p->first = p->second = p->third = NULL;
	p->next = NULL;
	p->name = NULL;
	p->rvalue = rval;
	return p;	
}

char TokName[][15] = 
	{"", 
	"Ident", "IntConst", "Exit", "When", "Begin", "Bind", "Record", "Mod", "Put", "Assert",
	"", "THEN", "END", "WHILE", "DO", "ELSE", "ElseIf", "Loop", "To", "Field",
	"Assign", "(", ")", "Plus", "Minus", "Star", "Slash", "Equal", "NotEqual", "LessThan",
	"LessOrEqual", "GreaterThan", "GreaterOrEqual", "", "", "", "", "", "", "", 
	"Var", "Int", "Boolean", "Prog", ",", "Dot", "RealConst","Not", "And", "Or",
	"If", ";", "Real", "Div"};

static int indent = 0;

void printTree (tree p)
{
	if (p == NULL) return;
	for (; p != NULL; p = p->next) {
		printf ("%*s%s", indent, "", TokName[p->kind]);
		switch (p->kind) {
			case Ident: 
				printf ("  %s\n", p->name);
				break;
			case IntConst:
				printf ("  %d\n", p->value);
				break;
			case Real:
				printf ("  %f\n", p->rvalue);
				break;
			default:
				printf ("\n");
				indent += 2;
				printTree (p->first);
				printTree (p->second);
				printTree (p->third);
				indent -= 2;
			}
		}
}
