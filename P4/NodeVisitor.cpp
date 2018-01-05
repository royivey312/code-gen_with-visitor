// NodeVisitor.cpp
#include "NodeVisitor.h"
#include "codespace.h"
#include "tree.h"
#include "y.tab.h"

void NodeVisitor::visit(PlusE      e)
{
	codespace n{};
	int rkind   = e.first->kind;
	auto rvalue = rkind == IntConst 
	            ? e.first->value
	            : rkind == Real
	            ? e.first->rvalue
	            : 
	n.assemblyLines << "PUSHW ";
}

void NodeVisitor::visit(SubE       e)
{

}

void NodeVisitor::visit(DivE       e)
{

}

void NodeVisitor::visit(MulE       e)
{

}

void NodeVisitor::visit(ModE       e)
{

}

void NodeVisitor::visit(LtE        e)
{

}

void NodeVisitor::visit(LeE        e)
{

}

void NodeVisitor::visit(GtE        e)
{

}

void NodeVisitor::visit(GeE        e)
{

}

void NodeVisitor::visit(EqE        e)
{

}

void NodeVisitor::visit(NeE        e)
{

}

void NodeVisitor::visit(IfE        e)
{

}

void NodeVisitor::visit(LoopE      e)
{

}

void NodeVisitor::visit(Assignment e)
{

}
