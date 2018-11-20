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

bool TypeChecker::inheritMethods() {
    std::deque<std::string> queue;
    std::string class_name;
    ClassRow *current_class, *child_class;
    MethodRow *old_method, *new_method;
    
    queue.push_back("Obj");
    while (!queue.empty()) {
        class_name = queue.front();
        current_class = AST::ASTNode::class_map[class_name];
        if (class_heir_.find(class_name) != class_heir_.end()) {
            for (auto child_name: class_heir_[class_name]) {
                queue.push_back(child_name);
                child_class = AST::ASTNode::class_map[child_name];
                for (auto m: current_class -> methods_) {
                    if (child_class -> methods_.find(m.first) == child_class -> methods_.end()) {
                        child_class -> methods_[m.first] = m.second;
                    }
                    else {
                        old_method = m.second;
                        new_method = child_class -> methods_[m.first];
                        if (old_method -> args_.size() != new_method -> args_.size()) {
                            std::cerr << "Redefined method " << m.first << " in class "
                                << child_name << " does not have same number of args " 
                                << "as defined in super." << std::endl;
                            return false;
                        }
                        int num_args = old_method -> args_.size();
                        for (int i = 0; i < num_args; i++) {
                            std::string sub_arg = old_method -> args_[i] -> class_name_;
                            std::string super_arg = new_method -> args_[i] -> class_name_;
                            if(LCA[sub_arg][super_arg] != super_arg) {
                                std::cerr << "In Class " << child_name << ", inherited method \""
                                    << m.first << "\", arg #" << (i+1) << ", the type is "
                                    << super_arg << " which is not a supertype of "
                                    << sub_arg << std::endl;
                                return false;
                            }
                        }
                        
                        std::string super_return = old_method -> type_ -> class_name_;
                        std::string sub_return = new_method -> type_ -> class_name_;
                        if (LCA[super_return][sub_return] != super_return) {
                            std::cerr << "In Class " << child_name << ", inherited method \""
                                << m.first << "\" return type is "
                                << sub_return << " which is not a subtype of "
                                << super_return << std::endl;
                            return false;
                        }
                    }
                }
            }
        }
        queue.pop_front();
    }

    return true;
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
            //DEBUG std::cerr << a_name << "\t" << b_name << "\t" << c_name << std::endl;
        }
    } 
    

    return true;
}
