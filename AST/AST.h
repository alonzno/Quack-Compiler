#ifndef AST_H
#define AST_H

#include <string>
#include <sstream>
#include <vector>

namespace AST {
    
    class AST_print_context {
        public:
            int indent_;
            AST_print_context() : indent_{0} {}
            void indent() { ++indent_; }
            void dedent() { --indent_; }
    };


    class ASTNode {
        public:
            virtual void json(std::ostream &out, AST_print_context &ctx) = 0;

        void json_indent(std::ostream& out, AST_print_context& ctx);
        void json_head(std::string node_kind, std::ostream& out, AST_print_context& ctx);
        void json_close(std::ostream& out, AST_print_context& ctx);
        void json_child(std::string field, ASTNode& child, std::ostream& out, AST_print_context& ctx, char sep=',');
    };
    
    class Block: public ASTNode {
        public:
            std::vector<ASTNode *> stmts_;
        public:
            Block() {}
            void append(ASTNode *stmt) { stmts_.push_back(stmt); }
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Ident: public ASTNode {
        public:
            std::string text_;
        public:
            Ident(std::string name): text_(name) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Arg: public ASTNode {
        public:
            Ident *param_name_;
            Ident *param_type_;
        public:
            Arg(Ident *name, Ident *type): param_name_(name), param_type_(type) {}
            void json(std::ostream &out, AST_print_context &ctx);

    };

    class Class: public ASTNode {
        public:
            Ident *class_name_;
            Ident *super_name_;
            Block *args_;
            Block *stmts_;
            Block *methods_;
        public:
            Class(Ident *name, Ident *super): class_name_(name), super_name_(super) {};
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Stub: public ASTNode {
        private:
            std::string text_;
        public:
            Stub(std::string text): text_(text) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class Assign: public ASTNode {
        public:
            ASTNode *l_expr_;
            ASTNode *r_expr_;
        public:
            Assign(ASTNode *l_expr, ASTNode *r_expr): l_expr_(l_expr), r_expr_(r_expr) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class While: public ASTNode {
        public:
            ASTNode *cond_;
            Block *body_;
        public:
            While(ASTNode *cond, Block *body): cond_(cond), body_(body) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };
}

#endif //AST_H
