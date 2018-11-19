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
    std::vector<ClassRow *> args_;
    std::map<std::string, std::string> sym_;
    
    MethodRow(ClassRow *clazz, std::string method_name): 
        class_(clazz), method_name_(method_name) {}
};

struct ClassRow
{
    std::string class_name_;
    ClassRow *super_class_ = NULL;
    MethodRow *constructor_ = NULL;
    std::map<std::string, MethodRow *> methods_;
    std::map<std::string, std::string> fields_;

    ClassRow(std::string class_name): class_name_(class_name) {}
};

typedef std::map<std::string, ClassRow *> NameClassMap;
typedef std::pair<std::string, ClassRow *> ClassEntry;
typedef std::pair<std::string, MethodRow *> MethodEntry;
typedef std::pair<std::string, std::vector<std::string>> AdjEntry;
typedef std::map<std::string, std::vector<std::string>> AdjMatrix;

#endif
