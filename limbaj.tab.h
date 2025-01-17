/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BGINMAIN = 258,                /* BGINMAIN  */
    ENDMAIN = 259,                 /* ENDMAIN  */
    ASSIGN = 260,                  /* ASSIGN  */
    BGINCLASS = 261,               /* BGINCLASS  */
    ENDCLASS = 262,                /* ENDCLASS  */
    CONST = 263,                   /* CONST  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    FOR = 267,                     /* FOR  */
    BGINGLOBAL = 268,              /* BGINGLOBAL  */
    ENDGLOBAL = 269,               /* ENDGLOBAL  */
    BGINFUNC = 270,                /* BGINFUNC  */
    ENDFUNC = 271,                 /* ENDFUNC  */
    PRINT = 272,                   /* PRINT  */
    LT = 273,                      /* LT  */
    LE = 274,                      /* LE  */
    GT = 275,                      /* GT  */
    GE = 276,                      /* GE  */
    EQ = 277,                      /* EQ  */
    NEQ = 278,                     /* NEQ  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    NOT = 281,                     /* NOT  */
    ID = 282,                      /* ID  */
    TYPE = 283,                    /* TYPE  */
    TYPEOF = 284,                  /* TYPEOF  */
    INT = 285,                     /* INT  */
    FLOAT = 286,                   /* FLOAT  */
    BOOL = 287,                    /* BOOL  */
    CHAR = 288,                    /* CHAR  */
    STRING = 289,                  /* STRING  */
    CLASS = 290                    /* CLASS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "limbaj.y"

    int num;
    float num_with_dot;
    bool bolean;
    char chr;
    char* string;
struct Node *nod;
struct ParamInfo *parametru;
struct Function *functie;
struct Function *metoda; 
struct Parameters *parameter;
struct Variable *variabila;

#line 113 "limbaj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */
