#pragma once
#include "NodeVisitor.h"


struct Element { virtual void accept(Visitor * v) = 0; };

typedef struct NodeElement : public Element
{
	NodeElement(){}
	NodeElement(NodeElement const &n) : kind  (n.kind)
	                            , value (n.value)
	                            , first (n.first)
	                            , second(n.second)
	                            , third (n.third)
	                            , next  (n.next)
	                            , name  (n.name)
	                            , rvalue(n.rvalue) {}
	int	kind, value;
	struct	NodeElement *first, *second, *third, *next;
	char *name;
	double rvalue;

	void accept(Visitor * v){ };
} node;
typedef node * tree;

/* Operations */
struct PlusE      : public NodeElement { PlusE(tree t)      : NodeElement(*t){} void accept(Visitor * v) override; };
struct SubE       : public NodeElement { SubE (tree t)      : NodeElement(*t){} void accept(Visitor * v) override; };
struct DivE       : public NodeElement { DivE (tree t)      : NodeElement(*t){} void accept(Visitor * v) override; };
struct MulE       : public NodeElement { MulE (tree t)      : NodeElement(*t){} void accept(Visitor * v) override; };
struct ModE       : public NodeElement { ModE (tree t)      : NodeElement(*t){} void accept(Visitor * v) override; };

/* Comparison */
struct LtE        : public NodeElement { LtE(tree t)        : NodeElement(*t){} void accept(Visitor * v) override; };
struct LeE        : public NodeElement { LeE(tree t)        : NodeElement(*t){} void accept(Visitor * v) override; };
struct GtE        : public NodeElement { GtE(tree t)        : NodeElement(*t){} void accept(Visitor * v) override; };
struct GeE        : public NodeElement { GeE(tree t)        : NodeElement(*t){} void accept(Visitor * v) override; };
struct EqE        : public NodeElement { EqE(tree t)        : NodeElement(*t){} void accept(Visitor * v) override; };
struct NeE        : public NodeElement { NeE(tree t)        : NodeElement(*t){} void accept(Visitor * v) override; };
/* if/elseif/else */
struct IfE        : public NodeElement { IfE(tree t)        : NodeElement(*t){} void accept(Visitor * v) override; };

/* loop */
struct LoopE      : public NodeElement { LoopE(tree t)      : NodeElement(*t){} void accept(Visitor * v) override; };

struct Assignment : public NodeElement { Assignment(tree t) : NodeElement(*t){} void accept(Visitor * v) override; };

struct IntId      : public NodeElement { IntId(tree t)      : NodeElement(*t){} void accept(Visitor * v) override; };
struct RealId     : public NodeElement { RealId(tree t)     : NodeElement(*t){} void accept(Visitor * v) override; };

extern char TokName[][15];

tree buildTree      (int kind, tree first, tree second, tree third);
tree buildIntTree   (int kind, int val);
tree buildStrTree   (int kind, char *name);
tree buildDoubleTree(int kind, double rval);
void printTree      (tree p);
