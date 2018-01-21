// NodeVisitor.cpp
#include "NodeVisitor.h"
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

      codeStream << ss.str();
      codeBytesCtr += sym->type == "real" ? 6 : 4;
   }
}

void NodeVisitor::generateInnerScope(NodeElement * e)
{
   NodeElement * next = nullptr;

   if (e != nullptr) 
      {
         dynamic_cast<Element*>(e)->accept(this);
         next = e->next;
      }

   while ( next != nullptr ) 
         {
            dynamic_cast<Element*>(next)->accept(this);
            next = next->next;
         }
}

void NodeVisitor::visit(PlusE      e)
{
   stringstream ss{};
   ss << "/* Addition BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "ADDI" << endl;
   codeStream << ss.str();
   codeBytesCtr++;
}

void NodeVisitor::visit(SubE       e)
{
   
   stringstream ss{};
   ss << "/* Subtraction BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI" << endl;
   codeStream << ss.str();
   codeBytesCtr++;

}

void NodeVisitor::visit(DivE       e)
{
   
   stringstream ss{};
   ss << "/* Division BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "DIVI" << endl;
   codeStream << ss.str();
   codeBytesCtr++;

}

void NodeVisitor::visit(MulE       e)
{
   
   stringstream ss{};
   ss << "/* Multiplication BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "MULI" << endl;
   codeStream << ss.str();
   codeBytesCtr++;

}

void NodeVisitor::visit(ModE       e)
{
   stringstream ss{};
   ss << "/* Mod BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "DUPL DIVI MULI SUBI" << endl;
   codeStream << ss.str();

   codeBytesCtr += 4;

}

/* RELATIONAL */

void NodeVisitor::visit(LtE        e)
{
   stringstream ss{};
   ss << "/* Less Than BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI TSTLTI" << endl;
   codeStream << ss.str();

   codeBytesCtr += 2;

}

void NodeVisitor::visit(LeE        e)
{
   stringstream ss{};
   ss << "/* Less Than or Equal BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SWAPW SUBI TSTLTI NOTW" << endl;
   codeStream << ss.str();

   codeBytesCtr += 4;

}

void NodeVisitor::visit(GtE        e)
{
   stringstream ss{};
   ss << "/* Greater Than BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SWAPW SUBI TSTLTI" << endl;
   codeStream << ss.str();
   codeBytesCtr += 3;

}

void NodeVisitor::visit(GeE        e)
{
   stringstream ss{};
   ss << "/* Greater Than or Equal BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI TSTLTI NOTW" << endl;
   codeStream << ss.str();
   codeBytesCtr += 3;


}

void NodeVisitor::visit(EqE        e)
{
   stringstream ss{};
   ss << "/* Equal Check BYTE NUM: " << codeBytesCtr << "*/"<< endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI TSTEQI" << endl;
   codeStream << ss.str();
   codeBytesCtr += 2;

}

void NodeVisitor::visit(NeE        e)
{

   stringstream ss{};
   ss << "/* Not Equal Check BYTE NUM: " << codeBytesCtr << "*/" << endl;

   codeStream << ss.str();
   ss.str(string{});

   operation(&e);

   ss << "SUBI TSTEQI NOTW" << endl;
   codeStream << ss.str();
   codeBytesCtr += 3;

}

void NodeVisitor::visit(IfE        e)
{
   stringstream ss{};

   ss << "/* If Condition Check BYTE NUM: " << codeBytesCtr << "*/" << endl;

   string label   { (char)labelCtr++ };
   string endLabel{ (char)labelCtr++ };
   ss << "PUSHW " << label << " GETSQ" << endl;
   codeStream << ss.str();
   ss.str(string{});
   codeBytesCtr += 4;

   Element     * cond     = e.first;
   NodeElement * then     = e.second->first;
   NodeElement * elseNode = e.third;
   NodeElement * next     = nullptr;

   cond->accept(this);

   ss << "GOZ" << endl;
   codeStream << ss.str();
   ss.str(string{});
   codeBytesCtr++;

   generateInnerScope(then);

   ss << "PUSHW " << endLabel << " GETSQ PUSHW -1 GOZ" << endl;
   codeBytesCtr += 8;
   codeStream << ss.str();
   ss.str(string{});

   ss << root->memCtr << ": " << label << ": " << codeBytesCtr << "Q" << endl;


   root->memCtr += 8;
   dataStream << ss.str();
   ss.str(string{});

   generateInnerScope(elseNode);

   ss << root->memCtr << ": " << endLabel << ": " << codeBytesCtr << "Q" << endl;

   root->memCtr += 6;

   dataStream << ss.str();
}

void NodeVisitor::visit(ElseE       e)
{
   stringstream ss{};
   ss << "/* Else BYTE NUM: " << codeBytesCtr << "*/" << endl;
   codeStream << ss.str();
   if (e.first != nullptr) { dynamic_cast<Element *>(e.first)->accept(this); }
}


void NodeVisitor::visit(LoopE      e)
{
   codeStream << "Visit" << endl;
}

void NodeVisitor::visit(VarE      e)
{
   putVarOnStack(dynamic_cast<NodeElement*>(&e));
}

void NodeVisitor::visit(Assignment e)
{

   NodeElement * lhs = e.first;
   Symbol * lhSymbol = root->lookup(lhs->name);
   Element * rhs = e.second;
   
   stringstream ss{};
   ss << "/* Assignment BYTE NUM: " << codeBytesCtr << "*/" << endl;
   ss << "PUSHW " << lhSymbol->id << endl;

   codeStream << ss.str();
   ss.str(string{});
   codeBytesCtr += 3;

   if (rhs != nullptr)
   {
      rhs->accept(this);

      ss << "PUTSW" << endl;
      codeStream << ss.str();
      codeBytesCtr += 1;
   }

}

void NodeVisitor::visit(OrE e)
{
   stringstream ss{};
   ss << "/* Or BYTE NUM:" << codeBytesCtr << " */" << endl;
   codeStream << ss.str();
   ss.str(string{});
   operation(&e);

   ss << "ORW" << endl;
   codeBytesCtr++;
   codeStream << ss.str();
}

void NodeVisitor::visit(AndE e)
{
   stringstream ss{};
   Element * operand = e.first;
   ss << "/* Or BYTE NUM:" << codeBytesCtr << " */" << endl;
   codeStream << ss.str();
   ss.str(string{});

   operation(&e);


   ss << "ANDW" << endl;
   codeBytesCtr++;
   codeStream << ss.str();
}

void NodeVisitor::visit(NotE e)
{
   stringstream ss{};
   Element * operand = e.first;
   ss << "/* NOT BYTE NUM:" << codeBytesCtr << " */" << endl;
   codeStream << ss.str();
   ss.str(string{});


   operand->accept(this);


   ss << "NOTW" << endl;
   codeBytesCtr++;
   codeStream << ss.str();
}

void NodeVisitor::visit(RealConstE e)
{
   stringstream ss{};
   ss << "PUSHL " << e.value << endl;
   codeStream << ss.str(); 
   codeBytesCtr += 5; 
}

void NodeVisitor::visit(IntConstE e)
{
   stringstream ss{};
   ss << "PUSHW " << e.value << endl;
   codeStream << ss.str();
   codeBytesCtr += 3;

}

void NodeVisitor::visit(DataAssignE e)
{
   NodeElement * it = e.first;
   stringstream ss{};

   while(it != nullptr)
   {
      Symbol * var = root->lookup(it->name);
      string value = var->type == "real" ? "0L" : "0W";

      ss << var->memoryAddr << ": " << var->id << ": " << value << endl;
      it = it->next;
   }

   dataStream << ss.str();
}
