#include <stack>
#include <iostream>
#include <algorithm>

#include "typecheck.h"

bool TypeChecker::checkClasses() {
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
        if (super_name == "") {
            super_name = "Obj";
        }

        it = class_heir_.find(super_name);
        if (it == class_heir_.end()) {
            std::vector<std::string> v;
            class_heir_.insert(Entry(super_name, v));
        }
        class_heir_[super_name].push_back(class_name);
    }

    //DEBUG
    for (auto p: class_heir_) {
        std::cerr << p.first << " ";
        for (auto v: p.second) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
    }

    //Detect Cycle
    std::vector<std::string> seen;
    std::stack<std::string> dfs_stack;
    std::string curr_node;
    
    dfs_stack.push("Obj");
    while (!dfs_stack.empty()) {

        curr_node = dfs_stack.top();
        dfs_stack.pop();
        if (std::find(seen.begin(), seen.end(), curr_node) != seen.end()) {
            std::cerr << "FALSE" << std::endl; //DEBUGGING
            return false;
        }
        seen.push_back(curr_node);
        if (class_heir_.find(curr_node) == class_heir_.end()) {
            continue;
        }
        for(auto s: class_heir_[curr_node]) {
            dfs_stack.push(s);
        }

    }
    std::cerr << "TRUE" << std::endl; //DEBUGGING
    return true;

}
