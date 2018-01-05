#pragma once
#include <iostream>
#include <list>
#include "codespace.h"
using namespace std;

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
struct LoopE;
struct Assignment;

class Visitor
{
public:
	virtual void visit(PlusE      e) = 0;
	virtual void visit(SubE       e) = 0;
	virtual void visit(DivE       e) = 0;
	virtual void visit(MulE       e) = 0;
	virtual void visit(ModE       e) = 0;
	virtual void visit(LtE        e) = 0;
	virtual void visit(LeE        e) = 0;
	virtual void visit(GtE        e) = 0;
	virtual void visit(GeE        e) = 0;
	virtual void visit(EqE        e) = 0;
	virtual void visit(NeE        e) = 0;
	virtual void visit(IfE        e) = 0;
	virtual void visit(LoopE      e) = 0;
	virtual void visit(Assignment e) = 0;
};

class NodeVisitor : public Visitor
{
	list<codespace> operations;
	SymbolTable * root;
public:
	void visit(PlusE      e);
    void visit(SubE       e);
    void visit(DivE       e);
    void visit(MulE       e);
    void visit(ModE       e);
    void visit(LtE        e);
    void visit(LeE        e);
    void visit(GtE        e);
    void visit(GeE        e);
    void visit(EqE        e);
    void visit(NeE        e);
    void visit(IfE        e);
    void visit(LoopE      e);
    void visit(Assignment e);
};