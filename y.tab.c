/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

/*---------------------------------------*/
/*--------------- Parser ----------------*/
/*---------------------------------------*/
#include "lex.yy.c"
#include <fstream>
#include <stack>
#define Trace(t) cout << t << endl

using namespace std;

void yyerror(string t);


// e.g.
// T = "VAR_INT", VorC = "CON"
// return "CON_INT"
string changeVarCon(string T,string VorC){
    if(VorC.length()!=3){
        cout << "changeVarCon error" << endl;
        return T;
    }
    string temp(T);
    temp[0] = VorC[0];
    temp[1] = VorC[1];
    temp[2] = VorC[2];
    return temp;
}

SymbolTable *scope;
Symbol *symbol;

// for syntax
bool flag;
vector<string> parameter;


// for branch (e.g. goto L1 goto L2)
int branchIndex; 
stack<int> branchStack;
bool elseBranch = false;

// for file
string fileName = "";
string jasmName = "";
ofstream fout;

void fileWrite(ofstream &f, string s){
    f << s << endl;
}


// for store val 
int int_value = 0; 
float float_value = 0.0; 
string string_value = "";  
bool bool_value = false;

void clear_val() {     
    int_value = 0; 
    float_value = 0.0; 
    string_value = "";  
    bool_value = false;
}


#line 133 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 74 "yacc.y" /* yacc.c:355  */

    int intVal;
    float floatVal;
    char* stringVal;
    bool boolVal;

#line 302 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 319 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   107,   108,   109,   110,   114,   115,   119,
     118,   149,   150,   154,   155,   159,   160,   161,   165,   228,
     296,   367,   399,   445,   488,   493,   494,   495,   496,   501,
     502,   507,   524,   506,   612,   613,   616,   617,   620,   641,
     643,   669,   678,   677,   694,   695,   698,   699,   700,   701,
     702,   706,   735,   739,   739,   757,   757,   775,   775,   793,
     793,   811,   815,   841,   892,   892,   961,   979,  1028,  1033,
    1032,  1041,  1055,  1040,  1067,  1075,  1074,  1091,  1091,  1102,
    1107,  1119,  1124,  1106,  1137,  1160,  1136,  1194,  1203,  1212,
    1231,  1249,  1267,  1285,  1289,  1301,  1328,  1355,  1382,  1409,
    1436,  1463,  1481,  1499,  1513,  1515,  1527,  1532,  1534,  1539,
    1541,  1543,  1581,  1582,  1585
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COM", "COL", "PER", "SEM", "PAR_L",
  "PAR_R", "SBRA_L", "SBRA_R", "LOOPDOT", "ADD", "SUB", "MUL", "DIV",
  "REM", "ASS", "AND", "OR", "NOT", "LE", "LEEQ", "GREQ", "GR", "EQ",
  "NEQ", "BEGIN_TOKEN", "BOOLEAN", "BREAK", "CHARACTER", "CASE",
  "CONTINUE", "CONSTANT", "DECLARE", "DO", "ELSE", "END", "EXIT", "FLOAT",
  "FOR", "IF", "IN", "INTEGER", "LOOP", "PRINT", "PRINTLN", "PROCEDURE",
  "PROGRAM", "RETURN", "STRING", "WHILE", "THEN", "READ", "TRUE", "FALSE",
  "INT_VAL", "FLOAT_VAL", "STRING_VAL", "BOOL_VAL", "ID", "UMINUS",
  "$accept", "EMPTY", "type", "opt_SEM", "ada", "$@1", "var_d_block",
  "var_d_stats", "var_d_stat", "var_d", "const_d", "array_d",
  "constant_expression", "proc_d_blocks", "proc_d_block", "$@2", "$@3",
  "formal_arguments", "arguments", "argument", "return_type",
  "block_in_proc", "main_block", "$@4", "statements", "statement",
  "simple_stmt", "$@5", "$@6", "$@7", "$@8", "function_invocation", "$@9",
  "procedure_invocation", "comma_separated_expressions", "$@10",
  "conditional_stmt", "$@11", "$@12", "opt_else", "$@13",
  "block_simple_stmt", "$@14", "while_loop", "$@15", "$@16", "$@17",
  "for_loop", "$@18", "$@19", "integer_expression", "boolean_expression",
  "expression", "bool_val", "array_reference", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -155

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-155)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,   -52,    24,  -155,  -155,    -1,   -22,  -155,    -8,     6,
    -155,   -22,  -155,  -155,  -155,   -19,  -155,    21,    -8,    67,
    -155,    47,  -155,  -155,  -155,    17,  -155,  -155,    15,  -155,
    -155,  -155,    52,  -155,  -155,  -155,  -155,  -155,    46,  -155,
      48,   225,     7,   104,    47,  -155,     3,    47,  -155,    37,
    -155,    50,   107,    36,   108,   112,     8,  -155,    56,     9,
    -155,    98,   225,  -155,  -155,  -155,  -155,  -155,   136,   128,
     142,   140,   145,   148,   152,   147,   104,  -155,  -155,   103,
      36,    36,    36,  -155,  -155,  -155,    18,  -155,   118,   327,
    -155,  -155,   164,    36,   165,    36,  -155,   143,    36,   167,
      36,    36,    36,   168,  -155,  -155,  -155,  -155,    47,  -155,
     169,  -155,   104,  -155,    37,  -155,    -1,   134,   274,  -155,
     357,  -155,    36,  -155,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,   175,    36,
     196,  -155,   133,  -155,   170,   115,   172,   327,   217,  -155,
     174,  -155,  -155,  -155,   156,   155,   139,  -155,    36,   193,
     225,    93,    93,  -155,  -155,  -155,   357,   342,   109,   109,
     109,   109,   109,   109,   293,  -155,   312,  -155,  -155,   178,
     201,   188,  -155,  -155,   225,   146,   202,   199,  -155,  -155,
     180,    -1,   218,   219,   225,  -155,    36,    36,   189,   136,
     171,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
     238,   222,  -155,   226,   225,   200,   208,  -155,  -155,   203,
    -155,   205,   204,  -155,   136,   136,   225,  -155,  -155,  -155,
     212,   211,   136,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     1,     2,     0,    11,     2,     0,
      12,    13,    15,    16,    17,     0,    29,     0,     2,     0,
      21,     0,    14,    31,    42,     0,    30,     5,     0,     6,
       3,     4,     0,   112,   113,    25,    28,    26,     0,    27,
       2,     2,     0,     0,     0,    18,     0,     0,    19,     0,
      34,     2,     0,     0,    55,    59,     0,    80,     0,    66,
      44,     0,     2,    46,    48,    47,    49,    50,     2,     0,
       0,     0,     0,     0,     0,    36,     0,    39,    32,     0,
       0,     0,     0,   106,   107,   108,   111,   110,     0,    88,
     105,   109,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,    45,     8,     7,    10,     0,    23,
       0,    20,     0,    35,     0,    40,     2,     0,     0,    94,
     103,    64,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,    61,     0,    68,     0,    87,     0,    43,
       0,    24,    38,    37,     0,     0,     0,   104,     0,     0,
      77,    89,    90,    91,    92,    93,   101,   102,    95,    96,
      98,    97,    99,   100,     0,    56,     0,    60,    81,     0,
       0,     0,    51,    22,     2,     0,     0,     0,   114,    79,
       2,     2,     0,     0,    77,    67,     0,     0,     0,     2,
       0,    65,    75,    74,    72,    78,    54,    58,    82,    70,
       0,     0,    33,     0,    77,     0,     0,    52,    41,     0,
      76,     0,     0,    84,     2,     2,    77,    73,    83,    85,
       0,     0,     2,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,    -5,   -23,  -112,  -155,  -155,   253,   256,  -155,  -155,
    -155,  -155,   -38,   250,  -155,  -155,  -155,  -155,   158,  -155,
    -155,    78,  -155,  -155,   -58,   -40,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -151,  -155,  -155,  -155,  -155,  -155,
    -155,  -154,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
     151,   177,   -51,   -10,  -155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,    32,   107,     2,     5,   154,    10,    11,    12,
      13,    14,    38,    17,    18,    40,   116,    51,    74,    75,
      78,   155,    25,    41,    61,   189,    63,    92,    93,    94,
      95,    87,   158,    64,   144,   180,    65,   160,   215,   204,
     214,   190,   191,    66,    98,   194,   216,    67,   226,   230,
     146,    88,   145,    90,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    62,    89,    16,   104,    97,    70,   187,     3,    72,
      19,    39,    20,    16,    96,    80,   100,     1,   101,    43,
      69,    81,    62,    21,     4,   121,   102,   122,    82,   118,
     119,   120,    44,     6,    39,    50,    60,    39,     9,    15,
     208,    23,   138,    80,   140,   209,    77,    89,    24,    81,
     147,   148,    48,   115,    42,    49,    82,    60,    45,    71,
     220,    46,    33,    34,    83,    84,    85,    68,    86,    47,
     150,   147,   229,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   212,   176,   152,
      33,    34,    83,    84,    85,    27,    86,    73,    39,    76,
      28,    33,    34,    35,    36,    37,    29,   126,   127,   128,
      30,     7,   227,   228,    79,   -53,    99,    31,   -69,   -57,
     233,   124,   125,   126,   127,   128,   198,   124,   125,   126,
     127,   128,    27,   129,   130,   103,   131,   132,   133,   134,
     135,   136,   105,    29,    62,   108,   210,    30,   109,   141,
     110,   111,   112,   114,    31,   124,   125,   126,   127,   128,
     113,   129,   130,   117,   131,   132,   133,   134,   135,   136,
     123,   137,   139,   143,   149,   151,   156,   178,   179,    60,
     183,   175,   181,   184,   195,   203,     7,   124,   125,   126,
     127,   128,   185,   129,   130,   186,   131,   132,   133,   134,
     135,   136,   177,   188,   196,   197,   199,   201,   124,   125,
     126,   127,   128,   200,   129,   130,   202,   131,   132,   133,
     134,   135,   136,   182,   206,   207,   211,   213,   218,   124,
     125,   126,   127,   128,   219,   129,   130,   221,   131,   132,
     133,   134,   135,   136,   217,   222,   224,   223,   225,   231,
     124,   125,   126,   127,   128,   232,   129,   130,     8,   131,
     132,   133,   134,   135,   136,    52,    53,    22,    26,   205,
      54,    55,   153,   159,    56,   142,    57,     0,    58,     0,
       0,     0,   157,     0,     0,    59,   124,   125,   126,   127,
     128,     0,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   192,     0,     0,     0,   124,   125,   126,   127,   128,
       0,   129,   130,     0,   131,   132,   133,   134,   135,   136,
     193,     0,     0,     0,   124,   125,   126,   127,   128,     0,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   124,
     125,   126,   127,   128,     0,   129,   130,     0,   131,   132,
     133,   134,   135,   136,   124,   125,   126,   127,   128,     0,
     129,     0,     0,   131,   132,   133,   134,   135,   136,   124,
     125,   126,   127,   128,     0,     0,     0,     0,   131,   132,
     133,   134,   135,   136
};

static const yytype_int16 yycheck[] =
{
       5,    41,    53,     8,    62,    56,    44,   158,    60,    47,
       4,    21,     6,    18,     6,     7,     7,    48,     9,     4,
      43,    13,    62,    17,     0,     7,    17,     9,    20,    80,
      81,    82,    17,    34,    44,    40,    41,    47,    60,    47,
     194,    60,    93,     7,    95,   196,    51,    98,    27,    13,
     101,   102,     6,    76,    37,     7,    20,    62,     6,    56,
     214,     9,    54,    55,    56,    57,    58,    60,    60,    17,
     108,   122,   226,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   199,   139,   112,
      54,    55,    56,    57,    58,    28,    60,    60,   108,    49,
      33,    54,    55,    56,    57,    58,    39,    14,    15,    16,
      43,   116,   224,   225,     7,     7,    60,    50,     3,     7,
     232,    12,    13,    14,    15,    16,   184,    12,    13,    14,
      15,    16,    28,    18,    19,    37,    21,    22,    23,    24,
      25,    26,     6,    39,   184,    17,   197,    43,     6,     6,
      10,     6,     4,     6,    50,    12,    13,    14,    15,    16,
       8,    18,    19,    60,    21,    22,    23,    24,    25,    26,
      52,     7,     7,     6,     6,     6,    42,    44,     8,   184,
       6,     6,    10,    27,     6,   190,   191,    12,    13,    14,
      15,    16,    37,    18,    19,    56,    21,    22,    23,    24,
      25,    26,     6,    10,     3,    17,    60,     8,    12,    13,
      14,    15,    16,    11,    18,    19,    36,    21,    22,    23,
      24,    25,    26,     6,     6,     6,    37,    56,     6,    12,
      13,    14,    15,    16,     8,    18,    19,    37,    21,    22,
      23,    24,    25,    26,     6,    37,    41,    44,    44,    37,
      12,    13,    14,    15,    16,    44,    18,    19,     5,    21,
      22,    23,    24,    25,    26,    40,    41,    11,    18,   191,
      45,    46,   114,   122,    49,    98,    51,    -1,    53,    -1,
      -1,    -1,     8,    -1,    -1,    60,    12,    13,    14,    15,
      16,    -1,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
       8,    -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    12,
      13,    14,    15,    16,    -1,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    12,    13,    14,    15,    16,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    66,    60,     0,    67,    34,    63,    68,    60,
      69,    70,    71,    72,    73,    47,    63,    75,    76,     4,
       6,    17,    69,    60,    27,    84,    75,    28,    33,    39,
      43,    50,    64,    54,    55,    56,    57,    58,    74,   115,
      77,    85,    37,     4,    17,     6,     9,    17,     6,     7,
      63,    79,    40,    41,    45,    46,    49,    51,    53,    60,
      63,    86,    87,    88,    95,    98,   105,   109,    60,    64,
      74,    56,    74,    60,    80,    81,    49,    63,    82,     7,
       7,    13,    20,    56,    57,    58,    60,    93,   113,   114,
     115,   116,    89,    90,    91,    92,     6,   114,   106,    60,
       7,     9,    17,    37,    86,     6,    63,    65,    17,     6,
      10,     6,     4,     8,     6,    64,    78,    60,   114,   114,
     114,     7,     9,    52,    12,    13,    14,    15,    16,    18,
      19,    21,    22,    23,    24,    25,    26,     7,   114,     7,
     114,     6,   113,     6,    96,   114,   112,   114,   114,     6,
      74,     6,    64,    80,    68,    83,    42,     8,    94,   112,
      99,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,     6,   114,     6,    44,     8,
      97,    10,     6,     6,    27,    37,    56,    96,    10,    87,
     103,   104,     8,     8,   107,     6,     3,    17,    86,    60,
      11,     8,    36,    63,   101,    83,     6,     6,   103,    96,
     114,    37,    65,    56,   102,   100,   108,     6,     6,     8,
     103,    37,    37,    44,    41,    44,   110,    65,    65,   103,
     111,    37,    44,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    65,    65,    67,
      66,    68,    68,    69,    69,    70,    70,    70,    71,    71,
      71,    71,    72,    72,    73,    74,    74,    74,    74,    75,
      75,    77,    78,    76,    79,    79,    80,    80,    81,    82,
      82,    83,    85,    84,    86,    86,    87,    87,    87,    87,
      87,    88,    88,    89,    88,    90,    88,    91,    88,    92,
      88,    88,    88,    88,    94,    93,    95,    95,    96,    97,
      96,    99,   100,    98,   101,   102,   101,   104,   103,   103,
     106,   107,   108,   105,   110,   111,   109,   112,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   115,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     1,     1,     1,     0,
       9,     1,     2,     1,     2,     1,     1,     1,     4,     4,
       6,     2,     8,     6,     7,     1,     1,     1,     1,     1,
       2,     0,     0,    10,     1,     3,     1,     3,     3,     1,
       2,     5,     0,     5,     1,     2,     1,     1,     1,     1,
       1,     4,     7,     0,     6,     0,     4,     0,     6,     0,
       4,     3,     2,     3,     0,     5,     1,     5,     1,     0,
       4,     0,     0,    10,     1,     0,     3,     0,     2,     1,
       0,     0,     0,    10,     0,     0,    15,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 107 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_INT"; }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 108 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_STRING";}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 109 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_BOOL";}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_FLOAT";}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "yacc.y" /* yacc.c:1646  */
    { 
        /* new a SymbolTable and its scope name is string($2) */
        scope = new SymbolTable(string((yyvsp[0].stringVal))); 

    // java
        fileWrite(fout,"class " + string((yyvsp[0].stringVal)));
        fileWrite(fout,"{");

        
    }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "yacc.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[-7].stringVal), (yyvsp[-1].stringVal))!=0){
            yyerror("Program ID not the same.");
        }

        SymbolTable *trash = scope;
        scope = scope->parentTable;
        delete trash;
    
    // java
        fileWrite(fout,"}");
    }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 166 "yacc.y" /* yacc.c:1646  */
    {
            if (scope->Lookup_Local(string((yyvsp[-3].stringVal))) == NULL) {
                scope->insert(string((yyvsp[-3].stringVal)), string((yyvsp[-1].stringVal)));
            }
            else {
                yyerror("\'" + string(string((yyvsp[-3].stringVal))) + "\' had been declared.");
            }

        // java
            symbol = scope->Lookup_Local(string((yyvsp[-3].stringVal)));
            if(symbol == NULL){
                yyerror("error: " + string((yyvsp[-3].stringVal)) + " not found.");
            }
            else{
                if(scope->parentTable == NULL){
                // global scope
                    if (symbol->type == "VAR_BOOL") {
                    // be used
                        symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                        symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;
                    // declare
                        fileWrite(fout, "field static int " + symbol->name);
                    }
                    else if(symbol->type == "VAR_INT") {
                        symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                        symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;
                        fileWrite(fout, "field static int " + symbol->name);
                    }
                    else {
                        yyerror("error: only integer and boolean variable in proj3.");
                    }
                }
                else{
                    // local scope
                    symbol->loadCode = "iload " + to_string(scope->IndexCounter);
                    symbol->storeCode = "istore " + to_string(scope->IndexCounter);
                    scope->IndexCounter++;

                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            // true -> 1, false -> 0
		            		fileWrite(fout,"iconst_1");
		            	}
		            	else {
		            		fileWrite(fout,"iconst_0");
		            	}
		            	fileWrite(fout,symbol->storeCode);
		            	clear_val();
		            }
		            else if (symbol->type == "VAR_INT") {
                        // local push to local array
		            	fileWrite(fout, "sipush " + to_string(int_value));
			            fileWrite(fout,symbol->storeCode);
		            	clear_val();
	            	}
                    else {
                        yyerror("error: only integer and boolean variable in proj3.");
                    }
                }
        // java end
            }
        }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 229 "yacc.y" /* yacc.c:1646  */
    {
            if (scope->Lookup_Local(string((yyvsp[-3].stringVal))) == NULL) {
                scope->insert(string((yyvsp[-3].stringVal)), string((yyvsp[-1].stringVal)));
            } 
            else {
                yyerror("\'" + string(string((yyvsp[-3].stringVal))) + "\' had been declared.");
            }

        // java
            symbol = scope->Lookup_Local(string((yyvsp[-3].stringVal)));
            if(symbol == NULL){
                yyerror("error: " + string((yyvsp[-3].stringVal)) + " not found.");
            }
            else {
                if(scope->parentTable == NULL){
                // global scope
                    symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                    symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;

                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            fileWrite(fout, "field static int " + symbol->name + " = 1");
                        } 
                        else {
                            fileWrite(fout, "field static int " + symbol->name + " = 0");
                        }
                        clear_val();
                    } 
                    else if (symbol->type == "VAR_INT") {
                        fileWrite(fout, "field static int " + symbol->name + " = " + to_string(int_value));
                        clear_val();
                    }
                    else{
                        // type not int or bool
                        yyerror("error: only integer and boolean variable in proj3.");
                    }
                    
                }
                else {
                    // local scope
                    symbol->loadCode = "iload " + to_string(scope->IndexCounter);
                    symbol->storeCode = "istore " + to_string(scope->IndexCounter);
                    scope->IndexCounter++;
                    
                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            fileWrite(fout, "iconst_1");
                        } 
                        else {
                            fileWrite(fout, "iconst_0");
                        }
                        fileWrite(fout, symbol->storeCode);
                        clear_val();
                    } 
                    else if (symbol->type == "VAR_INT") {
                        fileWrite(fout, "sipush " + to_string(int_value));
                        fileWrite(fout, symbol->storeCode);
                        clear_val();
                    }
                    else {
                        yyerror("error: only integer and boolean variable in proj3.");
                    }

                }
            }
        // java end
        }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 297 "yacc.y" /* yacc.c:1646  */
    {
            if (scope->Lookup_Local(string((yyvsp[-5].stringVal))) == NULL) {
                scope->insert(string((yyvsp[-5].stringVal)), string((yyvsp[-3].stringVal)));
                if (string((yyvsp[-3].stringVal)) != string((yyvsp[-1].stringVal))) {
                    yyerror("type error: not the same.");
                }
            } 
            else {
                yyerror("\'" + string(string((yyvsp[-5].stringVal))) + "\' had been declared.");
            }

        // Java 
            symbol = scope->Lookup_Local(string((yyvsp[-5].stringVal)));
            if(symbol == NULL){
                yyerror("error: " + string((yyvsp[-5].stringVal)) + " not found.");
            }
            else{
                if(scope->parentTable == NULL){
                // global scope
                    symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                    symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;

                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            fileWrite(fout, "field static int " + symbol->name + " = 1");
                        } 
                        else {
                            fileWrite(fout, "field static int " + symbol->name + " = 0");
                        }
                        clear_val();
                    } 
                    else if (symbol->type == "VAR_INT") {
                        fileWrite(fout, "field static int " + symbol->name + " = " + to_string(int_value));
                        clear_val();
                    }
                    else{
                        // type not int or bool
                        yyerror("error: only integer and boolean variable in proj3.");
                    }
                    
                }
                else {
                    // local scope
                    symbol->loadCode = "iload " + to_string(scope->IndexCounter);
                    symbol->storeCode = "istore " + to_string(scope->IndexCounter);
                    scope->IndexCounter++;
                    
                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            fileWrite(fout, "iconst_1");
                        } 
                        else {
                            fileWrite(fout, "iconst_0");
                        }
                        fileWrite(fout, symbol->storeCode);
                        clear_val();
                    } 
                    else if (symbol->type == "VAR_INT") {
                        fileWrite(fout, "sipush " + to_string(int_value));
                        fileWrite(fout, symbol->storeCode);
                        clear_val();
                    }
                    else {
                        yyerror("error: only integer and boolean variable in proj3.");
                    }

                }
            }
        // java end
        }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 368 "yacc.y" /* yacc.c:1646  */
    {
            if (scope->Lookup_Local(string((yyvsp[-1].stringVal))) == NULL) {
                scope->insert(string((yyvsp[-1].stringVal)),"NON");
            } 
            else {
                yyerror("\'" + string(string((yyvsp[-1].stringVal))) + "\' had been declared.");
            }

        // java
            symbol = scope->Lookup_Local(string((yyvsp[-1].stringVal)));
            if(symbol == NULL){
                yyerror("error: " + string((yyvsp[-1].stringVal)) + " not found.");
            }
            else{
                if(scope->parentTable == NULL){
                // global scope
                    symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                    symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;
                    fileWrite(fout, "field static int " + symbol->name);
                }
                else{
                // local scope
                    symbol->loadCode = "iload " + to_string(scope->IndexCounter);
                    symbol->storeCode = "istore " + to_string(scope->IndexCounter);
                    scope->IndexCounter++;
                }
            }
        }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 400 "yacc.y" /* yacc.c:1646  */
    {
            if (scope->Lookup_Local(string((yyvsp[-7].stringVal))) == NULL) {
                scope->insert(string((yyvsp[-7].stringVal)), changeVarCon(string((yyvsp[-3].stringVal)),"CON"));
                if (string((yyvsp[-3].stringVal)) != string((yyvsp[-1].stringVal))) {
                // if type != CON_expr.type
                    yyerror("type error: not the same.");
                }
            } 
            else {
                yyerror("\'" + string(string((yyvsp[-7].stringVal))) + "\' had been declared.");
            }

        // java
            symbol = scope->Lookup_Local(string((yyvsp[-7].stringVal)));
            if (symbol == NULL) {
                yyerror("error: " + string((yyvsp[-7].stringVal)) + " not found.");
            }
            else {
                if (symbol->type == "CON_BOOL") {
                    if (bool_value) {
                        symbol->loadCode = "iconst_1";
                    } 
                    else {
                        symbol->loadCode = "iconst_0";
                    }
                    clear_val();
                } 
                else if (symbol->type == "CON_INT") {
                    symbol->loadCode = "sipush " + to_string(int_value);
                    clear_val();
                } 
                else if (symbol->type == "CON_FLOAT") {
                    symbol->loadCode = "sipush " + to_string(float_value);
                    clear_val();
                }
                else if (symbol->type == "CON_STRING") {
                    symbol->loadCode = "ldc \"" + string_value + "\"";
                    clear_val();
                } 
                else {
                    yyerror("type error: should be CON_*.");
                }
            }
        // java end
        }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 446 "yacc.y" /* yacc.c:1646  */
    {
            if (scope->Lookup_Local(string((yyvsp[-5].stringVal))) == NULL) {
                scope->insert(string((yyvsp[-5].stringVal)),changeVarCon(string((yyvsp[-1].stringVal)),"CON"));
            } 
            else {
                yyerror("\'" + string(string((yyvsp[-5].stringVal))) + "\' had been declared.");
            }
        // java
            symbol = scope->Lookup_Local(string((yyvsp[-5].stringVal)));
            if (symbol == NULL) {
                yyerror("error: " + string((yyvsp[-5].stringVal)) + " not found.");
            }
            else {
                if (symbol->type == "CON_BOOL") {
                    if (bool_value) {
                        symbol->loadCode = "iconst_1";
                    } 
                    else {
                        symbol->loadCode = "iconst_0";
                    }
                    clear_val();
                } 
                else if (symbol->type == "CON_INT") {
                    symbol->loadCode = "sipush " + to_string(int_value);
                    clear_val();
                } 
                else if (symbol->type == "CON_FLOAT") {
                    symbol->loadCode = "sipush " + to_string(float_value);
                    clear_val();
                } 
                else if (symbol->type == "CON_STRING") {
                    symbol->loadCode = "ldc \"" + string_value + "\"";
                    clear_val();
                } 
                else {
                    yyerror("type error: should be CON_*.");
                }
            }
        // java end
        }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 489 "yacc.y" /* yacc.c:1646  */
    { yyerror("no array in proj3."); }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 493 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_INT"; int_value = (yyvsp[0].intVal);}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 494 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_STRING"; string_value = (yyvsp[0].stringVal);}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 495 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_BOOL"; bool_value = (yyvsp[0].boolVal);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 496 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_STRING"; float_value = (yyvsp[0].floatVal);}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 507 "yacc.y" /* yacc.c:1646  */
    {
            if (scope->Lookup_Local(string((yyvsp[0].stringVal))) == NULL) {
                flag = true;
                scope->insert(string((yyvsp[0].stringVal)), "PROC_NON");
                symbol = scope->Lookup_Local(string((yyvsp[0].stringVal)));
                SymbolTable *child = new SymbolTable(string((yyvsp[0].stringVal)), scope);
                scope = child;
                
            } 
            else {
                flag = false;
                yyerror("\'" + string(string((yyvsp[0].stringVal))) + "\' had been declared.");
            }

        }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 524 "yacc.y" /* yacc.c:1646  */
    {
        // java
            // procedure -> method
            string str_temp("method public static ");
            string str_temp2("invokestatic ");
            char c_temp = scope->returnType[5];
            
            if(c_temp == 'N'){
                str_temp += "void ";
                str_temp2 += "void";
            }
            else if(c_temp == 'I'){
                str_temp += "int ";
                str_temp2 += "int ";
            }
            else if(c_temp == 'F'){
                str_temp += "float ";
                str_temp2 += "float ";
            }
            else if(c_temp == 'S'){
                str_temp += "string ";
                str_temp2 += "string ";
            }
            else if(c_temp == 'B'){
                str_temp += "bool ";
                str_temp2 += "bool ";
            }

            str_temp += string((yyvsp[-3].stringVal));
            str_temp += "(";

            str_temp2 += scope->parentTable->name;
            str_temp2 += ".";
            str_temp2 += string((yyvsp[-3].stringVal));
            str_temp2 += "(";
            
            for(int i=0;i<symbol->argumentType.size();i++){
                //cout << symbol->argumentType[i]<<endl;
                if(i>=1) {
                    str_temp+=", ";
                    str_temp2+=", ";    
                }
                if(symbol->argumentType[i][4] == 'I'){
                    str_temp+="int";
                    str_temp2+="int";
                }
                else if(symbol->argumentType[i][4] == 'B'){
                    str_temp+="bool";
                    str_temp2+="bool";
                }
                else if(symbol->argumentType[i][4] == 'S'){
                    str_temp+="string";
                    str_temp2+="string";
                }
                else if(symbol->argumentType[i][4] == 'C'){
                    str_temp+="char";
                    str_temp2+="char";
                }
            }
            str_temp+=")";
            str_temp2+=")";
            
            symbol->loadCode = str_temp2;
            fileWrite(fout,str_temp);
            fileWrite(fout,"max_stack 15");
            fileWrite(fout,"max_locals 15");
            fileWrite(fout,"{");
            str_temp = "";
            str_temp2 = "";
        // java end
        }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 597 "yacc.y" /* yacc.c:1646  */
    {   
            if(scope->returnType == "PROC_NON") fileWrite(fout,"return");
            fileWrite(fout,"}");
            if(strcmp((yyvsp[-8].stringVal),(yyvsp[-1].stringVal))!=0){
                yyerror("procedure ID not the same");
            }
            { 
                SymbolTable *trash = scope;
                scope = scope->parentTable;
                delete trash;  
            }
        }
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 621 "yacc.y" /* yacc.c:1646  */
    {
            if(flag){
                symbol->argumentType.push_back(string((yyvsp[0].stringVal)));
            }
            scope->insert(string((yyvsp[-2].stringVal)),string((yyvsp[0].stringVal)));

        // java
	        if (scope->Lookup_Global(string((yyvsp[-2].stringVal))) != NULL) {
		        scope->Lookup_Global(string((yyvsp[-2].stringVal)))->loadCode = "iload " + to_string(scope->IndexCounter);
		        scope->Lookup_Global(string((yyvsp[-2].stringVal)))->storeCode = "istore " + to_string(scope->IndexCounter);
		        scope->IndexCounter++;
	        }
            else {
                yyerror( string((yyvsp[-2].stringVal)) + " not found.");
            }
        // java end
        }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 642 "yacc.y" /* yacc.c:1646  */
    { scope->returnType = "PROC_NON"; }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 644 "yacc.y" /* yacc.c:1646  */
    {
            /* if procedure successfully declared flag is true */
            if(flag){
                if(string((yyvsp[0].stringVal)) == "VAR_INT"){
                    symbol->type = "PROC_INT";
                    scope->returnType = "PROC_INT";
                }
                else if(string((yyvsp[0].stringVal)) == "VAR_FLOAT"){
                    symbol->type = "PROC_FLOAT";
                    scope->returnType = "PROC_FLOAT";
                }
                else if(string((yyvsp[0].stringVal)) == "VAR_STRING"){
                    symbol->type = "PROC_STRING";
                    scope->returnType = "PROC_STRING";
                }
                else if(string((yyvsp[0].stringVal)) == "VAR_BOOL"){
                    symbol->type = "PROC_BOOL";
                    scope->returnType = "PROC_BOOL";
                }
            }
            
        }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 678 "yacc.y" /* yacc.c:1646  */
    {
            fileWrite(fout,"method public static void main(java.lang.String[])");
            fileWrite(fout,"max_stack 15");
            fileWrite(fout,"max_locals 15");
            fileWrite(fout,"{");
        }
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 686 "yacc.y" /* yacc.c:1646  */
    {
            fileWrite(fout,"return");
            fileWrite(fout,"}");
        }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 707 "yacc.y" /* yacc.c:1646  */
    {
            symbol = scope->Lookup_Global(string((yyvsp[-3].stringVal)));
            /*if ID found*/
            if (symbol != NULL) {
                if (symbol->type == "NON") {
                    symbol->type = string((yyvsp[-1].stringVal));
                //Java
                    fileWrite(fout, symbol->storeCode);
                //Java end
                } 
                else if (symbol->type == "VAR_INT" ||  symbol->type == "VAR_FLOAT"  
                    || symbol->type == "VAR_STRING" ||  symbol->type == "VAR_BOOL" ) {
                    if(symbol->type != string((yyvsp[-1].stringVal))){
                        yyerror("type error: not the same.");   
                    }
                //Java
                    fileWrite(fout, symbol->storeCode);
                //Java end
                }
                else{
                    yyerror(string((yyvsp[-3].stringVal)) + "not variable.");   
                }
            }
            else {
            /*ID not found*/
                yyerror("\'" + string((yyvsp[-3].stringVal)) + "\' not declared.");
            }
        }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 736 "yacc.y" /* yacc.c:1646  */
    {
            yyerror("no array in proj3.");
        }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 739 "yacc.y" /* yacc.c:1646  */
    { /* java */ fileWrite(fout, "getstatic java.io.PrintStream java.lang.System.out"); }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 741 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == "ERROR" || string((yyvsp[-2].stringVal)) == "NON") {
                yyerror("type error: can not print this type.");
            }
            else if(string((yyvsp[-2].stringVal)) == "VAR_INT" || string((yyvsp[-2].stringVal)) == "CON_INT" || string((yyvsp[-2].stringVal)) == "PROC_INT"
            || string((yyvsp[-2].stringVal)) == "VAR_BOOL" || string((yyvsp[-2].stringVal)) == "CON_BOOL" || string((yyvsp[-2].stringVal)) == "PROC_BOOL") {
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(int)");        
            // java end
            }
            else if(string((yyvsp[-2].stringVal)) == "VAR_STRING" || string((yyvsp[-2].stringVal)) == "CON_STRING" || string((yyvsp[-2].stringVal)) == "PROC_STRING"){
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(java.lang.String)");
            // java end
            }
        }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 757 "yacc.y" /* yacc.c:1646  */
    { /* java */ fileWrite(fout, "getstatic java.io.PrintStream java.lang.System.out"); }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 759 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-1].stringVal)) == "ERROR" || string((yyvsp[-1].stringVal)) == "NON") {
                yyerror("type error: can not print this type.");
            }
            else if(string((yyvsp[-1].stringVal)) == "VAR_INT" || string((yyvsp[-1].stringVal)) == "CON_INT" || string((yyvsp[-1].stringVal)) == "PROC_INT"
            || string((yyvsp[-1].stringVal)) == "VAR_BOOL" || string((yyvsp[-1].stringVal)) == "CON_BOOL" || string((yyvsp[-1].stringVal)) == "PROC_BOOL") {
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(int)");        
            // java end
            }
            else if(string((yyvsp[-1].stringVal)) == "VAR_STRING" || string((yyvsp[-1].stringVal)) == "CON_STRING" || string((yyvsp[-1].stringVal)) == "PROC_STRING"){
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(java.lang.String)");
            // java end
            }                                                              
        }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 775 "yacc.y" /* yacc.c:1646  */
    { fileWrite(fout, "getstatic java.io.PrintStream java.lang.System.out"); }
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 777 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == "ERROR" || string((yyvsp[-2].stringVal)) == "NON") {
                yyerror("type error: can not print this type.");
            }
            else if(string((yyvsp[-2].stringVal)) == "VAR_INT" || string((yyvsp[-2].stringVal)) == "CON_INT" || string((yyvsp[-2].stringVal)) == "PROC_INT"
            || string((yyvsp[-2].stringVal)) == "VAR_BOOL" || string((yyvsp[-2].stringVal)) == "CON_BOOL" || string((yyvsp[-2].stringVal)) == "PROC_BOOL") {
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(int)");        
            // java end
            }
            else if(string((yyvsp[-2].stringVal)) == "VAR_STRING" || string((yyvsp[-2].stringVal)) == "CON_STRING" || string((yyvsp[-2].stringVal)) == "PROC_STRING"){
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(java.lang.String)");
            // java end
            }
        }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 793 "yacc.y" /* yacc.c:1646  */
    { fileWrite(fout, "getstatic java.io.PrintStream java.lang.System.out"); }
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 795 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-1].stringVal)) == "ERROR" || string((yyvsp[-1].stringVal)) == "NON") {
                yyerror("type error: can not print this type.");
            }
            else if(string((yyvsp[-1].stringVal)) == "VAR_INT" || string((yyvsp[-1].stringVal)) == "CON_INT" || string((yyvsp[-1].stringVal)) == "PROC_INT"
            || string((yyvsp[-1].stringVal)) == "VAR_BOOL" || string((yyvsp[-1].stringVal)) == "CON_BOOL" || string((yyvsp[-1].stringVal)) == "PROC_BOOL") {
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(int)");        
            // java end
            }
            else if(string((yyvsp[-1].stringVal)) == "VAR_STRING" || string((yyvsp[-1].stringVal)) == "CON_STRING" || string((yyvsp[-1].stringVal)) == "PROC_STRING"){
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(java.lang.String)");
            // java end
            } 
        }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 812 "yacc.y" /* yacc.c:1646  */
    {
            yyerror("no READ in proj3.");
        }
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 816 "yacc.y" /* yacc.c:1646  */
    {
            fileWrite(fout,"return");

            SymbolTable *temp = scope;
            while(temp->returnType == "NON") {
                if (temp->parentTable == NULL) {
                    break;
                }
                temp = temp->parentTable;
            }
            

            if(temp->returnType != "PROC_NON") {
            /* => it need to return something*/
                if(temp->returnType == "PROC_INT"
                || temp->returnType == "PROC_FLOAT"
                || temp->returnType == "PROC_STRING"
                || temp->returnType == "PROC_BOOL") {
                    yyerror(temp->name + " need return value.");
                } 
                else {
                    yyerror("syntax error: return in this scope is illegal.");
                }
            }
        }
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 842 "yacc.y" /* yacc.c:1646  */
    {
            fileWrite(fout, "ireturn");

            SymbolTable *temp = scope;
            while(temp->returnType == "NON") {
                if (temp->parentTable == NULL) {
                    break;
                }
                temp = temp->parentTable;
            }

            if(temp->returnType != "PROC_NON") {
                if(temp->returnType == "PROC_INT"
                || temp->returnType == "PROC_FLOAT"
                || temp->returnType == "PROC_STRING"
                || temp->returnType == "PROC_BOOL") {
                    if(temp->returnType == "PROC_INT"){
                        if(string((yyvsp[-1].stringVal)) != "VAR_INT"){
                            yyerror("type error: procedure return type and the expression are not the same.");
                        }
                    }
                    else if(temp->returnType == "PROC_FLOAT"){
                        if(string((yyvsp[-1].stringVal)) != "VAR_FLOAT"){
                            yyerror("type error: procedure return type and the expression are not the same.");
                        }
                    }
                    else if(temp->returnType == "PROC_STRING"){
                        if(string((yyvsp[-1].stringVal)) != "VAR_STRING"){
                            yyerror("type error: procedure return type and the expression are not the same.");
                        }
                    }
                    else if(temp->returnType == "PROC_BOOL"){
                        if(string((yyvsp[-1].stringVal)) != "VAR_BOOL"){
                            yyerror("type error: procedure return type and the expression are not the same.");
                        }
                    }
                } 
                else {
                    if(temp->returnType == "PROC_NON") {
                        yyerror("syntax error: it doesnt need to return.");
                    } 
                    else {
                        yyerror("syntax error: return in this scope is illegal.");
                    }
                }
            }
        }
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 892 "yacc.y" /* yacc.c:1646  */
    { parameter.clear(); }
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 893 "yacc.y" /* yacc.c:1646  */
    {
            symbol=scope->Lookup_Global(string((yyvsp[-4].stringVal)));
            if(symbol == NULL){
                (yyval.stringVal) = (char*)"ERROR";
                yyerror(string(string((yyvsp[-4].stringVal))) + " not declared.");
            }
            else{
            // java
                fileWrite(fout,symbol->loadCode);

                if(symbol->type == "PROC_INT" 
                || symbol->type == "PROC_FLOAT" 
                || symbol->type == "PROC_STRING" 
                || symbol->type == "PROC_BOOL"){ 
                    if(symbol->type == "PROC_INT"){
                        (yyval.stringVal) = (char*)"VAR_INT";
                    }
                    else if(symbol->type == "PROC_FLOAT"){
                        (yyval.stringVal) = (char*)"VAR_FLOAT";
                    }
                    else if(symbol->type == "PROC_STRING"){
                        (yyval.stringVal) = (char*)"VAR_STRING";
                    }
                    else if(symbol->type == "PROC_BOOL"){
                        (yyval.stringVal) = (char*)"VAR_BOOL";
                    }
                    if(symbol->argumentType.size() == parameter.size()){     
                       bool typeFlag=true; 
                       for(int i = 0; i < symbol->argumentType.size(); i++){
                            if(symbol->argumentType[i] == "VAR_INT"){
                                if(parameter[i] != "VAR_INT"){
                                    typeFlag=false;
                                }
                            }
                            else if(symbol->argumentType[i] == "VAR_FLOAT"){
                                if(parameter[i] != "VAR_FLOAT"){
                                    typeFlag=false;
                                }
                            }
                            else if(symbol->argumentType[i] == "VAR_STRING"){
                                if(parameter[i] != "VAR_STRING"){
                                    typeFlag=false;
                                }
                            }
                            else if(symbol->argumentType[i] == "VAR_BOOL"){
                                if(parameter[i] != "VAR_BOOL"){
                                    typeFlag=false;
                                }
                            }
                       }
                       if(!typeFlag){
                                    (yyval.stringVal) = (char*)"ERROR";
                                    yyerror(string(string((yyvsp[-4].stringVal))) + " 's arguments is not match.");
                       }
                    }
                    else{                                                   
                        (yyval.stringVal) = (char*)"ERROR";
                        yyerror(string(string((yyvsp[-4].stringVal))) + " arguments size is not match.");
                    }
                }
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror(string(string((yyvsp[-4].stringVal))) + " no return.");   
                }
            }
        }
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 962 "yacc.y" /* yacc.c:1646  */
    {
            symbol = scope->Lookup_Global(string((yyvsp[0].stringVal)));
            if (symbol == NULL) {
                yyerror("\'" + string(string((yyvsp[0].stringVal))) + "\' not declared.");
            } 
            else {
            // java
                fileWrite(fout, symbol->loadCode);
            // java end
                if (symbol->type != "PROC_NON") {
                yyerror("\'" + string(string((yyvsp[0].stringVal))) + "\' is not non-return procedure.");
                }
                if (symbol->argumentType.size() != 0) {
                    yyerror("\'" + string(string((yyvsp[0].stringVal))) + "\' need arguments.");
                } 
            }
        }
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 980 "yacc.y" /* yacc.c:1646  */
    {
            symbol = scope->Lookup_Global(string((yyvsp[-4].stringVal)));
            if (symbol == NULL) {
                yyerror("\'" + string(string((yyvsp[-4].stringVal))) + "\' not declared.");
            } 
            else {
            // Java 
                fileWrite(fout, symbol->loadCode);

                if (symbol->type != "PROC_NON") {
                    yyerror("\'" + string(string((yyvsp[-4].stringVal))) + "\' is not non-return procedure.");
                }
                if (symbol->argumentType.size() == parameter.size()) {
                    bool typeFlag = true;
                    for (int i = 0; i < symbol->argumentType.size(); i++) {
                        if(symbol->argumentType[i]== "PROC_INT"){
                            if(parameter[i] != "VAR_INT"){
                                typeFlag=false;
                            }
                        }
                        else if(symbol->argumentType[i] == "PROC_FLOAT"){
                            if(parameter[i] != "VAR_FLOAT"){
                                typeFlag=false;
                            }
                        }
                        else if(symbol->argumentType[i] == "PROC_STRING"){
                            if(parameter[i] != "VAR_STRING"){
                                typeFlag=false;
                            }
                        }
                        else if(symbol->argumentType[i] == "PROC_BOOL"){
                            if(parameter[i] != "VAR_BOOL"){
                                typeFlag=false;
                            }
                        }
                    }
                    if (!typeFlag) {
                        yyerror("type error: \'" + string(string((yyvsp[-4].stringVal))) + "\' parameter type is not match.");
                    }
                } 
                else {
                    yyerror("syntax error: \'" + string(string((yyvsp[-4].stringVal))) + "\' parameter amounts is not match.");
                }
            }
            
        }
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1029 "yacc.y" /* yacc.c:1646  */
    {
            parameter.push_back(string((yyvsp[0].stringVal)));
        }
#line 2608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1033 "yacc.y" /* yacc.c:1646  */
    {
            parameter.push_back(string((yyvsp[0].stringVal)));
        }
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1041 "yacc.y" /* yacc.c:1646  */
    {
        // java
            elseBranch = false;
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchIndex += 2;

            fileWrite(fout, "ifeq L" + to_string(branchStack.top()));
            branchStack.pop();
        }
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1055 "yacc.y" /* yacc.c:1646  */
    {
        // java
            if (elseBranch) {
                fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            }
            branchStack.pop();
        }
#line 2645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1068 "yacc.y" /* yacc.c:1646  */
    {
        // java
            branchStack.pop();
            fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            branchStack.pop();
        }
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1075 "yacc.y" /* yacc.c:1646  */
    {
        // java
            elseBranch = true;

            int gotoIndex = branchStack.top();
            branchStack.pop();
            int labelIndex = branchStack.top();
            branchStack.pop();

            fileWrite(fout, "goto L" + to_string(gotoIndex));
            fileWrite(fout, "L" + to_string(labelIndex) + ":");
        }
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1091 "yacc.y" /* yacc.c:1646  */
    {
            SymbolTable* child = new SymbolTable("TEMP",scope);
            scope = child;
        }
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1096 "yacc.y" /* yacc.c:1646  */
    { 
            // exit this scope
            SymbolTable *trash = scope;
            scope = scope->parentTable;
            delete trash;
        }
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1107 "yacc.y" /* yacc.c:1646  */
    {
        // java
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchIndex += 2;

            fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            branchStack.pop();
        }
#line 2709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1119 "yacc.y" /* yacc.c:1646  */
    {
            fileWrite(fout, "ifeq L" + to_string(branchStack.top()));
            branchStack.pop();
        }
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1124 "yacc.y" /* yacc.c:1646  */
    {
            int gotoIndex = branchStack.top();
            branchStack.pop();
            int labelIndex = branchStack.top();
            branchStack.pop();

            fileWrite(fout, "goto L" + to_string(gotoIndex));
            fileWrite(fout, "L" + to_string(labelIndex) + ":");
        }
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1137 "yacc.y" /* yacc.c:1646  */
    {
            symbol = scope->Lookup_Global(string((yyvsp[-6].stringVal)));
            if (symbol == NULL) {
                yyerror("\'" + string(string((yyvsp[-6].stringVal))) + "\' not declared.");
            } 
            else if (symbol->type != "VAR_INT") {
                yyerror("type error: \'" + string(string((yyvsp[-6].stringVal))) + "\' not integer.");
            }
        //java
            fileWrite(fout, "sipush " + to_string((yyvsp[-4].intVal)));
            fileWrite(fout, symbol->storeCode);

            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchIndex += 2;

            fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            branchStack.pop();
        // java end
        }
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1160 "yacc.y" /* yacc.c:1646  */
    {
        // java
            fileWrite(fout, "sipush " + to_string((yyvsp[-4].intVal)));
            symbol = scope->Lookup_Global((yyvsp[-8].stringVal));
            if (symbol != NULL) {
                fileWrite(fout, symbol->loadCode);
            }

            fileWrite(fout, "isub");
            fileWrite(fout, "ifeq L" + to_string(branchStack.top()));
            branchStack.pop();

            fileWrite(fout, "iconst_1");
            if (symbol != NULL) {
                fileWrite(fout, symbol->loadCode);
            }

            fileWrite(fout, "iadd");
            if (symbol != NULL) {
                fileWrite(fout, symbol->storeCode);
            }

            fileWrite(fout, "goto L" + to_string(branchStack.top()));
            branchStack.pop();

            fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            branchStack.pop();
        // java end
        }
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1195 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[0].stringVal)) != "VAR_INT") {
                yyerror("type error: The type is not integer.");
            }
        }
#line 2803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1204 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[0].stringVal)) != "VAR_BOOL") {
                yyerror("type error: The type is not boolean.");
            }
        }
#line 2813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1213 "yacc.y" /* yacc.c:1646  */
    {
            if(string(string((yyvsp[-2].stringVal))) == string(string((yyvsp[0].stringVal)))){
                if( string(string((yyvsp[-2].stringVal))) == "VAR_INT" ||  string((yyvsp[-2].stringVal)) == "VAR_FLOAT" 
                ||  string((yyvsp[-2].stringVal)) == "VAR_STRING" || string((yyvsp[-2].stringVal)) == "VAR_CHAR"){
                    (yyval.stringVal) = (char*)((yyvsp[-2].stringVal));  
                }
                else{
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("type error: this type can not ADD.");  
                }
            }
            else{        
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same.");
            }
        // java
            fileWrite(fout,"iadd");
        }
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1232 "yacc.y" /* yacc.c:1646  */
    {
            if(string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))){
                if( string((yyvsp[-2].stringVal)) == "VAR_INT" ||  string((yyvsp[-2].stringVal)) == "VAR_FLOAT" || string((yyvsp[-2].stringVal)) == "VAR_CHAR"){
                    (yyval.stringVal) = (char*)((yyvsp[-2].stringVal));  
                }
                else{
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("type error: this type can not SUB.");  
                }
            }
            else{        
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same.");
            }
        // java
            fileWrite(fout,"isub");
        }
#line 2858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1250 "yacc.y" /* yacc.c:1646  */
    {
            if(string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))){
                if( string((yyvsp[-2].stringVal)) == "VAR_INT" ||  string((yyvsp[-2].stringVal)) == "VAR_FLOAT"){
                    (yyval.stringVal) = (char*)((yyvsp[-2].stringVal));  
                }
                else{
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("type error: this type can not MUL.");  
                }
            }
            else{        
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same.");
            }
        // java
            fileWrite(fout,"imul");
        }
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1268 "yacc.y" /* yacc.c:1646  */
    {
            if(string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))){
                if( string((yyvsp[-2].stringVal)) == "VAR_INT" ||  string((yyvsp[-2].stringVal)) == "VAR_FLOAT"){
                    (yyval.stringVal) = (char*)((yyvsp[-2].stringVal));  
                }
                else{
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("type error: this type can not DIV.");  
                }
            }
            else{        
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same.");
            }
        // java
            fileWrite(fout, "idiv");
        }
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1286 "yacc.y" /* yacc.c:1646  */
    {
            yyerror("no % operation in proj3.");
        }
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1290 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[0].stringVal)) == "VAR_INT" || string((yyvsp[0].stringVal)) == "VAR_FLOAT") {
                (yyval.stringVal) = (char*)((yyvsp[0].stringVal));
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("This types can not UMINUS.");
            }
        // java
            fileWrite(fout, "ineg");
        }
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1302 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))) {
                if (string((yyvsp[-2].stringVal)) == "VAR_INT" || string((yyvsp[-2].stringVal)) == "VAR_FLOAT" || string((yyvsp[-2].stringVal)) == "VAR_CHAR") {
                    (yyval.stringVal) = (char*)"VAR_BOOL";
                } 
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("syntax error: can not LE.");
                }
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "iflt L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1329 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))) {
                if (string((yyvsp[-2].stringVal)) == "VAR_INT" || string((yyvsp[-2].stringVal)) == "VAR_FLOAT" || string((yyvsp[-2].stringVal)) == "VAR_CHAR") {
                    (yyval.stringVal) = (char*)"VAR_BOOL";
                } 
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("syntax error: can not LEEQ.");
                }
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifle L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
#line 2988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1356 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))) {
                if (string((yyvsp[-2].stringVal)) == "VAR_INT" || string((yyvsp[-2].stringVal)) == "VAR_FLOAT" || string((yyvsp[-2].stringVal)) == "VAR_CHAR") {
                    (yyval.stringVal) = (char*)"VAR_BOOL";
                } 
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("syntax error: can not GR.");
                }
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifgt L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
#line 3019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1383 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))) {
                if (string((yyvsp[-2].stringVal)) == "VAR_INT" || string((yyvsp[-2].stringVal)) == "VAR_FLOAT" || string((yyvsp[-2].stringVal)) == "VAR_CHAR") {
                    (yyval.stringVal) = (char*)"VAR_BOOL";
                } 
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("syntax error: can not GREQ.");
                }
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifge L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end   
        }
#line 3050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1410 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))) {
                if (string((yyvsp[-2].stringVal)) == "VAR_INT" || string((yyvsp[-2].stringVal)) == "VAR_FLOAT" || string((yyvsp[-2].stringVal)) == "VAR_CHAR") {
                    (yyval.stringVal) = (char*)"VAR_BOOL";
                } 
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("syntax error: can not EQ.");
                }
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifeq L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
#line 3081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1437 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))) {
                if (string((yyvsp[-2].stringVal)) == "VAR_INT" || string((yyvsp[-2].stringVal)) == "VAR_FLOAT" || string((yyvsp[-2].stringVal)) == "VAR_CHAR") {
                    (yyval.stringVal) = (char*)"VAR_BOOL";
                } 
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("syntax error: can not NEQ.");
                }
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifne L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
#line 3112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1464 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))) {
                if (string((yyvsp[-2].stringVal)) == "VAR_BOOL") {
                    (yyval.stringVal) = (char*)"VAR_BOOL";
                } 
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("syntax error: can not use AND.");
                }
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same!");
            }
        // java
            fileWrite(fout,"iand");
        }
#line 3134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1482 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[-2].stringVal)) == string((yyvsp[0].stringVal))) {
                if (string((yyvsp[-2].stringVal)) == "VAR_BOOL") {
                    (yyval.stringVal) = (char*)"VAR_BOOL";
                } 
                else {
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("syntax error: can not use OR.");
                }
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("type error: not the same!");
            }
        // java
            fileWrite(fout,"ior");
        }
#line 3156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1500 "yacc.y" /* yacc.c:1646  */
    {
            if (string((yyvsp[0].stringVal)) == "VAR_BOOL") {
                (yyval.stringVal) = (char*)"VAR_BOOL";
            } 
            else {
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("syntax error: can not use NOT.");
            }

        // A xor 1 = not A
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "ixor");
        }
#line 3174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1514 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)((yyvsp[-1].stringVal)); }
#line 3180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1516 "yacc.y" /* yacc.c:1646  */
    { 
            (yyval.stringVal) = (char*)"VAR_BOOL"; 
            // Java 
            // true -> 1, false -> 0
            if ((yyvsp[0].boolVal)) {
                fileWrite(fout, "iconst_1");
            } 
            else {
                fileWrite(fout, "iconst_0");
            }
        }
#line 3196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1528 "yacc.y" /* yacc.c:1646  */
    { 
            (yyval.stringVal) = (char*)"VAR_INT"; 
            fileWrite(fout, "sipush " + to_string((yyvsp[0].intVal)));
        }
#line 3205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1533 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)"VAR_FLOAT"; }
#line 3211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1535 "yacc.y" /* yacc.c:1646  */
    { 
            (yyval.stringVal) = (char*)"VAR_STRING"; 
            fileWrite(fout, "ldc \"" + string((yyvsp[0].stringVal)) + "\"");
        }
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1540 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)((yyvsp[0].stringVal)); }
#line 3226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1542 "yacc.y" /* yacc.c:1646  */
    { (yyval.stringVal) = (char*)((yyvsp[0].stringVal)); }
#line 3232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1544 "yacc.y" /* yacc.c:1646  */
    {
            symbol = scope->Lookup_Global(string((yyvsp[0].stringVal)));
            if(symbol != NULL){       
            // java  
                fileWrite(fout, symbol->loadCode);

                if(symbol->type == "VAR_INT"
                || symbol->type == "VAR_FLOAT" 
                || symbol->type == "VAR_CHAR" 
                || symbol->type == "VAR_BOOL" ){
                    (yyval.stringVal) = &symbol->type[0];
                }
                else if(symbol->type == "CON_INT"
                || symbol->type == "CON_FLOAT" 
                || symbol->type == "CON_CHAR" 
                || symbol->type == "CON_BOOL"){
                    string temp(symbol->type);
                    temp[0] = 'V';
                    temp[1] = 'A';
                    temp[2] = 'R';
                    (yyval.stringVal) = &temp[0];
                }
                else if(symbol->type == "VAR_STRING" || symbol->type == "CON_STRING"){
                    (yyval.stringVal) = (char*)"VAR_STRING";
                }
                else{
                    (yyval.stringVal) = (char*)"ERROR";
                    yyerror("\'" + string(string((yyvsp[0].stringVal))) + "\' is not constant or variable.");
                }
            }
            else{                                   
                (yyval.stringVal) = (char*)"ERROR";
                yyerror("\'" + string(string((yyvsp[0].stringVal))) + "\' not declared.");
            }
        }
#line 3272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1581 "yacc.y" /* yacc.c:1646  */
    { (yyval.boolVal) = true; }
#line 3278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1582 "yacc.y" /* yacc.c:1646  */
    { (yyval.boolVal) = false; }
#line 3284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1586 "yacc.y" /* yacc.c:1646  */
    {
            yyerror("no array in proj3.");
        }
#line 3292 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3296 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1590 "yacc.y" /* yacc.c:1906  */


void yyerror(string t) {
    cout << "LINE " << linecount << " | " << t<<endl;
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Input Filename Plz.\n");
        exit(1);
    }
    fileName = string(argv[1]);
    jasmName = fileName.substr(0, fileName.find_last_of('.'));

    yyin = fopen(argv[1], "r");
    fout.open(jasmName + ".jasm");
    yyparse();
    return 0;
}
