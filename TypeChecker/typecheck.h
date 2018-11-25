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
    InitTable builtins_;
    
    public:
        bool checkClasses();
        bool inheritMethods();
        bool inheritVariables();
        bool checkInit();
        TypeChecker(AST::Program **root): root_(root) {
            builtins_.push_back("Obj");
            builtins_.push_back("Nothing");
            builtins_.push_back("Int");
            builtins_.push_back("String");
            builtins_.push_back("Boolean");

            //Build Symbol Table
            (*root) -> updateClasses();
            
            //Check Class Heirarchy Well Formed
            if (!checkClasses()) {
                std::cerr << "Error Checking Class Heirarchy" << std::endl;
                std::cerr << "Aborting..." << std::endl;
                exit(1);
            }

            //Inherit Methods to Subtypes
            if (!inheritMethods()) {
                std::cerr << "Error Inheriting Methods" << std::endl;
                std::cerr << "Aborting..." << std::endl;
                exit(1);
            }

            if (!checkInit()) {
                std::cerr << "Error Performing Init" << std::endl;
                std::cerr << "Aborting..." << std::endl;
                exit(1);
            
            }

            if (AST::ASTNode::error_count > 0) {
                std::cerr << "Too many errors" << std::endl;
                std::cerr << "Aborting..." << std::endl;
                exit(1);
            }

            if (!inheritVariables()) {
                std::cerr << "Error Inheriting Variables" << std::endl;
                std::cerr << "Aborting..." << std::endl;
                exit(1);
            }
            
        };
};

#endif
