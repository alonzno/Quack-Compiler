#ifndef TYPECHECK_H
#define TYPECHECK_H

#include <AST.h>
#include <map>

typedef std::pair<std::string, std::vector<std::string> *> Entry;
typedef std::map<std::string, std::vector<std::string> *> Table;

class TypeChecker
{
    AST::ASTNode **root_;
    Table class_heir_;
    public:
        TypeChecker(AST::ASTNode **root): root_(root) {};
        void checkClasses();
};

#endif
