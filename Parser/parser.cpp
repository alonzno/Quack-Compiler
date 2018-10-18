//
// The parser driver just glues together a parser object
// and a lexer object.
//

#include "lex.yy.h"
#include "Messages.h"
#include <iostream>
#include <fstream>
#include <string>

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

    yy::Lexer *lexer  = new yy::Lexer(file);
    yy::parser *parser = new yy::parser(*lexer);
    parser->parse();
}
