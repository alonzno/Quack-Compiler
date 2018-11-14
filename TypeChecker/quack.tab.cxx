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
  parser::parser (yy::Lexer& lexer_yyarg, AST::ASTNode** root_yyarg)
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
#line 95 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {
       (yylhs.value.block) = new AST::Block();
       (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);

       (yylhs.value.block) -> append((yystack_[1].value.block));
       (yylhs.value.block) -> append((yystack_[0].value.block));

       (yylhs.value.block) -> apptype(new std::string((yystack_[1].value.block) -> block_type_));
       (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.block) -> block_type_));
       *root = (yylhs.value.block);
       }
#line 590 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 3:
#line 108 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 596 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 4:
#line 109 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.block) = new AST::Block(); 
       (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
       }
#line 605 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 5:
#line 114 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.block) = (yystack_[1].value.block);
       (yylhs.value.block) -> append((yystack_[0].value.clazz));
       (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.clazz) -> block_type_));
       }
#line 615 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 6:
#line 119 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.block) = new AST::Block();
       (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
       (yylhs.value.block) -> append((yystack_[0].value.clazz));
       (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.clazz) -> block_type_));
       }
#line 626 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 7:
#line 127 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 632 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 8:
#line 128 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.block) = new AST::Block(); 
          (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
          }
#line 641 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 9:
#line 132 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.block) = (yystack_[1].value.block); 
          (yylhs.value.block) -> append((yystack_[0].value.node)); 
          (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.node) -> block_type_));
          }
#line 651 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 10:
#line 137 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.block) = new AST::Block(); 
          (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
          (yylhs.value.block) -> append((yystack_[0].value.node)); 
          (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.node) -> block_type_));
          }
#line 662 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 11:
#line 145 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
        (yylhs.value.clazz) = new AST::Class(new AST::Ident((yystack_[8].value.str)), (yystack_[4].value.ident));
        (yylhs.value.clazz) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
        (yylhs.value.clazz) -> args_ = (yystack_[6].value.block);
        (yylhs.value.clazz) -> stmts_ = (yystack_[2].value.block);
        (yylhs.value.clazz) -> methods_ = (yystack_[1].value.block);
     }
#line 674 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 12:
#line 153 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 680 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 13:
#line 154 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
           (yylhs.value.block) = new AST::Block(); 
           (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
           }
#line 689 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 14:
#line 159 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
    (yylhs.value.block) = new AST::Block(); 
    (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
    (yylhs.value.block) -> append((yystack_[0].value.arg)); 
    (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.arg) -> block_type_));
    }
#line 700 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 15:
#line 165 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
    (yylhs.value.block) = (yystack_[2].value.block); 
    (yylhs.value.block) -> append((yystack_[0].value.arg)); 
    (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.arg) -> block_type_));
    }
#line 710 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 16:
#line 171 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
   (yylhs.value.arg) = new AST::Arg(new AST::Ident((yystack_[2].value.str)), new AST::Ident((yystack_[0].value.str))); 
   (yylhs.value.arg) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
   }
#line 719 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 17:
#line 176 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
                (yylhs.value.ident) = new AST::Ident((yystack_[0].value.str));
                (yylhs.value.ident) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
                }
#line 728 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 18:
#line 180 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
                (yylhs.value.ident) = new AST::Ident(""); 
                (yylhs.value.ident) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
                }
#line 737 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 19:
#line 188 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 743 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 20:
#line 189 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
           (yylhs.value.block) = new AST::Block(); 
           (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
           }
#line 752 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 21:
#line 194 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.block) = (yystack_[1].value.block); 
       (yylhs.value.block) -> append((yystack_[0].value.node)); 
       (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.node) -> block_type_));
       }
#line 762 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 22:
#line 199 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {
       (yylhs.value.block) = new AST::Block(); 
       (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
       (yylhs.value.block) -> append((yystack_[0].value.node)); 
       (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.node) -> block_type_));
       }
#line 773 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 23:
#line 206 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      (yylhs.value.node) = new AST::Method(new AST::Ident((yystack_[5].value.str)), (yystack_[1].value.ident), (yystack_[3].value.block), (yystack_[0].value.block)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 782 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 24:
#line 211 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.ident) = new AST::Ident((yystack_[0].value.str)); 
         (yylhs.value.ident) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 791 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 25:
#line 215 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.ident) = new AST::Ident(""); 
         (yylhs.value.ident) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 800 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 26:
#line 222 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[1].value.block); }
#line 806 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 27:
#line 226 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.node) = new AST::If_Else((yystack_[3].value.node), (yystack_[2].value.block), (yystack_[1].value.block), (yystack_[0].value.block)); 
         (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 815 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 28:
#line 231 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 821 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 29:
#line 232 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.block) = new AST::Block(); 
         (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 830 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 30:
#line 237 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.block) = (yystack_[3].value.block); 
         (yylhs.value.block) -> append(new AST::Elif((yystack_[1].value.node), (yystack_[0].value.block)));
         (yylhs.value.block) -> apptype(new std::string("Elif"));
         }
#line 840 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 31:
#line 242 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.block) = new AST::Block(); 
         (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         (yylhs.value.block) -> append(new AST::Elif((yystack_[1].value.node), (yystack_[0].value.block))); 
         (yylhs.value.block) -> apptype(new std::string("Elif"));
         }
#line 851 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 32:
#line 250 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 857 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 33:
#line 251 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
        (yylhs.value.block) = new AST::Block(); 
        (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
        }
#line 866 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 34:
#line 258 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.node) = new AST::While((yystack_[1].value.node), (yystack_[0].value.block)); 
         (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 875 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 35:
#line 265 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.node) = new AST::Assign((yystack_[4].value.node), (yystack_[3].value.ident), (yystack_[1].value.node)); 
         (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 884 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 36:
#line 272 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      (yylhs.value.node) = new AST::Ident((yystack_[0].value.str)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 893 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 37:
#line 276 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      (yylhs.value.node) = new AST::Member((yystack_[2].value.node), new AST::Ident((yystack_[0].value.str))); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 902 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 38:
#line 283 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = (yystack_[1].value.node); }
#line 908 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 39:
#line 287 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {  
      (yylhs.value.node) = new AST::StrConst((yystack_[0].value.str)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 917 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 40:
#line 292 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
      (yylhs.value.node) = new AST::IntConst((yystack_[0].value.num)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 926 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 41:
#line 297 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    {  (yylhs.value.node) = (yystack_[0].value.node); }
#line 932 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 42:
#line 301 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("PLUS"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 940 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 43:
#line 305 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("MINUS"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column); 
      }
#line 948 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 44:
#line 309 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("TIMES"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 956 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 45:
#line 313 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("DIVIDE"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 964 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 46:
#line 319 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call(new AST::IntConst(0), new AST::Ident("MINUS"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 972 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 47:
#line 323 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = (yystack_[1].value.node); }
#line 978 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 48:
#line 327 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("EQUALS"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 986 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 49:
#line 331 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("ATLEAST"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 994 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 50:
#line 335 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("ATMOST"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1002 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 51:
#line 339 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("LESS"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1010 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 52:
#line 343 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call( (yystack_[2].value.node), new AST::Ident("MORE"), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1018 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 53:
#line 347 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::And((yystack_[2].value.node), (yystack_[0].value.node)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1026 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 54:
#line 351 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Or((yystack_[2].value.node), (yystack_[0].value.node)); }
#line 1032 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 55:
#line 353 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Neg((yystack_[0].value.node)); }
#line 1038 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 56:
#line 357 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Call((yystack_[5].value.node), new AST::Ident((yystack_[3].value.str)), (yystack_[1].value.block)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1046 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 57:
#line 361 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 1052 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 58:
#line 362 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
           (yylhs.value.block) = new AST::Block(); 
           (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
           }
#line 1061 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 59:
#line 367 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.block) = (yystack_[2].value.block); 
          (yylhs.value.block) -> append((yystack_[0].value.node)); 
          (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.node) -> block_type_));
          }
#line 1071 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 60:
#line 372 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
        (yylhs.value.block) = new AST::Block(); 
        (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
        (yylhs.value.block) -> append((yystack_[0].value.node)); 
        (yylhs.value.block) -> apptype(new std::string((yystack_[0].value.node) -> block_type_));
        }
#line 1082 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 61:
#line 379 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::Constructor(new AST::Ident((yystack_[3].value.str)), (yystack_[1].value.block)); 
      (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
      }
#line 1090 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 62:
#line 385 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.node) = new AST::Return((yystack_[1].value.node)); 
         (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 1099 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 63:
#line 390 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = (yystack_[0].value.node); }
#line 1105 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 64:
#line 391 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
          (yylhs.value.node) = new AST::Stub("No Return"); 
          (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
          }
#line 1114 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 65:
#line 398 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
         (yylhs.value.node) = new AST::Typecase((yystack_[3].value.node), (yystack_[1].value.block)); 
         (yylhs.value.node) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
         }
#line 1123 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 66:
#line 403 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 1129 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 67:
#line 404 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
            (yylhs.value.block) = new AST::Block(); 
            (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
            }
#line 1138 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 68:
#line 408 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
             (yylhs.value.block) = (yystack_[4].value.block); 
             (yylhs.value.block) -> append(new AST::TypeAlt(new AST::Ident((yystack_[3].value.str)), new AST::Ident((yystack_[1].value.str)), (yystack_[0].value.block))); 
             (yylhs.value.block) -> apptype(new std::string("TypeAlt"));
             }
#line 1148 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 69:
#line 413 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:870
    { 
        (yylhs.value.block) = new AST::Block(); 
        (yylhs.value.block) -> setLine(yylhs.location.begin.line, yylhs.location.begin.column);
        (yylhs.value.block) -> append(new AST::TypeAlt(new AST::Ident((yystack_[3].value.str)), new AST::Ident((yystack_[1].value.str)), (yystack_[0].value.block))); 
        (yylhs.value.block) -> apptype(new std::string("TypeAlt"));
        }
#line 1159 "quack.tab.cxx" // lalr1.cc:870
    break;


#line 1163 "quack.tab.cxx" // lalr1.cc:870
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


  const signed char parser::yypact_ninf_ = -54;

  const signed char parser::yytable_ninf_ = -26;

  const short
  parser::yypact_[] =
  {
      16,     2,    28,    48,    16,   -54,    -4,   -54,    31,    31,
      31,    31,    31,    14,   -54,   -54,    31,    31,   -54,    48,
     -54,   -21,    87,   -54,    35,   -54,   125,   125,   176,    20,
     142,    -1,    31,   -23,   159,   -54,    43,    23,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    51,
     -54,    32,    40,    38,   -54,    48,    69,   -54,   -54,    59,
     176,    44,    42,   -54,   -54,    31,     7,     7,     7,    -1,
      -1,     7,     7,   -23,   -23,    54,    54,    50,    66,    83,
      35,    55,    31,    82,    86,    56,    60,    77,   -54,    31,
     106,    31,   -54,    79,    71,   -54,   -54,   125,    72,   -54,
      31,    90,   -54,    78,   176,   -54,    89,   -54,    48,   -54,
     -54,   125,    72,    99,   -54,   120,   -54,   -54,    72,   107,
     100,   120,   -54,   -54,    93,   -54,   -54,    35,   101,   104,
      72,   -54
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,     0,     0,     8,     3,     6,     0,     1,     0,     0,
      64,     0,     0,    36,    40,    39,     0,     0,     2,     7,
      10,    41,     0,     5,    13,    41,     0,     0,    63,     0,
       0,    55,    58,    46,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,    12,    14,     8,    29,    34,    62,    67,
      60,     0,    57,    47,    24,     0,    49,    50,    48,    53,
      54,    52,    51,    42,    43,    44,    45,    37,     0,    18,
       0,     0,     0,    33,    28,     0,     0,    66,    61,     0,
       0,    58,    16,     0,     0,    15,    26,     0,     0,    27,
       0,     0,    65,     0,    59,    35,     0,    17,     8,    31,
      32,     0,     0,     0,    56,    20,    30,    69,     0,     0,
       0,    19,    22,    68,     0,    11,    21,    13,     0,    25,
       0,    23
  };

  const short
  parser::yypgoto_[] =
  {
     -54,   -54,   -54,   -54,   -53,   -54,   139,    17,   -54,    65,
     -54,   -54,   -54,    41,    30,   -26,   144,   -54,   -54,   -54,
      -3,    -2,    70,   -54,   -54,   -54,   -54
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    18,    19,     5,    52,    53,    54,
      94,   120,   121,   122,    37,    56,    20,    83,    84,    99,
      25,    22,    61,    62,    29,    86,    87
  };

  const short
  parser::yytable_[] =
  {
      21,    57,    81,    47,    48,    49,    26,    27,    28,    30,
      31,    38,    39,    40,    33,    34,    21,    36,   -25,     1,
       6,    43,    44,    45,    46,    47,    48,    49,     7,    24,
      60,    45,    46,    47,    48,    49,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    32,    12,    13,
      14,    15,    21,    51,     8,   115,    16,     9,    10,    11,
      58,    64,    65,    90,    17,    12,    13,    14,    15,    77,
      78,   109,   110,    16,    79,    80,    82,    85,    88,    89,
      97,    17,    49,    91,    92,   116,   117,   104,    93,    60,
      98,    96,   123,   100,   101,   103,   102,   107,   111,    38,
      39,    40,    41,    42,   131,    21,   108,    55,   112,    43,
      44,    45,    46,    47,    48,    49,   113,   118,    38,    39,
      40,    41,    42,   114,   119,   124,   127,    50,    43,    44,
      45,    46,    47,    48,    49,   129,   125,    38,    39,    40,
      41,    42,    36,    23,   128,    95,   105,    43,    44,    45,
      46,    47,    48,    49,    38,    39,    40,    41,    42,   130,
      55,   106,   126,    35,    43,    44,    45,    46,    47,    48,
      49,    38,    39,    40,    41,    42,     0,    59,     0,     0,
       0,    43,    44,    45,    46,    47,    48,    49,    38,    39,
      40,    41,    42,    63,     0,     0,     0,     0,    43,    44,
      45,    46,    47,    48,    49
  };

  const short
  parser::yycheck_[] =
  {
       3,    27,    55,    26,    27,    28,     8,     9,    10,    11,
      12,    12,    13,    14,    16,    17,    19,    38,    39,     3,
      18,    22,    23,    24,    25,    26,    27,    28,     0,    33,
      32,    24,    25,    26,    27,    28,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    33,    17,    18,
      19,    20,    55,    18,     6,   108,    25,     9,    10,    11,
      40,    18,    39,    65,    33,    17,    18,    19,    20,    18,
      38,    97,    98,    25,    34,    37,     7,    18,    34,    37,
      82,    33,    28,    33,    18,   111,   112,    89,     5,    91,
       8,    36,   118,     7,    38,    18,    36,    18,   100,    12,
      13,    14,    15,    16,   130,   108,    35,    35,    18,    22,
      23,    24,    25,    26,    27,    28,    38,    18,    12,    13,
      14,    15,    16,    34,     4,    18,    33,    40,    22,    23,
      24,    25,    26,    27,    28,    34,    36,    12,    13,    14,
      15,    16,    38,     4,   127,    80,    40,    22,    23,    24,
      25,    26,    27,    28,    12,    13,    14,    15,    16,   129,
      35,    91,   121,    19,    22,    23,    24,    25,    26,    27,
      28,    12,    13,    14,    15,    16,    -1,    35,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    12,    13,
      14,    15,    16,    34,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    42,    43,    44,    47,    18,     0,     6,     9,
      10,    11,    17,    18,    19,    20,    25,    33,    45,    46,
      57,    61,    62,    47,    33,    61,    62,    62,    62,    65,
      62,    62,    33,    62,    62,    57,    38,    55,    12,    13,
      14,    15,    16,    22,    23,    24,    25,    26,    27,    28,
      40,    18,    48,    49,    50,    35,    56,    56,    40,    35,
      62,    63,    64,    34,    18,    39,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    18,    38,    34,
      37,    45,     7,    58,    59,    18,    66,    67,    34,    37,
      62,    33,    18,     5,    51,    50,    36,    62,     8,    60,
       7,    38,    36,    18,    62,    40,    63,    18,    35,    56,
      56,    62,    18,    38,    34,    45,    56,    56,    18,     4,
      52,    53,    54,    56,    18,    36,    54,    33,    48,    34,
      55,    56
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    53,    53,    54,    55,    55,    56,    57,    58,    58,
      59,    59,    60,    60,    57,    57,    61,    61,    57,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      64,    62,    57,    65,    65,    57,    66,    66,    67,    67
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,     0,     2,     1,     1,     0,     2,
       1,    10,     1,     0,     1,     3,     3,     2,     0,     1,
       0,     2,     1,     7,     2,     0,     3,     5,     1,     0,
       4,     3,     2,     0,     3,     5,     1,     3,     2,     1,
       1,     1,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     6,     1,     0,     3,
       1,     4,     3,     1,     0,     5,     1,     0,     5,     4
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
  "'<'", "'+'", "'-'", "'*'", "'/'", "'.'", "Abstract", "syntax", "tree",
  "nodes", "'('", "')'", "'{'", "'}'", "','", "':'", "'='", "';'",
  "$accept", "program", "opt_classes", "classes", "opt_statements",
  "statements", "class", "formal_args", "args", "arg", "opt_extends",
  "opt_methods", "methods", "method", "opt_ident", "statement_block",
  "statement", "opt_elif", "more_elif", "opt_else", "l_expr", "r_expr",
  "actual_args", "seq_r_expr", "opt_r_expr", "opt_type_alt",
  "more_type_alt", YY_NULLPTR
  };


  const unsigned short
  parser::yyrline_[] =
  {
       0,    95,    95,   108,   109,   114,   119,   127,   128,   132,
     137,   145,   153,   154,   159,   165,   171,   176,   180,   188,
     189,   194,   199,   206,   211,   215,   222,   226,   231,   232,
     237,   242,   250,   251,   258,   265,   272,   276,   283,   287,
     292,   297,   301,   305,   309,   313,   319,   323,   327,   331,
     335,   339,   343,   347,   351,   353,   357,   361,   362,   367,
     372,   379,   385,   390,   391,   398,   403,   404,   408,   413
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
      33,    34,    26,    24,    37,    25,    28,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    40,
      23,    39,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    29,    30,    31,
      32
    };
    const unsigned user_token_number_max_ = 280;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1597 "quack.tab.cxx" // lalr1.cc:1181
#line 420 "/Users/alonzoaltamirano/Repos/Quack-Compiler/TypeChecker/quack.yxx" // lalr1.cc:1182

#include "Messages.h"

void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}

void dump(AST::ASTNode* n) {
    // std::cout << "*** Building: " << n->str() << std::endl;
}
