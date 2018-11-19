#ifndef TYPECHECK_H
#define TYPECHECK_H

#include <map>
#include <stack>

#include "AST.h"
#include "SymTable.h"

class TypeChecker
{
    AST::Program **root_;
    AdjMatrix class_heir_;
    LCA_Table LCA;
    
    public:
        TypeChecker(AST::Program **root): root_(root) {};
        bool checkClasses();
};

#endif
