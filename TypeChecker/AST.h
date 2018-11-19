#ifndef AST_H
#define AST_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "SymTable.h"

#define NUM_LINES_IN_DUMMY 35

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
    };
    
    class Statement: public ASTNode {
        public:
    };

    class R_Expr: public Statement {
        public:
            virtual ClassRow* getType(NameClassMap *map) = 0;
            bool isThis() { return false; }
    };

    // ==================== Concrete Classes ======================
    
    class Block: public ASTNode {
        private:

            std::vector<Statement *> stmts_;
        public:
            Block() {}
            Block(Statement *n) { stmts_.push_back(n); }
            void append(Statement *stmt) { stmts_.push_back(stmt); }
            size_t getNumStmts() { return stmts_.size(); }
            ASTNode *getStmtAt(int index) { return stmts_[index]; }
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
            ClassRow *getType(NameClassMap *map) { 
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
                return NULL;
            }

            bool isThis() { return r_expr_ == NULL && name_ -> getText() == "this"; }
            bool canAssign() { return r_expr_ == NULL || r_expr_ -> isThis(); }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class Assign: public Statement {
        private:
            
            L_Expr *l_expr_;
            Ident *type_;
            R_Expr *r_expr_;
        public:
            L_Expr *getL_Expr() { return l_expr_; }
            R_Expr *getR_Expr() { return r_expr_; }
            std::string getType() { return type_ -> getText(); }
            Assign(L_Expr *l_expr, Ident *type, R_Expr *r_expr): l_expr_(l_expr), type_(type), r_expr_(r_expr) {}
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
                    method_row_ = new MethodRow();
                }
            std::string getName() { return name_ -> getText(); }
            std::string getType() { return return_type_ -> getText(); }
            std::vector<std::pair<std::string, std::string>> getArgs() { return args_ -> getArgs(); }
            std::vector<Statement *> getStmts() {
                std::vector<Statement *> retVal;
                Statement *stmt;
                int num_stmts = stmts_ -> getNumStmts();
                for (int i = 0; i < num_stmts; i++) {
                    stmt = (Statement *)(stmts_ -> getStmtAt(i));
                    retVal.push_back(stmt);
                }
                return retVal;
            }
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
                    row -> super_class_ = class_map[c -> getSuperName()];
                    row -> sym_["true"] = AST::ASTNode::class_map["Boolean"];
                    row -> sym_["false"] = AST::ASTNode::class_map["Boolean"];
                    row -> sym_["none"] = AST::ASTNode::class_map["Nothing"];
                    if (class_name == "Obj") {
                        row -> super_class_ = NULL;
                    }
                    for (Method *m: *(c -> getMethods())) {
                        row -> methods_[m -> getName()] = m -> getMethodRow();
                        m -> getMethodRow() -> class_ = row;
                        m -> getMethodRow() -> method_name_ = m -> getName();
                        m -> getMethodRow() -> type_ = class_map[m -> getType()];
                        
                        m -> getMethodRow() -> sym_["true"] = AST::ASTNode::class_map["Boolean"];
                        m -> getMethodRow() -> sym_["false"] = AST::ASTNode::class_map["Boolean"];
                        m -> getMethodRow() -> sym_["none"] = AST::ASTNode::class_map["Nothing"];
                        for (std::pair<std::string, std::string> a: m -> getArgs()) {
                            m -> getMethodRow() -> args_.push_back(class_map[a.second]);
                            m -> getMethodRow() -> sym_[a.first] = class_map[a.second];
                        }
                    }
                    row -> constructor_ = new MethodRow();
                    row -> constructor_ -> method_name_ = class_name;
                    row -> constructor_ -> class_ = row;
                    row -> constructor_ -> type_ = row;


                    row -> constructor_ -> sym_["true"] = AST::ASTNode::class_map["Boolean"];
                    row -> constructor_ -> sym_["false"] = AST::ASTNode::class_map["Boolean"];
                    row -> constructor_ -> sym_["none"] = AST::ASTNode::class_map["Nothing"];

                    for (std::pair<std::string, std::string> a: c -> getArgs()) {
                        row -> constructor_ -> args_.push_back(class_map[a.second]);
                        row -> constructor_ -> sym_[a.first] = class_map[a.second];
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
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    
    class IntConst: public R_Expr {
        private:
            
            int value_;
            std::string type_ = "Int";
        public:
            IntConst(int value): value_(value) {}
            int getValue() { return value_; }
            ClassRow *getType(NameClassMap *map) { return class_map["Int"]; }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class StrConst: public R_Expr {
        private:
            
            std::string value_;
            std::string type_ = "String";
        public:
            StrConst(std::string value): value_(value) {}
            std::string getValue() { return value_; }
            ClassRow *getType(NameClassMap *map) { return class_map["String"]; }
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
            ClassRow *getType(NameClassMap *map) { 
                ClassRow *type = obj_ -> getType(map);
                if (type == NULL) return NULL;
                MethodRow *method = type -> methods_[method_ -> getText()];
                return method -> type_;
            }
            Call(R_Expr *obj, Ident *method, ActualArgs *args): obj_(obj), method_(method), args_(args) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Constructor: public R_Expr {
        private:
            
            Ident *type_;
            ActualArgs *args_;
        public:
            Constructor(Ident *type, ActualArgs *args): type_(type), args_(args) {}
            ClassRow *getType(NameClassMap *map) {
                return class_map[type_ -> getText()];
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };


    class Return: public Statement {
        private:
            
            R_Expr *ret_val_;
        public:
            Return(R_Expr *ret_val): ret_val_(ret_val) {}
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
            ClassRow *getType(NameClassMap *map) { 
                if ( l_child_ -> getType(map) -> class_name_ == "Boolean" &&
                     r_child_ -> getType(map) -> class_name_ == "Boolean") {
                    return class_map["Boolean"];
                }
                error_count++;
                std::cerr << "AND operator on line " << getLine() << " is not being given Boolean operands" << std::endl;
                return class_map["Boolean"];
            }
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
            ClassRow *getType(NameClassMap *map) { 
                if ( l_child_ -> getType(map) -> class_name_ == "Boolean" &&
                     r_child_ -> getType(map) -> class_name_ == "Boolean") {
                    return class_map["Boolean"];
                }
                error_count++;
                std::cerr << "OR operator on line " << getLine() << " is not being given Boolean operands" << std::endl;
                return class_map["Boolean"];
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Neg: public R_Expr {
        private:
            
            R_Expr *operand_;
        public:
            Neg(R_Expr *operand): operand_(operand) {}
            R_Expr *getOperand() { return operand_; }
            ClassRow *getType(NameClassMap *map) { 
                if (operand_ -> getType(map) -> class_name_ == "Boolean") {
                    return class_map["Boolean"];
                }
                error_count++;
                std::cerr << "Negation on line " << getLine() << " is not being given a Boolean operand" << std::endl;
                return class_map["Boolean"];
            }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Typecase: public Statement {
        private:
            
            R_Expr *r_expr_;
            std::vector<class TypeAlt *> *type_alts_;
        public:
            Typecase(R_Expr *r_expr, std::vector<class TypeAlt *> *type_alts): 
                r_expr_(r_expr), type_alts_(type_alts) {}
            R_Expr *getR_Expr() { return r_expr_; }
            std::vector<class TypeAlt *> *getTypeAlts() { return type_alts_; }
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
            Block *getStmts() { return stmts_; }
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
}

#endif //AST_H
