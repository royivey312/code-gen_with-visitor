#include "tree.h"
#include "NodeVisitor.h"

#pragma once

struct Element {};

struct NodeElement : public Element, public Node
{
	NodeElement(tree t) : t(t) {}
};

/* Operations */
struct PlusE : NodeElement { PlusE(tree t) : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct SubE  : NodeElement { SubE (tree t) : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct DivE  : NodeElement { DivE (tree t) : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct MulE  : NodeElement { MulE (tree t) : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct ModE  : NodeElement { ModE (tree t) : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };

/* Comparison */
struct LtE   : NodeElement { LtE(tree t)   : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct LeE   : NodeElement { LeE(tree t)   : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct GtE   : NodeElement { GtE(tree t)   : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct GeE   : NodeElement { GeE(tree t)   : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct EqE   : NodeElement { EqE(tree t)   : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };
struct NeE   : NodeElement { NeE(tree t)   : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };

/* if/elseif/else */
struct IfE   : NodeElement { IfE(tree t)   : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };

/* loop */
struct LoopE : NodeElement { LoopE(tree t) : NodeElement(t){} void accept(NodeVisitor v) { v.visit(*this); } };