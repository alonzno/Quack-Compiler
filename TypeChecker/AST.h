#ifndef AST_H
#define AST_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

#include "SymTable.h"

#define NUM_LINES_IN_DUMMY 34


//Set Intersection & Difference Helpers

template<class vec_type>
std::vector<vec_type> vecIntersection(std::vector<vec_type> &v1, std::vector<vec_type> &v2) {
    std::vector<vec_type> v3(v1.size() + v2.size());
    
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    auto it = std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    v3.resize(it - v3.begin());
    return v3;
}

template<class vec_type>
std::vector<vec_type> vecDifference(std::vector<vec_type> &v1, std::vector<vec_type> &v2) {
    std::vector<vec_type> v3(v1.size() + v2.size());
    
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    auto it = std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    v3.resize(it - v3.begin());
    return v3;
}


namespace AST {
    
    class AST_print_context {
        public:
            int indent_;
            AST_print_context() : indent_{0} {}
            void indent() { ++indent_; }
            void dedent() { --indent_; }
    };

    // ==================== Abstract Classes =====================  
    class ASTNode {
        public:
            int line_ = 0;
            int column_ = 0;
            static NameClassMap class_map;
            static int error_count;

        public:
            virtual void json(std::ostream &out, AST_print_context &ctx) = 0;
            void json_indent(std::ostream& out, AST_print_context& ctx);
            void json_head(std::string node_kind, std::ostream& out, AST_print_context& ctx);
            void json_close(std::ostream& out, AST_print_context& ctx);
            void json_child(std::string field, ASTNode& child, std::ostream& out, AST_print_context& ctx, char sep=',');
            void setLine(int l, int c) { line_ = l; column_ = c; }
            int getLine() { return line_ - NUM_LINES_IN_DUMMY; }

            //DEBUG
            static void printClassesAndMethods() {
                std::cerr << "-------------------- CLASS MAP ---------------" << std::endl;
                for(auto c: class_map) {
                    std::cerr << "---------------- Begin Class ------------------" << std::endl;
                    std::cerr << "Class Name:\t" <<  c.first << std::endl;
                    if (c.second == NULL) continue;
                    std::cerr << "---------------- Begin Methods ------------------" << std::endl;
                    for (auto m: c.second -> methods_) {
                        std::cerr << "Method name:\t" << m.first << "\t";
                        for (auto a: m.second -> args_) {
                            std::cerr << " " << a -> class_name_;
                        }
                        std::cerr << " --> " << m.second -> type_ -> class_name_ << std::endl;
                    }
                    std::cerr << "---------------- End Methods ------------------" << std::endl;
                    std::cerr << "---------------- End Class ------------------" << std::endl;
                }
            }
    };
    
    class Statement: public ASTNode {
        public:
            virtual void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { return; }
    };

    class R_Expr: public Statement {
        public:
            virtual ClassRow* getType(ClassRow *class_row, MethodRow *method_row, bool &changed) = 0;
            virtual bool isThis() { return false; }
    };

    // ==================== Concrete Classes ======================
    
    class Block: public Statement {
        private:

            std::vector<Statement *> stmts_;
        public:
            Block() {}
            Block(Statement *n) { stmts_.push_back(n); }
            void append(Statement *stmt) { stmts_.push_back(stmt); }
            size_t getNumStmts() { return stmts_.size(); }
            Statement *getStmtAt(int index) { return stmts_[index]; }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                //std::cerr << "In Block Make Sym" << std::endl;  //DEBUG
                //AST_print_context ctx;          // DEBUG
                for (auto s: stmts_) {
                    //std::cerr << "Making a sym" << std::endl;  //DEBUG
                    //s -> json(std::cerr, ctx);                  //DEBUG
                    s -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);
                }
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Ident: public ASTNode {
        private:

            std::string text_;
        public:
            Ident(std::string name): text_(name) {}
            std::string getText()  { return text_; }
            void setText(std::string text) { text_ = text; }
            void json(std::ostream &out, AST_print_context &ctx);
    };


    class Arg: public ASTNode {
        private:
            
            Ident *param_name_;
            Ident *param_type_;
        public:
            Arg(Ident *name, Ident *type): param_name_(name), param_type_(type) {}
            std::string getName() { return param_name_ -> getText(); }
            std::string getType() { return param_type_ -> getText(); }
            void json(std::ostream &out, AST_print_context &ctx);

    };

    class FormalArgs: public ASTNode {
        private:

            std::vector<ASTNode *> *args_;
        public:
            FormalArgs() { args_ = new std::vector<ASTNode *>(); }
            void append(Arg *arg) { args_ -> push_back(arg); }
            std::vector<std::pair<std::string, std::string>> getArgs() {
                std::vector<std::pair<std::string, std::string>> retVal;
                Arg *arg_;
                int num_args = args_ -> size();

                for (int i = 0; i < num_args; i++) {
                    arg_ = (Arg *) (*args_)[i];
                    retVal.push_back(std::pair<std::string, std::string>(arg_ -> getName(), arg_ -> getType()));
                }

                return retVal;
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class ActualArgs: public ASTNode {
        private:

            std::vector<ASTNode *> args_;
        public:
            void append(R_Expr *arg) { args_.push_back(arg); }
            std::vector<R_Expr *> getArgs() {
                std::vector<R_Expr *> retVal;
                R_Expr *arg_;
                int num_args = args_.size();

                for (int i = 0; i < num_args; i++) {
                    arg_ = (R_Expr *) args_[i];
                    retVal.push_back(arg_);
                }

                return retVal;
            }
            std::vector<std::string> getTypes() {
                std::vector<std::string> types;
                //DO something
                return types;
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    

    class While: public Statement {
        private:
            
            R_Expr *cond_;
            Block *body_;
        public:
            While(R_Expr *cond, Block *body): cond_(cond), body_(body) {}
            R_Expr *getCond() { return cond_; }
            Block *getBody() { return body_; }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                InitTable localInit_cp = localInit;
                InitTable fieldInit_cp = localInit;
                body_ -> makeSym(localInit_cp, fieldInit_cp, localSym, fieldSym, inConstructor, inProgStmts);
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class L_Expr: public R_Expr {
        private:

            R_Expr *r_expr_ = NULL;
            Ident *name_;
        public:
            L_Expr(Ident *name): name_(name) {}
            L_Expr(R_Expr *r_expr, Ident *name): r_expr_(r_expr), name_(name) {}
            std::string getName() { return name_ -> getText(); }
            R_Expr *getR_Expr() { return r_expr_; }
            ClassRow *getType(ClassRow *class_row, MethodRow *method_row, bool &changed) { 
                /*
                if (r_expr_ == NULL) {
                    if (map -> find(name_ -> getText()) != map -> end()) {
                        return (*map)[name_ -> getText()];
                    }
                    std::cerr << "L_Expr not found" << std::endl;
                }
                ClassRow *row = r_expr_ -> getType(map);
                if (row -> fields_.find(name_ -> getText()) != row -> fields_.end()) {
                    return row -> fields_[name_ -> getText()];
                }
                std::cerr << "l_ExpR NOt FoUnd" << std::endl;
                */
                return NULL;
            }

            bool isThis() { return r_expr_ == NULL && name_ -> getText() == "this"; }
            bool isField() { return r_expr_ != NULL; }
            bool canAssign() { 
                if (r_expr_ == NULL && name_ -> getText() == "true") {
                    std::cerr << "Attempting to assign builtin \"true\" on line " << getLine() << std::endl;
                    std::cerr << "Aborting..." << std::endl;
                    exit(2);
                }
                else if (r_expr_ == NULL && name_ -> getText() == "false") {
                    std::cerr << "Attempting to assign builtin \"false\" on line " << getLine() << std::endl;
                    std::cerr << "Aborting..." << std::endl;
                    exit(2);
                }
                else if (r_expr_ == NULL && name_ -> getText() == "none") {
                    std::cerr << "Attempting to assign builtin \"none\" on line " << getLine() << std::endl;
                    std::cerr << "Aborting..." << std::endl;
                    exit(2);
                }
                else if (r_expr_ == NULL && name_ -> getText() == "this") {
                    std::cerr << "Atempting to assign \"this\" on line " << getLine() << std::endl;
                    std::cerr << "Aborting..." << std::endl;
                    exit(2);
                }

                return r_expr_ == NULL || r_expr_ -> isThis(); }

            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                if (r_expr_ == NULL) {
                    if (localSym.find(getName()) == localSym.end()) {
                        std::cerr << "Reference to undeclared local variable \"" << getName()
                            << "\" on line " << getLine() << std::endl;
                        error_count++;
                        //std::cerr << "Aborting..." << std::endl;
                        //exit(2);
                        return;
                    }
                    return;
                }
                else if (r_expr_ -> isThis()) {
                    if (fieldSym.find(getName()) == fieldSym.end()) {
                        std::cerr << "Reference to undeclared field \"this." << getName()
                            << "\" on line " << getLine() << std::endl;
                        error_count++;
                        //std::cerr << "Aborting..." << std::endl;
                        //exit(2);
                    }
                }
                else {
                    r_expr_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts); 
                }

            }

            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class Assign: public Statement {
        private:
            
            L_Expr *l_expr_;
            Ident *type_;
            R_Expr *r_expr_;
        public:
            Assign(L_Expr *l_expr, Ident *type, R_Expr *r_expr): l_expr_(l_expr), type_(type), r_expr_(r_expr) {}
            L_Expr *getL_Expr() { return l_expr_; }
            R_Expr *getR_Expr() { return r_expr_; }
            std::string getType() { return type_ -> getText(); }
            void updateSymTab(NameClassMap *map) { 
                /*
                if (l_expr_ -> canAssign()) {
                    R_Expr *r = l_expr_ -> getR_Expr();
                    if (r) {
                        NameClassMap new_map = r -> getType(map) -> fields_;
                        new_map[l_expr_ -> getName()] = r_expr_ -> getType(map);
                    }
                }
                error_count++;
                std::cerr << "Error: cannot assign fields outside of a constructor/methods" << std::endl;
                */
            }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                
                r_expr_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);
                
                //Begin L_Expr
                //std::cerr << "In Assign make Sym" << std::endl; //DEBUG
                if (l_expr_ -> isField()) {
                    //std::cerr << "In is field" << std::endl; //DEBUG
                    if (l_expr_ -> canAssign()) {
                        //std::cerr << "In is Can Assign" << std::endl; //DEBUG
                        if (inConstructor) {
                            //std::cerr << "In is Constructor" << std::endl; //DEBUG
                            //std::cerr << type_ << " " << l_expr_ << " " << r_expr_ << std::endl; // DEBUG
                            if (type_ -> getText() != "") {
                                if (std::find(fieldInit.begin(), fieldInit.end(), l_expr_ -> getName()) == fieldInit.end()) {
                                    fieldInit.push_back(l_expr_ -> getName());
                                    if (class_map.find(type_ -> getText()) == class_map.end()) {
                                        std::cerr << "Undeclared Type \"" << type_ -> getText() << " on line "
                                            << getLine() << std::endl;
                                        //std::cerr << "Aborting..." << std::endl;
                                        //exit(2);
                                        error_count++;
                                    }
                                    ClassRow *clazz = class_map[type_ -> getText()];
                                    fieldSym[l_expr_ -> getName()] = std::pair<bool, ClassRow *>(true, clazz);
                                    //std::cerr << "Adding typed symbol " << l_expr_ -> getName() << std::endl;  //DEBUG
                                } 
                                else {
                                    if (fieldSym[l_expr_ -> getName()].second == class_map[type_ -> getText()]) {
                                        //Same Type, no prob    
                                    }
                                    else {
                                        std::cerr << "Explicitly declared field \"this." << l_expr_ -> getName()
                                            << "\" on line " << getLine() << " previously declared type \""
                                            << fieldSym[l_expr_ -> getName()].second -> class_name_ << "\"" << std::endl;
                                        //std::cerr << "Aborting..." << std::endl;
                                        //error_count++;
                                        exit(2);
                                    }
                                }
                            }
                            //Not Typed
                            else {
                                //std::cerr << "In not typed" << std::endl;  //DEBUG
                                //std::cerr << l_expr_ -> getName() << std::endl;  //DEBUG
                                if (std::find(fieldInit.begin(), fieldInit.end(), l_expr_ -> getName()) == fieldInit.end()) {
                                    //std::cerr << "Adding symbol " << l_expr_ -> getName() << std::endl;  //DEBUG
                                    fieldInit.push_back(l_expr_ -> getName());
                                    fieldSym[l_expr_ -> getName()] = std::pair<bool, ClassRow *>(false, NULL);
                                //std::cerr << "leaving not typed" << std::endl; // DEBUG
                                }
                                else {
                                //std::cerr << "leaving not typed" << std::endl; // DEBUG
                                    //Don't even trip, Dawg
                                }
                            }
                        }
                        //Not in Constructor
                        else {
                            if (std::find(fieldInit.begin(), fieldInit.end(), l_expr_ -> getName()) != fieldInit.end()) {
                                //No-op
                            }
                            else {
                                std::cerr << "Reference to undeclared field \"this." << l_expr_ -> getName()
                                    << "\" on line " << getLine() << std::endl;
                                //std::cerr << "Aborting..." << std::endl;
                                //exit(2);
                                error_count++;
                            }
                        }
                    }
                    //Not assignable
                    else {
                        std::cerr << "Attempting to assign unassignable field named \"" << l_expr_ -> getName()
                            << "\" on line " << getLine() << std::endl;
                        //std::cerr << "Aborting..." << std::endl;
                        //exit(2);
                        error_count++;
                    }
                }
                //Not a field
                else {
                    if (l_expr_ -> canAssign()) {
                        if (std::find(localInit.begin(), localInit.end(), l_expr_ -> getName()) == localInit.end()) {
                            localInit.push_back(l_expr_ -> getName());    
                            if (type_ -> getText() == "") {
                                localSym[l_expr_ -> getName()] = std::pair<bool, ClassRow *>(false, NULL);
                            }
                            else {
                                if (class_map.find(type_ -> getText()) == class_map.end()) {
                                    std::cerr << "Undeclared Type \"" << type_ -> getText() << " on line "
                                        << getLine() << std::endl;
                                    //std::cerr << "Aborting..." << std::endl;
                                    //exit(2);
                                    error_count++;
                                }
                                else {
                                    localSym[l_expr_ -> getName()] = std::pair<bool, ClassRow *>(true, class_map[type_ -> getText()]);
                                }
                            }   
                        }
                        else {
                            if (type_ -> getText() == "") {
                                //No Op
                            }
                            else {
                                if (class_map.find(type_ -> getText()) == class_map.end()) {
                                    std::cerr << "Undeclared Type \"" << type_ -> getText() << " on line "
                                        << getLine() << std::endl;
                                    //std::cerr << "Aborting..." << std::endl;
                                    //exit(2);
                                    error_count++;
                                }
                                else {
                                    if (localSym[l_expr_ -> getName()].second == class_map[type_ -> getText()]) {
                                        //No op
                                    }
                                    else {
                                        std::cerr << "Explicitly declared variable \"" << l_expr_ -> getName()
                                            << "\" on line " << getLine() << " previously declared type \""
                                            << fieldSym[l_expr_ -> getName()].second -> class_name_ << "\"" << std::endl;
                                        //std::cerr << "Aborting..." << std::endl;
                                        //exit(2);
                                        error_count++;
                                    }
                                }
                            }
                        }   
                    }
                    else {
                        error_count++;
                        std::cerr << "Unassignable variable" << std::endl;
                    }
                }
                

            }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class Method: public ASTNode {
        private:
            
            Ident *name_;
            Ident *return_type_;
            FormalArgs *args_;
            Block *stmts_;
            MethodRow *method_row_;
        public:
            Method(Ident *name, Ident *return_type, FormalArgs *args, Block *stmts): 
                name_(name), return_type_(return_type), args_(args), stmts_(stmts) {
                    if (return_type_ -> getText() == "") {
                        return_type_ -> setText("Nothing");
                    }
                    method_row_ = new MethodRow();
                }
            std::string getName() { return name_ -> getText(); }
            std::string getType() { return return_type_ -> getText(); }
            std::vector<std::pair<std::string, std::string>> getArgs() { return args_ -> getArgs(); }
            Block *getStmts() { return stmts_; }
            MethodRow *getMethodRow() { return method_row_; }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class Class: public ASTNode {
        private:
            
            Ident *class_name_;
            Ident *super_name_;
            FormalArgs *args_;
            Block *stmts_;
            std::vector<Method *> *methods_;
            ClassRow *class_row_;
        public:
            Class(Ident *name, Ident *super): class_name_(name), super_name_(super) {}
            Class(Ident *name, Ident *super, FormalArgs *args, Block *stmts, std::vector<Method *> *methods):
                class_name_(name), super_name_(super), args_(args), stmts_(stmts), methods_(methods) {
                    if (super_name_ -> getText() == "") {
                        super_name_ -> setText("Obj");
                    }
                    class_row_ = new ClassRow(name -> getText());
                }
            std::string getClassName() { return class_name_ -> getText(); }
            std::string getSuperName() { return super_name_ -> getText(); }
            std::vector<Method *> *getMethods() { return methods_; }
            Block *getStmts() { return stmts_; }
            std::vector<std::pair<std::string, std::string>> getArgs() { return args_ -> getArgs(); }

            ClassRow *getClassRow() {
                return class_row_;
            }

            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class Program: public ASTNode {
        private:

            std::vector<Class *> *classes_;
            Block *stmts_;

            MethodRow *main_;
        public:
            Program(std::vector<Class *> *classes, Block *stmts): classes_(classes), stmts_(stmts){}
            std::vector<Class *> *getClasses() { return classes_; }
            Block *getStmts() { return stmts_; }
            void json(std::ostream &out, AST_print_context &ctx);
            void updateClasses() {
                std::string class_name;
                NameClassMap::iterator it;
                for (Class *c: *classes_) {
                    class_name = c -> getClassName();
                    it = class_map.find(class_name);
                    if (it == class_map.end()) {
                        class_map.insert(ClassEntry(class_name, c -> getClassRow()));
                    }
                    else {
                        std::cerr << "Redefinition of class " << class_name << " on line " 
                            << c -> getLine() << std::endl;
                        std::cerr << "Ignoring..." << std::endl;
                        error_count++;

                        auto my_it = std::find(classes_ -> begin(), classes_ -> end(), c);
                        if (my_it != classes_ -> end()) {
                            classes_ -> erase(my_it);
                        }
                        error_count++;
                    }
                }
                ClassRow *row;
                for (Class *c: *classes_) {
                    class_name = c -> getClassName();
                    row = c -> getClassRow();
                    if (class_map.find(c -> getSuperName()) == class_map.end()) {
                        std::cerr << "Undeclared Type: " << c -> getSuperName() 
                            << " on line " << c -> getLine() << std::endl;
                        //std::cerr << "Aborting..." << std::endl;
                        //exit(2);
                        error_count++;
                    }
                    row -> super_class_ = class_map[c -> getSuperName()];
                    row -> sym_["true"] = std::pair<bool, ClassRow *>(true, class_map["Boolean"]);
                    row -> sym_["false"] = std::pair<bool, ClassRow *>(true, class_map["Boolean"]);
                    row -> sym_["none"] = std::pair<bool, ClassRow *>(true, class_map["Nothing"]);
                    if (class_name == "Obj") {
                        row -> super_class_ = NULL;
                    }
                    for (Method *m: *(c -> getMethods())) {
                        if ( row -> methods_.find(m -> getName()) != row -> methods_.end()) {
                            std::cerr << "Redefinition of method: " << m -> getName() 
                                << " on line " << m -> getLine() << std::endl;
                            //std::cerr << "Aborting..." << std::endl;
                            //exit(2);
                            error_count++;
                        }
                        row -> methods_[m -> getName()] = m -> getMethodRow();
                        m -> getMethodRow() -> class_ = row;
                        m -> getMethodRow() -> method_name_ = m -> getName();

                        if (class_map.find(m -> getType()) == class_map.end()) {
                            std::cerr << "Undeclared Type: " << m -> getType() 
                                << " on line " << m -> getLine() << std::endl;
                            //std::cerr << "Aborting..." << std::endl;
                            //exit(2);
                            error_count++;
                        }
                        m -> getMethodRow() -> type_ = class_map[m -> getType()];
                        
                        m -> getMethodRow() -> sym_["true"] = std::pair<bool, ClassRow *>(true, class_map["Boolean"]);
                        m -> getMethodRow() -> sym_["false"] = std::pair<bool, ClassRow *>(true, class_map["Boolean"]);
                        m -> getMethodRow() -> sym_["none"] = std::pair<bool, ClassRow *>(true, class_map["Nothing"]);
                        for (std::pair<std::string, std::string> a: m -> getArgs()) {
                            if (class_map.find(a.second) == class_map.end()) {
                                std::cerr << "Undeclared Type: " << a.second
                                    << " on line " << m -> getLine() << std::endl;
                                //std::cerr << "Aborting..." << std::endl;
                                //exit(2);
                                error_count++;
                            }
                            m -> getMethodRow() -> args_.push_back(class_map[a.second]);
                            m -> getMethodRow() -> sym_[a.first] = std::pair<bool, ClassRow*>(true, class_map[a.second]);
                        }
                    }
                    row -> constructor_ = new MethodRow();
                    row -> constructor_ -> method_name_ = class_name;
                    row -> constructor_ -> class_ = row;
                    row -> constructor_ -> type_ = row;


                    row -> constructor_ -> sym_["true"] = std::pair<bool, ClassRow *>(true, class_map["Boolean"]);
                    row -> constructor_ -> sym_["false"] = std::pair<bool, ClassRow *>(true, class_map["Boolean"]);
                    row -> constructor_ -> sym_["none"] = std::pair<bool, ClassRow *>(true, class_map["Nothing"]);

                    for (std::pair<std::string, std::string> a: c -> getArgs()) {
                        if (class_map.find(a.second) == class_map.end()) {
                            std::cerr << "Undeclared Type: " << a.second 
                                << " on line " << c -> getLine() << std::endl;
                            //std::cerr << "Aborting..." << std::endl;
                            //exit(2);
                            error_count++;
                        }
                        row -> constructor_ -> args_.push_back(class_map[a.second]);
                        row -> constructor_ -> sym_[a.first] = std::pair<bool, ClassRow *>(false, class_map[a.second]);
                    }
                }
            }
    };

    class If_Else: public Statement {
        private:
            
            R_Expr *cond_;
            Block *if_stmts_;
            Block *else_stmts_;
        public:
            If_Else(R_Expr *cond, Block *if_stmts, Block *else_stmts): 
                cond_(cond), if_stmts_(if_stmts), else_stmts_(else_stmts) {}
            void setElseBlock(Block *else_stmts) { else_stmts_ = else_stmts; }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) {
                if (else_stmts_ != NULL) {
                    InitTable localInit_cp_1 = localInit;
                    InitTable localInit_cp_2 = localInit;

                    InitTable fieldInit_cp_1 = fieldInit;
                    InitTable fieldInit_cp_2 = fieldInit;
                
                    if_stmts_ -> makeSym(localInit_cp_1, fieldInit_cp_1, localSym, fieldSym, inConstructor, inProgStmts);
                    else_stmts_ -> makeSym(localInit_cp_2, fieldInit_cp_2, localSym, fieldSym, inConstructor, inProgStmts);
                    //std::cerr << "Getting intersections" << std::endl;
                    InitTable localInit_inter = vecIntersection(localInit_cp_1, localInit_cp_2);
                    InitTable fieldInit_inter = vecIntersection(fieldInit_cp_1, fieldInit_cp_2);
                    //std::cerr << "Got intersections" << std::endl;

                    for (auto s: localInit_inter) {
                        //std::cerr << s << std::endl;
                        if (std::find(localInit.begin(), localInit.end(), s) == localInit.end()) {
                            localInit.push_back(s);
                        }
                    }
                    for (auto s: fieldInit_inter) {
                        //std::cerr << s << std::endl;
                        if (std::find(fieldInit.begin(), fieldInit.end(), s) == fieldInit.end()) {
                            fieldInit.push_back(s);
                        }
                    }
                }
                else {
                    if_stmts_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);
                }
            }

            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    
    class IntConst: public R_Expr {
        private:
            
            int value_;
            std::string type_ = "Int";
        public:
            IntConst(int value): value_(value) {}
            int getValue() { return value_; }
            ClassRow *getType(ClassRow *class_row, MethodRow *method_row, bool &changed) { return class_map["Int"]; }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class StrConst: public R_Expr {
        private:
            
            std::string value_;
            std::string type_ = "String";
        public:
            StrConst(std::string value): value_(value) {}
            std::string getValue() { return value_; }
            ClassRow *getType(ClassRow *class_row, MethodRow *method_row, bool &changed) { return class_map["String"]; }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Call: public R_Expr {
        private:
            
            R_Expr *obj_;
            Ident *method_;
            ActualArgs *args_;
        public:
            R_Expr *getObj() { return obj_; }
            std::vector<R_Expr *> getArgs() { return args_ -> getArgs(); }
            std::string getMethodName() { return method_ -> getText(); }
            ClassRow *getType(ClassRow *class_row, MethodRow *method_row, bool &changed) { 
                /*
                ClassRow *type = obj_ -> getType(map);
                if (type == NULL) return NULL;
                MethodRow *method = type -> methods_[method_ -> getText()];
                return method -> type_;
                */
                return NULL;
            }
            Call(R_Expr *obj, Ident *method, ActualArgs *args): obj_(obj), method_(method), args_(args) {}
            //CHECK ACTUAL ARGS
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 

                //std::cerr << "In a method call make sym" << std::endl;
                for (auto r_exp: getArgs()) {
                    r_exp -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);
                }
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Constructor: public R_Expr {
        private:
            
            Ident *type_;
            ActualArgs *args_;
        public:
            Constructor(Ident *type, ActualArgs *args): type_(type), args_(args) {}
            std::vector<R_Expr *> getArgs() { return args_ -> getArgs(); }
            ClassRow *getType(ClassRow *class_row, MethodRow *method_row, bool &changed) {
                //return class_map[type_ -> getText()];
                return NULL;
            }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                if (class_map.find(type_ -> getText()) == class_map.end()) {
                    std::cerr << "Attempting to construct object of unrecognized class \"" 
                        << type_ -> getText() << "\" on line " << getLine() << std::endl;
                    //std::cerr << "Aborting..." << std::endl;
                    //exit(2);
                    error_count++;
                } 
                for (auto r_expr: getArgs()){
                    r_expr -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);
                }
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };


    class Return: public Statement {
        private:
            
            R_Expr *ret_val_;
        public:
            Return(R_Expr *ret_val): ret_val_(ret_val) {
                if (ret_val == NULL) {
                    ret_val_ = new L_Expr(new Ident("none"));
                }
            }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                if (ret_val_ != NULL) {
                    //std::cerr << "In Return" << std::endl; //DEBUG
                    ret_val_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);
                }
                else {
                    std::cerr << "NULL Return Expression" << std::endl;
                    std::cerr << "Aborting..." << std::endl;
                    exit(2);
                }
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class And: public R_Expr {
        private:
            
            R_Expr *l_child_;
            R_Expr *r_child_;
        public:
            And(R_Expr *l_child, R_Expr *r_child): l_child_(l_child), r_child_(r_child) {}
            R_Expr *getL_Child() { return l_child_; }
            R_Expr *getR_Child() { return r_child_; }
            ClassRow *getType(ClassRow *class_row, MethodRow *method_row, bool &changed) { 
                /*
                if ( l_child_ -> getType(map) -> class_name_ == "Boolean" &&
                     r_child_ -> getType(map) -> class_name_ == "Boolean") {
                    return class_map["Boolean"];
                }
                error_count++;
                std::cerr << "AND operator on line " << getLine() << " is not being given Boolean operands" << std::endl;
                return class_map["Boolean"];
                */
                return NULL;
            }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                if (l_child_ == NULL || r_child_ == NULL) {
                    std::cerr << "NULL left or right child in AND expression on line " << getLine() << std::endl;
                    exit(2);
                }
                
                l_child_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);
                r_child_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts); }

            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class Or: public R_Expr {
        private:
            
            R_Expr *l_child_;
            R_Expr *r_child_;
        public:
            Or(R_Expr *l_child, R_Expr *r_child): l_child_(l_child), r_child_(r_child) {}
            R_Expr *getL_Child() { return l_child_; }
            R_Expr *getR_Child() { return r_child_; }
            ClassRow *getType(ClassRow *class_row, MethodRow *method_row, bool &changed) { 
                /*
                if ( l_child_ -> getType(map) -> class_name_ == "Boolean" &&
                     r_child_ -> getType(map) -> class_name_ == "Boolean") {
                    return class_map["Boolean"];
                }
                error_count++;
                std::cerr << "OR operator on line " << getLine() << " is not being given Boolean operands" << std::endl;
                return class_map["Boolean"];*/
                return NULL;
            }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                if (l_child_ == NULL || r_child_ == NULL) {
                    std::cerr << "NULL left or right child in OR expression on line " << getLine() << std::endl;
                    std::cerr << "Aborting..." << std::endl;
                    exit(2);
                }
                
                l_child_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);
                r_child_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts); }

            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Neg: public R_Expr {
        private:
            
            R_Expr *operand_;
        public:
            Neg(R_Expr *operand): operand_(operand) {}
            R_Expr *getOperand() { return operand_; }
            ClassRow *getType(ClassRow *class_row, MethodRow *method_row, bool &changed) { 
                /*
                if (operand_ -> getType(map) -> class_name_ == "Boolean") {
                    return class_map["Boolean"];
                }
                error_count++;
                std::cerr << "Negation on line " << getLine() << " is not being given a Boolean operand" << std::endl;
                return class_map["Boolean"];
                */
                return NULL;
            }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) {
                if (operand_) {
                    std::cerr << "NULL operand in NEG expression on line " << getLine() << std::endl;
                    std::cerr << "Aborting..." << std::endl;
                    exit(2);
                }
                
                operand_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts); }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class TypeAlt: public ASTNode {
        private:
            
            Arg *arg_;
            Block *stmts_;
        public:
            std::pair<std::string, std::string> getArg() 
                { return std::pair<std::string, std::string>(arg_ -> getName(), arg_ -> getType()); }
            TypeAlt(Arg *arg, Block *stmts): arg_(arg), stmts_(stmts) {}
            //Arg *getArg() { return arg_; }
            Block *getStmts() { return stmts_; }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Typecase: public Statement {
        private:
            
            R_Expr *r_expr_;
            std::vector<TypeAlt *> *type_alts_;
        public:
            Typecase(R_Expr *r_expr, std::vector<TypeAlt *> *type_alts): 
                r_expr_(r_expr), type_alts_(type_alts) {}
            R_Expr *getR_Expr() { return r_expr_; }
            std::vector<TypeAlt *> *getTypeAlts() { return type_alts_; }
            void makeSym(InitTable &localInit, 
                         InitTable &fieldInit,
                         SymbolTable &localSym,
                         SymbolTable &fieldSym,
                         bool inConstructor = false,
                         bool inProgStmts = false) { 
                r_expr_ -> makeSym(localInit, fieldInit, localSym, fieldSym, inConstructor, inProgStmts);

                for (auto type_alt: *(type_alts_)) {
                    //Here check if arg_ is of valid type. TODO
                    //
                    //
                    //Then check if the l_exprs_ in stmts_ are properly initialized.
                    
                    if (class_map.find(type_alt -> getArg().second) == class_map.end()) {
                        std::cerr << "Undeclared type \"" << type_alt -> getArg().second << "\" in typecase on line "
                            << getLine() << std::endl;
                        error_count++;

                        //REMOVE THIS
                        std::cerr << "Aborting..." << std::endl;
                        exit(2);
                    }

                    InitTable localInit_cp = localInit;
                    InitTable fieldInit_cp = fieldInit;



                    return;
                }
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    
}

#endif //AST_H
