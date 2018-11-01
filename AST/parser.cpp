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
    private:
        yy::Lexer *lexer;
        yy::parser *parser;
        AST::ASTNode *root;
};

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./" 
            << argv[0] 
            << " <filename>" 
            << std::endl;
    }

    std::ifstream file;
    file.open(std::string(argv[1]));
    Driver driver(file);
    if (driver.parse_result()) {
        std::cout << "Finished parse with no errors" << std::endl;
        driver.json(std::cout);
    }
    //yy::Lexer *lexer  = new yy::Lexer(file);
    //yy::parser *parser = new yy::parser(*lexer, argv[1]);
}
