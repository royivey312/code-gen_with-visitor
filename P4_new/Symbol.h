//
// Created by roy on 11/25/17.
//

#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <ostream>
#include <list>
#include <memory>
#include "tree.h"
#include "y.tab.h"

using namespace std;

#pragma once

struct Symbol
{
    Symbol() {}
    Symbol(string id, string type, int scopelevel, int memoryAddr) : id(id)    , type(type)    , scopelevel(scopelevel), memoryAddr(memoryAddr)     {}
    Symbol(const Symbol& obj)                      : id(obj.id), type(obj.type), scopelevel(obj.scopelevel), memoryAddr(obj.memoryAddr) {}

    // Members
    string id;
    string type;
    int scopelevel;
    int memoryAddr;

    friend ostream &operator<<(ostream &os, const Symbol &symbol)
    {
        os << "mem: " << symbol.memoryAddr << ", id: " << symbol.id << ", type: " << symbol.type << ", Scpl " << symbol.scopelevel;
        return os;
    }
};



class SymbolTable
{
    SymbolTable         * parent;
    map<string, Symbol>   table{};
    list<SymbolTable*>    children{};

public:
    int scope;
    SymbolTable()                    : parent(nullptr), scope(0)                 { }
    SymbolTable(SymbolTable* parent) : parent(parent) , scope(parent->scope + 1) { }

    void insert       (Symbol sym)          { table[sym.id] = sym; }
    void addChildTable(SymbolTable * child) { children.emplace_back(child); }

    list<SymbolTable*> getChildren() { return children; }


    Symbol * lookup(string symID)
    {
        if   (table.find(symID) == table.end()) { return nullptr      ; }
        else                                    { return &table[symID]; }
    }

    Symbol * rlookup(string symID)
    {
        if   (table.find(symID) == table.end())
             {
                Symbol * sym = nullptr;

                if (parent == nullptr) { return nullptr; }
                
                sym = parent->rlookup(symID);

                if (sym != nullptr) { table[sym->id] = *sym; }
                return       sym;
             }
        else { return &table[symID]; }
    }

    friend ostream &operator<<(ostream &os, const SymbolTable &table)
    {
        for (auto sym : table.table)
        {
            os << "symbol: <" << sym.second << ">" << endl;
        }
        return os;
    }
};



class STConstuctor
{
    tree target;
    SymbolTable * globalTable;
    SymbolTable * currentTable;

public:
    STConstuctor(const tree& t) : target(t) {}

    SymbolTable * buildSymbolTables()
    {
        SymbolTable * main = new SymbolTable{};
        currentTable = main;
        globalTable  = main;

        cout << endl << "----> Entered Program Scope" << endl;

        rbuild(target);
        cout << "----> Exited Program Scope" << endl;

        return globalTable;
    }

private:

    void rbuild(tree &t)
    {
        if (t == nullptr) { return; }

        if (scopeChange(t->kind)) { checkNewScope(t); }
        else 
        {
            checkNode(t);

            // Double evaluation of types on exit, needs a refactor
            if(t->next == nullptr && t->kind != Exit) { rbuild(t->first); rbuild(t->second); rbuild(t->third); }
            else                    { rbuild(t->next); }    
        }
    }

    void checkNewScope(tree &scope)
    {
        string type{"Unknown Scope Change"};

        if      (scope->kind == Loop)  { type = "Loop";   }
        else if (scope->kind == Begin) { type = "Begin";  }
        else if (scope->kind == ElseIf){ type = "Else If";}
        else if (scope->kind == Else)  { type = "Else";   }
        else if (scope->kind == Then)  { type = "Then";   }

        cout << endl << "----> Entered " << type << " Scope" << endl;

        SymbolTable * pscope = currentTable;
        SymbolTable * cscope = new SymbolTable{pscope};

        currentTable = cscope;

        rbuild(scope->kind != ElseIf ? scope->first : scope->second);

        pscope->addChildTable(cscope);

        cout << *cscope;
        currentTable = pscope;

        cout << "----> Exited " << type << " Scope" << endl << endl;

        if (scope->kind == ElseIf) { rbuild(scope->third); }
    }

    bool scopeChange(int kind)
    {
        //cout << "ScopeCheck(" << kind << ")" << endl;
        if      (kind == Loop)  { return true;  }
        else if (kind == Begin) { return true;  }
        else if (kind == ElseIf){ return true;  }
        else if (kind == Else)  { return true;  }
        else if (kind == Then)  { return true;  }
        else                    { return false; }
    }

    void checkNode(tree  &node)
    {
        symbolCheck(node);
        typeCheck(node);
    }

    void symbolCheck(tree  &op)
    {
        tree lhs = op->first;
        tree rhs = op->second;

        if      (op->kind == TAssign)
        {
            list<string> idents = collectIdents(lhs);

            if (op->second->name == nullptr) { addRecord ( idents, op               ); }
            else                             { addSymbols( idents, op->second->name ); }
        }
        else if (op->kind == Bind)
        {
            list<string> idents = collectIdents(lhs);
            string id{ rhs->kind != Dot ? rhs->first->name : recordRef(rhs) };

            string type { getType(id) };

            addSymbols(idents, type);
        }
        else if (op->kind == Record)
        {

        }
        else { rbuild(op->first); rbuild(op->second); rbuild(op->third); }
    }

    string recordRef(tree &recRef)
    {
        string var{recRef->first->name};
        string ref{recRef->second->name};
        return string{var + "." + ref};
    }


    void addRecord(list<string> idents, tree &record)
    {
        list<Symbol> refs = gatherRecordSymbols(record->second);

        for(string id : idents)
        {

            Symbol * oldSym = currentTable->lookup(id);
            Symbol sym{id, string{"record"}, currentTable->scope, 0};

            if   ( oldSym == NULL )
                 { currentTable->insert(sym); }
            else
                 {
                    cout << "Re-Declaration of symbol: <" << *oldSym
                                                          << "> As <"
                                                          << sym
                                                          << ">"
                                                          << endl;
                    return;
                 }

            for(Symbol ref : refs)
            {
                ref.id = string{ id + "." + ref.id };
                currentTable->insert(ref);
            }
        }
    }

    list<Symbol> gatherRecordSymbols(tree &record)
    {
        tree field_list = record->first;
        return getFieldSyms(field_list);   
    }

    list<Symbol> getFieldSyms(tree &field_list)
    {
        list<Symbol> syms{};

        //cout << "first kind, name("<< TokName[field_list->kind] << ", " << field_list->name << ") " << endl;
        if (field_list == nullptr) { return syms; }

        cout.flush();

        string id{field_list->first->name};
        string type{field_list->second->name};

        Symbol recSym{id, type, currentTable->scope, memCtr};
        incrementMemCtr(recSym.type);

        syms.emplace_back(recSym);

        if(field_list->third != nullptr) 
        { 
            list<Symbol> othersyms = getFieldSyms(field_list->third);
            syms.insert( syms.end(),  othersyms.begin(), othersyms.end() );
        }

        return syms;
    }


    string getType(string id)
    {
        Symbol * sym = currentTable->rlookup(id);

        if   (sym == nullptr) {
                                   cout << "Attempt to reference undefined symbol '"
                                        << id << "'." << endl;
                                    return "Undefined";
                            
                              }
        return sym->type;
    }


    void typeCheck(tree  &op)
    {
        if (op->kind == Assign)     { evalOperation(op); }
    }

    void evalOperation(tree &op)
    {
        Symbol * LHSymbol = currentTable->rlookup(op->first->name);
        string   RHSType;

        if   (LHSymbol->type == "boolean") 
             { 
                RHSType = isRelational(op->second->kind) 
                        ? evalComparison(op->second)
                        : "Non-Boolean";
             }
        else { RHSType  = evalType(op->second); }
        

        if      (RHSType.find("Invalid") != string::npos) { cout << RHSType << endl; }
        else if (RHSType == "Undefined") {}
        else if (LHSymbol->type != RHSType)               { cout << "Type Mismatch: <"<< *LHSymbol << "> can not use operation " << TokName[op->kind] << " with " << RHSType << endl;}

    }

    // We need to find out if both sides of the equation are the same type
    // If they are not, then output a message. Always return boolean
    string evalComparison(tree &expr)
    {
        string LHSType = evalType(expr->first);
        string RHSType = evalType(expr->second);

        if(LHSType != RHSType) { cout << "Invalid compare between " 
                                      << LHSType
                                      << " and "
                                      << RHSType 
                                      << endl; return "Non-Boolean";}
 
        return "boolean";
    }

    string evalType(tree &expr)
    {
        string exprtype{"Unknown"};
        if      (expr->kind == Real)       { exprtype = "real";              }
        else if (expr->kind == IntConst )  { exprtype = "integer";           }
        else if (expr->kind == Boolean)    { exprtype = "boolean";           }
        else if (expr->kind == Ident)      { exprtype = getType(expr->name); }
        else if (expr->kind == Dot)        { exprtype = getType(recordRef(expr)); }
        else if (isCalc(expr->kind))       { exprtype = evalCalc(expr);      }

        return exprtype;
    }



    string evalCalc(tree &calc)
    {
        string LHSType = evalType(calc->first);
        string RHSType = evalType(calc->second);

        if      (LHSType                 == RHSType)      { return LHSType; } 
        else if (  RHSType.find("Invalid") != string::npos
                || LHSType != RHSType)                    { return "Invalid Operation: " + LHSType + " " + string{TokName[calc->kind]} + " " + RHSType; }
        else                                              { return RHSType; }
    }

    bool isRelational(int type)
    {
        if (  type == Eq
           || type == Ne
           || type == Lt
           || type == Le
           || type == Gt
           || type == Ge
            ){ return true; }
        else { return false;}
    }

    bool isCalc(int type)
    {
        if (  type == Plus
           || type == Minus
           || type == Star
           || type == Slash
           || type == Div
           || type == Mod
            ){ return true; }
        else { return false;}
    }


    list<string> collectIdents(tree &identNode)
    {
        // needs to handle Ident.Ident Case
        list<string> idlist;
        if (identNode == nullptr) { return idlist; }

        string id = identNode->name == nullptr ? "Unknown" : identNode->name;
        idlist.emplace_back(id);

        tree next = identNode->next;
        idlist.merge( collectIdents(next) );
        return idlist;
    }

    void addSymbols(list<string> idlist, string type)
    {
        
        for(string id : idlist)
        {
            Symbol * sym = currentTable->lookup(id);
            Symbol newsym{id, type, currentTable->scope, memCtr};

            if   ( sym == NULL )
                 {
                    currentTable->insert( newsym );
                    incrementMemCtr(newsym.type);
                 }
            else
                 { cout << "Re-Declaration of symbol: <" << *sym
                                                         << "> As <"
                                                         << newsym
                                                         << ">"
                                                         << endl; }
        }
    }

    void incrementMemCtr(string type) { memCtr += type == "real" ? realMem : intboolMem; }
    int memCtr = 0;
    const int realMem    = 8;
    const int intboolMem = 4;
};

//#endif //SYMBOL_H
