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
        json_child("param_name_", *param_name_, out, ctx);
        json_child("param_type_", *param_type_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void Class::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Class", out, ctx);
        json_child("class_name_", *class_name_, out, ctx);
        json_child("super_name_", *super_name_, out, ctx);
        json_child("args_", *args_, out, ctx);
        json_child("stmts_", *stmts_, out, ctx);
        json_child("methods_", *methods_, out, ctx, ' ');
        json_close(out, ctx);
    }
    
    void Stub::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Stub", out, ctx);
        out << "\"text_\" : \"" << text_ << "\"";
        json_close(out, ctx);
    }
    
    void Assign::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Assign", out, ctx);
        json_child("l_expr_", *l_expr_, out, ctx);
        json_child("type_", *type_, out, ctx);
        json_child("r_expr_", *r_expr_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void While::json(std::ostream &out, AST_print_context &ctx) {
        json_head("While", out, ctx);
        json_child("cond_", *cond_, out, ctx);
        json_child("body_", *body_, out, ctx, ' ');
        json_close(out, ctx);
    }
    
    void Method::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Method", out, ctx);
        json_child("name_", *name_, out, ctx);
        json_child("return_type_", *return_type_, out, ctx);
        json_child("args_", *args_, out, ctx);
        json_child("stmts_", *stmts_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void If_Else::json(std::ostream &out, AST_print_context &ctx) {
        json_head("If_Else", out, ctx);
        json_child("cond_", *cond_, out, ctx);
        json_child("if_stmts_", *if_stmts_, out, ctx);
        json_child("elifs_", *elifs_, out, ctx);
        json_child("else_stmts_", *else_stmts_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void Elif::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Elif", out, ctx);
        json_child("cond_", *cond_, out, ctx);
        json_child("stmts", *stmts_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void IntConst::json(std::ostream &out, AST_print_context &ctx) {
        json_head("IntConst", out, ctx);
        out << "\"value_\" : \"" << value_ << "\"";
        json_close(out, ctx);
    }

    void StrConst::json(std::ostream &out, AST_print_context &ctx) {
        json_head("StrConst", out, ctx);
        out << "\"value_\" : \"" << value_ << "\"";
        json_close(out, ctx);
    }

    void Call::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Call", out, ctx);
        json_child("obj_", *obj_, out, ctx);
        json_child("method_", *method_, out, ctx);
        json_child("args_", *args_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void Constructor::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Constructor", out, ctx);
        json_child("type_", *type_, out, ctx);
        json_child("args_", *args_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void Member::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Member", out, ctx);
        json_child("obj_", *obj_, out, ctx);
        json_child("field_", *field_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void Return::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Return", out, ctx);
        json_child("ret_val_", *ret_val_, out, ctx, ' ');
        json_close(out, ctx);
    }

    void And::json(std::ostream &out, AST_print_context &ctx) {
        json_head("And", out, ctx);
        json_child("l_child_", *l_child_, out, ctx);
        json_child("r_child_", *r_child_, out, ctx, ' ');
        json_close(out, ctx);
    }
    
    void Or::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Or", out, ctx);
        json_child("l_child_", *l_child_, out, ctx);
        json_child("r_child_", *r_child_, out, ctx, ' ');
        json_close(out, ctx);
    }
    
    void Neg::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Neg", out, ctx);
        json_child("operand_", *operand_, out, ctx, ' ');
        json_close(out, ctx);
    }
    
    void Typecase::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Typecase", out, ctx);
        json_child("r_expr_", *r_expr_, out, ctx);
        json_child("type_alts_", *type_alts_, out, ctx, ' ');
        json_close(out, ctx);
    }
    
    void TypeAlt::json(std::ostream &out, AST_print_context &ctx) {
        json_head("And", out, ctx);
        json_child("name_", *name_, out, ctx);
        json_child("type_", *type_, out, ctx);
        json_child("stmts_", *stmts_, out, ctx, ' ');
        json_close(out, ctx);
    }

}
