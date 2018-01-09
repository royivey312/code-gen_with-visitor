#pragma once
#include <iostream>
#include <list>
#include "codespace.h"
using namespace std;

struct NodeElement;

struct PlusE;
struct SubE ;
struct DivE ;
struct MulE ;
struct ModE ;

struct LtE ;
struct LeE ;
struct GtE ;
struct GeE ;
struct EqE ;
struct NeE ;

struct IfE ;
struct ElseE;

struct LoopE;
struct Assignment;
struct IntConstE;
struct RealConstE;
struct OrE;
struct AndE;
struct NotE;
struct DataAssignE;

struct Symbol;
struct SymbolTable;

class Visitor
{
public:
	virtual void visit(PlusE       e) = 0;
	virtual void visit(SubE        e) = 0;
	virtual void visit(DivE        e) = 0;
	virtual void visit(MulE        e) = 0;
	virtual void visit(ModE        e) = 0;
	virtual void visit(LtE         e) = 0;
	virtual void visit(LeE         e) = 0;
	virtual void visit(GtE         e) = 0;
	virtual void visit(GeE         e) = 0;
	virtual void visit(EqE         e) = 0;
	virtual void visit(NeE         e) = 0;

	virtual void visit(IfE         e) = 0;
	virtual void visit(ElseE       e) = 0;

	virtual void visit(LoopE       e) = 0;
	virtual void visit(Assignment  e) = 0;

	virtual void visit(IntConstE   e) = 0;
	virtual void visit(RealConstE  e) = 0;

	virtual void visit(OrE         e) = 0;
	virtual void visit(AndE        e) = 0;
	virtual void visit(NotE        e) = 0;
	virtual void visit(DataAssignE e) = 0;
};

class NodeVisitor : public Visitor
{

	SymbolTable * root;
	int labelCtr = (int)*"A";
	int codeBytesCtr = 0;
	list<codespace> operations;
	void putVarOnStack(NodeElement *);
	void operation(NodeElement *);
public:
	NodeVisitor(SymbolTable * t);
	void visit(PlusE       e);
    void visit(SubE        e);
    void visit(DivE        e);
    void visit(MulE        e);
    void visit(ModE        e);
    void visit(LtE         e);
    void visit(LeE         e);
    void visit(GtE         e);
    void visit(GeE         e);
    void visit(EqE         e);
    void visit(NeE         e);

    void visit(IfE         e);
	void visit(ElseE       e);

    void visit(LoopE       e);
    void visit(Assignment  e);
    void visit(IntConstE   e);
	void visit(RealConstE  e);
	void visit(OrE         e);
	void visit(AndE        e);
	void visit(NotE        e);
	void visit(DataAssignE e);
};