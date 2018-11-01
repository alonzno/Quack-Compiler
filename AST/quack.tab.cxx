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
#line 88 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { std::cout << "Finished parse with no errors" << std::endl; }
#line 580 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 4:
#line 92 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 586 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 6:
#line 96 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 592 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 7:
#line 99 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 598 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 8:
#line 101 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 604 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 10:
#line 104 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 610 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 12:
#line 107 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 616 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 14:
#line 110 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 622 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 15:
#line 112 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 628 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 17:
#line 117 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 634 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 18:
#line 119 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 640 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 20:
#line 122 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 646 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 21:
#line 126 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 652 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 22:
#line 130 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 658 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 24:
#line 133 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 664 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 27:
#line 140 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 670 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 28:
#line 144 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 676 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 30:
#line 149 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 682 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 31:
#line 153 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 688 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 32:
#line 157 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 694 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 33:
#line 159 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 700 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 34:
#line 161 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 706 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 35:
#line 165 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 712 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 36:
#line 167 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 718 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 37:
#line 169 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 724 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 38:
#line 171 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 730 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 39:
#line 175 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 736 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 40:
#line 177 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 742 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 41:
#line 181 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 748 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 42:
#line 183 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 754 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 43:
#line 185 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 760 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 44:
#line 187 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 766 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 45:
#line 189 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 772 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 46:
#line 191 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 778 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 47:
#line 193 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 784 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 48:
#line 195 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 790 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 49:
#line 199 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 796 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 51:
#line 202 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 802 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 53:
#line 205 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 808 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 54:
#line 207 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 814 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 55:
#line 211 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 820 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 57:
#line 214 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 826 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 58:
#line 218 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 832 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 59:
#line 220 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 838 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 61:
#line 223 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:870
    { }
#line 844 "quack.tab.cxx" // lalr1.cc:870
    break;


#line 848 "quack.tab.cxx" // lalr1.cc:870
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


  const signed char parser::yypact_ninf_ = -29;

  const signed char parser::yytable_ninf_ = -21;

  const short
  parser::yypact_[] =
  {
     -29,    13,    21,   -29,     7,   120,   -29,    -6,    -1,   213,
     213,   213,   213,   213,     1,   -29,   -29,   213,   213,   -29,
      17,    80,   -29,   -29,   -29,    24,   -29,   138,   138,   201,
      25,   160,    -5,   213,    27,   182,    44,    28,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,    46,
     -29,   120,    36,    38,   -29,   -29,   -29,   -29,   -29,   201,
      41,   -29,   -29,   213,    55,    55,    55,    -5,    -5,    55,
      55,    27,    27,    42,    42,    43,    10,    59,    68,    40,
       8,    11,    53,   -29,    97,   213,    69,   -29,   -29,   -29,
      70,   -29,   -29,   213,    56,   -29,    66,   -29,   213,   -29,
      71,    85,    67,   -29,   138,   -29,    82,   201,   -29,    24,
      99,   -29,    56,    88,    84,   -29,    96,   110,    56,   -29,
     -29
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,     0,     6,     1,     0,     2,     3,     0,     0,     0,
       0,    57,     0,     0,    29,    33,    32,     0,     0,     5,
      34,     0,    58,     6,     7,    10,    34,     0,     0,    56,
       0,     0,    48,    51,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    17,     0,     0,     6,    24,    27,    55,    61,    53,
       0,    40,    19,     0,    42,    43,    41,    46,    47,    45,
      44,    35,    36,    37,    38,    30,     0,     0,    12,     0,
      26,     0,    50,    54,     0,    51,     0,    15,    16,    14,
       0,     8,    21,     0,     0,    22,     0,    59,     0,    28,
       0,     0,     9,    11,     0,    25,     0,    52,    49,    10,
       0,    23,     0,     0,     0,    60,    20,     0,     0,    13,
      18
  };

  const signed char
  parser::yypgoto_[] =
  {
     -29,   -29,   -29,   -11,   -29,   -29,    23,   -29,   -29,   -29,
     -29,   -29,   -18,   -28,   -29,   -29,   -29,    -4,    -7,    49,
     -29,   -29,   -29,   -29
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     2,     5,     6,     7,    53,    91,   102,    24,
      76,    88,    37,    55,    19,    80,    95,    26,    21,    60,
      82,    30,    22,    81
  };

  const signed char
  parser::yytable_[] =
  {
      56,    20,    27,    28,    29,    31,    32,    38,    39,    40,
      34,    35,    51,     3,    86,    93,    94,    43,    44,    45,
      46,    47,    48,    49,     4,     8,    59,    23,    25,    96,
      33,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    52,    79,    87,    97,     9,    20,    36,    10,
      11,    12,   -20,    47,    48,    49,    84,    13,    14,    15,
      16,    57,    62,    63,    75,    17,   105,    77,    78,    18,
      49,    83,    85,    90,    92,    20,   111,    89,    59,    45,
      46,    47,    48,    49,   115,    98,   104,   101,   103,    54,
     120,   107,    38,    39,    40,    41,    42,   106,   118,   110,
     112,   108,    43,    44,    45,    46,    47,    48,    49,    38,
      39,    40,    41,    42,   109,   117,    50,   114,   116,    43,
      44,    45,    46,    47,    48,    49,     9,    36,   119,    10,
      11,    12,   113,    99,   100,     0,     0,    13,    14,    15,
      16,     0,     0,     0,     0,    17,     0,     0,     0,    18,
      38,    39,    40,    41,    42,     0,     0,     0,     0,     0,
      43,    44,    45,    46,    47,    48,    49,     0,     0,     0,
       0,    54,    38,    39,    40,    41,    42,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,    48,    49,     0,
       0,     0,     0,    58,    38,    39,    40,    41,    42,     0,
       0,     0,     0,     0,    43,    44,    45,    46,    47,    48,
      49,     0,    61,    38,    39,    40,    41,    42,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
      13,    14,    15,    16,     0,     0,     0,     0,    17,     0,
       0,     0,    18
  };

  const signed char
  parser::yycheck_[] =
  {
      28,     5,     9,    10,    11,    12,    13,    12,    13,    14,
      17,    18,    23,     0,     4,     7,     8,    22,    23,    24,
      25,    26,    27,    28,     3,    18,    33,    33,    29,    18,
      29,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    18,    54,    34,    34,     6,    51,    31,     9,
      10,    11,    35,    26,    27,    28,    63,    17,    18,    19,
      20,    36,    18,    35,    18,    25,    94,    31,    30,    29,
      28,    30,    29,     5,    34,    79,   104,    18,    85,    24,
      25,    26,    27,    28,   112,    32,    93,    18,    18,    33,
     118,    98,    12,    13,    14,    15,    16,    31,   116,    32,
      18,    30,    22,    23,    24,    25,    26,    27,    28,    12,
      13,    14,    15,    16,    29,    31,    36,    18,    30,    22,
      23,    24,    25,    26,    27,    28,     6,    31,    18,     9,
      10,    11,   109,    36,    85,    -1,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    33,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    33,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    38,    39,     0,     3,    40,    41,    42,    18,     6,
       9,    10,    11,    17,    18,    19,    20,    25,    29,    51,
      54,    55,    59,    33,    46,    29,    54,    55,    55,    55,
      58,    55,    55,    29,    55,    55,    31,    49,    12,    13,
      14,    15,    16,    22,    23,    24,    25,    26,    27,    28,
      36,    40,    18,    43,    33,    50,    50,    36,    33,    55,
      56,    30,    18,    35,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    18,    47,    31,    30,    40,
      52,    60,    57,    30,    55,    29,     4,    34,    48,    18,
       5,    44,    34,     7,     8,    53,    18,    34,    32,    36,
      56,    18,    45,    18,    55,    50,    31,    55,    30,    29,
      32,    50,    18,    43,    18,    50,    30,    31,    49,    18,
      50
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    41,    42,    43,
      43,    44,    44,    45,    45,    46,    47,    47,    48,    49,
      49,    50,    51,    52,    52,    53,    53,    51,    51,    54,
      54,    51,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    55,    51,    58,    58,    51,    59,
      60,    60
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     2,     0,     2,     6,     4,
       0,     2,     0,     5,     0,     4,     2,     0,     7,     2,
       0,     3,     5,     4,     0,     2,     0,     3,     5,     1,
       3,     2,     1,     1,     1,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     6,
       2,     0,     3,     0,     4,     3,     1,     0,     1,     5,
       5,     0
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
  "'<'", "'+'", "'-'", "'*'", "'/'", "'.'", "'('", "')'", "':'", "','",
  "'{'", "'}'", "'='", "';'", "$accept", "program", "classes",
  "statements", "class", "class_signature", "formal_args", "opt_extends",
  "more_idents", "class_body", "methods", "method", "opt_ident",
  "statement_block", "statement", "more_elif", "opt_else", "l_expr",
  "r_expr", "actual_args", "seq_r_expr", "opt_r_expr", "typecase",
  "type_alt", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    88,    88,    91,    92,    95,    96,    99,   101,   103,
     104,   106,   107,   109,   110,   112,   116,   117,   119,   121,
     122,   126,   130,   132,   133,   135,   136,   140,   144,   148,
     149,   153,   157,   159,   161,   165,   167,   169,   171,   175,
     177,   181,   183,   185,   187,   189,   191,   193,   195,   199,
     201,   202,   204,   205,   207,   211,   213,   214,   218,   220,
     222,   223
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
      29,    30,    26,    24,    32,    25,    28,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    36,
      23,    35,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
#line 1285 "quack.tab.cxx" // lalr1.cc:1181
#line 225 "/Users/alonzoaltamirano/Repos/Quack-Compiler/AST/quack.yxx" // lalr1.cc:1182

#include "Messages.h"

void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}

void dump(AST::ASTNode* n) {
    // std::cout << "*** Building: " << n->str() << std::endl;
}
