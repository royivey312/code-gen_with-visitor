// NodeVisitor.cpp
#include "NodeVisitor.h"
#include "codespace.h"
#include "tree.h"
#include "y.tab.h"
#include "Symbol.h"

NodeVisitor::NodeVisitor(SymbolTable * t) : root(t) {}

void NodeVisitor::visit(PlusE      e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(SubE       e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(DivE       e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(MulE       e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(ModE       e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(LtE        e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(LeE        e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(GtE        e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(GeE        e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(EqE        e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(NeE        e)
{

   cout << "Visit" << endl;
}

void NodeVisitor::visit(IfE        e)
{
   cout << "Visit" << endl;

}

void NodeVisitor::visit(LoopE      e)
{
   cout << "Visit" << endl;
}

void NodeVisitor::visit(Assignment e)
{

   Element * lhs = e.first;
   Element * rhs = e.second;
   
   stringstream ss{};
   ss << "PUSHW " << e.first->name << endl;
   cout << ss.str();
   ss.str(string{});

   rhs->accept(this);

   ss << "PUTSW" << endl;
   cout << ss.str();
}

void NodeVisitor::visit(OrE e)
{

}

void NodeVisitor::visit(AndE e)
{
   
}

void NodeVisitor::visit(NotE e)
{
   
}

void NodeVisitor::visit(RealConstE e)
{
   
}

void NodeVisitor::visit(IntConstE e)
{
   stringstream ss{};
   ss << "PUSHW " << e.value << endl;
   cout << ss.str();
}

void NodeVisitor::visit(DataAssignE e)
{
   NodeElement * it = e.first;
   stringstream ss{};

   ss << ".DATA ";

   while(it != nullptr)
   {
      Symbol * var = root->lookup(it->name);
      string value = var->type == "real" ? "0L" : "0W";

      ss << var->memoryAddr << ": " << var->id << ": " << value << endl;
      it = it->next;
   }

   ss << ".CODE"  << endl;

   cout << ss.str();
}
