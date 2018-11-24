#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <string>
#include <vector>
#include <map>

#include "AST.h"

typedef std::map<std::string, std::pair<bool, struct ClassRow *>> SymbolTable;

struct MethodRow
{
    std::string method_name_;
    struct ClassRow *class_;
    struct ClassRow *type_;
    std::vector<ClassRow *> args_;
    SymbolTable sym_;
};

struct ClassRow
{
    std::string class_name_;
    ClassRow *super_class_ = NULL;
    MethodRow *constructor_ = NULL;
    bool initialized = false;
    std::map<std::string, MethodRow *> methods_;
    SymbolTable fields_;
    SymbolTable sym_;

    ClassRow(std::string class_name): class_name_(class_name) {}
};

typedef std::vector<std::string> InitTable;
typedef std::map<std::string, struct ClassRow *> NameClassMap;
typedef std::pair<std::string, struct ClassRow *> ClassEntry;
typedef std::pair<std::string, struct MethodRow *> MethodEntry;
typedef std::pair<std::string, std::vector<std::string>> AdjEntry;
typedef std::map<std::string, std::vector<std::string>> AdjMatrix;
typedef std::map<std::string, std::map<std::string, std::string>> LCA_Table;


#endif
