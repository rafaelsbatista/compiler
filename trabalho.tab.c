/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "trabalho.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include "scope_structure.h"
	#include "attribute.h"
	
	FILE* asm_file;
	
	extern int yylex( void );
	
	int yyerror( char *s){
		printf("bison-- error %s\n",s);
		return 0;
	}
	int varCount = 0;
	object int_ = { -1, NULL, SCALAR_TYPE_};
	pobject pInt = &int_;
	
	object char_ = { -1, NULL, SCALAR_TYPE_};
	pobject pChar = &char_;
	
	object bool_ = { -1, NULL, SCALAR_TYPE_};
	pobject pBool = &bool_;
	
	object string_ = { -1, NULL, SCALAR_TYPE_};
	pobject pString = &string_;
	
	object universal_ = { -1, NULL, SCALAR_TYPE_};
	pobject pUniversal = &universal_;

#line 97 "trabalho.tab.c" /* yacc.c:339  */

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
   by #include "trabalho.tab.h".  */
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
#line 31 "trabalho.y" /* yacc.c:355  */

	int integer;
	int boolean;
	char character;
	struct identificador *id;
	char *string;
	int sToken;
	struct object *obj;
	int label;

#line 187 "trabalho.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRABALHO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "trabalho.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    96,    97,   100,   101,   104,   116,   117,
     122,   125,   128,   131,   136,   139,   141,   142,   144,   151,
     158,   164,   169,   173,   178,   179,   186,   187,   188,   191,
     194,   200,   205,   209,   213,   218,   223,   228,   233,   240,
     246,   252,   258,   261,   262,   263,   264,   265,   266,   267,
     273,   275,   283,   296,   310,   316,   322,   328,   335
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_EQ", "T_NEQ", "T_LT", "T_GT", "T_LE",
  "T_GE", "T_EQEQ", "T_AND", "T_OR", "T_TIMES", "T_DIVIDE", "T_PLUS",
  "T_MINUS", "T_COLON", "T_SEMICOLON", "T_COMMA", "T_LEFTBRACES",
  "T_RIGHTBRACES", "T_NOT", "T_CHAR", "T_STRING", "T_ID", "T_NUMBER",
  "R_INTEGER", "R_CHAR", "R_BOOLEAN", "R_STRING", "R_VAR", "R_THEN",
  "R_IF", "R_ELSE", "R_WHILE", "R_DO", "R_BREAK", "R_TRUE", "R_FALSE",
  "$accept", "P", "LDE", "DE", "DV", "LI", "TP", "B", "LS", "LS1", "MT",
  "ME", "MW", "S", "MA", "E", "F", "NB", "NBI", "IDU", "IDD", "TRUE",
  "FALSE", "CHR", "STR", "NUM", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -21

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-21)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -21,     4,    -5,   -21,     6,    42,   -21,   -21,   -21,    12,
     -21,   -13,   -21,   -21,    78,   119,     6,    -2,   -21,   -21,
     -21,   -21,    -2,   -21,    16,   -21,   -21,   -21,   -21,    44,
      60,   113,    59,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,    48,   -21,   -21,     3,   -21,    -2,   -21,
     -21,   -21,    60,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,   -21,    63,   -21,   -21,    45,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,    -2,    78,   -21,   127,    35,    78,   -21,
     -21,   -21,    78,   -21
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      51,     0,    50,     1,     0,     2,     4,     5,     6,     0,
      53,     0,     9,     3,    50,     0,     0,     0,    56,    57,
      52,    58,     0,    20,     0,    54,    55,    28,    24,     0,
      17,     0,    42,    49,    44,    45,    46,    47,    48,    10,
      11,    12,    13,     0,     8,    43,     0,    42,     0,    27,
      14,    15,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     7,    18,     0,
      16,    37,    32,    33,    34,    35,    36,    30,    31,    40,
      41,    38,    39,     0,    50,    18,     0,    21,    50,    25,
      19,    23,    50,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,    64,    22,   -21,   -21,    24,   -21,    19,
     -12,   -21,   -21,   -14,   -21,   -20,   -16,   -21,   -21,   -21,
      61,   -21,   -21,   -21,   -21,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,     6,    27,    11,    43,    28,    29,    51,
      84,    92,    48,    52,    66,    31,    32,     9,     2,    33,
      12,    34,    35,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    45,    46,    15,     3,    16,    47,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    17,
      18,    19,    20,    21,     7,     4,     8,     7,    69,     8,
      10,    14,    47,    49,    68,    25,    26,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   -50,   -29,    86,    50,    67,    83,    47,    90,    13,
      87,    70,     4,    88,    91,     0,     0,    44,    93,   -50,
      85,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       4,     0,    22,     0,    23,     0,    24,    25,    26,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     4,     0,
      22,     0,    23,     0,    24,    25,    26,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    89,    39,    40,    41,    42
};

static const yytype_int8 yycheck[] =
{
      14,    17,    22,    16,     0,    18,    22,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    21,
      22,    23,    24,    25,     2,    30,     2,     5,    48,     5,
      24,    19,    48,    17,    31,    37,    38,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    19,     3,    83,    20,    17,     3,    83,    33,     5,
      84,    52,    30,    85,    88,    -1,    -1,    16,    92,    19,
      35,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    32,    -1,    34,    -1,    36,    37,    38,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      32,    -1,    34,    -1,    36,    37,    38,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    57,     0,    30,    41,    42,    43,    46,    56,
      24,    44,    59,    42,    19,    16,    18,    21,    22,    23,
      24,    25,    32,    34,    36,    37,    38,    43,    46,    47,
      52,    54,    55,    58,    60,    61,    62,    63,    64,    26,
      27,    28,    29,    45,    59,    55,    54,    55,    51,    17,
      20,    48,    52,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    17,    53,    17,    31,    54,
      48,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,     3,    49,    35,    54,    52,    49,    17,
      33,    52,    50,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    44,    44,
      45,    45,    45,    45,    46,    47,    48,    48,    49,    50,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     5,     3,     1,
       1,     1,     1,     1,     4,     2,     2,     0,     0,     0,
       0,     5,     8,     6,     1,     5,     2,     2,     1,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     0,     1,     1,     1,     1,     1,     1,     1
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
        case 2:
#line 85 "trabalho.y" /* yacc.c:1646  */
    {endBlock();
			fprintf(asm_file, "%s", "\n");

			printHeader(asm_file,varCount);
			fclose(asm_file);
			
			
			printf("Codigo gerado com sucesso! [code.asm]\n");
		   }
#line 1363 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 104 "trabalho.y" /* yacc.c:1646  */
    {
			pobject ob = (yyvsp[-3].obj);
			while(ob != 0 && ob->eKind == NO_KIND_DEF_){
				ob->eKind = VAR_;
				ob->_.Var.pType = (yyvsp[-1].obj);
				ob = ob->pNext;
				varCount++;
			}
			
		}
#line 1378 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "trabalho.y" /* yacc.c:1646  */
    {addIdentificador((yyval.obj),(yyvsp[-2].obj),(yyvsp[0].obj));}
#line 1384 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "trabalho.y" /* yacc.c:1646  */
    {
		addIdentificador((yyval.obj),0,(yyvsp[0].obj));
		}
#line 1392 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "trabalho.y" /* yacc.c:1646  */
    { 
					(yyval.obj) = pInt;
					}
#line 1400 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "trabalho.y" /* yacc.c:1646  */
    { 
					(yyval.obj) = pChar;
					}
#line 1408 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "trabalho.y" /* yacc.c:1646  */
    { 
					(yyval.obj) = pBool;
					}
#line 1416 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 131 "trabalho.y" /* yacc.c:1646  */
    { 
					(yyval.obj) = pString;
					}
#line 1424 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 136 "trabalho.y" /* yacc.c:1646  */
    { endBlock();}
#line 1430 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 144 "trabalho.y" /* yacc.c:1646  */
    {
		int l = newLabel();
		(yyval.label) = l;
		fprintf(asm_file,"\tTJMP_FW L%d\n",l);
		}
#line 1440 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 151 "trabalho.y" /* yacc.c:1646  */
    {
		int l = newLabel();
		(yyval.label) = l;
		fprintf(asm_file,"\tTJMP_FW L%d\nL%d\n",l,l-1);
		}
#line 1450 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "trabalho.y" /* yacc.c:1646  */
    {
	int l = newLabel();
	(yyval.label) = l;
	fprintf(asm_file,"L%d\n",l);
}
#line 1460 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 164 "trabalho.y" /* yacc.c:1646  */
    {
			if(!CheckTypes((yyvsp[-3].obj),pBool)) {yyerror("Erro if\n");YYERROR;}
			fprintf(asm_file,"L%d:\n",(yyvsp[-1].label));
			
		}
#line 1470 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 169 "trabalho.y" /* yacc.c:1646  */
    {
			if(CheckTypes((yyvsp[-6].obj),pBool) != 1) {yyerror("Erro if\n");YYERROR;}
			fprintf(asm_file,"L%d:\n",(yyvsp[-1].label));
		}
#line 1479 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 173 "trabalho.y" /* yacc.c:1646  */
    {
			if(!CheckTypes((yyvsp[-3].obj),pBool)) {yyerror("Erro while\n");YYERROR;}
			
			fprintf(asm_file,"\tJMP_BW L%d\nL%d\n",(yyvsp[-4].label),(yyvsp[-1].label));
		}
#line 1489 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 179 "trabalho.y" /* yacc.c:1646  */
    {
			if(!CheckTypes((yyvsp[-4].obj),(yyvsp[-1].obj))) {
				yyerror("Erro atibuicao\n");
				YYERROR;
			}
			fprintf(asm_file,"\tSTORE_VAR %d\n",(yyvsp[-4].obj)->name);
		}
#line 1501 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 191 "trabalho.y" /* yacc.c:1646  */
    {
		fprintf(asm_file,"\tDUP\n");}
#line 1508 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 194 "trabalho.y" /* yacc.c:1646  */
    { if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro and\n");YYERROR;}
					if(!CheckTypes((yyvsp[-2].obj),pBool)) {yyerror("Erro and 2\n");YYERROR;}
					(yyval.obj) = pBool;
					
					fprintf(asm_file,"\tAND\n");
				  }
#line 1519 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 200 "trabalho.y" /* yacc.c:1646  */
    { if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro or\n");YYERROR;}
				   if(!CheckTypes((yyvsp[-2].obj),pBool)) {yyerror ("Erro or 2\n");YYERROR;}
					(yyval.obj) = pBool;
					fprintf(asm_file,"\tOR\n");
				  }
#line 1529 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 205 "trabalho.y" /* yacc.c:1646  */
    { if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro less than\n");YYERROR;}
				    (yyval.obj) = pBool;
					fprintf(asm_file,"\tLT\n");
				  }
#line 1538 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 209 "trabalho.y" /* yacc.c:1646  */
    { if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro greater than\n");YYERROR;}
				    (yyval.obj) = pBool;
					fprintf(asm_file,"\tGT\n");
				  }
#line 1547 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 213 "trabalho.y" /* yacc.c:1646  */
    { 
					if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro less equal\n");YYERROR;}
				    (yyval.obj) = pBool;
					fprintf(asm_file,"\tLE\n");
				  }
#line 1557 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 218 "trabalho.y" /* yacc.c:1646  */
    { 	
					if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro greater equal\n");YYERROR;}
				    (yyval.obj) = pBool;
					fprintf(asm_file,"\tGE\n");
				  }
#line 1567 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 223 "trabalho.y" /* yacc.c:1646  */
    { 
					if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro equal equal\n");YYERROR;}
				    (yyval.obj) = pBool;
					fprintf(asm_file,"\tEQ\n");
				  }
#line 1577 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 228 "trabalho.y" /* yacc.c:1646  */
    {
					if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro not equal\n");YYERROR;}
				    (yyval.obj)  = pBool;
					fprintf(asm_file,"\tNE\n");
				  }
#line 1587 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 233 "trabalho.y" /* yacc.c:1646  */
    { 
					if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro plus\n");YYERROR;}
					if(!CheckTypes((yyvsp[-2].obj),pInt) && !CheckTypes((yyvsp[-2].obj),pString)) yyerror("Erro tipo plus\n");
				    if(CheckTypes((yyvsp[-2].obj),pInt)) (yyval.obj) = pInt;
					else (yyval.obj) = pString;
					fprintf(asm_file,"\tADD\n");
				  }
#line 1599 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 240 "trabalho.y" /* yacc.c:1646  */
    { 
					if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro minus\n");YYERROR;}
					if(!CheckTypes((yyvsp[-2].obj),pInt)) {yyerror("Erro tipo minus\n");YYERROR;}
				    (yyval.obj) = pInt;
					fprintf(asm_file,"\tSUB\n");
				  }
#line 1610 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 246 "trabalho.y" /* yacc.c:1646  */
    { 
					if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro times\n");YYERROR;}
					if(!CheckTypes((yyvsp[-2].obj),pInt)) {yyerror("Erro tipo Times\n");YYERROR;}
				    (yyval.obj) = pInt;
					fprintf(asm_file,"\tMUL\n");
				  }
#line 1621 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 252 "trabalho.y" /* yacc.c:1646  */
    { 
					if(!CheckTypes((yyvsp[-2].obj),(yyvsp[0].obj))) {yyerror("Erro divide\n");YYERROR;}
					if(!CheckTypes((yyvsp[-2].obj),pInt)) {yyerror("Erro divide plus\n");YYERROR;}
				    (yyval.obj) = pInt;
					fprintf(asm_file,"\tDIV\n");
				  }
#line 1632 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 258 "trabalho.y" /* yacc.c:1646  */
    {(yyval.obj) = (yyvsp[0].obj);}
#line 1638 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 261 "trabalho.y" /* yacc.c:1646  */
    {(yyval.obj) = (yyvsp[0].obj);}
#line 1644 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 262 "trabalho.y" /* yacc.c:1646  */
    {(yyval.obj) = (yyvsp[0].obj);}
#line 1650 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 263 "trabalho.y" /* yacc.c:1646  */
    {(yyval.obj) = (yyvsp[0].obj);}
#line 1656 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 264 "trabalho.y" /* yacc.c:1646  */
    {(yyval.obj) = (yyvsp[0].obj);}
#line 1662 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 265 "trabalho.y" /* yacc.c:1646  */
    { (yyval.obj) = (yyvsp[0].obj);}
#line 1668 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 266 "trabalho.y" /* yacc.c:1646  */
    {(yyval.obj) = (yyvsp[0].obj);}
#line 1674 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 267 "trabalho.y" /* yacc.c:1646  */
    { 
				(yyval.obj) = (yyvsp[0].obj);
				fprintf(asm_file,"\tLOAD_VAR %d\n",(yyvsp[0].obj)->name);
			}
#line 1683 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 273 "trabalho.y" /* yacc.c:1646  */
    {newBlock();}
#line 1689 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 275 "trabalho.y" /* yacc.c:1646  */
    {
		asm_file = fopen("code.asm","w");

		fprintf(asm_file, "%s", "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                \n");
		newBlock();
	}
#line 1700 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 283 "trabalho.y" /* yacc.c:1646  */
    { 
			pobject p = (pobject)malloc(sizeof(object));
			if((p=Find((yyvsp[0].sToken))) == 0){
				yyerror("Erro variavel nao declarada\n");
				YYERROR;
				p = Define((yyvsp[0].sToken));
			}
			p->eKind = NO_KIND_DEF_;
			p->name = (yyvsp[0].sToken);
			(yyval.obj) = p;
			}
#line 1716 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 296 "trabalho.y" /* yacc.c:1646  */
    { 
			pobject p = (pobject)malloc(sizeof(object));
			if( (p=Search((yyvsp[0].sToken))) !=0 ){
				yyerror("Erro declaração de variavel repetida\n");
				YYERROR;
			} else {
				p = Define( (yyvsp[0].sToken) );
			}
			p->eKind = NO_KIND_DEF_;
			p->name = (yyvsp[0].sToken);
			(yyval.obj) = p;
}
#line 1733 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 310 "trabalho.y" /* yacc.c:1646  */
    { 
				fprintf(asm_file,"\tLOAD_CONST %d\n", (yyvsp[0].sToken));
				(yyval.obj) = pBool;
				}
#line 1742 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 316 "trabalho.y" /* yacc.c:1646  */
    { 
				fprintf(asm_file,"\tLOAD_CONST %d\n", (yyvsp[0].sToken));
				(yyval.obj) = pBool;
				}
#line 1751 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 322 "trabalho.y" /* yacc.c:1646  */
    { 
				fprintf(asm_file,"\tLOAD_CONST %d\n", (yyvsp[0].sToken));
				(yyval.obj) = pChar;
				}
#line 1760 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 328 "trabalho.y" /* yacc.c:1646  */
    {
				fprintf(asm_file,"\tLOAD_CONST %d\n", (yyvsp[0].sToken));
				(yyval.obj) = pString;
				
				}
#line 1770 "trabalho.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 335 "trabalho.y" /* yacc.c:1646  */
    { 
				fprintf(asm_file,"\tLOAD_CONST %d\n", (yyvsp[0].sToken));
				(yyval.obj) = pInt;
				}
#line 1779 "trabalho.tab.c" /* yacc.c:1646  */
    break;


#line 1783 "trabalho.tab.c" /* yacc.c:1646  */
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
#line 341 "trabalho.y" /* yacc.c:1906  */

int main( void )
{
	return yyparse();
}
