#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>

#include "typecheck.h"

bool TypeChecker::inheritVariables() {
    std::deque<std::string> queue;
    std::string class_name;
    ClassRow *current_class;
    ClassRow *child_class;

    SymbolTable current_sym;
    SymbolTable child_sym;

    queue.push_back("Obj");
    while (!queue.empty()) {
        class_name = queue.front();
        queue.pop_front();
        
        current_class = AST::ASTNode::class_map[class_name];
        current_sym = current_class -> fields_;
        if (class_heir_.find(class_name) != class_heir_.end()) {
            for (auto child_name: class_heir_[class_name]) {
                queue.push_back(child_name);
                child_class = AST::ASTNode::class_map[child_name];
                child_sym = child_class -> fields_;
                for (auto pair: current_sym) {
                    if (child_sym.find(pair.first) == child_sym.end()) {
                        std::cerr << "Class \"" << child_name << "\" does not define field \"" << pair.first
                            << "\" of super class \"" << class_name << std::endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool TypeChecker::checkInit() {
    for (auto clazz: *((*root_) -> getClasses())) {
        if (std::find(builtins_.begin(), builtins_.end(), clazz -> getClassName()) != builtins_.end()) {
            continue;
        }
        //std::cerr << "Checking Class: " << clazz -> getClassName() << std::endl; //DEBUG
        InitTable localInit_cons;
        InitTable fieldInit_cons;
        ClassRow *row = clazz -> getClassRow();

        localInit_cons.push_back("true");
        localInit_cons.push_back("false");
        localInit_cons.push_back("none");

        for (auto a: clazz -> getArgs()) {
            localInit_cons.push_back(a.first);
            //std::cerr << "ARG: " << a.first << " " << a.second << std::endl;    //DEBUG
            row -> sym_[a.first] = std::pair<bool, ClassRow*>(true, AST::ASTNode::class_map[a.second]);
        } 


        clazz -> getStmts() -> makeSym(localInit_cons,
                                       fieldInit_cons,
                                       clazz -> getClassRow() -> sym_,
                                       clazz -> getClassRow() -> fields_,
                                       true,
                                       false);
        
        //Begin Debugging
        /*
        std::cerr << "======================== Locals ==================" << std::endl;
        for (auto s: localInit_cons) {
            std::cerr << s << std::endl;
            std::cerr << (row -> sym_.find(s) != row -> sym_.end()) << std::endl;
        }
        std::cerr << "======================== Fields ==================" << std::endl;
        for (auto s: fieldInit_cons) {
            std::cerr << s << std::endl;
            std::cerr << (row -> fields_.find(s) != row -> fields_.end()) << std::endl;
        }
        */
        //End Debugging
        for (auto p: row -> fields_) {
            if (std::find(fieldInit_cons.begin(), fieldInit_cons.end(), p.first) == fieldInit_cons.end()) {
                std::cerr << "In class \"" << clazz -> getClassName() << "\", field \"this." << p.first
                    << "\" is not initialized on all code paths." << std::endl;
                AST::ASTNode::error_count++;
            }
        }

        
        for (auto method: *(clazz -> getMethods())) {
            InitTable localInit_meth;
            InitTable fieldInit_meth;
            
            MethodRow *m_row = row -> methods_[method -> getName()];
            //std::cerr << "Checking method: " << method -> getName() << std::endl; //DEBUG

            for (auto a: method -> getArgs()) {
                //std::cerr <<"Got args" << std::endl; //DEBUG
                localInit_meth.push_back(a.first);
                m_row -> sym_[a.first] = std::pair<bool, ClassRow*>(true, AST::ASTNode::class_map[a.second]);
                //std::cerr << "Added arg" << std::endl; //DEBUG
            }
                //std::cerr << "Getting Statement" << std::endl; //DEBUG
            method -> getStmts() -> makeSym(localInit_meth,
                                            fieldInit_cons,
                                            m_row -> sym_,
                                            row -> sym_,
                                            false,
                                            false);
        //Begin Debugging
        /*
        std::cerr << "======================== Locals ==================" << std::endl;
        for (auto s: localInit_meth){
            std::cerr << s << std::endl;
            std::cerr << (m_row -> sym_.find(s) != m_row -> sym_.end()) << std::endl;
        }
        std::cerr << "======================== Fields ==================" << std::endl;
        for (auto s: fieldInit_meth) {
            std::cerr << s << std::endl;
            std::cerr << (m_row -> class_ -> fields_.find(s) != m_row -> class_ -> fields_.end()) << std::endl;
        }
        */
        //End Debugging
            
        }
    }
    return true;
}

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
