#include "AST.h"
#include "SymTable.h"

namespace AST {
    
    NameClassMap ASTNode::class_map;
    int ASTNode::error_count;

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

    void Program::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Program", out, ctx);
        out << "\"classes_\" : [";
        std::string sep = "";
        for (ASTNode *clazz: *classes_) {
            out << sep;
            clazz->json(out,ctx);
            sep = ", ";
        }
        out << "],";
        json_child("stmts_", *stmts_, out, ctx, ' ');
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

    void FormalArgs::json(std::ostream &out, AST_print_context &ctx) {
        json_head("FormalArgs", out, ctx);
        out << "\"args_\" : [";
        std::string sep = "";
        for (ASTNode *arg: *args_) {
            out << sep;
            arg->json(out,ctx);
            sep = ", ";
        }
        out << "]";

        json_close(out, ctx);
    }
    
    void ActualArgs::json(std::ostream &out, AST_print_context &ctx) {
        json_head("ActualArgs", out, ctx);
        out << "\"args_\" : [";
        std::string sep = "";
        for (ASTNode *arg: args_) {
            out << sep;
            arg->json(out,ctx);
            sep = ", ";
        }
        out << "]";

        json_close(out, ctx);
    }

    void Class::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Class", out, ctx);
        json_child("class_name_", *class_name_, out, ctx);
        json_child("super_name_", *super_name_, out, ctx);
        json_child("args_", *args_, out, ctx);
        json_child("stmts_", *stmts_, out, ctx);
        out << "\"methods_\" : [";
        std::string sep = "";
        for (ASTNode *method: *methods_) {
            out << sep;
            method->json(out,ctx);
            sep = ", ";
        }
        out << "]";
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

    void L_Expr::json(std::ostream &out, AST_print_context &ctx) {
        json_head("L_Expr", out, ctx);
        if (r_expr_ != NULL) json_child("r_expr_", *r_expr_, out, ctx);
        json_child("name_", *name_, out, ctx, ' ');
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
        json_child("else_stmts_", *else_stmts_, out, ctx, ' ');
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

    void Return::json(std::ostream &out, AST_print_context &ctx) {
        json_head("Return", out, ctx);
        if (ret_val_ != NULL) json_child("ret_val_", *ret_val_, out, ctx, ' ');
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
        //json_child("type_alts_", *type_alts_, out, ctx, ' ');
        out << "\"type_alts_\" : [";
        std::string sep = "";
        for (ASTNode *type_alt: *type_alts_) {
            out << sep;
            type_alt->json(out,ctx);
            sep = ", ";
        }
        out << "]";
        json_close(out, ctx);
    }
    
    void TypeAlt::json(std::ostream &out, AST_print_context &ctx) {
        json_head("TypeAlt", out, ctx);
        json_child("arg_", *arg_, out, ctx);
        json_child("stmts_", *stmts_, out, ctx, ' ');
        json_close(out, ctx);
    }
    
}
