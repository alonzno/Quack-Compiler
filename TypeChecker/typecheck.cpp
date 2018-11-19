#include <stack>
#include <iostream>
#include <algorithm>

#include "typecheck.h"

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

    /*//DEBUG
    for (auto p: class_heir_) {
        std::cerr << p.first << " ";
        for (auto v: p.second) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
    }
    */

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

    return true;
}
