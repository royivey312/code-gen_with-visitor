// NodeVisitor.cpp
#include "NodeVisitor.h"
#include "codespace.h"
#include "tree.h"
#include "y.tab.h"
#include "Symbol.h"

NodeVisitor::NodeVisitor(SymbolTable * t) : root(t) {}

void NodeVisitor::operation(NodeElement * e)
{
   NodeElement * lhs = e->first;
   NodeElement * rhs = e->second;

   putVarOnStack(lhs);
   putVarOnStack(rhs);
}

void NodeVisitor::putVarOnStack(NodeElement * e)
{
   if   ( e->name == nullptr ) { dynamic_cast<Element*>(e)->accept(this); }
   else                          
   {
      stringstream ss{};
      Symbol * sym = root->lookup(e->name);
      string push{};
      string get{};

      if   ( sym->type == "real" ) { push = "PUSHL "; get = " GETSL"; }
      else                         { push = "PUSHW "; get = " GETSW"; }

      ss << push << sym->memoryAddr << get << endl;

      cout << ss.str();
   }
}

void NodeVisitor::visit(PlusE      e)
{
   stringstream ss{};
   ss << "/* Addition */" << endl;

   operation(&e);

   ss << "ADDI" << endl;
   cout << ss.str();
}

void NodeVisitor::visit(SubE       e)
{
   
   stringstream ss{};
   ss << "/* Subtraction */" << endl;

   operation(&e);

   ss << "SUBI" << endl;
   cout << ss.str();

}

void NodeVisitor::visit(DivE       e)
{
   
   stringstream ss{};
   ss << "/* Division */" << endl;

   operation(&e);

   ss << "DIVI" << endl;
   cout << ss.str();

}

void NodeVisitor::visit(MulE       e)
{
   
   stringstream ss{};
   ss << "/* Multiplication */" << endl;

   operation(&e);

   ss << "MULI" << endl;
   cout << ss.str();

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
   NodeElement * lhs = e.first;
   Symbol * lhSymbol = root->lookup(lhs->name);
   Element * rhs = e.second;
   
   stringstream ss{};
   ss << "PUSHW " << lhSymbol->memoryAddr << endl;
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
   stringstream ss{};
   ss << "PUSHL " << e.value << endl;
   cout << ss.str();  
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

   ss << ".DATA" << endl;

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
