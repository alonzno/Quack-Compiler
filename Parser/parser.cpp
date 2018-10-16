//
// The parser driver just glues together a parser object
// and a lexer object.
//

#include "lex.yy.h"
#include "Messages.h"

int main()
{
    yy::Lexer *lexer  = new yy::Lexer(std::cin);
    yy::parser *parser = new yy::parser(*lexer);
    parser->parse();
}
