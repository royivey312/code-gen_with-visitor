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

      ss << push << sym->id << get << endl;

      cout << ss.str();
      codeBytesCtr += sym->type == "real" ? 6 : 4;
   }
}

void NodeVisitor::visit(PlusE      e)
{
   stringstream ss{};
   ss << "/* Addition CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "ADDI" << endl;
   cout << ss.str();
   codeBytesCtr++;
}

void NodeVisitor::visit(SubE       e)
{
   
   stringstream ss{};
   ss << "/* Subtraction CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI" << endl;
   cout << ss.str();
   codeBytesCtr++;

}

void NodeVisitor::visit(DivE       e)
{
   
   stringstream ss{};
   ss << "/* Division CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "DIVI" << endl;
   cout << ss.str();
   codeBytesCtr++;

}

void NodeVisitor::visit(MulE       e)
{
   
   stringstream ss{};
   ss << "/* Multiplication CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "MULI" << endl;
   cout << ss.str();
   codeBytesCtr++;

}

void NodeVisitor::visit(ModE       e)
{
   stringstream ss{};
   ss << "/* Mod CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "DUPL DIVI MULI SUBI" << endl;
   cout << ss.str();

   codeBytesCtr += 4;

}

/* RELATIONAL */

void NodeVisitor::visit(LtE        e)
{
   stringstream ss{};
   ss << "/* Less Than CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI TSTLTI" << endl;
   cout << ss.str();

   codeBytesCtr += 2;

}

void NodeVisitor::visit(LeE        e)
{
   stringstream ss{};
   ss << "/* Less Than or Equal CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SWAPW SUBI TSTLTI NOTW" << endl;
   cout << ss.str();

   codeBytesCtr += 4;

}

void NodeVisitor::visit(GtE        e)
{
   stringstream ss{};
   ss << "/* Greater Than CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SWAPW SUBI TSTLTI" << endl;
   cout << ss.str();
   codeBytesCtr += 3;

}

void NodeVisitor::visit(GeE        e)
{
   stringstream ss{};
   ss << "/* Greater Than or Equal CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI TSTLTI NOTW" << endl;
   cout << ss.str();
   codeBytesCtr += 3;


}

void NodeVisitor::visit(EqE        e)
{
   stringstream ss{};
   ss << "/* Equal Check CS: " << codeBytesCtr << "*/"<< endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI TSTEQI" << endl;
   cout << ss.str();
   codeBytesCtr += 2;

}

void NodeVisitor::visit(NeE        e)
{

   stringstream ss{};
   ss << "/* Not Equal Check CS: " << codeBytesCtr << "*/" << endl;

   cout << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI TSTEQI NOTW" << endl;
   cout << ss.str();
   codeBytesCtr += 3;

}

void NodeVisitor::visit(IfE        e)
{
   stringstream ss{};
   string label{ (char)labelCtr++ };
   ss << "/* If Condition Check CS: " << codeBytesCtr << "*/" << endl;
   ss << "PUSHW c" << label << " GETSQ" << endl;

   cout << ss.str();
   ss.str(string{});
   codeBytesCtr += 4;

   dynamic_cast<Element *>(e.first)->accept(this);

   ss << "GOZ" << endl;
   cout << ss.str();
   ss.str(string{});
   codeBytesCtr++;

   Element * then = e.second;
   if (then != nullptr) { then->accept(this); }
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
   ss << "PUSHW " << lhSymbol->id << endl;

   cout << ss.str();
   ss.str(string{});
   codeBytesCtr += 3;

   rhs->accept(this);

   ss << "PUTSW" << endl;
   cout << ss.str();
   codeBytesCtr += 1;

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
   codeBytesCtr += 5; 
}

void NodeVisitor::visit(IntConstE e)
{
   stringstream ss{};
   ss << "PUSHW " << e.value << endl;
   cout << ss.str();
   codeBytesCtr += 3;

}

void NodeVisitor::visit(DataAssignE e)
{
   NodeElement * it = e.first;
   stringstream ss{};

   ss <<  endl  << ".DATA" << endl;

   while(it != nullptr)
   {
      Symbol * var = root->lookup(it->name);
      string value = var->type == "real" ? "0L" : "0W";

      ss << var->memoryAddr << ": " << var->id << ": " << value << endl;
      it = it->next;
   }

   ss << endl << ".CODE"  << endl;

   cout << ss.str();
}
