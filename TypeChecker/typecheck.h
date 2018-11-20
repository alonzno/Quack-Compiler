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
        bool checkClasses();
        bool inheritMethods();
        TypeChecker(AST::Program **root): root_(root) {

            //Build Symbol Table
            (*root) -> updateClasses();
            
            //Check Class Heirarchy Well Formed
            if (!checkClasses()) {
                std::cerr << "Aborting..." << std::endl;
                exit(1);
            }

            //Inherit Methods to Subtypes
            if (!inheritMethods()) {
                std::cerr << "Aborting..." << std::endl;
                exit(1);
            }
            
        };
};

#endif
