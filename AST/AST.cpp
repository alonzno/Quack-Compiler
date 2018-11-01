#include "AST.h"

namespace AST {

    //THIS IS CODE FOR DEBUGGING THE TREE USING MICHAELS JSON TO DOT
    void ASTNode::json_indent(std::ostream& out, AST_print_context& ctx) {
        if (ctx.indent_ > 0) {
            out << std::endl;
        }
        for (int i=0; i < ctx.indent_; ++i) {
            out << "    ";
        }
    }

    /* The head element looks like { "kind" : "block", */
    void ASTNode::json_head(std::string node_kind, std::ostream& out, AST_print_context& ctx) {
        json_indent(out, ctx);
        out << "{ \"kind\" : \"" << node_kind << "\"," ;
        ctx.indent();  // one level more for children
        return;
    }

    void ASTNode::json_close(std::ostream& out, AST_print_context& ctx) {
        // json_indent(out, ctx);
        out << "}";
        ctx.dedent();
    }

    void ASTNode::json_child(std::string field, ASTNode& child, std::ostream& out, AST_print_context& ctx, char sep) {
        json_indent(out, ctx);
        out << "\"" << field << "\" : ";
        child.json(out, ctx);
        out << sep;
    }

    void Block::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Block", out, ctx);
        out << "\"stmts_\" : [";
        std::string sep = "";
        for (ASTNode *stmt: stmts_) {
            out << sep;
            stmt->json(out,ctx);
            sep = ", ";
        }
        out << "]";
        json_close(out, ctx);
    }

    void Ident::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Ident", out, ctx);
        out << "\"text_\" : \"" << text_ << "\"";
        json_close(out,ctx);
    }
    
    void Arg::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Arg", out, ctx);
        out << "\"param_name_\" : \"" << param_name_ << "\", ";
        out << "\"param_type_\" : \"" << param_type_ << "\"";
        json_close(out, ctx);
    }

    void Class::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Class", out, ctx);
        out << "\"class_name_\" : \"" << class_name_ << "\", ";
        out << "\"super_name_\" : \"" << super_name_ << "\", ";
        args_->json(out,ctx);
        stmts_->json(out,ctx);
        methods_->json(out,ctx);
        json_close(out, ctx);
    }
    
    void Stub::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Stub", out, ctx);
        out << "\"text_\" : \"" << text_ << "\"";
        json_close(out, ctx);
    }

}
