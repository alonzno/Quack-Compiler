// lex.yy.cpp generated by reflex 1.0.9 from /Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx

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

#line 1 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"

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
//  SECTION 1: %{ user code %}                                                //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 13 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"

/* Externally visible file name --
* for error messages.
* FIXME: Need to extract this from structures that reflex passes
* or else find another way to dig it out.
*/
std::string yyfilename = "What file is this, anyway?";

/* Some strings can't be matched in one gulp.  We need
 * a buffer in which to assemble them from parts.
 */
std::string string_buf = "";

void yyerror (const std::string &msg, yy::position* where) {
     std::cout << where << ": " << msg;
}

/* Some long messages that don't fit well in the code below */

std::string BAD_ESC_MSG =
  "Illegal escape code; only \\\\, \\0, \\t, \\n, \\r, \\n are permitted";
std::string BAD_NL_STR =
  "Unclosed string?  Encountered newline in quoted string.";


#line 43 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
/* You'll probably want scanner states for both multi-line
   * comments and for triple-quote strings.  Do comments first,
   * because they're easier (you just throw away the text).  Then
   * do triple-quote strings.  You might consider doing the same for
   * normal strings with a single pair of double quotes, to avoid
   * writing a really ugly regex.  'comment' here is an example of
   * how to declare an exclusive scanner state.
   */

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  BISON C++                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

int yy::Lexer::yylex(yy::parser::semantic_type& yylval)
{
  static const reflex::Pattern PATTERN_INITIAL("(?m)(==)|([<]=)|([>]=)|([/][/].*[\\x0a])|([(-/:->\\x7b\\x7d])|(class)|(def)|(if)|(elif)|(else)|(and)|(or)|(not)|(extends)|(return)|(while)|(typecase)|([0-9]+)|([\"])|(\"\"\"(?:.|\\n)*[\"][\"][\"])|([\\x09\\x0a\\x20]*)|([/][\\x2a])|([A-Z_a-z][0-9A-Z_a-z]*)|(.)");
  static const reflex::Pattern PATTERN_comment("(?m)([^\\x2a]*)|([\\x2a][^/])|([\\x2a][/])");
  static const reflex::Pattern PATTERN_string("(?m)([\\x0a])|(\\\\0)|(\\\\b)|(\\\\t)|(\\\\n)|(\\\\r)|(\\\\f)|(\\\\[\"])|(\\\\\\\\)|(\\\\[^\"0\\x5cbfnrt])|([^\"\\x5c])|([\"])");
  if (!has_matcher())
  {
    matcher(new Matcher(PATTERN_INITIAL, stdinit(), this));
  }
  switch (start())
  {
    case INITIAL:
#line 60 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
/* We start with some tokens that are not value-bearing,
   * i.e., the parser needs to know only which token was matched.
   */

  /* Multi-character punctuation with names */
    break;
  }
  while (true)
  {
    switch (start())
    {
      case INITIAL:
        matcher().pattern(PATTERN_INITIAL);
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
#line 171 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return EOF; }

            }
            else
            {
              out().put(matcher().input());
            }
            break;
          case 1: // rule at line 60: ==
#line 60 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::EQUALS; }
            break;
          case 2: // rule at line 61: [<]=
#line 61 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::ATMOST; }
            break;
          case 3: // rule at line 62: [>]=
#line 62 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::ATLEAST; }


    /* Single-line comment */
            break;
          case 4: // rule at line 66: [/][/].*[\x0a]
#line 66 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ ; }

   /* Single character punctuation.  Because a character
    * in C or C++ can be treated as an integer, Bison lets
    * us return a character as a token.
    * JFlex/Cup do not let you do this in Java.
    * Here are a few ... there are more.
    */
            break;
          case 5: // rule at line 74: [(-/:->\x7b\x7d]
#line 74 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return text()[0]; }

  /* Keywords are essentially another kind of punctuation,
   * but since they also match the identifier pattern, we
   * need to be sure we give their patterns *before* the
   * identifier pattern.  Most scanner generators work this
   * way, but WARNING for Python PLY users:  PLY prioritizes
   * by length of the regular expression!
   * Here are a couple of examples.
   */

            break;
          case 6: // rule at line 85: class
#line 85 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::CLASS; }
            break;
          case 7: // rule at line 86: def
#line 86 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::DEF; }
            break;
          case 8: // rule at line 87: if
#line 87 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::IF; }
            break;
          case 9: // rule at line 88: elif
#line 88 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::ELIF; }
            break;
          case 10: // rule at line 89: else
#line 89 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::ELSE; }
            break;
          case 11: // rule at line 90: and
#line 90 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::AND; }
            break;
          case 12: // rule at line 91: or
#line 91 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::OR; }
            break;
          case 13: // rule at line 92: not
#line 92 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::NOT; }
            break;
          case 14: // rule at line 93: extends
#line 93 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::EXTENDS; }
            break;
          case 15: // rule at line 94: return
#line 94 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::RETURN; }
            break;
          case 16: // rule at line 95: while
#line 95 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::WHILE; }
            break;
          case 17: // rule at line 96: typecase
#line 96 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ return parser::token::TYPECASE; }


   /* The following tokens are value-bearing:
    * We pass a value back to the parser by copying
    * it into the yylval parameter.  The parser
    * expects string values for identifiers and
    * string literals in yylval.str.  It expects integer
    * values for integer literals in yylval.num.
    * I'll give pattern for integer literals.
    * You'll need another for identifiers.  Remember to
    * 'strdup' the value returned by 'text()', or else it will
    * be clobbered by subsequent calls.
    */

            break;
          case 18: // rule at line 111: [0-9]+
#line 111 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ yylval.num = atoi(text()); return parser::token::INT_LIT; }

  /* You *can* write a one-line regular expression for matching a quoted string,
   * but you probably can't read it.  (I can't read mine.)  Scanner states and
   * simpler patterns are probably a better idea.
   * You almost certainly scanner states for triple quotes.
   * The tricky bit is catching errors, such as disallowed escape sequences
   * and unclosed quotes.
   */

    /* Single-line string */
            break;
          case 19: // rule at line 122: ["]
#line 122 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ start(string); }
            break;
          case 20: // rule at line 145: """(?:.|\n)*["]["]["]
#line 145 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{
                string_buf.append(str().substr(3,size()-3));
                yylval.str = strdup(string_buf.c_str());
                string_buf.clear();
                start(INITIAL);
                return parser::token::STRING_LIT; }

  /* Ignore whitespace */
            break;
          case 21: // rule at line 153: [\x09\x0a\x20]*
#line 153 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ ; }

   /* Multi-line comments */
            break;
          case 22: // rule at line 156: [/][\x2a]
#line 156 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ start(comment); }
            break;
          case 23: // rule at line 163: [A-Z_a-z][0-9A-Z_a-z]*
#line 163 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ yylval.str = strdup(text()); return parser::token::IDENT; }


            break;
          case 24: // rule at line 166: .
#line 166 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{   report::error("Unexpected character '" + std::string(text()) + "'" +
       " at line " + std::to_string(lineno()) +
       ", column " + std::to_string(columno()));
   }

            break;
        }
        break;
      case comment:
        matcher().pattern(PATTERN_comment);
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
#line 159 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ report::error("EOF in comment"); }
            }
            else
            {
              out().put(matcher().input());
            }
            break;
          case 1: // rule at line 157: [^\x2a]*
#line 157 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ ; }
            break;
          case 2: // rule at line 158: [\x2a][^/]
#line 158 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ ; }
            break;
          case 3: // rule at line 160: [\x2a][/]
#line 160 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ start(INITIAL); }

    /* Identifier */
            break;
        }
        break;
      case string:
        matcher().pattern(PATTERN_string);
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
#line 127 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ report::error("EOF encountered in string literal at line " + std::to_string(lineno())); }
            }
            else
            {
              out().put(matcher().input());
            }
            break;
          case 1: // rule at line 123: [\x0a]
#line 123 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.clear();
                          report::error("Unclosed string literal at line "
                          + std::to_string(lineno()));
                          start(INITIAL); }
            break;
          case 2: // rule at line 128: \\0
#line 128 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append("\0"); }
            break;
          case 3: // rule at line 129: \\b
#line 129 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append("\b"); }
            break;
          case 4: // rule at line 130: \\t
#line 130 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append("\t"); }
            break;
          case 5: // rule at line 131: \\n
#line 131 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append("\n"); }
            break;
          case 6: // rule at line 132: \\r
#line 132 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append("\r"); }
            break;
          case 7: // rule at line 133: \\f
#line 133 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append("\f"); }
            break;
          case 8: // rule at line 134: \\["]
#line 134 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append("\""); }
            break;
          case 9: // rule at line 135: \\\\
#line 135 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append("\\"); }
            break;
          case 10: // rule at line 136: \\[^"0\x5cbfnrt]
#line 136 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ report::error("Unrecognized escape sequence '" + str() + "'");}
            break;
          case 11: // rule at line 137: [^"\x5c]
#line 137 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ string_buf.append(text()); }
            break;
          case 12: // rule at line 138: ["]
#line 138 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"
{ yylval.str = strdup(string_buf.c_str());
                string_buf.clear();
                start(INITIAL);
                return parser::token::STRING_LIT; }

    /* Multiline String */

            break;
        }
        break;
      default:
        return 0;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 3: user code                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 174 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.lxx"

/* No main program here */

