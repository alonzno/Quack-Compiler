#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>

#include "typecheck.h"

std::deque<std::string> findPath(AdjMatrix list, std::string a) {
    std::deque<std::string> ret_val;
    ClassRow *row  = AST::ASTNode::class_map[a];

    while(row != NULL) {
        ret_val.push_front(row -> class_name_);
        row = row -> super_class_;
    }

    return ret_val;
}

std::string getLCA(AdjMatrix list, std::string a, std::string b) {
    std::deque<std::string> a_path = findPath(list, a);
    std::deque<std::string> b_path = findPath(list, b);
    
    int i;
    for (i = 0; i < a_path.size() && i < b_path.size(); i++) {
        if (a_path[i] != b_path[i]) {
            break;
        }
    }

    return a_path[i-1];
}

bool TypeChecker::checkClasses() {
    std::vector<AST::Class *> *classes_ = (*root_) -> getClasses();

    int num_classes = classes_ -> size();

    std::string class_name, super_name;
    AST::Class *clazz_;
    AdjMatrix::iterator it;

    for (int i = 0; i < num_classes; i++) {
        clazz_ = (*classes_)[i];
        class_name = clazz_ -> getClassName();
        super_name = clazz_ -> getSuperName();

        if (super_name == "") {
            super_name = "Obj";
        }

        if(class_name == "Obj" && super_name == "Obj") {
            continue;
        }

        it = class_heir_.find(super_name);
        if (it == class_heir_.end()) {
            std::vector<std::string> v;
            class_heir_.insert(AdjEntry(super_name, v));
        }
        class_heir_[super_name].push_back(class_name);
    }

    //Detect Cycle
    std::vector<std::string> seen;
    std::vector<std::string> super_unseen;
    std::stack<std::string> dfs_stack;
    std::string curr_node;

    for (AdjMatrix::iterator it = class_heir_.begin(); it != class_heir_.end(); it++) {
        super_unseen.push_back(it->first);
    }

    dfs_stack.push("Obj");
    while (!dfs_stack.empty()) {

        curr_node = dfs_stack.top();
        dfs_stack.pop();
        
        auto it = std::find(super_unseen.begin(), super_unseen.end(), curr_node);
        if (it != super_unseen.end()) {
            super_unseen.erase(it);
        }

        if (std::find(seen.begin(), seen.end(), curr_node) != seen.end()) {
            std::cerr << "Class heirarchy malformed: Cycle" << std::endl;
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

    if (super_unseen.size()) {
        std::cerr << "Class heirarchy malformed: All Objects Must Be Subtypes of Obj" << std::endl;
        return false;
    }
    
    //Build LCA_Table
    std::string a_name, b_name, c_name;
    for (AST::Class *a: *classes_) {
        for (AST::Class *b: *classes_) {
            a_name = a -> getClassName();
            b_name = b -> getClassName();
            c_name = getLCA(class_heir_, a_name, b_name);

            LCA[a_name][b_name] = c_name;
        }
    } 
    

    return true;
}
