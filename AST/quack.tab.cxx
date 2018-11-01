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
#line 28 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:416

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
#line 94 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    {
       (yylhs.value.block) = new AST::Block();
       (yylhs.value.block) -> append((yystack_[1].value.block));
       (yylhs.value.block) -> append((yystack_[0].value.stub));
       *root = (yylhs.value.block);
       }
#line 585 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 3:
#line 102 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 591 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 4:
#line 103 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 597 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 5:
#line 105 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.block) = (yystack_[1].value.block);
       (yylhs.value.block) -> append((yystack_[0].value.clazz)); }
#line 605 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 6:
#line 108 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { 
       (yylhs.value.block) = new AST::Block();
       (yylhs.value.block) -> append((yystack_[0].value.clazz));
       }
#line 614 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 8:
#line 115 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { (yylhs.value.stub) = new AST::Stub("No Statements"); }
#line 620 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 9:
#line 116 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { (yylhs.value.stub) = new AST::Stub("Statements"); }
#line 626 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 10:
#line 117 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { (yylhs.value.stub) = new AST::Stub("Statement"); }
#line 632 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 11:
#line 120 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 638 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 12:
#line 122 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 644 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 13:
#line 124 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 650 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 14:
#line 125 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 656 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 15:
#line 127 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 662 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 16:
#line 128 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 668 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 17:
#line 130 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 674 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 18:
#line 132 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 680 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 19:
#line 133 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 686 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 20:
#line 138 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 692 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 22:
#line 143 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 698 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 23:
#line 145 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 704 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 25:
#line 148 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 710 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 26:
#line 152 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 716 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 27:
#line 156 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 722 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 29:
#line 159 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 728 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 32:
#line 166 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 734 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 33:
#line 170 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 740 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 35:
#line 175 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 746 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 36:
#line 179 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 752 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 37:
#line 183 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 758 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 38:
#line 185 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 764 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 39:
#line 187 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 770 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 40:
#line 191 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 776 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 41:
#line 193 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 782 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 42:
#line 195 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 788 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 43:
#line 197 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 794 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 44:
#line 201 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 800 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 45:
#line 203 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 806 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 46:
#line 207 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 812 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 47:
#line 209 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 818 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 48:
#line 211 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 824 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 49:
#line 213 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 830 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 50:
#line 215 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 836 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 51:
#line 217 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 842 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 52:
#line 219 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 848 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 53:
#line 221 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 854 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 54:
#line 225 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 860 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 56:
#line 228 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 866 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 58:
#line 231 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 872 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 59:
#line 233 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 878 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 60:
#line 237 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 884 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 62:
#line 240 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 890 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 63:
#line 244 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 896 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 64:
#line 246 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 902 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 66:
#line 249 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 908 "quack.tab.cxx" // lalr1.cc:870
    break;


#line 912 "quack.tab.cxx" // lalr1.cc:870
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


  const signed char parser::yypact_ninf_ = -25;

  const signed char parser::yytable_ninf_ = -26;

  const short
  parser::yypact_[] =
  {
       9,    12,    31,   111,     9,   -25,    -5,    18,   -25,    -4,
      -4,    -4,    -4,    -4,    19,   -25,   -25,    -4,    -4,   -25,
     111,   -25,   -19,    41,   -25,   -25,   111,   -25,    40,   -25,
     125,   125,   176,    21,   142,   183,    -4,    -3,   159,   -25,
      52,    20,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    53,   -25,   -25,    36,    39,   -25,    42,
     111,   -25,   -25,   -25,   -25,   176,    45,   -25,   -25,    -4,
      22,    22,    22,   183,   183,    22,    22,    -3,    -3,    46,
      46,    43,     6,    57,    75,    40,    44,    11,   -12,    49,
     -25,    87,    -4,    67,   -25,   -25,   -25,    68,   -25,   -25,
     -25,    -4,    51,   -25,    54,   -25,    -4,   -25,    55,    58,
     -25,   125,   -25,    77,   176,   -25,    40,   -25,    51,    59,
     -25,    60,    51,   -25
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,     0,     0,     8,     3,     6,     0,     0,     1,     0,
       0,    62,     0,     0,    34,    38,    37,     0,     0,     2,
       7,    10,    39,     0,    63,     5,     8,    11,    14,    39,
       0,     0,    61,     0,     0,    53,    56,    44,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    22,     0,     0,    13,    15,
       8,    29,    32,    60,    66,    58,     0,    45,    24,     0,
      47,    48,    46,    51,    52,    50,    49,    40,    41,    42,
      43,    35,     0,     0,    19,     0,     0,    31,     0,    55,
      59,     0,    56,     0,    20,    21,    17,     0,    12,    16,
      26,     0,     0,    27,     0,    64,     0,    33,     0,     0,
      18,     0,    30,     0,    57,    54,    14,    28,     0,     0,
      65,    25,     0,    23
  };

  const signed char
  parser::yypgoto_[] =
  {
     -25,   -25,   -25,   -25,   -15,   -25,   100,   -25,   -11,   -25,
      23,   -25,   -25,   -25,   -25,   -14,   -24,    86,   -25,   -25,
       2,    -9,    24,   -25,   -25,   -25,   -25
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    19,    20,     5,     6,    57,    58,
      59,    98,    27,    82,    95,    41,    61,    21,    87,   103,
      29,    23,    66,    89,    33,    24,    88
  };

  const signed char
  parser::yytable_[] =
  {
      30,    31,    32,    34,    35,    22,   104,    62,    37,    38,
      93,    55,     1,    13,    14,    15,    16,    40,   101,   102,
     -25,    17,    22,    51,    52,    53,   105,    65,    22,    18,
       7,     8,    26,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    94,    86,    49,    50,    51,    52,
      53,    28,    36,    42,    43,    44,    45,    46,    56,    69,
      91,    63,    22,    47,    48,    49,    50,    51,    52,    53,
      68,    81,    83,    84,    53,    96,    92,    85,   112,    90,
      97,    54,   100,    65,   106,   109,   110,   117,    60,   115,
     113,   116,   111,   121,   120,   118,    40,   114,   123,    42,
      43,    44,    45,    46,    25,   119,    39,   122,    99,    47,
      48,    49,    50,    51,    52,    53,   108,     9,     0,     0,
      10,    11,    12,     0,     0,     0,     0,   107,    13,    14,
      15,    16,     0,     0,     0,     0,    17,    42,    43,    44,
      45,    46,     0,     0,    18,     0,     0,    47,    48,    49,
      50,    51,    52,    53,    42,    43,    44,    45,    46,     0,
       0,     0,    60,     0,    47,    48,    49,    50,    51,    52,
      53,    42,    43,    44,    45,    46,     0,     0,     0,    64,
       0,    47,    48,    49,    50,    51,    52,    53,    42,    43,
      44,    45,    46,    67,     0,    42,    43,    44,    47,    48,
      49,    50,    51,    52,    53,    47,    48,    49,    50,    51,
      52,    53
  };

  const signed char
  parser::yycheck_[] =
  {
       9,    10,    11,    12,    13,     3,    18,    31,    17,    18,
       4,    26,     3,    17,    18,    19,    20,    36,     7,     8,
      39,    25,    20,    26,    27,    28,    38,    36,    26,    33,
      18,     0,    37,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    38,    60,    24,    25,    26,    27,
      28,    33,    33,    12,    13,    14,    15,    16,    18,    39,
      69,    40,    60,    22,    23,    24,    25,    26,    27,    28,
      18,    18,    36,    34,    28,    18,    33,    35,   102,    34,
       5,    40,    38,    92,    35,    18,    18,   111,    37,    34,
      36,    33,   101,    34,   118,    18,    36,   106,   122,    12,
      13,    14,    15,    16,     4,   116,    20,   121,    85,    22,
      23,    24,    25,    26,    27,    28,    92,     6,    -1,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    40,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    25,    12,    13,    14,
      15,    16,    -1,    -1,    33,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    37,    -1,    22,    23,    24,    25,    26,    27,
      28,    12,    13,    14,    15,    16,    -1,    -1,    -1,    37,
      -1,    22,    23,    24,    25,    26,    27,    28,    12,    13,
      14,    15,    16,    34,    -1,    12,    13,    14,    22,    23,
      24,    25,    26,    27,    28,    22,    23,    24,    25,    26,
      27,    28
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    42,    43,    44,    47,    48,    18,     0,     6,
       9,    10,    11,    17,    18,    19,    20,    25,    33,    45,
      46,    58,    61,    62,    66,    47,    37,    53,    33,    61,
      62,    62,    62,    65,    62,    62,    33,    62,    62,    58,
      36,    56,    12,    13,    14,    15,    16,    22,    23,    24,
      25,    26,    27,    28,    40,    45,    18,    49,    50,    51,
      37,    57,    57,    40,    37,    62,    63,    34,    18,    39,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    18,    54,    36,    34,    35,    45,    59,    67,    64,
      34,    62,    33,     4,    38,    55,    18,     5,    52,    51,
      38,     7,     8,    60,    18,    38,    35,    40,    63,    18,
      18,    62,    57,    36,    62,    34,    33,    57,    18,    49,
      57,    34,    56,    57
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    54,    54,    55,    56,    56,    57,    58,    59,    59,
      60,    60,    58,    58,    61,    61,    58,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    64,    62,
      58,    65,    65,    58,    66,    67,    67
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,     0,     2,     1,     1,     0,     2,
       1,     2,     6,     1,     0,     1,     3,     3,     2,     0,
       4,     2,     0,     7,     2,     0,     3,     5,     4,     0,
       2,     0,     3,     5,     1,     3,     2,     1,     1,     1,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     6,     2,     0,     3,     0,     4,
       3,     1,     0,     1,     5,     5,     0
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
  "nodes", "'('", "')'", "','", "':'", "'{'", "'}'", "'='", "';'",
  "$accept", "program", "opt_classes", "classes", "opt_statements",
  "statements", "class", "class_signature", "formal_args", "args", "arg",
  "opt_extends", "class_body", "methods", "method", "opt_ident",
  "statement_block", "statement", "more_elif", "opt_else", "l_expr",
  "r_expr", "actual_args", "seq_r_expr", "opt_r_expr", "typecase",
  "type_alt", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    94,    94,   102,   103,   105,   108,   114,   115,   116,
     117,   120,   122,   124,   125,   127,   128,   130,   132,   133,
     138,   142,   143,   145,   147,   148,   152,   156,   158,   159,
     161,   162,   166,   170,   174,   175,   179,   183,   185,   187,
     191,   193,   195,   197,   201,   203,   207,   209,   211,   213,
     215,   217,   219,   221,   225,   227,   228,   230,   231,   233,
     237,   239,   240,   244,   246,   248,   249
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
      33,    34,    26,    24,    35,    25,    28,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    40,
      23,    39,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
#line 1345 "quack.tab.cxx" // lalr1.cc:1181
#line 251 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:1182

#include "Messages.h"

void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}

void dump(AST::ASTNode* n) {
    // std::cout << "*** Building: " << n->str() << std::endl;
}
