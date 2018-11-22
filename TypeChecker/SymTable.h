#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <string>
#include <vector>
#include <map>

#include "AST.h"

struct MethodRow
{
    std::string method_name_;
    struct ClassRow *class_;
    struct ClassRow *type_;
    std::vector<ClassRow *> args_;
    std::map<std::string, ClassRow *> sym_;
};

struct ClassRow
{
    std::string class_name_;
    ClassRow *super_class_ = NULL;
    MethodRow *constructor_ = NULL;
    bool initialized = false;
    std::map<std::string, MethodRow *> methods_;
    std::map<std::string, ClassRow *> fields_;
    std::map<std::string, ClassRow *> sym_;

    ClassRow(std::string class_name): class_name_(class_name) {}
};

typedef std::vector<std::string> InitTable;
typedef std::map<std::string, ClassRow *> NameClassMap;
typedef std::pair<std::string, ClassRow *> ClassEntry;
typedef std::pair<std::string, MethodRow *> MethodEntry;
typedef std::pair<std::string, std::vector<std::string>> AdjEntry;
typedef std::map<std::string, std::vector<std::string>> AdjMatrix;
typedef std::map<std::string, std::pair<bool, ClassRow *>> SymbolTable;
typedef std::map<std::string, std::map<std::string, std::string>> LCA_Table;

#endif
