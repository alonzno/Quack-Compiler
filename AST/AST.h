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
            Ident *type_;
            ASTNode *r_expr_;
        public:
            Assign(ASTNode *l_expr, Ident *type, ASTNode *r_expr): l_expr_(l_expr), type_(type), r_expr_(r_expr) {}
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
    
    class Method: public ASTNode {
        public:
            Ident *name_;
            Ident *return_type_;
            Block *args_;
            Block *stmts_;
        public:
            Method(Ident *name, Ident *return_type, Block *args, Block *stmts): name_(name), return_type_(return_type), args_(args), stmts_(stmts) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    // REVISE THIS SO THAT THE elif's are nested in the else
    class If_Else: public ASTNode {
        public:
            ASTNode *cond_;
            Block *if_stmts_;
            Block *elifs_;
            Block *else_stmts_;
        public:
            If_Else(ASTNode *cond, Block *if_stmts, Block *elifs, Block *else_stmts): cond_(cond), if_stmts_(if_stmts), elifs_(elifs), else_stmts_(else_stmts) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };
    
    class Elif: public ASTNode {
        public:
            ASTNode *cond_;
            Block *stmts_;
        public:
            Elif(ASTNode *cond, Block *stmts): cond_(cond), stmts_(stmts) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class IntConst: public ASTNode {
        public:
            int value_;
        public:
            IntConst(int value): value_(value) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class StrConst: public ASTNode {
        public:
            std::string value_;
        public:
            StrConst(std::string value): value_(value) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Call: public ASTNode {
        public:
            ASTNode *obj_;
            Ident *method_;
            ASTNode *args_;
        public:
            Call(ASTNode *obj, Ident *method, ASTNode *args): obj_(obj), method_(method), args_(args) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Constructor: public ASTNode {
        public:
            Ident *type_;
            Block *args_;
        public:
            Constructor(Ident *type, Block *args): type_(type), args_(args) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Member: public ASTNode {
        public:
            ASTNode *obj_;
            Ident *field_;
        public:
            Member(ASTNode *obj, Ident *field): obj_(obj), field_(field) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };

    class Return: public ASTNode {
        public:
            ASTNode *ret_val_;
        public:
            Return(ASTNode *ret_val): ret_val_(ret_val) {}
            void json(std::ostream &out, AST_print_context &ctx);
    };
}

#endif //AST_H
