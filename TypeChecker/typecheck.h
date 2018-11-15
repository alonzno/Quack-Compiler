#ifndef TYPECHECK_H
#define TYPECHECK_H

#include <AST.h>
#include <map>
#include <stack>

typedef std::pair<std::string, std::vector<std::string>> Entry;
typedef std::map<std::string, std::vector<std::string>> ClassTable;
typedef std::map<std::string, std::string> TypeTable;
typedef std::vector<std::string> InitTable;

class TypeChecker
{
    AST::ASTNode **root_;
    ClassTable class_heir_;
    InitTable init_table_;
    TypeTable type_table_;
    
    public:
        TypeChecker(AST::ASTNode **root): root_(root) {};
        bool checkClasses();
        bool checkInit();
        bool checkInitClass(std::stack<std::string> &pre, AST::Class *clazz);
        bool checkInitMethod(std::stack<std::string> &pre, AST::Method *method);
        bool checkInitStmt(std::stack<std::string> &pre, AST::ASTNode *stmt, std::string type);
        std::string makePrefix(std::stack<std::string> s);
};

#endif
