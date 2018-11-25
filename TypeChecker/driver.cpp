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
            //root -> updateClasses();

            /*//DEBUG
            for (NameClassMap::iterator it = root -> AST::ASTNode::class_map.begin(); it != AST::ASTNode::class_map.end(); it++) {
                std::cout << it -> first << std::endl;
            }
            */

            return result == 0 && report::ok();
        }

        void json(std::ostream &out){
            AST::AST_print_context context;
            root->json(out, context);
        }
        void checkTypes() {
            type_checker = new TypeChecker(&root);
            
            //DEBUG
            //AST::ASTNode::printClassesAndMethods();
        }
    private:
        yy::Lexer *lexer;
        yy::parser *parser;
        AST::Program *root;
        TypeChecker *type_checker;
};

std::ifstream appendDummyCode(char *fname) {
    std::ifstream in_file, dummy_file, out_file;
    std::ofstream writer_file;
    std::string line;

    in_file.open(fname);

    dummy_file.open("samples/dummy_program.qk");
    writer_file.open("tmp", std::ios::trunc);

    if (!writer_file.is_open()) {
        std::cerr << "Error writing temp file" << std::endl;
        exit(2);
    }
    if (dummy_file.is_open()) {
        while( getline(dummy_file, line) ) {
            writer_file << line << std::endl;
        }
        dummy_file.close();
    }
    else {
        std::cerr << "No dummy program found in ./samples/" << std::endl;
        exit(2);
    }
    if (in_file.is_open()) {
        while( getline(in_file, line) ) {
            writer_file << line << std::endl;
        }
        in_file.close();
    }
    else {
        std::cerr << "No file named " << fname << std::endl;
        exit(2);
    }    
    
    writer_file.close();

    out_file.open("tmp");
    return out_file;
}

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
    file = appendDummyCode(argv[1]);

    Driver driver(file);

    if (driver.parse_result()) {
        //std::cout << "Finished parse with no errors" << std::endl;
        //driver.json(std::cout);
        driver.checkTypes();

    }
}
