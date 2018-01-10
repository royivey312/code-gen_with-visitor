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
	struct NodeElement *first, *second, *third, *next;
	char *name;
	double rvalue;
	void accept(Visitor * v) {}

} node;
typedef node * tree;


/* Operations */
struct PlusE      : public NodeElement { PlusE(tree t)       : NodeElement(*t){} void accept(Visitor * v); };
struct SubE       : public NodeElement { SubE (tree t)       : NodeElement(*t){} void accept(Visitor * v); };
struct DivE       : public NodeElement { DivE (tree t)       : NodeElement(*t){} void accept(Visitor * v); };
struct MulE       : public NodeElement { MulE (tree t)       : NodeElement(*t){} void accept(Visitor * v); };
struct ModE       : public NodeElement { ModE (tree t)       : NodeElement(*t){} void accept(Visitor * v); };

/* Comparison */
struct LtE        : public NodeElement { LtE (tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };
struct LeE        : public NodeElement { LeE (tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };
struct GtE        : public NodeElement { GtE (tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };
struct GeE        : public NodeElement { GeE (tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };
struct EqE        : public NodeElement { EqE (tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };
struct NeE        : public NodeElement { NeE (tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };
struct OrE        : public NodeElement { OrE (tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };
struct NotE       : public NodeElement { NotE(tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };
struct AndE       : public NodeElement { AndE(tree t)        : NodeElement(*t){} void accept(Visitor * v) ; };

/* if/elseif/else */
struct IfE        : public NodeElement { IfE(tree t)         : NodeElement(*t){} void accept(Visitor * v) ; };
struct ElseE      : public NodeElement { ElseE(tree t)       : NodeElement(*t){} void accept(Visitor * v) ; };

/* loop */
struct LoopE      : public NodeElement { LoopE(tree t)       : NodeElement(*t){} void accept(Visitor * v) ; };

struct Assignment : public NodeElement { Assignment(tree t)  : NodeElement(*t){} void accept(Visitor * v) ; };

struct IntConstE  : public NodeElement { IntConstE  (tree t) : NodeElement(*t){} void accept(Visitor * v) ; };
struct RealConstE : public NodeElement { RealConstE (tree t) : NodeElement(*t){} void accept(Visitor * v) ; };
struct VarE       : public NodeElement { VarE       (tree t) : NodeElement(*t){} void accept(Visitor * v) ; };
struct DataAssignE: public NodeElement { DataAssignE(tree t) : NodeElement(*t){} void accept(Visitor * v) ; };

extern char TokName[][15];

tree buildTree      (int kind, tree first, tree second, tree third);
tree buildIntTree   (int kind, int val);
tree buildStrTree   (int kind, char *name);
tree buildDoubleTree(int kind, double rval);
void printTree      (tree p);
