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
	tree p   = (tree)malloc(sizeof (node));
	p->kind  = kind;
	p->value = val;
	p->first = p->second = p->third = NULL;
	p->next  = NULL;
	p->name  = NULL;
	return p;
}

tree buildStrTree (int kind, char* name)
{
	tree p   = (tree)malloc(sizeof (node));
	p->kind  = kind;
	p->value = 0;
	p->first = p->second = p->third = NULL;
	p->next  = NULL;
	p->name  = name;
	return p;
}

tree buildDoubleTree(int kind, double rval)
{
	tree p    = (tree)malloc(sizeof (node));
	p->kind   = kind;
	p->value  = 0;
	p->first  = p->second = p->third = NULL;
	p->next   = NULL;
	p->name   = NULL;
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

/* Operations */
void PlusE      ::accept(Visitor * v){ v->visit(*this); }
void SubE       ::accept(Visitor * v){ v->visit(*this); }
void DivE       ::accept(Visitor * v){ v->visit(*this); }
void MulE       ::accept(Visitor * v){ v->visit(*this); }
void ModE       ::accept(Visitor * v){ v->visit(*this); }

/* comparison */
void LtE        ::accept(Visitor * v){ v->visit(*this); }
void LeE        ::accept(Visitor * v){ v->visit(*this); }
void GtE        ::accept(Visitor * v){ v->visit(*this); }
void GeE        ::accept(Visitor * v){ v->visit(*this); }
void EqE        ::accept(Visitor * v){ v->visit(*this); }
void NeE        ::accept(Visitor * v){ v->visit(*this); }

/* Boolean Operations */
void OrE        ::accept(Visitor * v){ v->visit(*this); }
void AndE       ::accept(Visitor * v){ v->visit(*this); }
void NotE       ::accept(Visitor * v){ v->visit(*this); }

/* If/elseif/else */
void IfE        ::accept(Visitor * v){ v->visit(*this); }

/* Loop */
void LoopE      ::accept(Visitor * v){ v->visit(*this); }

void Assignment ::accept(Visitor * v){ v->visit(*this); }

void IntConstE  ::accept(Visitor * v){ v->visit(*this); }
void RealConstE ::accept(Visitor * v){ v->visit(*this); }
void DataAssignE::accept(Visitor * v){ v->visit(*this); }


