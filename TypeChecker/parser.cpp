//
// The parser driver just glues together a parser object
// and a lexer object.
//

#include "lex.yy.h"
#include "Messages.h"
#include <iostream>
#include <fstream>
#include <string>

#include "AST.h"
#include "typecheck.h"

class Driver {
    public:
        explicit Driver(std::ifstream &in) {
            lexer = new yy::Lexer(in);
            parser = new yy::parser(*lexer, &root);
            root = NULL; 
        }

        ~Driver() { delete lexer; delete parser; }

        bool parse_result() {
            int result = parser->parse();
            return result == 0 && report::ok();
        }

        void json(std::ostream &out){
            AST::AST_print_context context;
            root->json(out, context);
        }

        void checkTypes() {
            type_checker = new TypeChecker(&root);
            type_checker -> checkClasses();
            type_checker -> checkInit();
        }
    private:
        yy::Lexer *lexer;
        yy::parser *parser;
        AST::ASTNode *root;
        TypeChecker *type_checker;
};

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./" 
            << argv[0] 
            << " <filename>" 
            << std::endl;
        exit(1);
    }

    std::ifstream file;
    file.open(std::string(argv[1]));
    Driver driver(file);

    if (driver.parse_result()) {
        std::cout << "Finished parse with no errors" << std::endl;
        driver.json(std::cout);
        driver.checkTypes();

    }
    //yy::Lexer *lexer  = new yy::Lexer(file);
    //yy::parser *parser = new yy::parser(*lexer, argv[1]);
}
