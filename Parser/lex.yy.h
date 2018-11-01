// lex.yy.h generated by reflex 1.0.9 from /Users/alonzoaltamirano/Repos/Quack-Compiler/Parser/quack.lxx

#ifndef REFLEX_HEADER_H
#define REFLEX_HEADER_H
#define IN_HEADER 1

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define REFLEX_OPTION_YYLTYPE             yy::location
#define REFLEX_OPTION_YYSTYPE             yy::parser::semantic_type
#define REFLEX_OPTION_bison_cc            true
#define REFLEX_OPTION_bison_cc_namespace  yy
#define REFLEX_OPTION_bison_cc_parser     parser
#define REFLEX_OPTION_bison_locations     true
#define REFLEX_OPTION_header_file         lex.yy.h
#define REFLEX_OPTION_lex                 yylex
#define REFLEX_OPTION_lexer               Lexer
#define REFLEX_OPTION_namespace           yy
#define REFLEX_OPTION_noyywrap            true
#define REFLEX_OPTION_outfile             lex.yy.cpp

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top{ user code %}                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 1 "/Users/alonzoaltamirano/Repos/Quack-Compiler/Parser/quack.lxx"

/* Quack scanner
 *
 * 2018 Fall version for RE/flex,
 * skeleton.
 *
 */

#include "quack.tab.hxx"  /* Generated by bison. */
#include "Messages.h"


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  ABSTRACT LEXER CLASS                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/abslexer.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

namespace yy {

class Lexer : public reflex::AbstractLexer<reflex::Matcher> {
 public:
  typedef reflex::AbstractLexer<reflex::Matcher> AbstractBaseLexer;
  Lexer(
      const reflex::Input& input = reflex::Input(),
      std::ostream&        os    = std::cout)
    :
      AbstractBaseLexer(input, os)
  {
  }
  static const int INITIAL = 0;
  static const int comment = 1;
  static const int string = 2;
  virtual int yylex(yy::parser::semantic_type *yylval, yy::location *yylloc)
  {
    yylloc->step();
    int ret = yylex(*yylval);
    yylloc->end.line = matcher().lineno();
    yylloc->end.column = matcher().columno();
    return ret;
  }
  virtual int yylex(yy::parser::semantic_type& yylval);
};

} // namespace yy

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  BISON C++                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#endif
