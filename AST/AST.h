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
        private:
            std::vector<ASTNode *> stmts_;
        public:
            void append(ASTNode *stmt) { stmts_.push_back(stmt); }
            void json(std::ostream &out, unsigned int ident = 0);
    };

    class Ident: public ASTNode {
        private:
            std::string text_;
        public:
            Ident(std::string name): text_(name) {}
    };

}

#endif //AST_H
