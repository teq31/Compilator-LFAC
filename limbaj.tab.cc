// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "limbaj.y"


#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include<fstream>
#include "AST.h"
#include "IdList.h"
#include "FunctionList.h"
#include "limbaj.tab.h"
#include "Symbol_Table.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yyleng;
extern int yylex();

void yyerror(const char * s);

using namespace std;

class IdList ids;
class AST ast;
class FunctionList fs;
class ClassList cl;

SymTable* globalTable = new SymTable("global");
SymTable* classTable = nullptr;
SymTable* functionTable = nullptr;
SymTable* blockTable=nullptr;
string scope;
string altscope;


bool isInteger(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (const std::invalid_argument& ia) {
        return false;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}

bool isFloat(const std::string& str) {
    try {
        std::stof(str);
        return true;
    } catch (const std::invalid_argument& ia) {
        return false;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}

bool isBoolean(const std::string& str) {
    return (str == "true" || str == "false");
}


#line 107 "limbaj.tab.cc"


#include "limbaj.tab.hh"




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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 185 "limbaj.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

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
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
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


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // progr: user_defined_data_types global_variables functions main
#line 115 "limbaj.y"
                                                               { 
                                                                    cout <<"The program works!! (ง ͡ʘ ͜ʖ ͡ʘ)ง \n";
                                                                    ids.printVars();
                                                                    fs.printFunctions();
                                                                    cl.printClass();
                                                                    ofstream outFile("symbol_tables.txt");
                                                                    if (!outFile) {
                                                                        cerr << "Nu s-a putut deschide fișierul pentru scriere!" << endl;
                                                                        return 1;
                                                                    }


                                                                    globalTable->print(outFile);

                                                                    outFile.close();
                                                                  cout << "Tabela de simboluri a fost scrisă în symbol_tables.txt" << endl;
                                                               }
#line 657 "limbaj.tab.cc"
    break;

  case 8: // nume: ID
#line 143 "limbaj.y"
          { scope = (yystack_[0].value.string) ;
            altscope=scope;
            classTable = new SymTable(scope, globalTable);
            globalTable->addChild(classTable);
            globalTable->addClass(Class(scope));

            ClassInfo classInfo;
            classInfo.name=(yystack_[0].value.string);
            cl.addClass(classInfo);    }
#line 671 "limbaj.tab.cc"
    break;

  case 11: // param_class: TYPE ID
#line 158 "limbaj.y"
                     {

    (yylhs.value.parameter) = new Parameters((yystack_[1].value.string),(yystack_[0].value.string));
   
}
#line 681 "limbaj.tab.cc"
    break;

  case 12: // list_param_class: param_class
#line 165 "limbaj.y"
                               {
                         (yylhs.value.metoda)=new Function();
                         (yylhs.value.metoda)->parameters.push_back(*(yystack_[0].value.parameter));
                      }
#line 690 "limbaj.tab.cc"
    break;

  case 13: // list_param_class: list_param ',' param
#line 169 "limbaj.y"
                                    {
                                    (yylhs.value.metoda)->parameters.push_back(*(yystack_[0].value.parametru));
                                    }
#line 698 "limbaj.tab.cc"
    break;

  case 15: // methods: TYPE ID '(' list_param_class ')' '{' list1 '}'
#line 175 "limbaj.y"
                                                    {
    FunctionInfo funcInfo;
    funcInfo.name = (yystack_[6].value.string);
    funcInfo.returnType = (yystack_[7].value.string);
    funcInfo.isMethod = !scope.empty(); 
    funcInfo.className = scope; 
    funcInfo.parameters= (yystack_[4].value.metoda)->parameters;
               
    fs.addFunction(funcInfo);

    scope = (yystack_[6].value.string) ;
    SymTable* functionTable = new SymTable(scope, classTable);
    classTable->addChild(functionTable);
    classTable->addFunction(Function((yystack_[6].value.string),(yystack_[7].value.string),(yystack_[4].value.metoda)->parameters));

    
}
#line 720 "limbaj.tab.cc"
    break;

  case 16: // methods: TYPE ID '(' ')' '{' list1 '}'
#line 192 "limbaj.y"
                                  {
    FunctionInfo funcInfo;
    funcInfo.name = (yystack_[5].value.string);
    funcInfo.returnType = (yystack_[6].value.string);
    funcInfo.isMethod = !scope.empty(); 
    funcInfo.className = scope; 
               
    fs.addFunction(funcInfo);
}
#line 734 "limbaj.tab.cc"
    break;

  case 17: // class_instance_declaration: ID ID
#line 203 "limbaj.y"
                                  {
    string className = (yystack_[1].value.string);
    string instanceName = (yystack_[0].value.string);
}
#line 743 "limbaj.tab.cc"
    break;

  case 22: // decl: TYPE ID
#line 216 "limbaj.y"
               { 
                    if(!ids.existsVar((yystack_[0].value.string))) 
                    {   
                        ids.addVar((yystack_[1].value.string),(yystack_[0].value.string),NULL,NULL,NULL,false);
                    }
               }
#line 754 "limbaj.tab.cc"
    break;

  case 28: // decl_func: TYPE ID '(' list_param ')' '{' list1 '}'
#line 235 "limbaj.y"
              {
                altscope = scope; 
                scope = (yystack_[6].value.string); 
            
                if (fs.existsFunction(scope.c_str())) {
                    yyerror("Function redefinition");
                } else {
                    FunctionInfo funcInfo;
                    funcInfo.name = (yystack_[6].value.string);
                    funcInfo.returnType = (yystack_[7].value.string);
                    funcInfo.isMethod = scope.empty(); 
                    funcInfo.parameters= (yystack_[4].value.functie)->parameters;
                    
                    fs.addFunction(funcInfo);
                 }
                scope = altscope; 
              }
#line 776 "limbaj.tab.cc"
    break;

  case 29: // decl_func: TYPE ID '(' ')' '{' list1 '}'
#line 253 "limbaj.y"
              {
                altscope = scope; 
                scope = (yystack_[5].value.string); 

                if (fs.existsFunction(scope.c_str())) {
                    yyerror("Function redefinition");
                } else {
                    FunctionInfo funcInfo;
                    funcInfo.name = (yystack_[5].value.string);
                    funcInfo.returnType = (yystack_[6].value.string);
                    fs.addFunction(funcInfo);
                 }
                scope = altscope; 
              }
#line 795 "limbaj.tab.cc"
    break;

  case 30: // list_param: param
#line 269 "limbaj.y"
                      {
                         (yylhs.value.functie)=new FunctionInfo;
                         (yylhs.value.functie)->parameters.push_back(*(yystack_[0].value.parametru));
                      }
#line 804 "limbaj.tab.cc"
    break;

  case 31: // list_param: list_param ',' param
#line 273 "limbaj.y"
                                    {
                                    (yylhs.value.functie)->parameters.push_back(*(yystack_[0].value.parametru));
                                    }
#line 812 "limbaj.tab.cc"
    break;

  case 32: // param: TYPE ID
#line 278 "limbaj.y"
                {
                     (yylhs.value.parametru) = new ParamInfo;    
                     (yylhs.value.parametru)->type = (yystack_[1].value.string);
                     (yylhs.value.parametru)->name = (yystack_[0].value.string);
                }
#line 822 "limbaj.tab.cc"
    break;

  case 63: // list: list IF '(' expression ')' '{' list '}'
#line 329 "limbaj.y"
                                                {
                                                    if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                        {
                                                            yyerror("'if' accepts only boolean expressions");
                                                        }
                                                }
#line 833 "limbaj.tab.cc"
    break;

  case 64: // list: list IF '(' expression ')' '{' list '}' ELSE '{' list '}'
#line 335 "limbaj.y"
                                                                 {
                                                                       if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                                            {
                                                                                yyerror("'if' accepts only boolean expressions");
                                                                            }
                                                                 }
#line 844 "limbaj.tab.cc"
    break;

  case 65: // list: list WHILE '(' expression ')' '{' list '}'
#line 341 "limbaj.y"
                                                  {
                                                        if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                            {
                                                                 yyerror("'while' accepts only boolean expressions");
                                                            }
                                                  }
#line 855 "limbaj.tab.cc"
    break;

  case 72: // statement: ID '(' list_param_call ')'
#line 355 "limbaj.y"
                                     {
            FunctionInfo *func = fs.getFunction((yystack_[3].value.string)); // presupunem că există o metodă getFunction care returnează informații despre funcția cu numele dat
            if (func == nullptr) {
                yyerror(("Undefined function: " + std::string((yystack_[3].value.string))).c_str());
            } else {
                if (func->parameters.size() != (yystack_[1].value.functie)->parameters.size()) {
                    yyerror(("Incorrect number of arguments for function: " + std::string((yystack_[3].value.string))).c_str());
                } else {
                    for (size_t i = 0; i < func->parameters.size(); ++i) {
                        if (func->parameters[i].type != (yystack_[1].value.functie)->parameters[i].type) {
                            yyerror(("Argument type mismatch in function " + std::string((yystack_[3].value.string)) + " for parameter " + std::to_string(i+1) + ": expected " + func->parameters[i].type + ", got " + (yystack_[1].value.functie)->parameters[i].type).c_str());
                        }
                    }
                }
            }
        }
#line 876 "limbaj.tab.cc"
    break;

  case 73: // statement_print: print
#line 374 "limbaj.y"
                       {
                         cout << ast.evaluateTree() << endl; ast.printTree(); 
                     }
#line 884 "limbaj.tab.cc"
    break;

  case 74: // statement_typeof: expression
#line 379 "limbaj.y"
                             {  
                                cout << "TypeOf value: ";
                                string resultValue = ast.evaluateTree();

                                if (isInteger(resultValue)) {
                                    cout << "Integer" << endl;
                                } else if (isFloat(resultValue)) {
                                    cout << "Float" << endl;
                                } else if (isBoolean(resultValue)) {
                                    cout << "Boolean" << endl;
                                } else {
                                    cout << "Unknown" << endl;
                                }

                               ast.printTree();         
                             }
#line 905 "limbaj.tab.cc"
    break;

  case 75: // list_param_call: list_param_call ',' param_call
#line 397 "limbaj.y"
                                                {
                                    (yylhs.value.functie)->parameters.push_back(*(yystack_[0].value.parametru));
                                    }
#line 913 "limbaj.tab.cc"
    break;

  case 76: // list_param_call: param_call
#line 400 "limbaj.y"
                            {
                         (yylhs.value.functie)=new FunctionInfo;
                         (yylhs.value.functie)->parameters.push_back(*(yystack_[0].value.parametru));
                      }
#line 922 "limbaj.tab.cc"
    break;

  case 77: // param_call: INT
#line 406 "limbaj.y"
                    { (yylhs.value.parametru)=new ParamInfo; (yylhs.value.parametru)->type="int"; }
#line 928 "limbaj.tab.cc"
    break;

  case 78: // param_call: FLOAT
#line 407 "limbaj.y"
                   { (yylhs.value.parametru)=new ParamInfo; (yylhs.value.parametru)->type="float"; }
#line 934 "limbaj.tab.cc"
    break;

  case 79: // param_call: BOOL
#line 408 "limbaj.y"
                  { (yylhs.value.parametru)=new ParamInfo; (yylhs.value.parametru)->type="bool"; }
#line 940 "limbaj.tab.cc"
    break;

  case 80: // param_call: ID
#line 409 "limbaj.y"
                    { 
            if(!ids.existsVar((yystack_[0].value.string))){string err="Variable '"+string((yystack_[0].value.string))+"' was not declared!"; yyerror(err.c_str());}
            else {(yylhs.value.parametru)=new ParamInfo; (yylhs.value.parametru)->type=ids.TypeOf((yystack_[0].value.string));}       
                    }
#line 949 "limbaj.tab.cc"
    break;

  case 81: // declarations: TYPE ID
#line 415 "limbaj.y"
                     {   
                        if(!ids.existsVar((yystack_[0].value.string)))   
                            {   
                               ids.addVar((yystack_[1].value.string),(yystack_[0].value.string),NULL,NULL,NULL,false);
                             
                            }
                     }
#line 961 "limbaj.tab.cc"
    break;

  case 82: // declarations: TYPE ID '[' INT ']' ASSIGN '{' array_list '}'
#line 423 "limbaj.y"
                            {
                                char* token = strtok((yystack_[1].value.string), " ");
                                int index = 0;
                                while (token != NULL) 
                                    {
                                        if (token[0] != '\0') 
                                            {
                                                ids.addVar((yystack_[8].value.string), (string((yystack_[7].value.string)) + "[" + to_string(index) + "]").c_str(), token, NULL, NULL, false);
                                                index++;
                                                if(index>(yystack_[5].value.num))
                                                    {   
                                                        string err="Array's '"+string((yystack_[7].value.string))+"' max size is: "+to_string((yystack_[5].value.num));
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        token = strtok(NULL, " ");
                                    }
                            }
#line 984 "limbaj.tab.cc"
    break;

  case 83: // array_list: array_list ',' INT
#line 444 "limbaj.y"
                {
                     (yylhs.value.string) = (char*)malloc(strlen((yystack_[2].value.string)) + strlen(to_string((yystack_[0].value.num)).c_str()) + 2); 
                     strcpy((yylhs.value.string), (yystack_[2].value.string));
                     strcat((yylhs.value.string), to_string((yystack_[0].value.num)).c_str());
                     strcat((yylhs.value.string), " ");
                }
#line 995 "limbaj.tab.cc"
    break;

  case 84: // array_list: array_list ',' FLOAT
#line 451 "limbaj.y"
                {
                     (yylhs.value.string) = (char*)malloc(strlen((yystack_[2].value.string)) + strlen(to_string((yystack_[0].value.num_with_dot)).c_str()) + 2); 
                     strcpy((yylhs.value.string), (yystack_[2].value.string));
                     strcat((yylhs.value.string), to_string((yystack_[0].value.num_with_dot)).c_str());
                     strcat((yylhs.value.string), " ");
                }
#line 1006 "limbaj.tab.cc"
    break;

  case 85: // array_list: INT
#line 458 "limbaj.y"
                {
                     (yylhs.value.string) = strdup(to_string((yystack_[0].value.num)).c_str()); strcat((yylhs.value.string)," ");
                }
#line 1014 "limbaj.tab.cc"
    break;

  case 86: // array_list: FLOAT
#line 462 "limbaj.y"
                {
                     (yylhs.value.string) = strdup(to_string((yystack_[0].value.num_with_dot)).c_str()); strcat((yylhs.value.string)," ");
                }
#line 1022 "limbaj.tab.cc"
    break;

  case 87: // assignments: ID ASSIGN ID
#line 469 "limbaj.y"
                        {    
                              if(!ids.existsVar((yystack_[2].value.string)))
                                    { 
                                        string err="Variable '"+string((yystack_[2].value.string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(!ids.existsVar((yystack_[0].value.string)))
                                    { 
                                        string err="Variable '"+string((yystack_[0].value.string))+"' was not declared ";   
                                        yyerror(err.c_str());
                                    }
                              else if(ids.TypeOf((yystack_[2].value.string))!=ids.TypeOf((yystack_[0].value.string))) 
                                    {   
                                        string err="Variables '"+string((yystack_[2].value.string))+"' and '"+string((yystack_[0].value.string))+"' have different types";    
                                        yyerror(err.c_str());
                                    }
                              else  { 
                                        string val=ids.get_val((yystack_[0].value.string));
                                        ids.addVal((yystack_[2].value.string),val.c_str());
                                    }     
                        }
#line 1048 "limbaj.tab.cc"
    break;

  case 88: // assignments: ID ASSIGN INT
#line 491 "limbaj.y"
                        { 
                              if(!ids.existsVar((yystack_[2].value.string)))
                                    {
                                        string err="Variable '"+string((yystack_[2].value.string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yystack_[2].value.string))!="int")
                                    {
                                        string err="Cannot assign 'int' to an '"+ids.TypeOf((yystack_[2].value.string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal((yystack_[2].value.string),to_string((yystack_[0].value.num)).c_str());
                                    }             
                        }
#line 1068 "limbaj.tab.cc"
    break;

  case 89: // assignments: ID ASSIGN FLOAT
#line 507 "limbaj.y"
                        { 
                              if(!ids.existsVar((yystack_[2].value.string)))
                                    { 
                                        string err="Variable '"+string((yystack_[2].value.string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yystack_[2].value.string))!="float")
                                    {
                                        string err="Cannot assign 'float' to an '"+ids.TypeOf((yystack_[2].value.string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal((yystack_[2].value.string),to_string((yystack_[0].value.num_with_dot)).c_str());
                                    }             
                        }
#line 1088 "limbaj.tab.cc"
    break;

  case 90: // assignments: ID ASSIGN BOOL
#line 523 "limbaj.y"
                        {   
                              if(!ids.existsVar((yystack_[2].value.string)))
                                    {
                                        string err="Variable '"+string((yystack_[2].value.string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yystack_[2].value.string))!="bool")
                                    {
                                        string err="Cannot assign 'bool' to an'"+ids.TypeOf((yystack_[2].value.string))+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal((yystack_[2].value.string),to_string((yystack_[0].value.bolean)).c_str()? "true" : "false");
                                    }             
                        }
#line 1108 "limbaj.tab.cc"
    break;

  case 91: // assignments: ID ASSIGN CHAR
#line 539 "limbaj.y"
                        { 
                              if(!ids.existsVar((yystack_[2].value.string)))
                                    { 
                                        string err="Variable '"+string((yystack_[2].value.string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yystack_[2].value.string))!="char")
                                    {
                                        string err="Cannot assign 'char' to an '"+ids.TypeOf((yystack_[2].value.string))+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        string str(1,(yystack_[0].value.chr));ids.addVal((yystack_[2].value.string),str.c_str());
                                    }             
                        }
#line 1128 "limbaj.tab.cc"
    break;

  case 92: // assignments: ID ASSIGN STRING
#line 555 "limbaj.y"
                        {   
                              if(!ids.existsVar((yystack_[2].value.string)))
                                    { 
                                        string err="Variable '"+string((yystack_[2].value.string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yystack_[2].value.string))!="string")
                                    {
                                        string err="Cannot assign 'string' to an'"+ids.TypeOf((yystack_[2].value.string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal((yystack_[2].value.string),(yystack_[0].value.string));
                                    }             
                        }
#line 1148 "limbaj.tab.cc"
    break;

  case 93: // assignments: ID '[' INT ']' ASSIGN INT
#line 571 "limbaj.y"
                        {
                              string id=string((yystack_[5].value.string))+"["+to_string((yystack_[3].value.num))+"]";
                              if(!ids.existsVar(id.c_str()))
                                    {
                                         string err="Variable '"+ string(id.c_str())+"' was not declared ";
                                         yyerror(err.c_str());
                                    }
                              if(ids.TypeOf(id.c_str())!="int")
                                    {
                                         string err="Cannot assign 'int' to an '"+ids.TypeOf(id.c_str())+"'";
                                         yyerror(err.c_str());
                                    }
                              else  {
                                         ids.addVal(id.c_str(),to_string((yystack_[0].value.num)).c_str());
                                    }
                        }
#line 1169 "limbaj.tab.cc"
    break;

  case 94: // assignments: CONST TYPE ID
#line 588 "limbaj.y"
                    { yyerror("Constant must have value assigned at declaration!");}
#line 1175 "limbaj.tab.cc"
    break;

  case 95: // assignments: CONST TYPE ID ASSIGN INT
#line 590 "limbaj.y"
                                    {   
                                         if(!ids.existsVar((yystack_[2].value.string)))   
                                             {        
                                                if(strcmp((yystack_[3].value.string),"int")==0)
                                                    {
                                                        ids.addVar((yystack_[3].value.string),(yystack_[2].value.string),to_string((yystack_[0].value.num)).c_str(),NULL,NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yystack_[2].value.string)) + " has type " + (yystack_[3].value.string) + ", assigned value has type int"; 
                                                        yyerror(err.c_str());
                                                    }
                                             }                    
                                         else 
                                             {  
                                                yyerror("variable already declared");
                                             }
                                    }
#line 1198 "limbaj.tab.cc"
    break;

  case 96: // assignments: CONST TYPE ID ASSIGN FLOAT
#line 609 "limbaj.y"
                                    {   
                                        if(!ids.existsVar((yystack_[2].value.string)))   
                                            {   
                                                if(strcmp((yystack_[3].value.string),"float")==0)
                                                    {
                                                        ids.addVar((yystack_[3].value.string),(yystack_[2].value.string),to_string((yystack_[0].value.num_with_dot)).c_str(),NULL,NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yystack_[3].value.string)) + " has type " + (yystack_[3].value.string) + ", assigned value has type float"; 
                                                        yyerror(err.c_str());
                                                    }
                                            }                    
                                        else 
                                            {  
                                                yyerror("variable already declared");
                                            }    

                                    }
#line 1222 "limbaj.tab.cc"
    break;

  case 97: // assignments: CONST TYPE ID ASSIGN BOOL
#line 629 "limbaj.y"
                                    { 
                                        if (!ids.existsVar((yystack_[2].value.string))) 
                                            {
                                                if (strcmp((yystack_[3].value.string), "bool") == 0) 
                                                    {
                                                        ids.addVar((yystack_[3].value.string), (yystack_[2].value.string), (yystack_[0].value.bolean) ? "true" : "false", NULL, NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yystack_[2].value.string)) + " has type " + (yystack_[3].value.string) + ", assigned value has type bool";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
#line 1245 "limbaj.tab.cc"
    break;

  case 98: // assignments: CONST TYPE ID ASSIGN CHAR
#line 648 "limbaj.y"
                                    {
                                        if (!ids.existsVar((yystack_[2].value.string))) 
                                            {
                                                if (strcmp((yystack_[3].value.string), "char") == 0) 
                                                    {
                                                        string str(1,(yystack_[0].value.chr));
                                                        ids.addVar((yystack_[3].value.string), (yystack_[2].value.string), str.c_str(), NULL, NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yystack_[2].value.string)) + " has type " + (yystack_[3].value.string) + ", assigned value has type char";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
#line 1269 "limbaj.tab.cc"
    break;

  case 99: // assignments: CONST TYPE ID ASSIGN STRING
#line 668 "limbaj.y"
                                    {
                                        if (!ids.existsVar((yystack_[2].value.string))) 
                                            {
                                                if (strcmp((yystack_[3].value.string), "string") == 0) 
                                                    {
                                                        ids.addVar((yystack_[3].value.string), (yystack_[2].value.string), (yystack_[0].value.string), NULL, NULL,true);
                                                    } 
                                                else 
                                                    {
                                                        string err = "Constant " + string((yystack_[2].value.string)) + " has type " + (yystack_[3].value.string) + ", assigned value has type string";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }                                            
                                    }
#line 1292 "limbaj.tab.cc"
    break;

  case 100: // print: '(' expression ')'
#line 690 "limbaj.y"
        {
           (yylhs.value.nod) = (yystack_[1].value.nod);  
        }
#line 1300 "limbaj.tab.cc"
    break;

  case 101: // expression: expression '+' expression
#line 696 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                            {
                                string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' + '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yylhs.value.nod) = new Node { (yystack_[2].value.nod), (yystack_[0].value.nod), "+",(yystack_[2].value.nod)->type }; 
                        ast.AddNode("+",(yystack_[2].value.nod),(yystack_[0].value.nod),(yystack_[2].value.nod)->type);
                    }
#line 1318 "limbaj.tab.cc"
    break;

  case 102: // expression: expression '-' expression
#line 710 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type) 
                            {
                                string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' - '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yylhs.value.nod) = new Node { (yystack_[2].value.nod), (yystack_[0].value.nod), "-",(yystack_[2].value.nod)->type }; 
                        ast.AddNode("-",(yystack_[2].value.nod),(yystack_[0].value.nod),(yystack_[2].value.nod)->type);
                    }
#line 1336 "limbaj.tab.cc"
    break;

  case 103: // expression: expression '*' expression
#line 724 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")  
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                            {
                                string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' * '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yylhs.value.nod) = new Node { (yystack_[2].value.nod), (yystack_[0].value.nod), "*",(yystack_[2].value.nod)->type }; 
                        ast.AddNode("*",(yystack_[2].value.nod),(yystack_[0].value.nod),(yystack_[2].value.nod)->type);
                    }
#line 1354 "limbaj.tab.cc"
    break;

  case 104: // expression: expression '/' expression
#line 738 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                            {   
                                string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' / '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yylhs.value.nod) = new Node { (yystack_[2].value.nod), (yystack_[0].value.nod), "/",(yystack_[2].value.nod)->type }; 
                        ast.AddNode("/",(yystack_[2].value.nod),(yystack_[0].value.nod),(yystack_[2].value.nod)->type);}
#line 1371 "limbaj.tab.cc"
    break;

  case 105: // expression: expression '^' expression
#line 751 "limbaj.y"
                   { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                            {
                                string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' ^ '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod), "^",(yystack_[2].value.nod)->type}; 
                        ast.AddNode("^",(yystack_[2].value.nod),(yystack_[0].value.nod),(yystack_[2].value.nod)->type);
                    }
#line 1389 "limbaj.tab.cc"
    break;

  case 106: // expression: expression AND expression
#line 765 "limbaj.y"
                   {
                        if((yystack_[2].value.nod)->type=="int"||(yystack_[2].value.nod)->type=="float"||(yystack_[0].value.nod)->type=="int"||(yystack_[0].value.nod)->type=="float")
                            {
                                string err="Operation && only supports bool operands ! '"+(yystack_[2].value.nod)->type+"' && '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                            (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod),"&&",(yystack_[2].value.nod)->type}; 
                            ast.AddNode("&&",(yystack_[2].value.nod),(yystack_[0].value.nod),(yystack_[2].value.nod)->type);
                    }
#line 1403 "limbaj.tab.cc"
    break;

  case 107: // expression: expression OR expression
#line 775 "limbaj.y"
                   {
                         if((yystack_[2].value.nod)->type=="int"||(yystack_[2].value.nod)->type=="float"||(yystack_[0].value.nod)->type=="int"||(yystack_[0].value.nod)->type=="float")
                            {
                                string err="Operation || only supports bool operands ! '"+(yystack_[2].value.nod)->type+"' || '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                            (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod),"||",(yystack_[2].value.nod)->type}; 
                            ast.AddNode("||",(yystack_[2].value.nod),(yystack_[0].value.nod),(yystack_[2].value.nod)->type);
                    }
#line 1417 "limbaj.tab.cc"
    break;

  case 108: // expression: NOT expression
#line 785 "limbaj.y"
                    {
                        if((yystack_[0].value.nod)->type=="int"||(yystack_[0].value.nod)->type=="float")
                            {
                                string err="Operation ! only supports bool operand! !'"+(yystack_[0].value.nod)->type+"''";
                                yyerror(err.c_str());
                            }
                            (yylhs.value.nod) = new Node{(yystack_[0].value.nod), NULL,"!",(yystack_[0].value.nod)->type}; 
                            ast.AddNode("!",(yystack_[0].value.nod),NULL,(yystack_[0].value.nod)->type); }
#line 1430 "limbaj.tab.cc"
    break;

  case 109: // expression: expression LT expression
#line 794 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                            { 
                                string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' < '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                            (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod), "<","bool"}; 
                            ast.AddNode("<",(yystack_[2].value.nod),(yystack_[0].value.nod),"bool");}
#line 1447 "limbaj.tab.cc"
    break;

  case 110: // expression: expression LE expression
#line 807 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                            {
                                string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' <= '"+(yystack_[0].value.nod)->type+"'";
                                yyerror(err.c_str());
                            }
                            (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod), "<=","bool"}; 
                            ast.AddNode("<=",(yystack_[2].value.nod),(yystack_[0].value.nod),"bool");}
#line 1464 "limbaj.tab.cc"
    break;

  case 111: // expression: expression GT expression
#line 820 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                        {
                            string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' > '"+(yystack_[0].value.nod)->type+"'";
                            yyerror(err.c_str());
                        }
                        (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod), ">","bool"}; 
                        ast.AddNode(">",(yystack_[2].value.nod),(yystack_[0].value.nod),"bool");}
#line 1481 "limbaj.tab.cc"
    break;

  case 112: // expression: expression GE expression
#line 833 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                        {
                            string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' >= '"+(yystack_[0].value.nod)->type+"'";
                            yyerror(err.c_str());
                        }
                        (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod), ">=","bool"}; 
                        ast.AddNode(">=",(yystack_[2].value.nod),(yystack_[0].value.nod),"bool");}
#line 1498 "limbaj.tab.cc"
    break;

  case 113: // expression: expression EQ expression
#line 846 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                        {
                            string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' == '"+(yystack_[0].value.nod)->type+"'";
                            yyerror(err.c_str());
                        }
                        (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod), "==","bool"}; 
                        ast.AddNode("==",(yystack_[2].value.nod),(yystack_[0].value.nod),"bool");
                    }
#line 1516 "limbaj.tab.cc"
    break;

  case 114: // expression: expression NEQ expression
#line 860 "limbaj.y"
                    { 
                        if((yystack_[2].value.nod)->type=="bool"||(yystack_[0].value.nod)->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if((yystack_[2].value.nod)->type!=(yystack_[0].value.nod)->type)
                        {
                            string err="Operands have different types! '"+(yystack_[2].value.nod)->type+"' != '"+(yystack_[0].value.nod)->type+"'";
                            yyerror(err.c_str());
                        }
                        (yylhs.value.nod) = new Node{(yystack_[2].value.nod), (yystack_[0].value.nod), "!=","bool"}; 
                        ast.AddNode("!=",(yystack_[2].value.nod),(yystack_[0].value.nod),"bool");}
#line 1533 "limbaj.tab.cc"
    break;

  case 115: // expression: '(' expression ')'
#line 873 "limbaj.y"
                        {
                            (yylhs.value.nod)=(yystack_[1].value.nod);
                        }
#line 1541 "limbaj.tab.cc"
    break;

  case 116: // expression: INT
#line 877 "limbaj.y"
                        { 
                            (yylhs.value.nod) = new Node{NULL, NULL, to_string((yystack_[0].value.num)),"int"}; 
                            ast.AddNode(to_string((yystack_[0].value.num)),NULL,NULL,"int");
                        }
#line 1550 "limbaj.tab.cc"
    break;

  case 117: // expression: FLOAT
#line 882 "limbaj.y"
                        {
                            (yylhs.value.nod)=new Node{NULL,NULL,to_string((yystack_[0].value.num_with_dot)),"float"};
                            ast.AddNode(to_string((yystack_[0].value.num_with_dot)),NULL,NULL,"float");
                        }
#line 1559 "limbaj.tab.cc"
    break;

  case 118: // expression: BOOL
#line 887 "limbaj.y"
                        {
                            (yylhs.value.nod)=new Node{NULL,NULL,(yystack_[0].value.bolean)?"true":"false","bool"};
                            ast.AddNode((yystack_[0].value.bolean)?"true":"false",NULL,NULL,"bool");
                        }
#line 1568 "limbaj.tab.cc"
    break;

  case 119: // expression: STRING
#line 892 "limbaj.y"
                        {
                             (yylhs.value.nod)=new Node{NULL,NULL,(yystack_[0].value.string),"string"};
                             ast.AddNode((yystack_[0].value.string),NULL,NULL,"string");
                        }
#line 1577 "limbaj.tab.cc"
    break;

  case 120: // expression: ID
#line 897 "limbaj.y"
                        {
                        if(!ids.existsVar((yystack_[0].value.string)))
                            {
                                string err="Variable '"+string((yystack_[0].value.string))+"' was not declared!";
                                yyerror(err.c_str());
                            }
                        (yylhs.value.nod)=new Node{NULL,NULL,ids.get_val((yystack_[0].value.string)),ids.TypeOf((yystack_[0].value.string))}; 
                        ast.AddNode(ids.get_val((yystack_[0].value.string)),NULL,NULL,ids.TypeOf((yystack_[0].value.string)));
                        }
#line 1591 "limbaj.tab.cc"
    break;


#line 1595 "limbaj.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
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
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short parser::yypact_ninf_ = -156;

  const signed char parser::yytable_ninf_ = -33;

  const short
  parser::yypact_[] =
  {
      34,  -156,    17,    29,     1,  -156,  -156,    35,  -156,    53,
    -156,    18,  -156,    80,  -156,    41,  -156,    64,    70,  -156,
      56,    11,  -156,  -156,  -156,  -156,  -156,  -156,  -156,    78,
    -156,   190,    79,    69,  -156,    85,    77,    89,    91,    95,
       0,   130,    -6,   115,  -156,  -156,   134,   120,   124,    -5,
     144,    -6,    -6,   146,    -6,  -156,  -156,   305,    22,   148,
     138,    -6,  -156,  -156,  -156,  -156,  -156,    -6,  -156,   273,
    -156,   142,  -156,   141,   164,   152,   -30,  -156,   187,   207,
     215,   195,   162,   240,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,    -4,  -156,   171,   186,  -156,   248,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,     5,  -156,  -156,  -156,   196,   214,   335,
     203,   205,   193,   211,  -156,  -156,    22,   269,   231,  -156,
     334,   334,   334,   334,   310,   310,   304,   281,   182,   182,
     241,   241,  -156,   256,   244,  -156,   264,   259,   126,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,   261,  -156,
    -156,   284,   311,   267,  -156,   288,   214,   307,   312,   336,
     337,   340,   325,  -156,   328,   136,     2,    60,   349,    73,
    -156,   338,   147,  -156,   331,   375,    43,    43,   146,   324,
    -156,  -156,  -156,   371,  -156,   131,  -156,    90,  -156,   157,
     352,  -156,  -156,  -156,  -156,   342,   341,   343,   344,  -156,
    -156,  -156,  -156,  -156,  -156,   345,   357,   358,   359,   361,
    -156,  -156,    30,  -156,  -156,   347,    43,    43,    43,    43,
      43,    43,   348,   350,  -156,   351,   353,   354,   355,  -156,
     109,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
      87,   367,   369,   370,   372,  -156,  -156,   168,   100,   114,
    -156,   368,   373,   366,   374,   395,  -156,  -156,  -156,  -156,
    -156,  -156,   362,  -156,   178,  -156
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     5,     0,    18,     0,     1,    20,    24,     4,     0,
       6,     0,    26,     0,     8,     0,    19,     0,     0,    23,
       0,     0,    67,     2,    10,    17,    22,    21,    25,     0,
      27,     0,    14,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    73,     0,     0,     0,
      81,     0,   120,   116,   117,   118,   119,     0,    71,    74,
      62,    11,     9,     0,     0,     0,     0,    30,    94,     0,
       0,     0,     0,     0,    87,    88,    89,    90,    91,    92,
      80,    77,    78,    79,     0,    76,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,    32,    38,     0,     0,     0,
       0,     0,     0,     0,   100,    72,     0,     0,     0,   115,
     109,   110,   111,   112,   113,   114,   106,   107,   101,   102,
     103,   104,   105,     0,     0,    12,     0,     0,     0,    38,
      31,    95,    96,    97,    98,    99,    67,    67,     0,    67,
      75,     0,     0,    11,    38,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    38,    13,     0,     0,     0,     0,     0,
      39,    33,    28,    63,    65,     0,    66,     0,    16,     0,
       0,    57,    58,    59,    60,     0,     0,     0,     0,    40,
      41,    42,    45,    44,    43,     0,     0,     0,     0,     0,
      85,    86,     0,    15,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,    82,
       0,    38,    48,    50,    47,    49,    51,    52,    67,    67,
       0,     0,     0,     0,     0,    83,    84,     0,     0,     0,
      64,     0,     0,     0,     0,    34,    36,    37,    53,    54,
      55,    56,     0,    38,     0,    35
  };

  const short
  parser::yypgoto_[] =
  {
    -156,  -156,  -156,  -156,  -156,  -156,  -156,   293,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,   295,  -115,  -149,
    -156,   223,   224,   -18,  -156,  -155,  -156,  -156,  -156,  -156,
     287,  -156,  -156,  -156,  -156,   -45
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,    10,    15,    32,    47,   146,    48,
      19,     7,    11,    20,    13,    21,    30,    76,    77,   148,
     174,   205,    82,   206,    23,    31,    43,    55,    68,    94,
      95,    44,   222,    45,    56,    69
  };

  const short
  parser::yytable_[] =
  {
     175,   176,   177,   150,   179,    57,    79,    80,     8,    83,
      35,    36,   117,    37,    38,   182,    98,     5,   118,    39,
      61,    62,    99,    74,    63,    64,    65,    28,    66,    40,
      41,    42,    16,   143,   199,    67,     9,    75,   125,    29,
       1,    58,     6,    59,   126,    17,    18,   144,   193,    90,
      12,   184,    91,    92,    93,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    35,    36,
     201,    37,    38,   202,   203,   204,   239,    39,   240,   250,
      14,    35,    36,    22,    37,    38,    24,    40,    41,    42,
      39,    25,   257,   258,   259,    35,    36,    26,    37,    38,
      40,    41,    42,    27,    39,    33,   194,    46,    35,    36,
      49,    37,    38,    50,    40,    41,    42,    39,    51,   196,
     220,   221,    35,    36,   274,    37,    38,    40,    41,    42,
      52,    39,    53,   260,   167,   168,    54,   169,   170,   255,
     256,    40,    41,    42,   167,   168,   266,   169,   170,   216,
     217,   218,   219,   171,   172,   167,   168,    60,   169,   170,
     267,    71,    70,   171,   172,   167,   168,    72,   169,   170,
      73,    78,   173,    81,   171,   172,   167,   168,    96,   169,
     170,    97,   192,   113,   171,   172,   167,   168,   114,   169,
     170,   115,   119,   198,    34,   171,   172,   116,    35,    36,
     122,    37,    38,   223,   123,   171,   172,    39,   242,   243,
     244,   245,   246,   247,   265,   127,   128,    40,    41,    42,
     110,   111,   112,   158,   275,   100,   101,   102,   103,   104,
     105,   106,   107,   100,   101,   102,   103,   104,   105,   106,
     107,   149,    74,   108,   109,   110,   111,   112,   156,   120,
     157,   108,   109,   110,   111,   112,   159,   121,   100,   101,
     102,   103,   104,   105,   106,   107,   100,   101,   102,   103,
     104,   105,   106,   107,   161,   162,   108,   109,   110,   111,
     112,   112,   124,   163,   108,   109,   110,   111,   112,   164,
     129,   100,   101,   102,   103,   104,   105,   106,   107,   100,
     101,   102,   103,   104,   105,   106,   165,   166,   178,   108,
     109,   110,   111,   112,   180,   -32,   181,   108,   109,   110,
     111,   112,   100,   101,   102,   103,   104,   105,   100,   101,
     102,   103,    84,   183,   185,    85,    86,    87,    88,    89,
     108,   109,   110,   111,   112,   189,   108,   109,   110,   111,
     112,   209,   190,   186,   210,   211,   212,   213,   214,   226,
     227,   228,   229,   230,   231,   151,   152,   153,   154,   155,
     108,   109,   110,   111,   112,   191,   195,   187,   188,   -31,
     200,   215,   224,   197,   225,   232,   233,   235,   236,   237,
     234,   238,   241,   248,   261,   249,   262,   263,   251,   264,
     252,   253,   254,   270,   268,   272,   145,   273,   147,   269,
     207,   271,   208,   160
  };

  const short
  parser::yycheck_[] =
  {
     149,   156,   157,   118,   159,     5,    51,    52,     7,    54,
       8,     9,    42,    11,    12,   164,    61,     0,    48,    17,
      26,    27,    67,    28,    30,    31,    32,    16,    34,    27,
      28,    29,    14,    28,   183,    41,    35,    42,    42,    28,
       6,    41,    13,    43,    48,    27,    28,    42,    46,    27,
      15,   166,    30,    31,    32,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     8,     9,
      27,    11,    12,    30,    31,    32,    46,    17,    48,   234,
      27,     8,     9,     3,    11,    12,    45,    27,    28,    29,
      17,    27,   241,   248,   249,     8,     9,    27,    11,    12,
      27,    28,    29,    47,    17,    27,    46,    28,     8,     9,
      41,    11,    12,    28,    27,    28,    29,    17,    41,    46,
      30,    31,     8,     9,   273,    11,    12,    27,    28,    29,
      41,    17,    41,    46,     8,     9,    41,    11,    12,    30,
      31,    27,    28,    29,     8,     9,    46,    11,    12,    18,
      19,    20,    21,    27,    28,     8,     9,    27,    11,    12,
      46,    27,    47,    27,    28,     8,     9,    47,    11,    12,
      46,    27,    46,    27,    27,    28,     8,     9,    30,    11,
      12,    43,    46,    41,    27,    28,     8,     9,    47,    11,
      12,    27,     5,    46,     4,    27,    28,    45,     8,     9,
       5,    11,    12,    46,    42,    27,    28,    17,   226,   227,
     228,   229,   230,   231,    46,    44,    30,    27,    28,    29,
      38,    39,    40,    30,    46,    18,    19,    20,    21,    22,
      23,    24,    25,    18,    19,    20,    21,    22,    23,    24,
      25,    45,    28,    36,    37,    38,    39,    40,    45,    42,
      45,    36,    37,    38,    39,    40,    45,    42,    18,    19,
      20,    21,    22,    23,    24,    25,    18,    19,    20,    21,
      22,    23,    24,    25,     5,    44,    36,    37,    38,    39,
      40,    40,    42,    27,    36,    37,    38,    39,    40,    45,
      42,    18,    19,    20,    21,    22,    23,    24,    25,    18,
      19,    20,    21,    22,    23,    24,    42,    48,    47,    36,
      37,    38,    39,    40,    30,    48,     5,    36,    37,    38,
      39,    40,    18,    19,    20,    21,    22,    23,    18,    19,
      20,    21,    27,    45,    27,    30,    31,    32,    33,    34,
      36,    37,    38,    39,    40,     5,    36,    37,    38,    39,
      40,    27,    27,    41,    30,    31,    32,    33,    34,    18,
      19,    20,    21,    22,    23,    30,    31,    32,    33,    34,
      36,    37,    38,    39,    40,    47,    27,    41,    41,    48,
       5,    10,    30,    45,    42,    42,    42,    30,    30,    30,
      45,    30,    45,    45,    27,    45,    27,    27,    47,    27,
      47,    47,    47,    37,    36,    10,   113,    45,   113,    36,
     187,    37,   188,   126
  };

  const signed char
  parser::yystos_[] =
  {
       0,     6,    50,    51,    52,     0,    13,    60,     7,    35,
      53,    61,    15,    63,    27,    54,    14,    27,    28,    59,
      62,    64,     3,    73,    45,    27,    27,    47,    16,    28,
      65,    74,    55,    27,     4,     8,     9,    11,    12,    17,
      27,    28,    29,    75,    80,    82,    28,    56,    58,    41,
      28,    41,    41,    41,    41,    76,    83,     5,    41,    43,
      27,    26,    27,    30,    31,    32,    34,    41,    77,    84,
      47,    27,    47,    46,    28,    42,    66,    67,    27,    84,
      84,    27,    71,    84,    27,    30,    31,    32,    33,    34,
      27,    30,    31,    32,    78,    79,    30,    43,    84,    84,
      18,    19,    20,    21,    22,    23,    24,    25,    36,    37,
      38,    39,    40,    41,    47,    27,    45,    42,    48,     5,
      42,    42,     5,    42,    42,    42,    48,    44,    30,    42,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    28,    42,    56,    57,    66,    68,    45,
      67,    30,    31,    32,    33,    34,    45,    45,    30,    45,
      79,     5,    44,    27,    45,    42,    48,     8,     9,    11,
      12,    27,    28,    46,    69,    68,    74,    74,    47,    74,
      30,     5,    68,    45,    67,    27,    41,    41,    41,     5,
      27,    47,    46,    46,    46,    27,    46,    45,    46,    68,
       5,    27,    30,    31,    32,    70,    72,    70,    71,    27,
      30,    31,    32,    33,    34,    10,    18,    19,    20,    21,
      30,    31,    81,    46,    30,    42,    18,    19,    20,    21,
      22,    23,    42,    42,    45,    30,    30,    30,    30,    46,
      48,    45,    72,    72,    72,    72,    72,    72,    45,    45,
      74,    47,    47,    47,    47,    30,    31,    68,    74,    74,
      46,    27,    27,    27,    27,    46,    46,    46,    36,    36,
      37,    37,    10,    45,    68,    46
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    52,    52,    53,    54,    55,
      55,    56,    57,    57,    58,    58,    58,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    72,
      72,    73,    74,    74,    74,    74,    74,    74,    75,    75,
      75,    75,    75,    76,    77,    78,    78,    79,    79,    79,
      79,    80,    80,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     4,     0,     3,     0,     2,     7,     1,     3,
       0,     2,     1,     3,     0,     8,     7,     2,     0,     3,
       0,     3,     2,     1,     0,     3,     0,     2,     8,     7,
       1,     3,     2,     3,     8,    12,     8,     8,     0,     2,
       3,     3,     3,     3,     3,     3,     4,     3,     3,     3,
       3,     3,     3,    10,    10,    10,    10,     1,     1,     1,
       1,     3,     3,     8,    12,     8,     8,     0,     1,     1,
       2,     2,     4,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     9,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     6,     3,     5,     5,     5,     5,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "BGINMAIN", "ENDMAIN",
  "ASSIGN", "BGINCLASS", "ENDCLASS", "CONST", "IF", "ELSE", "WHILE", "FOR",
  "BGINGLOBAL", "ENDGLOBAL", "BGINFUNC", "ENDFUNC", "PRINT", "LT", "LE",
  "GT", "GE", "EQ", "NEQ", "AND", "OR", "NOT", "ID", "TYPE", "TYPEOF",
  "INT", "FLOAT", "BOOL", "CHAR", "STRING", "CLASS", "'+'", "'-'", "'*'",
  "'/'", "'^'", "'('", "')'", "'['", "']'", "'{'", "'}'", "';'", "','",
  "$accept", "progr", "user_defined_data_types", "class_list", "clasa",
  "nume", "list_class_fields", "param_class", "list_param_class",
  "methods", "class_instance_declaration", "global_variables",
  "global_variables_list", "decl", "functions", "functions_list",
  "decl_func", "list_param", "param", "list1", "statement1", "expr",
  "expr_for", "op", "main", "list", "statement", "statement_print",
  "statement_typeof", "list_param_call", "param_call", "declarations",
  "array_list", "assignments", "print", "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   115,   115,   133,   134,   137,   138,   141,   143,   154,
     155,   158,   165,   169,   174,   175,   192,   203,   208,   209,
     212,   213,   216,   222,   226,   227,   230,   231,   234,   252,
     269,   273,   278,   286,   287,   288,   289,   290,   291,   294,
     295,   296,   297,   298,   299,   300,   301,   304,   305,   306,
     307,   308,   309,   312,   313,   314,   315,   318,   319,   320,
     321,   324,   328,   329,   335,   341,   347,   348,   351,   352,
     353,   354,   355,   374,   379,   397,   400,   406,   407,   408,
     409,   415,   422,   443,   450,   457,   461,   468,   490,   506,
     522,   538,   554,   570,   587,   589,   608,   628,   647,   667,
     689,   695,   709,   723,   737,   750,   764,   774,   784,   793,
     806,   819,   832,   845,   859,   872,   876,   881,   886,   891,
     896
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
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

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    38,    36,    48,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
    };
    // Last valid token kind.
    const int code_max = 290;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 2158 "limbaj.tab.cc"

#line 912 "limbaj.y"


void yyerror(const char * s)
    {
        printf("error: %s line:%d\n",s,yylineno);
    }  

int main(int argc, char** argv)
{
     yyin=fopen(argv[1],"r");
     yyparse();
} 


