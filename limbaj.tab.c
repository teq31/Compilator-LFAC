/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "limbaj.y"


#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include<fstream>
#include "AST.h"
#include "limbaj.tab.h"
#include "Symbol_Table.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yyleng;
extern int yylex();

void yyerror(const char * s);

using namespace std;

class AST ast;

SymTable* globalTable = new SymTable("global");
SymTable* classTable = nullptr;
SymTable* functionTable = nullptr;
SymTable* blockTable=nullptr;
SymTable* mainTable=nullptr;
SymTable* currentTable=globalTable;
SymTable* parentTable=nullptr;
string scope;
string altscope;


bool isInteger(const std::string& str) 
{
    try 
    {
        std::stoi(str);
        return true;
    } 
    catch (const std::invalid_argument& ia) 
    {
        return false;
    } 
    catch (const std::out_of_range& oor) 
    {
        return false;
    }
}

bool isFloat(const std::string& str) 
{
    try 
    {
        std::stof(str);
        return true;
    } 
    catch (const std::invalid_argument& ia) 
    {
        return false;
    } 
    catch (const std::out_of_range& oor) 
    {
        return false;
    }
}

bool isBoolean(const std::string& str) 
{
    return (str == "true" || str == "false");
}


#line 148 "limbaj.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGINMAIN = 3,                   /* BGINMAIN  */
  YYSYMBOL_ENDMAIN = 4,                    /* ENDMAIN  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_BGINCLASS = 6,                  /* BGINCLASS  */
  YYSYMBOL_ENDCLASS = 7,                   /* ENDCLASS  */
  YYSYMBOL_CONST = 8,                      /* CONST  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_BGINGLOBAL = 13,                /* BGINGLOBAL  */
  YYSYMBOL_ENDGLOBAL = 14,                 /* ENDGLOBAL  */
  YYSYMBOL_BGINFUNC = 15,                  /* BGINFUNC  */
  YYSYMBOL_ENDFUNC = 16,                   /* ENDFUNC  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_LE = 19,                        /* LE  */
  YYSYMBOL_GT = 20,                        /* GT  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_ID = 27,                        /* ID  */
  YYSYMBOL_TYPE = 28,                      /* TYPE  */
  YYSYMBOL_TYPEOF = 29,                    /* TYPEOF  */
  YYSYMBOL_INT = 30,                       /* INT  */
  YYSYMBOL_FLOAT = 31,                     /* FLOAT  */
  YYSYMBOL_BOOL = 32,                      /* BOOL  */
  YYSYMBOL_CHAR = 33,                      /* CHAR  */
  YYSYMBOL_STRING = 34,                    /* STRING  */
  YYSYMBOL_CLASS = 35,                     /* CLASS  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '^'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_progr = 50,                     /* progr  */
  YYSYMBOL_user_defined_data_types = 51,   /* user_defined_data_types  */
  YYSYMBOL_class_list = 52,                /* class_list  */
  YYSYMBOL_clasa = 53,                     /* clasa  */
  YYSYMBOL_nume = 54,                      /* nume  */
  YYSYMBOL_list_class_fields = 55,         /* list_class_fields  */
  YYSYMBOL_param_class = 56,               /* param_class  */
  YYSYMBOL_list_param_class = 57,          /* list_param_class  */
  YYSYMBOL_methods = 58,                   /* methods  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_global_variables = 61,          /* global_variables  */
  YYSYMBOL_global_variables_list = 62,     /* global_variables_list  */
  YYSYMBOL_decl = 63,                      /* decl  */
  YYSYMBOL_functions = 64,                 /* functions  */
  YYSYMBOL_functions_list = 65,            /* functions_list  */
  YYSYMBOL_decl_func = 66,                 /* decl_func  */
  YYSYMBOL_67_3 = 67,                      /* $@3  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_list_param = 69,                /* list_param  */
  YYSYMBOL_param = 70,                     /* param  */
  YYSYMBOL_list1 = 71,                     /* list1  */
  YYSYMBOL_72_5 = 72,                      /* $@5  */
  YYSYMBOL_73_6 = 73,                      /* $@6  */
  YYSYMBOL_74_7 = 74,                      /* $@7  */
  YYSYMBOL_cont1 = 75,                     /* cont1  */
  YYSYMBOL_statement1 = 76,                /* statement1  */
  YYSYMBOL_declaration1 = 77,              /* declaration1  */
  YYSYMBOL_assignments1 = 78,              /* assignments1  */
  YYSYMBOL_expr = 79,                      /* expr  */
  YYSYMBOL_expr_for = 80,                  /* expr_for  */
  YYSYMBOL_op = 81,                        /* op  */
  YYSYMBOL_main = 82,                      /* main  */
  YYSYMBOL_83_8 = 83,                      /* $@8  */
  YYSYMBOL_list = 84,                      /* list  */
  YYSYMBOL_85_9 = 85,                      /* $@9  */
  YYSYMBOL_86_10 = 86,                     /* $@10  */
  YYSYMBOL_87_11 = 87,                     /* $@11  */
  YYSYMBOL_cont = 88,                      /* cont  */
  YYSYMBOL_statement = 89,                 /* statement  */
  YYSYMBOL_statement_print = 90,           /* statement_print  */
  YYSYMBOL_statement_typeof = 91,          /* statement_typeof  */
  YYSYMBOL_list_param_call = 92,           /* list_param_call  */
  YYSYMBOL_param_call = 93,                /* param_call  */
  YYSYMBOL_declarations = 94,              /* declarations  */
  YYSYMBOL_array_list = 95,                /* array_list  */
  YYSYMBOL_assignments = 96,               /* assignments  */
  YYSYMBOL_print = 97,                     /* print  */
  YYSYMBOL_expression = 98                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   138,   139,   142,   143,   146,   148,   156,
     157,   160,   173,   185,   198,   200,   199,   245,   244,   272,
     273,   276,   277,   280,   297,   298,   301,   302,   306,   305,
     350,   350,   375,   379,   384,   401,   402,   402,   408,   408,
     414,   414,   420,   423,   424,   426,   427,   429,   438,   446,
     455,   463,   471,   479,   496,   497,   498,   499,   500,   501,
     504,   521,   538,   555,   575,   576,   577,   578,   581,   581,
     600,   601,   601,   607,   607,   618,   618,   624,   627,   633,
     640,   641,   642,   643,   644,   664,   670,   689,   692,   698,
     700,   702,   704,   715,   729,   753,   760,   767,   772,   779,
     801,   823,   854,   879,   901,   929,   951,   970,   991,   993,
    1016,  1040,  1063,  1087,  1114,  1119,  1133,  1147,  1161,  1174,
    1188,  1198,  1208,  1217,  1230,  1243,  1256,  1269,  1283,  1296,
    1300,  1305,  1310,  1315,  1320
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BGINMAIN", "ENDMAIN",
  "ASSIGN", "BGINCLASS", "ENDCLASS", "CONST", "IF", "ELSE", "WHILE", "FOR",
  "BGINGLOBAL", "ENDGLOBAL", "BGINFUNC", "ENDFUNC", "PRINT", "LT", "LE",
  "GT", "GE", "EQ", "NEQ", "AND", "OR", "NOT", "ID", "TYPE", "TYPEOF",
  "INT", "FLOAT", "BOOL", "CHAR", "STRING", "CLASS", "'+'", "'-'", "'*'",
  "'/'", "'^'", "'('", "')'", "'['", "']'", "'{'", "'}'", "';'", "','",
  "$accept", "progr", "user_defined_data_types", "class_list", "clasa",
  "nume", "list_class_fields", "param_class", "list_param_class",
  "methods", "$@1", "$@2", "global_variables", "global_variables_list",
  "decl", "functions", "functions_list", "decl_func", "$@3", "$@4",
  "list_param", "param", "list1", "$@5", "$@6", "$@7", "cont1",
  "statement1", "declaration1", "assignments1", "expr", "expr_for", "op",
  "main", "$@8", "list", "$@9", "$@10", "$@11", "cont", "statement",
  "statement_print", "statement_typeof", "list_param_call", "param_call",
  "declarations", "array_list", "assignments", "print", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-35)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,  -193,    39,    55,     0,  -193,  -193,    51,  -193,    59,
    -193,   -10,  -193,    91,  -193,    26,  -193,    83,    71,     9,
    -193,  -193,  -193,  -193,  -193,  -193,    92,  -193,  -193,    96,
      84,   177,    99,    87,    95,   -23,  -193,   102,   103,   113,
     119,   120,     6,   110,    -3,   115,  -193,  -193,   125,  -193,
     122,   147,   133,   -12,  -193,   152,    74,    -3,   153,    -3,
    -193,  -193,   166,   337,   157,   158,    -3,  -193,  -193,  -193,
    -193,  -193,    -3,  -193,   267,  -193,   -22,  -193,  -193,  -193,
     150,   175,   203,  -193,  -193,  -193,  -193,   167,   334,   193,
     222,   186,   201,  -193,  -193,  -193,  -193,  -193,  -193,    -3,
    -193,  -193,  -193,  -193,    -2,  -193,   190,   206,  -193,   226,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,   215,   216,  -193,   218,   219,  -193,  -193,
    -193,   340,  -193,    74,    74,    74,    74,    74,    74,   224,
     245,   248,  -193,   234,  -193,   337,   289,   256,  -193,   339,
     339,   339,   339,   303,   303,   297,   290,    53,    53,   262,
     262,  -193,   277,  -193,   286,   175,   104,  -193,  -193,  -193,
    -193,  -193,  -193,   287,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,   291,  -193,  -193,  -193,    11,   341,  -193,  -193,   318,
     304,   324,   342,   375,   354,  -193,   335,  -193,  -193,   111,
    -193,  -193,  -193,   357,  -193,  -193,    -3,   343,   124,  -193,
      74,    74,   153,   317,  -193,  -193,  -193,     5,    61,    63,
      68,   259,    14,  -193,   131,   344,   345,   347,  -193,  -193,
    -193,  -193,  -193,  -193,   380,  -193,   355,   361,   362,   363,
    -193,  -193,  -193,  -193,     2,  -193,  -193,   349,   350,   351,
     352,   353,   356,   358,  -193,    44,   359,  -193,  -193,  -193,
     370,   371,   374,   379,  -193,  -193,  -193,  -193,  -193,  -193,
     100,   366,   372,   373,   376,   136,   144,   156,  -193,  -193,
    -193,  -193,  -193,   397,  -193,  -193,   364,  -193,   164,  -193
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     5,     0,    19,     0,     1,    21,    24,     4,     0,
       6,     0,    26,     0,     8,     0,    20,     0,     0,     0,
      68,     2,    10,    23,    22,    25,     0,    27,    77,    14,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    11,     9,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
      82,    85,     0,     0,     0,    93,     0,   134,   130,   131,
     132,   133,     0,    83,    86,    70,     0,     7,    34,    30,
       0,     0,   108,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,     0,
      92,    89,    90,    91,     0,    88,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,    42,    28,
      33,     0,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,    84,     0,     0,     0,   129,   123,
     124,   125,   126,   127,   128,   120,   121,   115,   116,   117,
     118,   119,    11,    17,     0,     0,     0,    42,   109,   110,
     111,   112,   113,     0,    55,    57,    54,    56,    58,    59,
      73,     0,    75,    99,    87,     0,     0,    42,    15,    13,
       0,     0,     0,     0,     0,    31,     0,    45,    46,     0,
      77,    72,    77,     0,    77,   107,     0,     0,     0,    42,
       0,     0,     0,     0,    47,    35,    29,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,    48,    49,
      50,    53,    52,    51,    78,    74,     0,     0,     0,     0,
      76,   100,    97,    98,     0,    16,    36,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     0,    38,    40,    77,
       0,     0,     0,     0,    95,    96,    42,    37,    42,    42,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    60,
      61,    62,    63,    43,    39,    41,     0,    42,     0,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,  -193,  -193,  -193,  -193,  -193,   336,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
     338,   -78,  -166,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -112,   199,   225,  -193,  -193,  -192,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,   270,  -193,  -193,  -193,  -193,   -57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,    10,    15,    29,    33,   126,    34,
     209,   187,     7,    11,    18,    13,    19,    27,   167,   128,
      53,    54,   166,   256,   268,   269,   267,   196,   197,   198,
      87,    91,    88,    21,    28,    31,   173,   202,   204,   201,
      45,    60,    73,   104,   105,    46,   244,    47,    61,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,   199,    92,   130,    16,    51,   123,     8,   217,   108,
     218,    62,   220,    37,    38,   109,    39,    40,    17,    52,
     124,   208,    41,    66,    67,    25,     1,    68,    69,    70,
      80,    71,    42,    43,    44,     9,    81,    26,    72,     5,
     144,   205,   143,   224,   242,   243,   145,    63,   254,    64,
     255,   234,   206,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    12,   270,     6,    37,
      38,    22,    39,    40,   264,   265,    37,    38,    41,    39,
      40,   236,   237,   238,   239,    41,    14,   189,    42,    43,
      44,   120,   121,   122,    20,    42,    43,    44,   225,   226,
     275,    83,   276,   277,    84,    85,    86,   235,    37,    38,
      23,    39,    40,   190,   240,   191,   192,    41,    24,    30,
     190,   288,   191,   192,    32,    35,    48,    42,    43,    44,
      55,   193,   194,   190,    49,   191,   192,    65,   193,   194,
     190,    50,   191,   192,    56,   190,   278,   191,   192,   221,
     195,   193,   194,   190,    57,   191,   192,   216,   193,   194,
      58,    59,    75,   193,   194,   190,    76,   191,   192,    77,
     223,   193,   194,   190,    78,   191,   192,   245,    79,    82,
      90,    36,   283,   193,   194,    37,    38,   106,    39,    40,
     284,   193,   194,    93,    41,   129,    94,    95,    96,    97,
      98,   107,   285,    51,    42,    43,    44,    99,   131,   132,
     289,   110,   111,   112,   113,   114,   115,   116,   117,   110,
     111,   112,   113,   114,   115,   116,   117,   140,   141,   118,
     119,   120,   121,   122,   146,   139,   147,   118,   119,   120,
     121,   122,   162,   142,   110,   111,   112,   113,   114,   115,
     116,   117,   110,   111,   112,   113,   114,   115,   116,   117,
     164,   163,   118,   119,   120,   121,   122,   165,   148,   180,
     118,   119,   120,   121,   122,   181,   183,   110,   111,   112,
     113,   114,   115,   116,   117,   110,   111,   112,   113,   114,
     115,   116,   117,   182,   185,   118,   119,   120,   121,   122,
     186,   241,   122,   118,   119,   120,   121,   122,   110,   111,
     112,   113,   114,   115,   116,   110,   111,   112,   113,   114,
     115,   110,   111,   112,   113,   -34,   118,   119,   120,   121,
     122,   188,   200,   118,   119,   120,   121,   122,   203,   118,
     119,   120,   121,   122,   228,   210,   207,   229,   230,   231,
     232,   233,   133,   134,   135,   136,   137,   138,   174,   175,
     176,   177,   178,   179,   100,   211,   -33,   101,   102,   103,
     168,   169,   170,   171,   172,   118,   119,   120,   121,   122,
     213,   214,   215,   212,   219,   250,   246,   247,   222,   248,
     249,   251,   252,   253,   257,   258,   259,   271,   272,   260,
     261,   273,   279,   262,   266,   263,   274,   286,   280,   287,
     281,   227,   125,   282,   127,   184
};

static const yytype_int16 yycheck[] =
{
      57,   167,    59,    81,    14,    28,    28,     7,   200,    66,
     202,     5,   204,     8,     9,    72,    11,    12,    28,    42,
      42,   187,    17,    26,    27,    16,     6,    30,    31,    32,
      42,    34,    27,    28,    29,    35,    48,    28,    41,     0,
      42,    30,    99,   209,    30,    31,    48,    41,    46,    43,
      48,    46,    41,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    15,   259,    13,     8,
       9,    45,    11,    12,    30,    31,     8,     9,    17,    11,
      12,    18,    19,    20,    21,    17,    27,   165,    27,    28,
      29,    38,    39,    40,     3,    27,    28,    29,   210,   211,
     266,    27,   268,   269,    30,    31,    32,    46,     8,     9,
      27,    11,    12,     9,    46,    11,    12,    17,    47,    27,
       9,   287,    11,    12,    28,    41,    27,    27,    28,    29,
      28,    27,    28,     9,    47,    11,    12,    27,    27,    28,
       9,    46,    11,    12,    41,     9,    46,    11,    12,   206,
      46,    27,    28,     9,    41,    11,    12,    46,    27,    28,
      41,    41,    47,    27,    28,     9,    41,    11,    12,    47,
      46,    27,    28,     9,    27,    11,    12,    46,    45,    27,
      27,     4,    46,    27,    28,     8,     9,    30,    11,    12,
      46,    27,    28,    27,    17,    45,    30,    31,    32,    33,
      34,    43,    46,    28,    27,    28,    29,    41,     5,    42,
      46,    18,    19,    20,    21,    22,    23,    24,    25,    18,
      19,    20,    21,    22,    23,    24,    25,     5,    42,    36,
      37,    38,    39,    40,    44,    42,    30,    36,    37,    38,
      39,    40,    27,    42,    18,    19,    20,    21,    22,    23,
      24,    25,    18,    19,    20,    21,    22,    23,    24,    25,
      42,    45,    36,    37,    38,    39,    40,    48,    42,    45,
      36,    37,    38,    39,    40,    30,    42,    18,    19,    20,
      21,    22,    23,    24,    25,    18,    19,    20,    21,    22,
      23,    24,    25,    45,     5,    36,    37,    38,    39,    40,
      44,    42,    40,    36,    37,    38,    39,    40,    18,    19,
      20,    21,    22,    23,    24,    18,    19,    20,    21,    22,
      23,    18,    19,    20,    21,    48,    36,    37,    38,    39,
      40,    45,    45,    36,    37,    38,    39,    40,    47,    36,
      37,    38,    39,    40,    27,    41,     5,    30,    31,    32,
      33,    34,    18,    19,    20,    21,    22,    23,   133,   134,
     135,   136,   137,   138,    27,    41,    48,    30,    31,    32,
      30,    31,    32,    33,    34,    36,    37,    38,    39,    40,
       5,    27,    47,    41,    27,    30,    42,    42,    45,    42,
      10,    30,    30,    30,    45,    45,    45,    27,    27,    47,
      47,    27,    36,    47,    45,    47,    27,    10,    36,    45,
      37,   212,    76,    37,    76,   145
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    50,    51,    52,     0,    13,    61,     7,    35,
      53,    62,    15,    64,    27,    54,    14,    28,    63,    65,
       3,    82,    45,    27,    47,    16,    28,    66,    83,    55,
      27,    84,    28,    56,    58,    41,     4,     8,     9,    11,
      12,    17,    27,    28,    29,    89,    94,    96,    27,    47,
      46,    28,    42,    69,    70,    28,    41,    41,    41,    41,
      90,    97,     5,    41,    43,    27,    26,    27,    30,    31,
      32,    34,    41,    91,    98,    47,    41,    47,    27,    45,
      42,    48,    27,    27,    30,    31,    32,    79,    81,    98,
      27,    80,    98,    27,    30,    31,    32,    33,    34,    41,
      27,    30,    31,    32,    92,    93,    30,    43,    98,    98,
      18,    19,    20,    21,    22,    23,    24,    25,    36,    37,
      38,    39,    40,    28,    42,    56,    57,    69,    68,    45,
      70,     5,    42,    18,    19,    20,    21,    22,    23,    42,
       5,    42,    42,    98,    42,    48,    44,    30,    42,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    27,    45,    42,    48,    71,    67,    30,    31,
      32,    33,    34,    85,    81,    81,    81,    81,    81,    81,
      45,    30,    45,    42,    93,     5,    44,    60,    45,    70,
       9,    11,    12,    27,    28,    46,    76,    77,    78,    71,
      45,    88,    86,    47,    87,    30,    41,     5,    71,    59,
      41,    41,    41,     5,    27,    47,    46,    84,    84,    27,
      84,    98,    45,    46,    71,    79,    79,    80,    27,    30,
      31,    32,    33,    34,    46,    46,    18,    19,    20,    21,
      46,    42,    30,    31,    95,    46,    42,    42,    42,    10,
      30,    30,    30,    30,    46,    48,    72,    45,    45,    45,
      47,    47,    47,    47,    30,    31,    45,    75,    73,    74,
      84,    27,    27,    27,    27,    71,    71,    71,    46,    36,
      36,    37,    37,    46,    46,    46,    10,    45,    71,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    54,    55,
      55,    56,    57,    57,    58,    59,    58,    60,    58,    61,
      61,    62,    62,    63,    64,    64,    65,    65,    67,    66,
      68,    66,    69,    69,    70,    71,    72,    71,    73,    71,
      74,    71,    71,    75,    75,    76,    76,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    80,    81,    81,    81,    81,    83,    82,
      84,    85,    84,    86,    84,    87,    84,    84,    88,    88,
      89,    89,    89,    89,    89,    90,    91,    92,    92,    93,
      93,    93,    93,    94,    94,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     3,     0,     2,     7,     1,     3,
       0,     2,     1,     3,     0,     0,     9,     0,     8,     0,
       3,     0,     3,     2,     0,     3,     0,     2,     0,     9,
       0,     8,     1,     3,     2,     3,     0,     7,     0,     9,
       0,     9,     0,     3,     7,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      10,    10,    10,    10,     1,     1,     1,     1,     0,     4,
       3,     0,     7,     0,     9,     0,     9,     0,     3,     7,
       1,     1,     2,     2,     4,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     9,     3,     3,     1,     1,     5,
       8,     3,     3,     3,     3,     3,     3,     6,     3,     5,
       5,     5,     5,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* progr: user_defined_data_types global_variables functions main  */
#line 126 "limbaj.y"
                                                               { 
                                                                    cout <<"The program works!! /ᐠ - ˕ -マ \n";
                                                                    ofstream outFile("symbol_tables.txt");
                                                                    if (!outFile) {
                                                                        cerr << "Nu s-a putut deschide fișierul pentru scriere!" << endl;
                                                                        return 1;
                                                                    }
                                                                    globalTable->print(outFile);
                                                                    outFile.close();
                                                                  cout << "Tabela de simboluri a fost scrisă în symbol_tables.txt" << endl;
                                                               }
#line 1459 "limbaj.tab.c"
    break;

  case 8: /* nume: ID  */
#line 148 "limbaj.y"
          { scope = (yyvsp[0].string) ;
            classTable = new SymTable(scope, globalTable);
            globalTable->addChild(classTable);
            globalTable->addClass(Class(scope));

           }
#line 1470 "limbaj.tab.c"
    break;

  case 11: /* param_class: TYPE ID  */
#line 161 "limbaj.y"
{
    if (classTable->getVariable((yyvsp[0].string))) 
    {
        yyerror("Variable already exists in the class scope.");
    } 
    else
    {
        (yyval.parameter) = new Parameters((yyvsp[-1].string), (yyvsp[0].string));
        classTable->addVariable(Variable((yyvsp[0].string), (yyvsp[-1].string)));
    }
}
#line 1486 "limbaj.tab.c"
    break;

  case 12: /* list_param_class: param_class  */
#line 174 "limbaj.y"
                    {
                        if (classTable->getVariable((yyvsp[0].parameter)->name)) 
                        {
                            yyerror("Parameter conflicts with an existing variable in the class scope.");
                        } 
                        else
                        {
                            (yyval.metoda) = new Function();
                            (yyval.metoda)->Param.push_back(*(yyvsp[0].parameter));
                        }
                    }
#line 1502 "limbaj.tab.c"
    break;

  case 13: /* list_param_class: list_param ',' param  */
#line 186 "limbaj.y"
                    {
                        if (classTable->getVariable((yyvsp[0].parameter)->name)) 
                        {
                            yyerror("Parameter conflicts with an existing variable in the class scope.");
                        }
                        else
                        {
                            (yyval.metoda)->Param.push_back(*(yyvsp[0].parameter));
                        }
                    }
#line 1517 "limbaj.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 200 "limbaj.y"
    {
        scope = (yyvsp[-4].string) ;
        if (classTable->getFunctionName(scope.c_str())) 
        {
            yyerror("Method redefinition");
        }
        else
        {
            functionTable = new SymTable(scope, classTable);
            currentTable=functionTable;
            classTable->addChild(functionTable);
            classTable->addFunction(Function((yyvsp[-4].string),(yyvsp[-5].string),(yyvsp[-2].metoda)->Param));}
    }
#line 1535 "limbaj.tab.c"
    break;

  case 16: /* methods: TYPE ID '(' list_param_class ')' '{' $@1 list1 '}'  */
#line 213 "limbaj.y"
    {
        Function* currentFunction = globalTable->getFunction(scope);
        if (currentFunction) 
        {
            for (const auto &var : variabile) 
            {
                bool conflictWithParam = false;
                for (const auto &parametru : currentFunction->Param) 
                {
                    if (parametru.name == var.name) 
                    {
                        conflictWithParam = true;
                        break;
                    }
                }
                if (functionTable->getVariable(var.name)) 
                {
                    yyerror("Variable already exists in the function scope.");
                } 
                else if (conflictWithParam) 
                {
                    yyerror("Variable conflicts with a function parameter.");
                } 
                else 
                {
                    functionTable->addVariable(var);
                }
            }
        }
        variabile.clear();
    }
#line 1571 "limbaj.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 245 "limbaj.y"
    {
        scope = (yyvsp[-3].string) ;
        if (globalTable->getFunctionName(scope.c_str())) 
        {
            yyerror("Function redefinition");
        }
        else 
        {
            functionTable = new SymTable(scope, classTable);
            currentTable=functionTable;
            classTable->addChild(functionTable);
            classTable->addFunction(Function((yyvsp[-3].string),(yyvsp[-4].string),std::vector<Parameters>()));
        }
    }
#line 1590 "limbaj.tab.c"
    break;

  case 18: /* methods: TYPE ID '(' ')' '{' $@2 list1 '}'  */
#line 259 "limbaj.y"
    {
        for (const auto &var : variabile) 
        {
            if (functionTable->getVariable(var.name)) 
            {
                yyerror("Variable already exists in the function scope.");
            }
            functionTable->addVariable(var);
        }
        variabile.clear();
    }
#line 1606 "limbaj.tab.c"
    break;

  case 23: /* decl: TYPE ID  */
#line 280 "limbaj.y"
               { 
                    if(!existsVar((yyvsp[0].string))) 
                    {   

                        globalTable->addVariable(Variable((yyvsp[0].string),(yyvsp[-1].string),""));
                        (yyval.variabila)=new Variable((yyvsp[0].string),(yyvsp[-1].string));
                        global_variabile.push_back(*(yyval.variabila));
                    }
                    else 
                    {
                        string err="Variable '"+string((yyvsp[0].string))+"' was already declared ";
                        yyerror(err.c_str());
                    }
               }
#line 1625 "limbaj.tab.c"
    break;

  case 28: /* $@3: %empty  */
#line 306 "limbaj.y"
              {
            
                scope = (yyvsp[-4].string); 
                if (globalTable->getFunctionName(scope.c_str())) {
                    yyerror("Function redefinition");
                } else {
                    functionTable = new SymTable(scope, globalTable);
                    currentTable=functionTable;
                    globalTable->addChild(functionTable);
                    globalTable->addFunction(Function((yyvsp[-4].string),(yyvsp[-5].string),(yyvsp[-2].functie)->Param));
                }
              }
#line 1642 "limbaj.tab.c"
    break;

  case 29: /* decl_func: TYPE ID '(' list_param ')' '{' $@3 list1 '}'  */
#line 319 "limbaj.y"
            {  
                Function* currentFunction = globalTable->getFunction(scope);
                if (currentFunction) 
                {
                    for (const auto &var : variabile) 
                    {
                        bool conflictWithParam = false;
                        for (const auto &parametru : currentFunction->Param) 
                        {
                            if (parametru.name == var.name) 
                            {
                                conflictWithParam = true;
                                break;
                            }
                        }
                        if (functionTable->getVariable(var.name)) 
                        {
                            yyerror("Variable already exists in the function scope.");
                        } 
                        else if (conflictWithParam) 
                        {
                            yyerror("Variable conflicts with a function parameter.");
                        } 
                        else 
                        {
                            functionTable->addVariable(var);
                        }
                    }
                }
                variabile.clear();
            }
#line 1678 "limbaj.tab.c"
    break;

  case 30: /* $@4: %empty  */
#line 350 "limbaj.y"
                                { scope = (yyvsp[-3].string); 
                if (globalTable->getFunctionName(scope.c_str())) {
                    yyerror("Function redefinition");
                } else {
                    functionTable = new SymTable(scope, globalTable);
                    currentTable=functionTable;
                    globalTable->addChild(functionTable);
                    globalTable->addFunction(Function((yyvsp[-3].string),(yyvsp[-4].string),std::vector<Parameters>()));
                }
              }
#line 1693 "limbaj.tab.c"
    break;

  case 31: /* decl_func: TYPE ID '(' ')' '{' $@4 list1 '}'  */
#line 360 "limbaj.y"
              {   
                for (const auto &var : variabile) 
                {
                    if (functionTable->getVariable(var.name)) 
                    {
                        yyerror("Variable already exists in the function scope.");
                    }
                    functionTable->addVariable(var);
                }
                variabile.clear();
                  
              }
#line 1710 "limbaj.tab.c"
    break;

  case 32: /* list_param: param  */
#line 375 "limbaj.y"
                      {
                         (yyval.functie)=new Function();
                         (yyval.functie)->Param.push_back(*(yyvsp[0].parameter));
                      }
#line 1719 "limbaj.tab.c"
    break;

  case 33: /* list_param: list_param ',' param  */
#line 379 "limbaj.y"
                                    {
                                    (yyval.functie)->Param.push_back(*(yyvsp[0].parameter));
                                    }
#line 1727 "limbaj.tab.c"
    break;

  case 34: /* param: TYPE ID  */
#line 384 "limbaj.y"
                {
                     Function* currentFunction = globalTable->getFunction(scope);
                     
                     if (currentFunction) 
                     {
                         for (const auto &parametru : currentFunction->Param) 
                         {
                             if (parametru.name == (yyvsp[0].string)) 
                             {
                                 yyerror("Duplicate parameter name in the function.");
                             }
                         }
                     }
                     (yyval.parameter) = new Parameters((yyvsp[-1].string), (yyvsp[0].string));
                }
#line 1747 "limbaj.tab.c"
    break;

  case 36: /* $@5: %empty  */
#line 402 "limbaj.y"
                             { blockTable = new SymTable("block", currentTable);
                                    parentTable=currentTable;
                                     currentTable->addChild(blockTable);
                                     currentTable=blockTable;
     
     }
#line 1758 "limbaj.tab.c"
    break;

  case 38: /* $@6: %empty  */
#line 408 "limbaj.y"
                                    { blockTable = new SymTable("block", currentTable);
                                       parentTable=currentTable;
                                     currentTable->addChild(blockTable);
                                     currentTable=blockTable;
     
     }
#line 1769 "limbaj.tab.c"
    break;

  case 39: /* list1: list1 WHILE '(' expr ')' '{' $@6 list1 '}'  */
#line 413 "limbaj.y"
                  { currentTable=parentTable; }
#line 1775 "limbaj.tab.c"
    break;

  case 40: /* $@7: %empty  */
#line 414 "limbaj.y"
                                      { blockTable = new SymTable("block", currentTable);
                                         parentTable=currentTable;
                                       currentTable->addChild(blockTable);
                                       currentTable=blockTable;
     
     }
#line 1786 "limbaj.tab.c"
    break;

  case 41: /* list1: list1 FOR '(' expr_for ')' '{' $@7 list1 '}'  */
#line 419 "limbaj.y"
                 { currentTable=parentTable; }
#line 1792 "limbaj.tab.c"
    break;

  case 43: /* cont1: '{' list1 '}'  */
#line 423 "limbaj.y"
                     { currentTable=parentTable; }
#line 1798 "limbaj.tab.c"
    break;

  case 44: /* cont1: '{' list1 '}' ELSE '{' list1 '}'  */
#line 424 "limbaj.y"
                                      { currentTable=parentTable;}
#line 1804 "limbaj.tab.c"
    break;

  case 47: /* declaration1: TYPE ID  */
#line 429 "limbaj.y"
                      {   (yyval.variabila)=new Variable((yyvsp[0].string),(yyvsp[-1].string));
                           if(currentTable==functionTable)
                             variabile.push_back(*(yyval.variabila));
                           else
                             currentTable->addVariable(Variable((yyvsp[0].string),(yyvsp[-1].string)));

                          
                      }
#line 1817 "limbaj.tab.c"
    break;

  case 48: /* assignments1: ID ASSIGN ID  */
#line 438 "limbaj.y"
                          {    string val;
                               for (auto &var : variabile) 
                                    if(var.name==(yyvsp[0].string))
                                       val=var.value;
                                for (auto &var : variabile) 
                                     if(var.name==(yyvsp[-2].string))
                                        var.value=val;
                            }
#line 1830 "limbaj.tab.c"
    break;

  case 49: /* assignments1: ID ASSIGN INT  */
#line 446 "limbaj.y"
                         {   
                             for (auto &var : variabile) 
                                if(var.name==(yyvsp[-2].string))
                                  {            
                                    (yyval.variabila)=new Variable("",(yyvsp[-2].string),to_string((yyvsp[0].num)).c_str());
                                    var.value=(yyval.variabila)->value;
                                  }
                                    
                        }
#line 1844 "limbaj.tab.c"
    break;

  case 50: /* assignments1: ID ASSIGN FLOAT  */
#line 455 "limbaj.y"
                           {
                for (auto &var : variabile) 
                     if(var.name==(yyvsp[-2].string))
                    {            
                         (yyval.variabila)=new Variable("",(yyvsp[-2].string),to_string((yyvsp[0].num_with_dot)).c_str());
                         var.value=(yyval.variabila)->value;
                     }
          }
#line 1857 "limbaj.tab.c"
    break;

  case 51: /* assignments1: ID ASSIGN STRING  */
#line 463 "limbaj.y"
                            {
            for (auto &var : variabile) 
                    if(var.name==(yyvsp[-2].string))
                     {            
                         (yyval.variabila)=new Variable("",(yyvsp[-2].string),(yyvsp[0].string));
                         var.value=(yyval.variabila)->value;
                    }
          }
#line 1870 "limbaj.tab.c"
    break;

  case 52: /* assignments1: ID ASSIGN CHAR  */
#line 471 "limbaj.y"
                         {
            for (auto &var : variabile) 
                 if(var.name==(yyvsp[-2].string))
                 {            
                     (yyval.variabila)=new Variable("",(yyvsp[-2].string),to_string((yyvsp[0].chr)).c_str());
                     var.value=(yyval.variabila)->value;
                 }
          }
#line 1883 "limbaj.tab.c"
    break;

  case 53: /* assignments1: ID ASSIGN BOOL  */
#line 479 "limbaj.y"
                         {
            for (auto &var : variabile) 
               if(var.name==(yyvsp[-2].string))
                {   string val=to_string((yyvsp[0].bolean)).c_str();
                    if(val=="1")
                         val="true";
                     if(val=="0")
                          val="false";
                                                    
                     (yyval.variabila)=new Variable("",(yyvsp[-2].string),val);
                     var.value=(yyval.variabila)->value;
                                            
                 }
          }
#line 1902 "limbaj.tab.c"
    break;

  case 60: /* expr_for: ID ASSIGN INT ';' ID LT INT ';' ID '+'  */
#line 505 "limbaj.y"
    {
        bool found = false;
        for (const auto &var : variabile) 
        {
            if (var.name == (yyvsp[-9].string)) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            string err = "Variable '" + string((yyvsp[-9].string)) + "' is not declared!";
            yyerror(err.c_str());
        }
    }
#line 1923 "limbaj.tab.c"
    break;

  case 61: /* expr_for: ID ASSIGN INT ';' ID LE INT ';' ID '+'  */
#line 522 "limbaj.y"
    {
        bool found = false;
        for (const auto &var : variabile) 
        {
            if (var.name == (yyvsp[-9].string)) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            string err = "Variable '" + string((yyvsp[-9].string)) + "' is not declared!";
            yyerror(err.c_str());
        }
    }
#line 1944 "limbaj.tab.c"
    break;

  case 62: /* expr_for: ID ASSIGN INT ';' ID GT INT ';' ID '-'  */
#line 539 "limbaj.y"
    {
        bool found = false;
        for (const auto &var : variabile) 
        {
            if (var.name == (yyvsp[-9].string)) 
            {  
                found = true;
                break;
            }
        }
        if (!found) 
        {
            string err = "Variable '" + string((yyvsp[-9].string)) + "' is not declared!";
            yyerror(err.c_str());
        }
    }
#line 1965 "limbaj.tab.c"
    break;

  case 63: /* expr_for: ID ASSIGN INT ';' ID GE INT ';' ID '-'  */
#line 556 "limbaj.y"
    {
        bool found = false;
        for (const auto &var : variabile) 
        {
            if (var.name == (yyvsp[-9].string)) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            string err = "Variable '" + string((yyvsp[-9].string)) + "' is not declared!";
            yyerror(err.c_str());
        }
    }
#line 1986 "limbaj.tab.c"
    break;

  case 68: /* $@8: %empty  */
#line 581 "limbaj.y"
                 {
    
     mainTable = new SymTable("main", globalTable);
     globalTable->addChild(mainTable);
     globalTable->addFunction(Function("","main",std::vector<Parameters>()));
     currentTable=mainTable;
     }
#line 1998 "limbaj.tab.c"
    break;

  case 69: /* main: BGINMAIN $@8 list ENDMAIN  */
#line 587 "limbaj.y"
                    {
     for ( auto &var : global_variabile) 
       if(existsVarMain(var.name))
         mainTable->addVariable(var);
       variabile.clear();
       for (auto &var : global_variabile) 
         globalTable->updateValue(var,var.value);
      }
#line 2011 "limbaj.tab.c"
    break;

  case 71: /* $@9: %empty  */
#line 601 "limbaj.y"
                            { blockTable = new SymTable("block", currentTable);
                                    parentTable=currentTable;
                                     currentTable->addChild(blockTable);
                                     currentTable=blockTable;
     
     }
#line 2022 "limbaj.tab.c"
    break;

  case 73: /* $@10: %empty  */
#line 607 "limbaj.y"
                                         {   blockTable = new SymTable("block", currentTable);
                                       parentTable=currentTable;
                                       currentTable->addChild(blockTable);
                                       currentTable=blockTable;
     
     }
#line 2033 "limbaj.tab.c"
    break;

  case 74: /* list: list WHILE '(' expression ')' '{' $@10 list '}'  */
#line 612 "limbaj.y"
                 { currentTable=parentTable; 
                 
                   if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                  {
                         yyerror("'while' accepts only boolean expressions");
                }}
#line 2044 "limbaj.tab.c"
    break;

  case 75: /* $@11: %empty  */
#line 618 "limbaj.y"
                                     { blockTable = new SymTable("block", currentTable);
                                         parentTable=currentTable;
                                       currentTable->addChild(blockTable);
                                       currentTable=blockTable;
     
     }
#line 2055 "limbaj.tab.c"
    break;

  case 76: /* list: list FOR '(' expr_for ')' '{' $@11 list '}'  */
#line 623 "limbaj.y"
                { currentTable=parentTable; }
#line 2061 "limbaj.tab.c"
    break;

  case 78: /* cont: '{' list '}'  */
#line 627 "limbaj.y"
                   { currentTable=parentTable;

                    if(ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                    {
                         yyerror("'if' accepts only boolean expressions");
                    } }
#line 2072 "limbaj.tab.c"
    break;

  case 79: /* cont: '{' list '}' ELSE '{' list '}'  */
#line 633 "limbaj.y"
                                    { currentTable=parentTable;
     
                                     if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                    {
                                            yyerror("'if' accepts only boolean expressions");
                                    }}
#line 2083 "limbaj.tab.c"
    break;

  case 84: /* statement: ID '(' list_param_call ')'  */
#line 644 "limbaj.y"
                                    {
             Function *func = globalTable->getFunction((yyvsp[-3].string)); 
            if (func == nullptr) {
                yyerror(("Undefined function: " + std::string((yyvsp[-3].string))).c_str());
            } else {
                if (func->Param.size() != (yyvsp[-1].functie)->Param.size()) {
                    yyerror(("Incorrect number of arguments for function: " + std::string((yyvsp[-3].string))).c_str());
                } else {
                    for (size_t i = 0; i < func->Param.size(); ++i) {
                        if (func->Param[i].type != (yyvsp[-1].functie)->Param[i].type) {
                            yyerror(("Argument type mismatch in function " + std::string((yyvsp[-3].string)) + " for parameter " + std::to_string(i+1) + ": expected " + func->Param[i].type + ", got " + (yyvsp[-1].functie)->Param[i].type).c_str());
                        }
                    }
                }
            }
    
}
#line 2105 "limbaj.tab.c"
    break;

  case 85: /* statement_print: print  */
#line 665 "limbaj.y"
                    {
                        cout << ast.evaluateTree() << endl; ast.printTree(); 
                    }
#line 2113 "limbaj.tab.c"
    break;

  case 86: /* statement_typeof: expression  */
#line 670 "limbaj.y"
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
#line 2134 "limbaj.tab.c"
    break;

  case 87: /* list_param_call: list_param_call ',' param_call  */
#line 689 "limbaj.y"
                                                {
                                    (yyval.functie)->Param.push_back(*(yyvsp[0].parameter));
                                    }
#line 2142 "limbaj.tab.c"
    break;

  case 88: /* list_param_call: param_call  */
#line 692 "limbaj.y"
                            {
                         (yyval.functie)=new Function();
                         (yyval.functie)->Param.push_back(*(yyvsp[0].parameter));
                      }
#line 2151 "limbaj.tab.c"
    break;

  case 89: /* param_call: INT  */
#line 698 "limbaj.y"
                    { (yyval.parameter)=new Parameters("int",""); 
                  }
#line 2158 "limbaj.tab.c"
    break;

  case 90: /* param_call: FLOAT  */
#line 700 "limbaj.y"
                   { (yyval.parameter)=new Parameters("float",""); 
          }
#line 2165 "limbaj.tab.c"
    break;

  case 91: /* param_call: BOOL  */
#line 702 "limbaj.y"
                  { (yyval.parameter)=new Parameters("bool",""); 
           }
#line 2172 "limbaj.tab.c"
    break;

  case 92: /* param_call: ID  */
#line 704 "limbaj.y"
                    {  bool ok; string type;
                      for (auto &var : global_variabile) 
                          if(var.name==(yyvsp[0].string))
                            { ok=1; type=var.type; }
                     if(ok==0)
                        {string err="Variable '"+string((yyvsp[0].string))+"' was not declared!"; yyerror(err.c_str());}
                     else
                        {(yyval.parameter)=new Parameters(type,(yyvsp[0].string)); }       
                    }
#line 2186 "limbaj.tab.c"
    break;

  case 93: /* declarations: TYPE ID  */
#line 715 "limbaj.y"
                     {   
                        if(existsVar((yyvsp[0].string))==0)   
                            {   
                            if(currentTable==mainTable)
                             { (yyval.variabila)=new Variable((yyvsp[0].string),(yyvsp[-1].string));
                               variabile.push_back(*(yyval.variabila));
                               global_variabile.push_back(*(yyval.variabila)); }
                             else
                               currentTable->addVariable(Variable((yyvsp[0].string),(yyvsp[-1].string)));
                            }
                        else {
                              string err="Variable '"+string((yyvsp[0].string))+"' was already declared ";
                             yyerror(err.c_str());}
                     }
#line 2205 "limbaj.tab.c"
    break;

  case 94: /* declarations: TYPE ID '[' INT ']' ASSIGN '{' array_list '}'  */
#line 730 "limbaj.y"
                            {
                                char* token = strtok((yyvsp[-1].string), " ");
                                int index = 0;
                                while (token != NULL) 
                                    {
                                        if (token[0] != '\0') 
                                            {
                                             
                                                (yyval.variabila)=new Variable((string((yyvsp[-7].string)) + "[" + to_string(index) + "]").c_str(),(yyvsp[-8].string));
                                                variabile.push_back(*(yyval.variabila));
                                                global_variabile.push_back(*(yyval.variabila));
                                                index++;
                                                if(index>(yyvsp[-5].num))
                                                    {   
                                                        string err="Array's '"+string((yyvsp[-7].string))+"' max size is: "+to_string((yyvsp[-5].num));
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        token = strtok(NULL, " ");
                                    }
                            }
#line 2231 "limbaj.tab.c"
    break;

  case 95: /* array_list: array_list ',' INT  */
#line 754 "limbaj.y"
                {
                        (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string)) + strlen(to_string((yyvsp[0].num)).c_str()) + 2); 
                        strcpy((yyval.string), (yyvsp[-2].string));
                        strcat((yyval.string), to_string((yyvsp[0].num)).c_str());
                        strcat((yyval.string), " ");
                }
#line 2242 "limbaj.tab.c"
    break;

  case 96: /* array_list: array_list ',' FLOAT  */
#line 761 "limbaj.y"
                {
                        (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string)) + strlen(to_string((yyvsp[0].num_with_dot)).c_str()) + 2); 
                        strcpy((yyval.string), (yyvsp[-2].string));
                        strcat((yyval.string), to_string((yyvsp[0].num_with_dot)).c_str());
                        strcat((yyval.string), " ");
                }
#line 2253 "limbaj.tab.c"
    break;

  case 97: /* array_list: INT  */
#line 768 "limbaj.y"
                {
                    (yyval.string) = strdup(to_string((yyvsp[0].num)).c_str()); 
                    strcat((yyval.string), " ");
                }
#line 2262 "limbaj.tab.c"
    break;

  case 98: /* array_list: FLOAT  */
#line 773 "limbaj.y"
                {
                    (yyval.string) = strdup(to_string((yyvsp[0].num_with_dot)).c_str()); 
                    strcat((yyval.string), " ");
                }
#line 2271 "limbaj.tab.c"
    break;

  case 99: /* assignments: ID ASSIGN '(' expression ')'  */
#line 779 "limbaj.y"
                                           { 
              
              if(!existsVar((yyvsp[-4].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-4].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
              else if(TypeOf((yyvsp[-4].string))!=ast.getroot()->type) 
                                    {   
                                        string err="Variables '"+string((yyvsp[-4].string))+"' and '"+ast.getroot()->type+"' have different types";    
                                        yyerror(err.c_str());
                                    }
               else{    
                  for (auto &var : global_variabile) 
                  if(var.name==(yyvsp[-4].string))
                  {
                      (yyval.variabila)=new Variable("",(yyvsp[-4].string),ast.evaluateTree().c_str());
                     var.value=(yyval.variabila)->value;
                  }
                }

            }
#line 2298 "limbaj.tab.c"
    break;

  case 100: /* assignments: ID '[' INT ']' ASSIGN '(' expression ')'  */
#line 801 "limbaj.y"
                                                       { 
               string id=string((yyvsp[-7].string))+"["+to_string((yyvsp[-5].num))+"]";
              if(!existsVar(id.c_str()))
                                    { 
                                        string err="Variable '"+string(id.c_str())+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
              else if(TypeOf(id.c_str())!=ast.getroot()->type) 
                                    {   
                                        string err="Variables '"+string(id.c_str())+"' and '"+ast.getroot()->type+"' have different types";    
                                        yyerror(err.c_str());
                                    }
               else{    
                  for (auto &var : global_variabile) 
                  if(var.name==id)
                  {
                      (yyval.variabila)=new Variable("",(yyvsp[-7].string),ast.evaluateTree().c_str());
                     var.value=(yyval.variabila)->value;
                  }
                }

            }
#line 2325 "limbaj.tab.c"
    break;

  case 101: /* assignments: ID ASSIGN ID  */
#line 824 "limbaj.y"
                        {    
                              if(!existsVar((yyvsp[-2].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(!existsVar((yyvsp[0].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[0].string))+"' was not declared ";   
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf((yyvsp[-2].string))!=TypeOf((yyvsp[0].string))) 
                                    {   
                                        string err="Variables '"+string((yyvsp[-2].string))+"' and '"+string((yyvsp[0].string))+"' have different types";    
                                        yyerror(err.c_str());
                                    }
                              else  { 
                                        string val=getValue((yyvsp[0].string));
                                        
                                        for (auto &var : global_variabile) 
                                            if(var.name==(yyvsp[0].string))
                                              val=var.value;
                                        for (auto &var : global_variabile) 
                                          if(var.name==(yyvsp[-2].string))
                                            var.value=val;

                                        

                                    }     
                        }
#line 2360 "limbaj.tab.c"
    break;

  case 102: /* assignments: ID ASSIGN INT  */
#line 855 "limbaj.y"
                        { 
                              if(!existsVar((yyvsp[-2].string)))
                                    {
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf((yyvsp[-2].string))!="int")
                                    {
                                        string err="Cannot assign 'int' to an '"+TypeOf((yyvsp[-2].string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                       

                                        for (auto &var : global_variabile) 
                                          if(var.name==(yyvsp[-2].string))
                                            {
                                                  (yyval.variabila)=new Variable("",(yyvsp[-2].string),to_string((yyvsp[0].num)).c_str());
                                                  var.value=(yyval.variabila)->value;
                                             }
                                        
                                            
                                    }             
                        }
#line 2389 "limbaj.tab.c"
    break;

  case 103: /* assignments: ID ASSIGN FLOAT  */
#line 880 "limbaj.y"
                        { 
                              if(!existsVar((yyvsp[-2].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf((yyvsp[-2].string))!="float")
                                    {
                                        string err="Cannot assign 'float' to an '"+TypeOf((yyvsp[-2].string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                       
                                        for (auto &var : global_variabile) 
                                          if(var.name==(yyvsp[-2].string))
                                           {
                                              (yyval.variabila)=new Variable("",(yyvsp[-2].string),to_string((yyvsp[0].num_with_dot)).c_str());
                                              var.value=(yyval.variabila)->value;
                                           }
                                    }             
                        }
#line 2415 "limbaj.tab.c"
    break;

  case 104: /* assignments: ID ASSIGN BOOL  */
#line 902 "limbaj.y"
                        {   
                              if(!existsVar((yyvsp[-2].string)))
                                    {
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                             else if(TypeOf((yyvsp[-2].string))!="bool")
                                    {
                                        string err="Cannot assign 'bool' to an'"+TypeOf((yyvsp[-2].string))+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                       
                                       for (auto &var : global_variabile) 
                                          if(var.name==(yyvsp[-2].string))
                                           {   string val=to_string((yyvsp[0].bolean)).c_str();
                                               if(val=="1")
                                                  val="true";
                                                if(val=="0")
                                                  val="false";
                                                    
                                               (yyval.variabila)=new Variable("",(yyvsp[-2].string),val);
                                               var.value=(yyval.variabila)->value;
                                            
                                            }
                                    }             
                        }
#line 2447 "limbaj.tab.c"
    break;

  case 105: /* assignments: ID ASSIGN CHAR  */
#line 930 "limbaj.y"
                        { 
                              if(!existsVar((yyvsp[-2].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf((yyvsp[-2].string))!="char")
                                    {
                                        string err="Cannot assign 'char' to an '"+TypeOf((yyvsp[-2].string))+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        string str(1,(yyvsp[0].chr));
                                         for (auto &var : global_variabile) 
                                          if(var.name==(yyvsp[-2].string))
                                           {
                                              (yyval.variabila)=new Variable("",(yyvsp[-2].string),to_string((yyvsp[0].chr)).c_str());
                                              var.value=(yyval.variabila)->value;
                                           }
                                    }             
                        }
#line 2473 "limbaj.tab.c"
    break;

  case 106: /* assignments: ID ASSIGN STRING  */
#line 952 "limbaj.y"
                        {   
                              if(!existsVar((yyvsp[-2].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf((yyvsp[-2].string))!="string")
                                    {
                                        string err="Cannot assign 'string' to an'"+TypeOf((yyvsp[-2].string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                      
                                        for (auto &var : global_variabile) 
                                          if(var.name==(yyvsp[-2].string))
                                            var.value=(yyvsp[0].string);
                                    }             
                        }
#line 2496 "limbaj.tab.c"
    break;

  case 107: /* assignments: ID '[' INT ']' ASSIGN INT  */
#line 971 "limbaj.y"
                        {
                              string id=string((yyvsp[-5].string))+"["+to_string((yyvsp[-3].num))+"]";
                              if(!existsVar(id.c_str()))
                                    {
                                         string err="Variable '"+ string(id.c_str())+"' was not declared ";
                                         yyerror(err.c_str());
                                    }
                              else if(TypeOf(id.c_str())!="int")
                                    {
                                         string err="Cannot assign 'int' to an '"+TypeOf(id.c_str())+"'";
                                         yyerror(err.c_str());
                                    }
                              else  {
                                        
                                           for (auto &var :global_variabile) 
                                             if(var.name==id)
                                               var.value=to_string((yyvsp[0].num)).c_str();
                                         
                                    }
                        }
#line 2521 "limbaj.tab.c"
    break;

  case 108: /* assignments: CONST TYPE ID  */
#line 992 "limbaj.y"
                    { yyerror("Constant must have value assigned at declaration!");}
#line 2527 "limbaj.tab.c"
    break;

  case 109: /* assignments: CONST TYPE ID ASSIGN INT  */
#line 994 "limbaj.y"
                                    {   
                                         if(!existsVar((yyvsp[-2].string)))   
                                             {        
                                                if(strcmp((yyvsp[-3].string),"int")==0)
                                                    {    string type=(yyvsp[-3].string);
                                                       
                                                         (yyval.variabila)=new Variable((yyvsp[-2].string),type,to_string((yyvsp[0].num)).c_str());
                                                         (yyval.variabila)->constanta="const";
                                                         variabile.push_back(*(yyval.variabila));
                                                         global_variabile.push_back(*(yyval.variabila));
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-2].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type int"; 
                                                        yyerror(err.c_str());
                                                    }
                                             }                    
                                         else 
                                             {  
                                                yyerror("variable already declared");
                                             }
                                    }
#line 2554 "limbaj.tab.c"
    break;

  case 110: /* assignments: CONST TYPE ID ASSIGN FLOAT  */
#line 1017 "limbaj.y"
                                    {   
                                        if(!existsVar((yyvsp[-2].string)))   
                                            {   
                                                if(strcmp((yyvsp[-3].string),"float")==0)
                                                    {
                                                       
                                                         string type=string("const ")+(yyvsp[-3].string);
                                                         (yyval.variabila)=new Variable((yyvsp[-2].string),type,to_string((yyvsp[0].num_with_dot)).c_str());
                                                         variabile.push_back(*(yyval.variabila));
                                                          global_variabile.push_back(*(yyval.variabila));
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-3].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type float"; 
                                                        yyerror(err.c_str());
                                                    }
                                            }                    
                                        else 
                                            {  
                                                yyerror("variable already declared");
                                            }    

                                    }
#line 2582 "limbaj.tab.c"
    break;

  case 111: /* assignments: CONST TYPE ID ASSIGN BOOL  */
#line 1041 "limbaj.y"
                                    { 
                                        if (!existsVar((yyvsp[-2].string))) 
                                            {
                                                if (strcmp((yyvsp[-3].string), "bool") == 0) 
                                                    {
                                                      
                                                         string type=string("const ")+(yyvsp[-3].string);
                                                         (yyval.variabila)=new Variable((yyvsp[-2].string),type,to_string((yyvsp[0].bolean)).c_str());
                                                         variabile.push_back(*(yyval.variabila));
                                                           global_variabile.push_back(*(yyval.variabila));
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-2].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type bool";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
#line 2609 "limbaj.tab.c"
    break;

  case 112: /* assignments: CONST TYPE ID ASSIGN CHAR  */
#line 1064 "limbaj.y"
                                    {
                                        if (!existsVar((yyvsp[-2].string))) 
                                            {
                                                if (strcmp((yyvsp[-3].string), "char") == 0) 
                                                    {
                                                        string str(1,(yyvsp[0].chr));
                                                
                                                         string type=string("const ")+(yyvsp[-3].string);
                                                         (yyval.variabila)=new Variable((yyvsp[-2].string),type,to_string((yyvsp[0].chr)).c_str());
                                                         variabile.push_back(*(yyval.variabila));
                                                        global_variabile.push_back(*(yyval.variabila));
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-2].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type char";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
#line 2637 "limbaj.tab.c"
    break;

  case 113: /* assignments: CONST TYPE ID ASSIGN STRING  */
#line 1088 "limbaj.y"
                                    {
                                        if (!existsVar((yyvsp[-2].string))) 
                                            {
                                                if (strcmp((yyvsp[-3].string), "string") == 0) 
                                                    {
                                                      
                                                         string type=string("const ")+(yyvsp[-3].string);
                                                   
                                                         (yyval.variabila)=new Variable((yyvsp[-2].string),type,(yyvsp[0].string));
                                                         variabile.push_back(*(yyval.variabila));
                                                        global_variabile.push_back(*(yyval.variabila));
                                                    } 
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-2].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type string";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }                                            
                                    }
#line 2665 "limbaj.tab.c"
    break;

  case 114: /* print: '(' expression ')'  */
#line 1115 "limbaj.y"
        {
           (yyval.nod) = (yyvsp[-1].nod);  
        }
#line 2673 "limbaj.tab.c"
    break;

  case 115: /* expression: expression '+' expression  */
#line 1120 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            {
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' + '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node { (yyvsp[-2].nod), (yyvsp[0].nod), "+",(yyvsp[-2].nod)->type }; 
                        ast.AddNode("+",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 2691 "limbaj.tab.c"
    break;

  case 116: /* expression: expression '-' expression  */
#line 1134 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type) 
                            {
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' - '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node { (yyvsp[-2].nod), (yyvsp[0].nod), "-",(yyvsp[-2].nod)->type }; 
                        ast.AddNode("-",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 2709 "limbaj.tab.c"
    break;

  case 117: /* expression: expression '*' expression  */
#line 1148 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")  
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            {
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' * '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node { (yyvsp[-2].nod), (yyvsp[0].nod), "*",(yyvsp[-2].nod)->type }; 
                        ast.AddNode("*",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 2727 "limbaj.tab.c"
    break;

  case 118: /* expression: expression '/' expression  */
#line 1162 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            {   
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' / '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node { (yyvsp[-2].nod), (yyvsp[0].nod), "/",(yyvsp[-2].nod)->type }; 
                        ast.AddNode("/",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);}
#line 2744 "limbaj.tab.c"
    break;

  case 119: /* expression: expression '^' expression  */
#line 1175 "limbaj.y"
                   { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            {
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' ^ '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "^",(yyvsp[-2].nod)->type}; 
                        ast.AddNode("^",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 2762 "limbaj.tab.c"
    break;

  case 120: /* expression: expression AND expression  */
#line 1189 "limbaj.y"
                   {
                        if((yyvsp[-2].nod)->type=="int"||(yyvsp[-2].nod)->type=="float"||(yyvsp[0].nod)->type=="int"||(yyvsp[0].nod)->type=="float")
                            {
                                string err="Operation && only supports bool operands ! '"+(yyvsp[-2].nod)->type+"' && '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                            (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod),"&&",(yyvsp[-2].nod)->type}; 
                            ast.AddNode("&&",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 2776 "limbaj.tab.c"
    break;

  case 121: /* expression: expression OR expression  */
#line 1199 "limbaj.y"
                   {
                         if((yyvsp[-2].nod)->type=="int"||(yyvsp[-2].nod)->type=="float"||(yyvsp[0].nod)->type=="int"||(yyvsp[0].nod)->type=="float")
                            {
                                string err="Operation || only supports bool operands ! '"+(yyvsp[-2].nod)->type+"' || '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                            (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod),"||",(yyvsp[-2].nod)->type}; 
                            ast.AddNode("||",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 2790 "limbaj.tab.c"
    break;

  case 122: /* expression: NOT expression  */
#line 1209 "limbaj.y"
                    {
                        if((yyvsp[0].nod)->type=="int"||(yyvsp[0].nod)->type=="float")
                            {
                                string err="Operation ! only supports bool operand! !'"+(yyvsp[0].nod)->type+"''";
                                yyerror(err.c_str());
                            }
                            (yyval.nod) = new Node{(yyvsp[0].nod), NULL,"!",(yyvsp[0].nod)->type}; 
                            ast.AddNode("!",(yyvsp[0].nod),NULL,(yyvsp[0].nod)->type); }
#line 2803 "limbaj.tab.c"
    break;

  case 123: /* expression: expression LT expression  */
#line 1218 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            { 
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' < '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                            (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "<","bool"}; 
                            ast.AddNode("<",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 2820 "limbaj.tab.c"
    break;

  case 124: /* expression: expression LE expression  */
#line 1231 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            {
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' <= '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                            (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "<=","bool"}; 
                            ast.AddNode("<=",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 2837 "limbaj.tab.c"
    break;

  case 125: /* expression: expression GT expression  */
#line 1244 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                        {
                            string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' > '"+(yyvsp[0].nod)->type+"'";
                            yyerror(err.c_str());
                        }
                        (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), ">","bool"}; 
                        ast.AddNode(">",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 2854 "limbaj.tab.c"
    break;

  case 126: /* expression: expression GE expression  */
#line 1257 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                        {
                            string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' >= '"+(yyvsp[0].nod)->type+"'";
                            yyerror(err.c_str());
                        }
                        (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), ">=","bool"}; 
                        ast.AddNode(">=",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 2871 "limbaj.tab.c"
    break;

  case 127: /* expression: expression EQ expression  */
#line 1270 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                        {
                            string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' == '"+(yyvsp[0].nod)->type+"'";
                            yyerror(err.c_str());
                        }
                        (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "==","bool"}; 
                        ast.AddNode("==",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");
                    }
#line 2889 "limbaj.tab.c"
    break;

  case 128: /* expression: expression NEQ expression  */
#line 1284 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                        {
                            string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' != '"+(yyvsp[0].nod)->type+"'";
                            yyerror(err.c_str());
                        }
                        (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "!=","bool"}; 
                        ast.AddNode("!=",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 2906 "limbaj.tab.c"
    break;

  case 129: /* expression: '(' expression ')'  */
#line 1297 "limbaj.y"
                        {
                            (yyval.nod)=(yyvsp[-1].nod);
                        }
#line 2914 "limbaj.tab.c"
    break;

  case 130: /* expression: INT  */
#line 1301 "limbaj.y"
                        { 
                            (yyval.nod) = new Node{NULL, NULL, to_string((yyvsp[0].num)),"int"}; 
                            ast.AddNode(to_string((yyvsp[0].num)),NULL,NULL,"int");
                        }
#line 2923 "limbaj.tab.c"
    break;

  case 131: /* expression: FLOAT  */
#line 1306 "limbaj.y"
                        {
                            (yyval.nod)=new Node{NULL,NULL,to_string((yyvsp[0].num_with_dot)),"float"};
                            ast.AddNode(to_string((yyvsp[0].num_with_dot)),NULL,NULL,"float");
                        }
#line 2932 "limbaj.tab.c"
    break;

  case 132: /* expression: BOOL  */
#line 1311 "limbaj.y"
                        {
                            (yyval.nod)=new Node{NULL,NULL,(yyvsp[0].bolean)?"true":"false","bool"};
                            ast.AddNode((yyvsp[0].bolean)?"true":"false",NULL,NULL,"bool");
                        }
#line 2941 "limbaj.tab.c"
    break;

  case 133: /* expression: STRING  */
#line 1316 "limbaj.y"
                        {
                             (yyval.nod)=new Node{NULL,NULL,(yyvsp[0].string),"string"};
                             ast.AddNode((yyvsp[0].string),NULL,NULL,"string");
                        }
#line 2950 "limbaj.tab.c"
    break;

  case 134: /* expression: ID  */
#line 1321 "limbaj.y"
                        {
                        if(!existsVar((yyvsp[0].string)))
                            {
                                string err="Variable '"+string((yyvsp[0].string))+"' was not declared!";
                                yyerror(err.c_str());
                            }
                        (yyval.nod)=new Node{NULL,NULL,getValue((yyvsp[0].string)),TypeOf((yyvsp[0].string))}; 
                        ast.AddNode(getValue((yyvsp[0].string)),NULL,NULL,TypeOf((yyvsp[0].string)));
                        }
#line 2964 "limbaj.tab.c"
    break;


#line 2968 "limbaj.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1336 "limbaj.y"


void yyerror(const char * s)
    {
        printf("error: %s line:%d\n",s,yylineno);
    }  

int main(int argc, char** argv)
{
     yyin=fopen(argv[1],"r");
     yyparse();
} 
