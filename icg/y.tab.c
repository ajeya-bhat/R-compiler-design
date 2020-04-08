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
#line 1 "icg.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int valid=1;
int yylex();	
extern char* yytext;
int yyerror(const char *s);
int tops=-1;
void display();
extern int yylineno;
extern char* yytext;
char pushvar[20];
int lnum=0;
char temp[2] = "t";
char temp2[4]="t";
int temp_i = 0;
char tmp_i[3];
int W[10000];
int F[10000];
int A[10000];
int if_top=-1;
int while_top=-1;
int for_top=-1;
int l_while = 0;
int ltop = 0;	
void ifelse4();
void ifelse3();
void ifelse2();
void ifelse1();
void for3();
void for2();
void for1();
void while3();
void while2();
void while1();
void codegen_assign();
void codegen();
void push(char *string);
int label[20];
int ops=0;
char ff[3][10];
int quadnum = 0;	
char stk[100][100];

#line 112 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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

/* Copy the second part of user declarations.  */

#line 225 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      34,    35,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
      29,     2,    30,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    52,    55,    56,    59,    60,    61,    62,
      63,    64,    65,    66,    69,    69,    69,    69,    72,    72,
      72,    72,    75,    75,    78,    79,    82,    82,    84,    84,
      85,    85,    86,    89,    90,    91,    92,    95,    95,    96,
      96,    97,   100,   100,   101,   101,   102,   106,   107,   110,
     111,   112,   113,   114,   115,   118,   119,   122,   123,   126,
     127,   128,   133,   134,   137,   138,   139,   140,   145,   147,
     150,   151,   154,   157,   159
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NL", "PRINT", "WHILE", "FOR", "IF",
  "IN", "ELSE", "TRUE1", "FALSE1", "NUMB", "STRI", "id", "COPEN", "BROPEN",
  "BRCLOSE", "T_pl", "T_min", "T_mul", "T_div", "T_lt", "T_gt", "T_eq",
  "T_and", "T_or", "T_ass", "T_eqeq", "'<'", "'>'", "T_le", "T_ge", "T_ne",
  "'('", "')'", "':'", "','", "$accept", "RR", "$@1", "N", "R",
  "WHILEBODY", "$@2", "$@3", "$@4", "FORBODY", "$@5", "$@6", "$@7",
  "IFBODY", "$@8", "NIFLADDER", "E", "$@9", "EXP", "$@10", "$@11", "COND",
  "OP1", "@12", "@13", "OP2", "@14", "@15", "LIT", "RELOP", "ASSIGNOP",
  "LOGICOP", "RANGE", "VECTOR", "VEC", "NUMC", "NUM", "BOOL", "STR", "FIT",
  "ID", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    60,
      62,   284,   285,   286,    40,    41,    58,    44
};
# endif

#define YYPACT_NINF -32

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-32)))

#define YYTABLE_NINF -14

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,     6,   146,   -32,    14,   -21,    16,    16,    16,   -32,
     -32,    16,   -32,   128,   128,   128,   128,     8,    12,   -32,
     -32,   -22,   128,    35,   -32,   -32,    -9,     4,    97,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,     0,   -32,   -32,   -32,   -32,     0,   -32,   -32,
     -32,   -32,    15,   -32,   -32,   -32,   -32,    20,    16,    16,
      26,     0,     0,    10,   -32,     0,     0,    10,    52,    16,
      49,     0,    61,    12,    12,    62,   -32,   -32,    64,   128,
       0,   -32,    63,    16,   145,   -22,   128,   -32,   -32,   -32,
      16,     9,    37,   -32,   -32,     0,     0,     0,   -32,    39,
     -32,    35,   -32,    41,   -32,   -32,    10,    10,    10,   -32,
      43,    42,    16,    70,    16,    16,   -32,    35,    50,   -32,
      68,    71,   -32,   -32,    16,    16,    16,    97,   -32,    97,
      72,    76,    77,    16,    86,   -32,    97,    90,    16,    78,
     -32,   -32,   -32,   -32,    16,    16,    84,   -32,    16,    97,
      89,   107,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     5,     5,     5,    69,
      74,     5,     3,     0,     0,     0,     0,     0,    41,    46,
      48,    47,     0,     0,     4,    14,     0,     0,     0,     6,
       8,     7,     9,    32,    37,    39,    49,    50,    51,    52,
      53,    54,     0,    42,    44,    55,    56,     0,    12,    70,
      71,    72,     0,    64,    65,    66,    67,     0,     5,     5,
       0,     0,     0,    28,    47,     0,     0,    30,     0,     5,
       0,     0,     0,    38,    40,     0,    43,    45,     0,     0,
       0,    73,     0,     5,    36,    47,     0,    29,    31,    10,
       5,     0,     0,    57,    58,     0,     0,     0,    11,     0,
      68,     0,    18,     0,    61,    22,    33,    35,    34,    15,
       0,    63,     5,     0,     5,     5,    60,     0,     0,    59,
       0,     0,    62,    19,     5,     5,     5,     0,    23,     0,
       0,     0,     0,     5,     0,    16,     0,    24,     5,     0,
      26,    25,    17,    20,     5,     5,     0,    21,     5,     0,
       0,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,    -7,    -6,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,    36,   -27,   -32,   -32,    -3,   -32,   -32,   -31,    31,
      40,   -32,   -32,     3,    99,    11,   -20,   -32,   -32,   -32,
      -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    25,    12,    13,    57,   115,   138,    14,
     112,   126,   145,    15,   114,   128,   141,   144,    16,    75,
      78,    83,    17,    61,    62,    18,    65,    66,    19,    42,
      47,    96,   102,   110,   111,   103,    20,    54,    55,    82,
      21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    27,    45,    53,    28,    46,     3,    29,    30,    31,
      32,    33,     9,    23,    10,    63,    48,    22,    56,    24,
      67,   100,    60,    10,   101,    58,    34,    35,    34,    35,
      36,    37,    43,    44,    76,    77,    38,    64,    59,    39,
      40,    41,    64,    72,    84,    49,    50,     9,    51,    10,
      68,    70,    71,    84,    69,    79,    64,    64,    73,    74,
      64,    64,    80,    81,    86,    87,    85,    88,   106,   107,
     108,    91,   105,    89,   109,    85,    92,   113,   116,   117,
      98,    53,   100,    99,   124,   123,   104,   125,   133,   137,
      64,    64,    64,   134,   135,   143,    56,    53,     4,   140,
     148,     5,     6,     7,     8,   118,   151,   120,   121,     9,
     152,    10,    56,    11,   -13,    95,    90,   127,   129,   130,
     122,   131,    52,   132,   119,    97,   136,     0,   -13,     4,
     139,   142,     5,     6,     7,     8,     0,   146,   147,     0,
       9,   149,    10,   150,    11,   -13,   -13,     4,     0,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
      10,     0,    11,    34,    35,     0,     0,    36,    37,     0,
      93,    94,     0,    38,     0,     0,    39,    40,    41
};

static const yytype_int16 yycheck[] =
{
       7,     8,    24,    23,    11,    27,     0,    13,    14,    15,
      16,     3,    12,    34,    14,    42,    22,     3,    23,     3,
      47,    12,    28,    14,    15,    34,    18,    19,    18,    19,
      22,    23,    20,    21,    65,    66,    28,    42,    34,    31,
      32,    33,    47,    17,    71,    10,    11,    12,    13,    14,
      35,    58,    59,    80,    34,     3,    61,    62,    61,    62,
      65,    66,    69,    14,     3,     3,    71,     3,    95,    96,
      97,     8,    35,    79,    35,    80,    83,    36,    35,    37,
      86,   101,    12,    90,    16,    35,    91,    16,    16,     3,
      95,    96,    97,    17,    17,    17,   101,   117,     1,     9,
      16,     4,     5,     6,     7,   112,    17,   114,   115,    12,
       3,    14,   117,    16,    17,    84,    80,   124,   125,   126,
     117,   127,    23,   129,   113,    85,   133,    -1,     0,     1,
     136,   138,     4,     5,     6,     7,    -1,   144,   145,    -1,
      12,   148,    14,   149,    16,    17,     0,     1,    -1,    -1,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,
      14,    -1,    16,    18,    19,    -1,    -1,    22,    23,    -1,
      25,    26,    -1,    28,    -1,    -1,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    40,     0,     1,     4,     5,     6,     7,    12,
      14,    16,    42,    43,    47,    51,    56,    60,    63,    66,
      74,    78,     3,    34,     3,    41,    41,    41,    41,    42,
      42,    42,    42,     3,    18,    19,    22,    23,    28,    31,
      32,    33,    67,    20,    21,    24,    27,    68,    42,    10,
      11,    13,    72,    74,    75,    76,    78,    44,    34,    34,
      42,    61,    62,    60,    78,    64,    65,    60,    35,    34,
      41,    41,    17,    63,    63,    57,    66,    66,    58,     3,
      41,    14,    77,    59,    60,    78,     3,     3,     3,    42,
      59,     8,    41,    25,    26,    67,    69,    68,    42,    41,
      12,    15,    70,    73,    78,    35,    60,    60,    60,    35,
      71,    72,    48,    36,    52,    45,    35,    37,    41,    73,
      41,    41,    71,    35,    16,    16,    49,    41,    53,    41,
      41,    42,    42,    16,    17,    17,    41,     3,    46,    42,
       9,    54,    41,    17,    55,    50,    41,    41,    16,    41,
      42,    17,     3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    40,    39,    41,    41,    42,    42,    42,    42,
      42,    42,    42,    42,    44,    45,    46,    43,    48,    49,
      50,    47,    52,    51,    53,    53,    55,    54,    57,    56,
      58,    56,    56,    59,    59,    59,    59,    61,    60,    62,
      60,    60,    64,    63,    65,    63,    63,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    73,    74,
      75,    75,    76,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     2,     2,     2,     2,
       6,     6,     3,     0,     0,     0,     0,    16,     0,     0,
       0,    18,     0,    11,     4,     5,     0,     8,     0,     5,
       0,     5,     2,     3,     3,     3,     1,     0,     4,     0,
       4,     1,     0,     4,     0,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 52 "icg.y" /* yacc.c:1646  */
    {printf("\n\nIntermediate code is:\n\n");}
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "icg.y" /* yacc.c:1646  */
    {while1();}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 69 "icg.y" /* yacc.c:1646  */
    {while2();}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 69 "icg.y" /* yacc.c:1646  */
    {while3();}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 72 "icg.y" /* yacc.c:1646  */
    {for1();}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 72 "icg.y" /* yacc.c:1646  */
    {for2();}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 72 "icg.y" /* yacc.c:1646  */
    {for3();}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 75 "icg.y" /* yacc.c:1646  */
    {ifelse1();}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "icg.y" /* yacc.c:1646  */
    {ifelse4();}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 79 "icg.y" /* yacc.c:1646  */
    {ifelse3();}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 82 "icg.y" /* yacc.c:1646  */
    {ifelse2();}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 84 "icg.y" /* yacc.c:1646  */
    {codegen();}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 85 "icg.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 89 "icg.y" /* yacc.c:1646  */
    {codegen();}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 90 "icg.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 91 "icg.y" /* yacc.c:1646  */
    {codegen();}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 95 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"+");push(pushvar);}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 95 "icg.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])+(yyvsp[-1]);codegen();}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 96 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"-");push(pushvar);}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 96 "icg.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])-(yyvsp[-1]);codegen();}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 97 "icg.y" /* yacc.c:1646  */
    {(yyval)=(yyval);}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 100 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"*");push(pushvar);}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 100 "icg.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])*(yyvsp[-1]);codegen();}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 101 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"/");push(pushvar);}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 101 "icg.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])/(yyvsp[-1]);codegen();}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 102 "icg.y" /* yacc.c:1646  */
    {(yyval)=(yyval);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 107 "icg.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 110 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"<");push(pushvar);}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 111 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,">");push(pushvar);}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 112 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"==");push(pushvar);}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 113 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"<=");push(pushvar);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 114 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,">=");push(pushvar);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 115 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"!=");push(pushvar);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 118 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"=");push(pushvar);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 119 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"<-");push(pushvar);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 122 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"&&");push(pushvar);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 123 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,"||");push(pushvar);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 145 "icg.y" /* yacc.c:1646  */
    {strcpy(ff[ops++],yytext);if(ops==2){ops=0;}}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 147 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,yytext);push(pushvar);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 157 "icg.y" /* yacc.c:1646  */
    {strcpy(ff[2],yytext);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 159 "icg.y" /* yacc.c:1646  */
    {strcpy(pushvar,yytext);push(pushvar);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1656 "y.tab.c" /* yacc.c:1646  */
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
#line 162 "icg.y" /* yacc.c:1906  */


#include <ctype.h>
int yyerror(const char *s)
{
  	extern int yylineno;
  	valid =0;
  	printf("\nLine no: %d \n The error is: %s\n\n",yylineno-1,s);
}

typedef struct quadruples{
		char *op;
		char *arg1;
		char *arg2;
		char *res;
	}alls;

alls q[100];


void display()
{
	printf("\n\nQuadruples\n\n");
	printf("\tResult:\t\t Operator:\t Arg1:\t\t Arg2:\t\t \n");
	for(int i=0;i<quadnum;i++)
	{
			printf("\t%s \t\t %s \t\t %s \t\t %s \t\t \n",q[i].res,q[i].op,q[i].arg1,q[i].arg2);
	}	
	
}

void push(char *string)	{
	
    strcpy(stk[++tops], string);
}

void codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,stk[tops-2],stk[tops-1],stk[tops]);
    q[quadnum].op = (char*)malloc(sizeof(char)*strlen(stk[tops-1]));
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops-2]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op,stk[tops-1]);
    strcpy(q[quadnum].arg1,stk[tops-2]);
    strcpy(q[quadnum].arg2,stk[tops]);
    strcpy(q[quadnum].res,temp);
    quadnum++;
    tops-=2;
    strcpy(stk[tops],temp);

temp_i++;
}
void codegen_assign()
{
    printf("%s %s %s\n", stk[tops-2], stk[tops-1],stk[tops]);
    q[quadnum].op = (char*)malloc(sizeof(char)*3);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(stk[tops-2]));
    strcpy(q[quadnum].op, stk[tops-1]);
    strcpy(q[quadnum].arg1, stk[tops]);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res, stk[tops-2]);
    quadnum++;
    	tops -= 2;
}

void ifelse1()
{
    lnum++;
    strcpy(temp, "T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp, tmp_i);
    printf("%s = not %s\n", temp, stk[tops]);
    q[quadnum].op = (char*)malloc(sizeof(char)*4);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op, "not");
    strcpy(q[quadnum].arg1, stk[tops]);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res, temp);
    quadnum++;
    printf("if %s goto L%d\n", temp, lnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*3);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op, "if");
    strcpy(q[quadnum].arg1, temp);
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d", lnum);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    temp_i++;
    label[++ltop] = lnum;
	A[++if_top]=lnum;
	lnum++;
}

void ifelse2()
{
    int x;
    
    x=label[ltop--];
    printf("goto L%d\n",A[if_top]+1);
    q[quadnum].op = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op, "goto");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char jug[10];
    sprintf(jug,"%d", A[if_top]+1);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,jug));
    quadnum++;
    printf("L%d: \n",x);
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");

    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[] = "L";
    strcpy(q[quadnum].res,strcat(l1,jug1));
    quadnum++;
    label[++ltop]=lnum;
}

void ifelse3()
{
    int y;
    y = label[ltop--];
	int tempnum=A[if_top--]+1;
	printf("L%d: \n",tempnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    lnum++;
}

void ifelse4()
{
		int res=A[if_top--];
		printf("L%d:\n",res);
		q[quadnum].op = (char*)malloc(sizeof(char)*6);
    		q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    		q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    		q[quadnum].res = (char*)malloc(sizeof(char)*(res+2));
    		strcpy(q[quadnum].op,"Label");
                strcpy(q[quadnum].arg1, "NULL");
		strcpy(q[quadnum].arg2, "NULL");

    		char jug1[10];
    		sprintf(jug1,"%d",res);
    		char l1[] = "L";
    		strcpy(q[quadnum].res,strcat(l1,jug1));
    		quadnum++;
		}


void while1()
{
    lnum++;
    printf("L%d: \n",lnum++);
    
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
}



void while2()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,stk[tops]);
    q[quadnum].op = (char*)malloc(sizeof(char)*4);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op,"not");
    strcpy(q[quadnum].arg1,stk[tops]);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res,temp);
    quadnum++;
    printf("if %s goto L%d\n",temp,lnum);
    W[++while_top]=lnum++;
    q[quadnum].op = (char*)malloc(sizeof(char)*3);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"if");
    strcpy(q[quadnum].arg1,temp);
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",W[while_top]);
    char l[]="L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    temp_i++;
 }



void while3()
{
	int tempnum=W[while_top--]-1;
    printf("goto L%d \n",tempnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(l_while+2));
    strcpy(q[quadnum].op,"goto");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[]="L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    printf("L%d: \n",tempnum+1);lnum++;
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[quadnum].res,strcat(l1,x1));
    quadnum++;
}

void for1()
{
    printf("%s = %s\n", ff[2],ff[0]);
    q[quadnum].op = (char*)malloc(sizeof(char));
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(ff[0]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(ff[2]));
    strcpy(q[quadnum].op, "=");
    strcpy(q[quadnum].arg1, ff[0]);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res, ff[2]);
    quadnum++;
    lnum++;
    printf("L%d: \n",lnum++);    
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
}

void for2()
{

	strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
	temp_i++;
    printf("%s=%s < %s\n", temp,ff[2],ff[1]);
    q[quadnum].op = (char*)malloc(sizeof(char));
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(ff[2]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*strlen(ff[1]));
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op, "<");
    strcpy(q[quadnum].arg1, ff[2]);
    strcpy(q[quadnum].arg2, ff[1]);
    strcpy(q[quadnum].res, temp);
    strcpy(temp2,temp);
    quadnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("T%d = not T%d\n",temp_i,temp_i-1);
    q[quadnum].op = (char*)malloc(sizeof(char)*4);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(temp2));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op,"not");
    strcpy(q[quadnum].arg1,temp2);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res,temp);
    quadnum++;
    printf("if %s goto L%d\n",temp,lnum);
    F[++for_top]=lnum++;
    q[quadnum].op = (char*)malloc(sizeof(char)*3);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"if");
    strcpy(q[quadnum].arg1,temp);
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",F[for_top]);
    char l[]="L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    temp_i++;
 }

void for3()
{
	
	int tempnum=F[for_top--]-1;
    printf("goto L%d \n",tempnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(l_while+2));
    strcpy(q[quadnum].op,"goto");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[]="L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    printf("L%d: \n",tempnum+1);lnum++;
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[quadnum].res,strcat(l1,x1));
    quadnum++;
}

int main()
{
	extern FILE *yyin;
    yyin=fopen("a.r","r");yyparse();
	if(valid)
	{
  		printf("\n\nParsing successful\n\n");
		
	}
	else
	{
  		printf("\n\nParsing unsuccessful\n\n");
		
	}
	display();
	return 0;
}        


  
