/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NL = 258,
    PRINT = 259,
    WHILE = 260,
    FOR = 261,
    IF = 262,
    IN = 263,
    ELSE = 264,
    TRUE1 = 265,
    FALSE1 = 266,
    NUMB = 267,
    STRI = 268,
    id = 269,
    COPEN = 270,
    BROPEN = 271,
    BRCLOSE = 272,
    T_pl = 273,
    T_min = 274,
    T_mul = 275,
    T_div = 276,
    T_lt = 277,
    T_gt = 278,
    T_eq = 279,
    T_and = 280,
    T_or = 281,
    T_ass = 282,
    T_eqeq = 283,
    T_le = 284,
    T_ge = 285,
    T_ne = 286
  };
#endif
/* Tokens.  */
#define NL 258
#define PRINT 259
#define WHILE 260
#define FOR 261
#define IF 262
#define IN 263
#define ELSE 264
#define TRUE1 265
#define FALSE1 266
#define NUMB 267
#define STRI 268
#define id 269
#define COPEN 270
#define BROPEN 271
#define BRCLOSE 272
#define T_pl 273
#define T_min 274
#define T_mul 275
#define T_div 276
#define T_lt 277
#define T_gt 278
#define T_eq 279
#define T_and 280
#define T_or 281
#define T_ass 282
#define T_eqeq 283
#define T_le 284
#define T_ge 285
#define T_ne 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
