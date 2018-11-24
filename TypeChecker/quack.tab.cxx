// A Bison parser, made by GNU Bison 3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "quack.tab.cxx" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "quack.tab.hxx"

// User implementation prologue.

#line 51 "quack.tab.cxx" // lalr1.cc:415
// Unqualified %code blocks.
#line 28 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:416

    #include "lex.yy.h"
    #undef yylex
    #define yylex lexer.yylex  /* Within bison's parse() we should invoke lexer.yylex(), not the global yylex() */
    void dump(AST::ASTNode* n);


#line 61 "quack.tab.cxx" // lalr1.cc:416


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 156 "quack.tab.cxx" // lalr1.cc:491

  /// Build a parser object.
  parser::parser (yy::Lexer& lexer_yyarg, AST::Program** root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
    , location ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value (other.value)
    , location (other.location)
  {
  }

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    value = that.value;
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.value, that.location)
  {
    // that is emptied.
    that.type = empty_symbol;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  parser::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 110 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {
       *root = new AST::Program((yystack_[1].value.classes), (yystack_[0].value.block));
       }
#line 582 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 3:
#line 115 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.classes) = (yystack_[0].value.classes); }
#line 588 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 4:
#line 116 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.classes) = new std::vector<AST::Class *>(); 
       }
#line 596 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 5:
#line 120 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.classes) = (yystack_[1].value.classes);
       (yylhs.value.classes) -> push_back((yystack_[0].value.clazz));
       }
#line 605 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 6:
#line 124 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.classes) = new std::vector<AST::Class *>();
       (yylhs.value.classes) -> push_back((yystack_[0].value.clazz));
       }
#line 614 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 7:
#line 130 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 620 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 8:
#line 131 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.block) = new AST::Block(); 
          (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
          }
#line 629 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 9:
#line 135 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.block) = (yystack_[1].value.block); 
          (yylhs.value.block) -> append((yystack_[0].value.stmt)); 
          }
#line 638 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 10:
#line 139 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.block) = new AST::Block(); 
          (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
          (yylhs.value.block) -> append((yystack_[0].value.stmt)); 
          }
#line 648 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 11:
#line 146 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
        (yylhs.value.clazz) = new AST::Class(new AST::Ident((yystack_[8].value.str)), (yystack_[4].value.ident), (yystack_[6].value.formal_args), (yystack_[2].value.block), (yystack_[1].value.methods));
        (yylhs.value.clazz) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
     }
#line 657 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 12:
#line 151 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.formal_args) = (yystack_[0].value.formal_args); }
#line 663 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 13:
#line 152 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
           (yylhs.value.formal_args) = new AST::FormalArgs(); 
           (yylhs.value.formal_args) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
           }
#line 672 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 14:
#line 157 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
    (yylhs.value.formal_args) = new AST::FormalArgs(); 
    (yylhs.value.formal_args) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
    (yylhs.value.formal_args) -> append((yystack_[0].value.arg)); 
    }
#line 682 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 15:
#line 162 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
    (yylhs.value.formal_args) = (yystack_[2].value.formal_args); 
    (yylhs.value.formal_args) -> append((yystack_[0].value.arg)); 
    }
#line 691 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 16:
#line 167 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
   (yylhs.value.arg) = new AST::Arg(new AST::Ident((yystack_[2].value.str)), new AST::Ident((yystack_[0].value.str))); 
   (yylhs.value.arg) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
   }
#line 700 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 17:
#line 172 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
                (yylhs.value.ident) = new AST::Ident((yystack_[0].value.str));
                (yylhs.value.ident) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
                }
#line 709 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 18:
#line 176 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
                (yylhs.value.ident) = new AST::Ident(""); 
                (yylhs.value.ident) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
                }
#line 718 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 19:
#line 184 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.methods) = (yystack_[0].value.methods); }
#line 724 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 20:
#line 185 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
           (yylhs.value.methods) = new std::vector<AST::Method *>(); 
           }
#line 732 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 21:
#line 189 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.methods) = (yystack_[1].value.methods); 
       (yylhs.value.methods) -> push_back((yystack_[0].value.method)); 
       }
#line 741 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 22:
#line 193 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {
       (yylhs.value.methods) = new std::vector<AST::Method *>(); 
       (yylhs.value.methods) -> push_back((yystack_[0].value.method)); 
       }
#line 750 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 23:
#line 198 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::Ident *method_name = new AST::Ident((yystack_[5].value.str));
      method_name -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.method) = new AST::Method(method_name, (yystack_[1].value.ident), (yystack_[3].value.formal_args), (yystack_[0].value.block)); 
      (yylhs.value.method) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 761 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 24:
#line 205 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.ident) = new AST::Ident((yystack_[0].value.str)); 
         (yylhs.value.ident) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 770 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 25:
#line 209 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.ident) = new AST::Ident(""); 
         (yylhs.value.ident) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 779 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 26:
#line 216 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[1].value.block); }
#line 785 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 27:
#line 219 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.stmt) = (yystack_[0].value.if_else); }
#line 791 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 28:
#line 221 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.if_else) = new AST::If_Else((yystack_[3].value.r_expr), (yystack_[2].value.block), NULL); 
         std::vector<AST::If_Else *> *elif_block = (yystack_[1].value.elif_block);
         AST::Block *final_else = (yystack_[0].value.block);
         
         AST::If_Else *current_if = (yylhs.value.if_else);
         AST::Block *block_wrapper;

         int num_if = elif_block -> size();
         for (int i = 0; i < num_if; i++) {
            block_wrapper = new AST::Block();
            block_wrapper -> append((*elif_block)[i]);
            current_if -> setElseBlock(block_wrapper);
            current_if = (*elif_block)[i];
         }
         current_if -> setElseBlock(final_else);
         
         delete elif_block;

         (yylhs.value.if_else) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 817 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 29:
#line 243 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.elif_block) = (yystack_[0].value.elif_block); }
#line 823 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 30:
#line 244 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.elif_block) = new std::vector<AST::If_Else *>();
         }
#line 831 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 31:
#line 248 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.elif_block) = (yystack_[3].value.elif_block); 
         AST::If_Else *if_else = new AST::If_Else((yystack_[1].value.r_expr), (yystack_[0].value.block), NULL); 
         if_else -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         (yylhs.value.elif_block) -> push_back(if_else); 
         }
#line 842 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 32:
#line 254 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.elif_block) = new std::vector<AST::If_Else *>();
         AST::If_Else *if_else = new AST::If_Else((yystack_[1].value.r_expr), (yystack_[0].value.block), NULL); 
         if_else -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         (yylhs.value.elif_block) -> push_back(if_else); 
         }
#line 853 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 33:
#line 262 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 859 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 34:
#line 263 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
        (yylhs.value.block) = new AST::Block(); 
        (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
        }
#line 868 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 35:
#line 270 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.stmt) = new AST::While((yystack_[1].value.r_expr), (yystack_[0].value.block)); 
         (yylhs.value.stmt) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 877 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 36:
#line 277 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.stmt) = new AST::Assign((yystack_[4].value.l_expr), (yystack_[3].value.ident), (yystack_[1].value.r_expr)); 
         (yylhs.value.stmt) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 886 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 37:
#line 284 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      (yylhs.value.l_expr) = new AST::L_Expr(new AST::Ident((yystack_[0].value.str))); 
      (yylhs.value.l_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 895 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 38:
#line 288 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      (yylhs.value.l_expr) = new AST::L_Expr((yystack_[2].value.r_expr), new AST::Ident((yystack_[0].value.str))); 
      (yylhs.value.l_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 904 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 39:
#line 295 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.stmt) = (yystack_[1].value.r_expr); }
#line 910 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 40:
#line 299 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {  
      (yylhs.value.r_expr) = new AST::StrConst((yystack_[0].value.str)); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 919 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 41:
#line 304 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      (yylhs.value.r_expr) = new AST::IntConst((yystack_[0].value.num)); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 928 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 42:
#line 309 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {  (yylhs.value.r_expr) = (yystack_[0].value.l_expr); }
#line 934 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 43:
#line 313 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("PLUS"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 946 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 44:
#line 321 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("MINUS"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column); 
      }
#line 958 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 45:
#line 329 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("TIMES"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 970 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 46:
#line 337 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("DIVIDE"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 982 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 47:
#line 347 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call(new AST::IntConst(0), new AST::Ident("MINUS"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 994 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 48:
#line 355 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.r_expr) = (yystack_[1].value.r_expr); }
#line 1000 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 49:
#line 359 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("EQUALS"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1012 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 50:
#line 367 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("ATLEAST"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1024 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 51:
#line 375 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("ATMOST"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1036 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 52:
#line 383 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("LESS"), args); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1048 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 53:
#line 391 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      AST::ActualArgs *args = new AST::ActualArgs();
      args -> append((yystack_[0].value.r_expr));
      args -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      (yylhs.value.r_expr) = new AST::Call( (yystack_[2].value.r_expr), new AST::Ident("MORE"), args);
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1060 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 54:
#line 399 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.r_expr) = new AST::And((yystack_[2].value.r_expr), (yystack_[0].value.r_expr)); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1068 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 55:
#line 403 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.r_expr) = new AST::Or((yystack_[2].value.r_expr), (yystack_[0].value.r_expr)); }
#line 1074 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 56:
#line 405 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.r_expr) = new AST::Neg((yystack_[0].value.r_expr)); }
#line 1080 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 57:
#line 409 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.r_expr) = new AST::Call((yystack_[5].value.r_expr), new AST::Ident((yystack_[3].value.str)), (yystack_[1].value.actual_args)); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1088 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 58:
#line 413 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.actual_args) = (yystack_[0].value.actual_args); }
#line 1094 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 59:
#line 414 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
           (yylhs.value.actual_args) = new AST::ActualArgs(); 
           (yylhs.value.actual_args) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
           }
#line 1103 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 60:
#line 419 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.actual_args) = (yystack_[2].value.actual_args); 
          (yylhs.value.actual_args) -> append((yystack_[0].value.r_expr)); 
          }
#line 1112 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 61:
#line 423 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.actual_args) = new AST::ActualArgs(); 
          (yylhs.value.actual_args) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
          (yylhs.value.actual_args) -> append((yystack_[0].value.r_expr)); 
          }
#line 1122 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 62:
#line 429 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.r_expr) = new AST::Constructor(new AST::Ident((yystack_[3].value.str)), (yystack_[1].value.actual_args)); 
      (yylhs.value.r_expr) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1130 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 63:
#line 435 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.stmt) = new AST::Return((yystack_[1].value.r_expr)); 
         (yylhs.value.stmt) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 1139 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 64:
#line 440 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.r_expr) = (yystack_[0].value.r_expr); }
#line 1145 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 65:
#line 441 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.r_expr) = NULL; 
          }
#line 1153 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 66:
#line 447 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.stmt) = new AST::Typecase((yystack_[3].value.r_expr), (yystack_[1].value.typealts)); 
         (yylhs.value.stmt) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 1162 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 67:
#line 452 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.typealts) = (yystack_[0].value.typealts); }
#line 1168 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 68:
#line 453 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
            (yylhs.value.typealts) = new std::vector<AST::TypeAlt *>(); 
            }
#line 1176 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 69:
#line 456 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
             (yylhs.value.typealts) = (yystack_[1].value.typealts); 
             (yylhs.value.typealts) -> push_back((yystack_[0].value.typealt));
             }
#line 1185 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 70:
#line 460 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {
        (yylhs.value.typealts) = new std::vector<AST::TypeAlt *>(); 
        (yylhs.value.typealts) -> push_back((yystack_[0].value.typealt));
        }
#line 1194 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 71:
#line 464 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {
            AST::Arg *arg = new AST::Arg(new AST::Ident((yystack_[3].value.str)), new AST::Ident((yystack_[1].value.str)));
            (yylhs.value.typealt) = new AST::TypeAlt(arg, (yystack_[0].value.block));
            (yylhs.value.typealt) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
        }
#line 1204 "quack.tab.cxx" // lalr1.cc:870
    break;


#line 1208 "quack.tab.cxx" // lalr1.cc:870
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -55;

  const signed char parser::yytable_ninf_ = -26;

  const short
  parser::yypact_[] =
  {
      16,     2,    28,    49,    16,   -55,     0,   -55,    32,    32,
      32,    32,    32,     1,   -55,   -55,    32,    32,   -55,    49,
     -55,   -55,   -17,    96,   -55,    30,   -55,   130,   130,   189,
      18,   150,    -1,    32,   -23,   170,   -55,    44,    35,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      45,   -55,    31,    41,    42,   -55,    49,    69,   -55,   -55,
      59,   189,    50,    46,   -55,   -55,    32,     8,     8,     8,
      -1,    -1,     8,     8,   -23,   -23,    54,    54,    55,    65,
      80,    30,    56,    32,    82,    85,    60,    61,    59,   -55,
     -55,    32,   113,    32,   -55,    77,    66,   -55,   -55,   130,
      67,   -55,    32,    78,   -55,   -55,   189,   -55,    71,   -55,
      49,   -55,   -55,   130,    67,   -55,    95,   -55,   -55,    86,
      73,    95,   -55,    74,   -55,   -55,    30,    76,    79,    67,
     -55
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,     0,     0,     8,     3,     6,     0,     1,     0,     0,
      65,     0,     0,    37,    41,    40,     0,     0,     2,     7,
      10,    27,    42,     0,     5,    13,    42,     0,     0,    64,
       0,     0,    56,    59,    47,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     0,     0,    12,    14,     8,    30,    35,    63,
      68,    61,     0,    58,    48,    24,     0,    50,    51,    49,
      54,    55,    53,    52,    43,    44,    45,    46,    38,     0,
      18,     0,     0,     0,    34,    29,     0,     0,    67,    70,
      62,     0,     0,    59,    16,     0,     0,    15,    26,     0,
       0,    28,     0,     0,    66,    69,    60,    36,     0,    17,
       8,    32,    33,     0,     0,    57,    20,    31,    71,     0,
       0,    19,    22,     0,    11,    21,    13,     0,    25,     0,
      23
  };

  const signed char
  parser::yypgoto_[] =
  {
     -55,   -55,   -55,   -55,   -54,   -55,   110,   -11,   -55,    36,
     -55,   -55,   -55,    -5,     3,   -27,   111,   -55,   -55,   -55,
     -55,    -3,    -2,    40,   -55,   -55,   -55,   -55,    62
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    18,    19,     5,    53,    54,    55,
      96,   120,   121,   122,    38,    57,    20,    21,    84,    85,
     101,    26,    23,    62,    63,    30,    87,    88,    89
  };

  const short
  parser::yytable_[] =
  {
      22,    58,    82,    48,    49,    50,    27,    28,    29,    31,
      32,    39,    40,    41,    34,    35,    22,    37,   -25,     1,
       6,    44,    45,    46,    47,    48,    49,    50,     7,    25,
      33,    61,    46,    47,    48,    49,    50,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    52,    12,
      13,    14,    15,    22,    59,     8,   116,    16,     9,    10,
      11,    17,    65,    78,    92,    79,    12,    13,    14,    15,
      66,    80,   111,   112,    16,    81,    83,    86,    17,    91,
      90,    99,    50,    94,    93,    95,   117,   118,    98,   106,
     100,    61,   102,   104,   103,   109,   114,   110,    56,   119,
     113,   115,   130,   126,   123,   124,   128,    22,    39,    40,
      41,    42,    43,    37,    24,   127,   125,    97,    44,    45,
      46,    47,    48,    49,    50,    39,    40,    41,    42,    43,
      36,   129,    51,   108,     0,    44,    45,    46,    47,    48,
      49,    50,    39,    40,    41,    42,    43,     0,     0,   107,
     105,     0,    44,    45,    46,    47,    48,    49,    50,     0,
       0,    56,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,    44,    45,    46,    47,    48,    49,    50,     0,
       0,    60,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,    44,    45,    46,    47,    48,    49,    50,     0,
      64,    39,    40,    41,    42,    43,     0,     0,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50
  };

  const short
  parser::yycheck_[] =
  {
       3,    28,    56,    26,    27,    28,     8,     9,    10,    11,
      12,    12,    13,    14,    16,    17,    19,    34,    35,     3,
      18,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      29,    33,    24,    25,    26,    27,    28,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    18,    17,
      18,    19,    20,    56,    36,     6,   110,    25,     9,    10,
      11,    29,    18,    18,    66,    34,    17,    18,    19,    20,
      35,    30,    99,   100,    25,    33,     7,    18,    29,    33,
      30,    83,    28,    18,    29,     5,   113,   114,    32,    91,
       8,    93,     7,    32,    34,    18,    18,    31,    31,     4,
     102,    30,   129,    29,    18,    32,    30,   110,    12,    13,
      14,    15,    16,    34,     4,   126,   121,    81,    22,    23,
      24,    25,    26,    27,    28,    12,    13,    14,    15,    16,
      19,   128,    36,    93,    -1,    22,    23,    24,    25,    26,
      27,    28,    12,    13,    14,    15,    16,    -1,    -1,    36,
      88,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    38,    39,    40,    43,    18,     0,     6,     9,
      10,    11,    17,    18,    19,    20,    25,    29,    41,    42,
      53,    54,    58,    59,    43,    29,    58,    59,    59,    59,
      62,    59,    59,    29,    59,    59,    53,    34,    51,    12,
      13,    14,    15,    16,    22,    23,    24,    25,    26,    27,
      28,    36,    18,    44,    45,    46,    31,    52,    52,    36,
      31,    59,    60,    61,    30,    18,    35,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    18,    34,
      30,    33,    41,     7,    55,    56,    18,    63,    64,    65,
      30,    33,    59,    29,    18,     5,    47,    46,    32,    59,
       8,    57,     7,    34,    32,    65,    59,    36,    60,    18,
      31,    52,    52,    59,    18,    30,    41,    52,    52,     4,
      48,    49,    50,    18,    32,    50,    29,    44,    30,    51,
      52
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    45,    45,    46,    47,    47,    48,
      48,    49,    49,    50,    51,    51,    52,    53,    54,    55,
      55,    56,    56,    57,    57,    53,    53,    58,    58,    53,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    59,    53,    62,    62,    53,    63,    63,    64,
      64,    65
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,     0,     2,     1,     1,     0,     2,
       1,    10,     1,     0,     1,     3,     3,     2,     0,     1,
       0,     2,     1,     7,     2,     0,     3,     1,     5,     1,
       0,     4,     3,     2,     0,     3,     5,     1,     3,     2,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     6,     1,     0,
       3,     1,     4,     3,     1,     0,     5,     1,     0,     2,
       1,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "CLASS", "DEF", "EXTENDS", "IF", "ELIF",
  "ELSE", "WHILE", "RETURN", "TYPECASE", "ATLEAST", "ATMOST", "EQUALS",
  "AND", "OR", "NOT", "IDENT", "INT_LIT", "STRING_LIT", "NEG", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'.'", "'('", "')'", "'{'", "'}'",
  "','", "':'", "'='", "';'", "$accept", "program", "opt_classes",
  "classes", "opt_statements", "statements", "class", "opt_formal_args",
  "formal_args", "arg", "opt_extends", "opt_methods", "methods", "method",
  "opt_ident", "statement_block", "statement", "if_statement", "opt_elif",
  "more_elif", "opt_else", "l_expr", "r_expr", "actual_args", "seq_r_expr",
  "opt_r_expr", "opt_type_alt", "more_type_alt", "type_alt", YY_NULLPTR
  };


  const unsigned short
  parser::yyrline_[] =
  {
       0,   110,   110,   115,   116,   120,   124,   130,   131,   135,
     139,   146,   151,   152,   157,   162,   167,   172,   176,   184,
     185,   189,   193,   198,   205,   209,   216,   219,   221,   243,
     244,   248,   254,   262,   263,   270,   277,   284,   288,   295,
     299,   304,   309,   313,   321,   329,   337,   347,   355,   359,
     367,   375,   383,   391,   399,   403,   405,   409,   413,   414,
     419,   423,   429,   435,   440,   441,   447,   452,   453,   456,
     460,   464
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,    26,    24,    33,    25,    28,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    36,
      23,    35,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
    };
    const unsigned user_token_number_max_ = 276;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1645 "quack.tab.cxx" // lalr1.cc:1181
#line 470 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:1182

#include "Messages.h"

void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}

void dump(AST::ASTNode* n) {
    // std::cout << "*** Building: " << n->str() << std::endl;
}
