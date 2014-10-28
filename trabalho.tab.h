/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_TRABALHO_TAB_H_INCLUDED
# define YY_YY_TRABALHO_TAB_H_INCLUDED
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
    T_EQ = 258,
    T_NEQ = 259,
    T_LT = 260,
    T_GT = 261,
    T_LE = 262,
    T_GE = 263,
    T_EQEQ = 264,
    T_AND = 265,
    T_OR = 266,
    T_TIMES = 267,
    T_DIVIDE = 268,
    T_PLUS = 269,
    T_MINUS = 270,
    T_COLON = 271,
    T_SEMICOLON = 272,
    T_COMMA = 273,
    T_LEFTBRACES = 274,
    T_RIGHTBRACES = 275,
    T_NOT = 276,
    T_CHAR = 277,
    T_STRING = 278,
    T_ID = 279,
    T_NUMBER = 280,
    R_INTEGER = 281,
    R_CHAR = 282,
    R_BOOLEAN = 283,
    R_STRING = 284,
    R_VAR = 285,
    R_THEN = 286,
    R_IF = 287,
    R_ELSE = 288,
    R_WHILE = 289,
    R_DO = 290,
    R_BREAK = 291,
    R_TRUE = 292,
    R_FALSE = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "trabalho.y" /* yacc.c:1909  */

	int integer;
	int boolean;
	char character;
	struct identificador *id;
	char *string;
	int sToken;
	int label;

#line 103 "trabalho.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRABALHO_TAB_H_INCLUDED  */
