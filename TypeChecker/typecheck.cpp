#include <stack>
#include <iostream>
#include <algorithm>

#include "typecheck.h"

bool TypeChecker::checkClasses() {
    AST::Block *classes_ = (AST::Block *)((AST::Block *) (*root_)) -> stmts_[0];
    //AST::AST_print_context ctx;   
    std::vector<std::string *> ptr = classes_ -> types_;

    int num_classes = classes_ -> stmts_.size();

    std::string class_name, super_name;
    AST::Class *clazz_;
    ClassTable::iterator it;

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

bool TypeChecker::checkInit() {
    AST::Block *classes_ = (AST::Block *)((AST::Block *) (*root_)) -> stmts_[0];
    AST::Block *pgm_stmts_ = (AST::Block *)((AST::Block *) (*root_)) -> stmts_[1];

    int num_classes = classes_ -> stmts_.size();
    int num_stmts = pgm_stmts_ -> stmts_.size();
    
    std::stack<std::string> prefix;
    for (int i = 0; i < num_classes; i++) {
        AST::Class *clazz = (AST::Class *)classes_ -> stmts_[i];
        checkInitClass(prefix, clazz);
    }

    //Debugging
    for (std::string s: init_table_) {
        std::cerr << s << std::endl;
    }
    
    return false;
}

bool TypeChecker::checkInitClass(std::stack<std::string> &pre, AST::Class *clazz) {
    
    bool is_ok = true;
    pre.push(clazz -> class_name_ -> text_);

    AST::Method *cons = clazz -> constructor_;
    for (AST::ASTNode *a: cons -> args_ -> stmts_) {
        AST::Arg *arg = (AST::Arg *)a;
        init_table_.push_back(makePrefix(pre) + (arg -> param_name_ -> text_));
    }

    for (int j = 0; j < cons -> stmts_ -> stmts_.size(); j++) {
       std::string stmt_type_ = *(cons -> stmts_ -> types_[j]);
       AST::ASTNode *stmt_ = cons -> stmts_ -> stmts_[j];
       checkInitStmt(pre, stmt_, stmt_type_);
    }
    
    for (AST::ASTNode *m: clazz -> methods_ -> stmts_) {
        AST::Method *method = (AST::Method *)m;
        checkInitMethod(pre, method);
        init_table_.push_back(makePrefix(pre) + (method -> name_ -> text_));
    }


    pre.pop();
    
    return is_ok;
}

bool TypeChecker::checkInitMethod(std::stack<std::string> &pre, AST::Method *method) {
    
    bool is_ok = true;
    pre.push(method -> name_ -> text_);
    for (AST::ASTNode *a: method -> args_ -> stmts_) {
        AST::Arg *arg = (AST::Arg *)a;
        init_table_.push_back(makePrefix(pre) + (arg -> param_name_ -> text_));
    }

    pre.pop();
    return is_ok;
}

bool TypeChecker::checkInitStmt(std::stack<std::string> &pre, AST::ASTNode *stmt, std::string type) {
    bool is_ok = true;
        
    if (type == "If_Else") {
        std::cerr << "If_Else" << std::endl;
    }
    else if (type == "While") {
        std::cerr << "While" << std::endl;
    }
    else if (type == "Assign") {
        std::cerr << "Assign" << std::endl;
    }
    else {
        std::cerr << type << std::endl;
    }

    return is_ok;
}

std::string TypeChecker::makePrefix(std::stack<std::string> s) {
    std::string ret_str = "";
    while (!s.empty()) {
        ret_str = s.top() + "&" + ret_str;
        s.pop();
    }
    return ret_str;
}

