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
    COM = 258,
    COL = 259,
    PER = 260,
    SEM = 261,
    PAR_L = 262,
    PAR_R = 263,
    SBRA_L = 264,
    SBRA_R = 265,
    LOOPDOT = 266,
    ADD = 267,
    SUB = 268,
    MUL = 269,
    DIV = 270,
    REM = 271,
    ASS = 272,
    AND = 273,
    OR = 274,
    NOT = 275,
    LE = 276,
    LEEQ = 277,
    GREQ = 278,
    GR = 279,
    EQ = 280,
    NEQ = 281,
    BEGIN_TOKEN = 282,
    BOOLEAN = 283,
    BREAK = 284,
    CHARACTER = 285,
    CASE = 286,
    CONTINUE = 287,
    CONSTANT = 288,
    DECLARE = 289,
    DO = 290,
    ELSE = 291,
    END = 292,
    EXIT = 293,
    FLOAT = 294,
    FOR = 295,
    IF = 296,
    IN = 297,
    INTEGER = 298,
    LOOP = 299,
    PRINT = 300,
    PRINTLN = 301,
    PROCEDURE = 302,
    PROGRAM = 303,
    RETURN = 304,
    STRING = 305,
    WHILE = 306,
    THEN = 307,
    READ = 308,
    TRUE = 309,
    FALSE = 310,
    INT_VAL = 311,
    FLOAT_VAL = 312,
    STRING_VAL = 313,
    BOOL_VAL = 314,
    ID = 315,
    UMINUS = 316
  };
#endif
/* Tokens.  */
#define COM 258
#define COL 259
#define PER 260
#define SEM 261
#define PAR_L 262
#define PAR_R 263
#define SBRA_L 264
#define SBRA_R 265
#define LOOPDOT 266
#define ADD 267
#define SUB 268
#define MUL 269
#define DIV 270
#define REM 271
#define ASS 272
#define AND 273
#define OR 274
#define NOT 275
#define LE 276
#define LEEQ 277
#define GREQ 278
#define GR 279
#define EQ 280
#define NEQ 281
#define BEGIN_TOKEN 282
#define BOOLEAN 283
#define BREAK 284
#define CHARACTER 285
#define CASE 286
#define CONTINUE 287
#define CONSTANT 288
#define DECLARE 289
#define DO 290
#define ELSE 291
#define END 292
#define EXIT 293
#define FLOAT 294
#define FOR 295
#define IF 296
#define IN 297
#define INTEGER 298
#define LOOP 299
#define PRINT 300
#define PRINTLN 301
#define PROCEDURE 302
#define PROGRAM 303
#define RETURN 304
#define STRING 305
#define WHILE 306
#define THEN 307
#define READ 308
#define TRUE 309
#define FALSE 310
#define INT_VAL 311
#define FLOAT_VAL 312
#define STRING_VAL 313
#define BOOL_VAL 314
#define ID 315
#define UMINUS 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 74 "yacc.y" /* yacc.c:1909  */

    int intVal;
    float floatVal;
    char* stringVal;
    bool boolVal;

#line 183 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
