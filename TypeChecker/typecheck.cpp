#include "typecheck.h"
#include <iostream>
void TypeChecker::checkClasses() {
    AST::Block *classes_ = (AST::Block *)((AST::Block *) (*root_)) -> stmts_[0];
    AST::AST_print_context ctx;   
    int num_classes = classes_ -> stmts_.size();
    std::string class_name, super_name;
    AST::Class *clazz_;
    Table::iterator it;
    for (int i = 0; i < num_classes; i++) {
        clazz_ = (AST::Class *) classes_ -> stmts_[i];
        class_name = ((AST::Ident *) clazz_ -> class_name_) -> text_;
        super_name = ((AST::Ident *) clazz_ -> super_name_) -> text_;
        it = class_heir_.find(super_name);
        if (it == class_heir_.end()) {
            std::vector<std::string> *v = new std::vector<std::string>();
            class_heir_.insert(Entry(super_name, v));
        }
        class_heir_[super_name] -> push_back(class_name);
    }
}
