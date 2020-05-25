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
#line 1 "assembly.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int valid=1;
int glob=0;
void dispi();
int yylex();	
extern char* yytext;
int yyerror(const char *s);
int tops=-1;
int qno1=0;
void display();
extern int yylineno;
extern char* yytext;
char appendvar[20];
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
void endif();
void endif_start_else();
void start_else();
void start_if();
void end_for();
void mid_for();
void start_for();
void end1_while();
void end_while();
void start_while();
void create_node_for_eq();
void create_node();
void print1();
void icg();
void optimize1();
void optimize2();
void append(char *string);
int label[20];
int ops=0;
char ff[3][10];
int qno = 0;	
char stk[100][100];
char param[10][10];
int paramtop=-1;
int change=0;
int length_arr = 0;
int count1 = 0;

#line 124 "y.tab.c" /* yacc.c:339  */

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

#line 237 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

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
       0,    64,    64,    64,    67,    68,    71,    72,    73,    74,
      75,    75,    76,    77,    78,    81,    81,    81,    81,    84,
      84,    84,    84,    87,    87,    90,    91,    94,    94,    96,
      96,    97,    97,    98,   101,   102,   103,   106,   106,   107,
     107,   108,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   119,   120,   123,   124,   125,   126,   127,   128,   131,
     132,   139,   140,   141,   146,   147,   148,   151,   152,   153,
     154,   159,   161,   164,   165,   168,   171,   173
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
  "'('", "')'", "':'", "','", "$accept", "RR", "$@1", "N", "R", "$@2",
  "WHILEBODY", "$@3", "$@4", "$@5", "FORBODY", "$@6", "$@7", "$@8",
  "IFBODY", "$@9", "NIFLADDER", "E", "$@10", "EXP", "$@11", "$@12", "COND",
  "OP1", "@13", "@14", "OP2", "@15", "@16", "@17", "@18", "LIT", "RELOP",
  "ASSIGNOP", "RANGE", "VECTOR", "VEC", "NUMC", "NUM", "BOOL", "STR",
  "FIT", "ID", YY_NULLPTR
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

#define YYPACT_NINF -30

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-30)))

#define YYTABLE_NINF -15

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -30,    12,   176,   -30,     1,   -12,     1,     1,     1,   -30,
     -30,     1,   -30,   158,   158,   158,   158,    14,     4,   -30,
     -30,     7,   -30,   158,    -4,   -30,    -7,    15,    52,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,    36,   -30,   -30,   -30,   -30,   -30,   -30,    36,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,    17,
       1,     1,    18,    36,    36,    25,   -30,    36,    36,    36,
      36,    25,    27,     1,    57,    36,     1,     4,     4,     1,
     -30,   -30,   -30,   -30,     1,     1,    36,   -30,    64,     1,
     175,     7,   158,   -30,   -30,   158,     1,     6,    30,    36,
      36,   -30,   -30,    39,   -30,    -4,   -30,    44,   -30,     1,
      25,    25,   -30,    46,    45,     1,    73,   -30,     1,   -30,
      -4,    53,   -30,     1,    70,   -30,   -30,    71,     1,     1,
       1,    52,    75,    52,   -30,    72,     1,    77,   -30,    52,
       1,     1,    79,    88,   -30,   -30,   -30,   -30,     1,     1,
     -30,    82,     1,    52,    84,     1,   -30
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     5,     0,     5,     5,     5,    72,
      77,     5,     3,     0,     0,     0,     0,     5,    41,    50,
      52,    51,     4,     0,     0,    15,     0,     0,     0,     6,
       8,     7,     9,    37,    39,    53,    54,    55,    56,    57,
      58,    33,     0,    42,    44,    46,    48,    59,    60,     0,
      13,    73,    74,    75,    10,    67,    68,    69,    70,     0,
       5,     5,     0,     0,     0,    29,    51,     0,     0,     0,
       0,    31,     0,     5,     0,     0,     5,    38,    40,     5,
      43,    45,    47,    49,     5,     5,     0,    76,     0,     5,
      36,    51,     0,    30,    32,     0,     5,     0,     0,     0,
       0,    12,    11,     0,    71,    66,    19,     0,    63,     5,
      34,    35,    16,     0,    65,     5,     0,    23,     5,    62,
      66,     0,    61,     5,     0,    64,    20,     0,     5,     5,
       5,     0,     0,     0,    24,     0,     5,     0,    17,     0,
       5,     5,     0,    25,    18,    21,    27,    26,     5,     5,
      22,     0,     5,     0,     0,     5,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,    -6,     0,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,    16,   -23,   -30,   -30,    -3,   -30,   -30,   -30,
     -30,   -29,    20,    13,   -30,   -15,    83,   -10,   -21,   -30,
     -30,   -30,    51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    23,    12,    72,    13,    59,   118,   141,
      14,   115,   129,   148,    15,   123,   134,   147,   149,    16,
      79,    84,    89,    17,    63,    64,    18,    67,    68,    69,
      70,    19,    42,    49,   106,   113,   114,   107,    20,    56,
      57,    88,    21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    26,    27,    55,    22,    28,    51,    52,     9,    53,
      10,    41,     3,    29,    30,    31,    32,    22,   104,    65,
      10,   105,    24,    50,    43,    44,    71,    60,    62,    45,
      46,    47,    33,    34,    48,    76,    35,    36,    80,    81,
      82,    83,    37,    33,    34,    38,    39,    40,     9,    61,
      10,    73,    90,     4,    74,    75,     5,     6,     7,     8,
      77,    78,    85,    90,     9,   109,    10,    86,    11,   -14,
      92,    87,    97,    93,   112,    58,   110,   111,    94,    95,
     116,   119,   120,    98,    55,   104,   128,   130,   126,   138,
     103,   136,   101,    66,   140,   102,   145,   146,   152,    55,
      66,   155,    96,   117,   100,   125,   122,    54,     0,   121,
      99,     0,   124,     0,    66,    66,     0,   127,    66,    66,
      66,    66,   131,   132,   133,     0,    91,     0,     0,     0,
     139,   135,     0,   137,   143,   144,     0,    91,     0,   142,
       0,     0,   150,   151,     0,     0,   153,     0,   108,   156,
      66,    66,     0,   154,     0,     0,    58,     0,   -14,     4,
       0,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       9,    58,    10,     0,    11,   -14,   -14,     4,     0,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
      10,     0,    11,    33,    34,     0,     0,    35,    36,     0,
       0,     0,     0,    37,     0,     0,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
       6,     7,     8,    24,     3,    11,    10,    11,    12,    13,
      14,    17,     0,    13,    14,    15,    16,     3,    12,    42,
      14,    15,    34,    23,    20,    21,    49,    34,    28,    25,
      26,    24,    18,    19,    27,    17,    22,    23,    67,    68,
      69,    70,    28,    18,    19,    31,    32,    33,    12,    34,
      14,    34,    75,     1,    60,    61,     4,     5,     6,     7,
      63,    64,    35,    86,    12,    35,    14,    73,    16,    17,
      76,    14,     8,    79,    35,    24,    99,   100,    84,    85,
      36,    35,    37,    89,   105,    12,    16,    16,    35,    17,
      96,    16,    92,    42,    17,    95,    17,     9,    16,   120,
      49,    17,    86,   109,    91,   120,   116,    24,    -1,   115,
      90,    -1,   118,    -1,    63,    64,    -1,   123,    67,    68,
      69,    70,   128,   129,   130,    -1,    75,    -1,    -1,    -1,
     136,   131,    -1,   133,   140,   141,    -1,    86,    -1,   139,
      -1,    -1,   148,   149,    -1,    -1,   152,    -1,    97,   155,
      99,   100,    -1,   153,    -1,    -1,   105,    -1,     0,     1,
      -1,    -1,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,   120,    14,    -1,    16,    17,     0,     1,    -1,    -1,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,
      14,    -1,    16,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    40,     0,     1,     4,     5,     6,     7,    12,
      14,    16,    42,    44,    48,    52,    57,    61,    64,    69,
      76,    80,     3,    41,    34,    41,    41,    41,    41,    42,
      42,    42,    42,    18,    19,    22,    23,    28,    31,    32,
      33,    41,    70,    20,    21,    25,    26,    24,    27,    71,
      42,    10,    11,    13,    74,    76,    77,    78,    80,    45,
      34,    34,    42,    62,    63,    61,    80,    65,    66,    67,
      68,    61,    43,    34,    41,    41,    17,    64,    64,    58,
      69,    69,    69,    69,    59,    35,    41,    14,    79,    60,
      61,    80,    41,    41,    41,    41,    60,     8,    41,    70,
      71,    42,    42,    41,    12,    15,    72,    75,    80,    35,
      61,    61,    35,    73,    74,    49,    36,    41,    46,    35,
      37,    41,    75,    53,    41,    73,    35,    41,    16,    50,
      16,    41,    41,    41,    54,    42,    16,    42,    17,    41,
      17,    47,    42,    41,    41,    17,     9,    55,    51,    56,
      41,    41,    16,    41,    42,    17,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    40,    39,    41,    41,    42,    42,    42,    42,
      43,    42,    42,    42,    42,    45,    46,    47,    44,    49,
      50,    51,    48,    53,    52,    54,    54,    56,    55,    58,
      57,    59,    57,    57,    60,    60,    60,    62,    61,    63,
      61,    61,    65,    64,    66,    64,    67,    64,    68,    64,
      64,    69,    69,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    73,    74,    74,    74,
      74,    75,    76,    77,    77,    78,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     2,     2,     2,     2,
       0,     7,     6,     3,     0,     0,     0,     0,    16,     0,
       0,     0,    18,     0,    12,     4,     5,     0,     8,     0,
       5,     0,     5,     2,     3,     3,     1,     0,     4,     0,
       4,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 64 "assembly.y" /* yacc.c:1646  */
    {printf("\n\nIntermediate code is:\n\n");}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 75 "assembly.y" /* yacc.c:1646  */
    {print1();}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 81 "assembly.y" /* yacc.c:1646  */
    {start_while();}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 81 "assembly.y" /* yacc.c:1646  */
    {end_while();}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 81 "assembly.y" /* yacc.c:1646  */
    {end1_while();}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 84 "assembly.y" /* yacc.c:1646  */
    {start_for();}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 84 "assembly.y" /* yacc.c:1646  */
    {mid_for();}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "assembly.y" /* yacc.c:1646  */
    {end_for();}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 87 "assembly.y" /* yacc.c:1646  */
    {start_if();}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 90 "assembly.y" /* yacc.c:1646  */
    {endif();}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "assembly.y" /* yacc.c:1646  */
    {endif_start_else();}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 94 "assembly.y" /* yacc.c:1646  */
    {start_else();}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 96 "assembly.y" /* yacc.c:1646  */
    {create_node();}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 97 "assembly.y" /* yacc.c:1646  */
    {create_node_for_eq();}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "assembly.y" /* yacc.c:1646  */
    {create_node();}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 102 "assembly.y" /* yacc.c:1646  */
    {create_node_for_eq();}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 106 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"+");append(appendvar);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 106 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])+(yyvsp[-1]);create_node();}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 107 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"-");append(appendvar);}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 107 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])-(yyvsp[-1]);create_node();}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 108 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyval);}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 111 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"*");append(appendvar);}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 111 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])*(yyvsp[-1]);create_node();}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 112 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"/");append(appendvar);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 112 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])/(yyvsp[-1]);create_node();}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 113 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"&&");append(appendvar);}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 113 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])&&(yyvsp[-1]);create_node();}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 114 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"||");append(appendvar);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 114 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3])||(yyvsp[-1]);create_node();}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 115 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyval);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 120 "assembly.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 123 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"<");append(appendvar);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 124 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,">");append(appendvar);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 125 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"==");append(appendvar);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 126 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"<=");append(appendvar);}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 127 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,">=");append(appendvar);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 128 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"!=");append(appendvar);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 131 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"=");append(appendvar);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 132 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,"<-");append(appendvar);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 159 "assembly.y" /* yacc.c:1646  */
    {strcpy(ff[ops++],yytext);if(ops==2){ops=0;}}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 161 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,yytext);append(appendvar);}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 168 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,yytext);append(appendvar);}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 171 "assembly.y" /* yacc.c:1646  */
    {strcpy(ff[2],yytext);strcpy(param[++paramtop],yytext);}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 173 "assembly.y" /* yacc.c:1646  */
    {strcpy(appendvar,yytext);append(appendvar);}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1692 "y.tab.c" /* yacc.c:1646  */
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
#line 176 "assembly.y" /* yacc.c:1906  */


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
		int valid;
	}alls;
alls q1[100];
alls q[100];

typedef struct element{
    int a;
    char s[20];
}ele;

ele e[100];

void display()
{glob=0;
	printf("\n\nQuadruples\n\n");
	printf("\tResult:\t\t Operator:\t Arg1:\t\t Arg2:\t\t \n");
	for(int i=0;i<qno;i++)
	{
		if(q[i].valid)
		{	strcpy(q[glob].op,q[i].op);
    strcpy(q[glob].arg1,q[i].arg1);
    strcpy(q[glob].arg2,q[i].arg2);
	q[glob].valid=q[i].valid;
    strcpy(q[glob++].res,q[i].res);

			printf(" \t%s \t\t %s \t\t %s \t\t %s \t\t\n",q[i].res,q[i].op,q[i].arg1,q[i].arg2);
		}
	}	
	
}

void append(char *string)	{
	
    strcpy(stk[++tops], string);
}

void print1(){
//printf("print(%s)\n",yytext);
printf("param %s\nCall print1, 1\npop param\n",yytext);
q[qno].op = (char*)malloc(sizeof(char)*7);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(yytext));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*5);
	q[qno].valid=1;
	strcpy(q[qno].op,"param");
    strcpy(q[qno].arg1,yytext);
    strcpy(q[qno].arg2,"NULL");
    strcpy(q[qno].res,"NULL");
	qno++;
q[qno].op = (char*)malloc(sizeof(char)*7);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(yytext));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*5);
	q[qno].valid=1;
	strcpy(q[qno].op,"call");
    strcpy(q[qno].arg1,"print");
    strcpy(q[qno].arg2,"1");
    strcpy(q[qno].res,"NULL");
	qno++;
q[qno].op = (char*)malloc(sizeof(char)*7);
    q[qno].arg1 = (char*)malloc(sizeof(char)*10);
    q[qno].arg2 = (char*)malloc(sizeof(char)*6);
    q[qno].res = (char*)malloc(sizeof(char)*6);
	q[qno].valid=1;
	strcpy(q[qno].op,"pop");
    strcpy(q[qno].arg1,"param");
    strcpy(q[qno].arg2,"NULL");
    strcpy(q[qno].res,"NULL");
	qno++;
}

void create_node()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,stk[tops-2],stk[tops-1],stk[tops]);
    q[qno].op = (char*)malloc(sizeof(char)*strlen(stk[tops-1]));
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops-2]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op,stk[tops-1]);
    strcpy(q[qno].arg1,stk[tops-2]);
    strcpy(q[qno].arg2,stk[tops]);
    strcpy(q[qno].res,temp);
    qno++;
    tops-=2;
    strcpy(stk[tops],temp);

temp_i++;
}
void create_node_for_eq()
{
    printf("%s %s %s\n", stk[tops-2], stk[tops-1],stk[tops]);
    q[qno].op = (char*)malloc(sizeof(char)*3);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(stk[tops-2]));
    q[qno].valid=1;
    strcpy(q[qno].op, stk[tops-1]);
    strcpy(q[qno].arg1, stk[tops]);
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res, stk[tops-2]);
    qno++;
    	tops -= 2;
}

void start_if()
{
    lnum++;
    strcpy(temp, "T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp, tmp_i);
    printf("%s = not %s\n", temp, stk[tops]);
    q[qno].op = (char*)malloc(sizeof(char)*4);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op, "not");
    strcpy(q[qno].arg1, stk[tops]);
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res, temp);
    qno++;
    printf("if %s goto L%d\n", temp, lnum);
    q[qno].op = (char*)malloc(sizeof(char)*3);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op, "if");
    strcpy(q[qno].arg1, temp);
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d", lnum);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    temp_i++;
    label[++ltop] = lnum;
	A[++if_top]=lnum;
	lnum++;
}

void start_else()
{
    int x;
    
    x=label[ltop--];
    printf("goto L%d\n",A[if_top]+1);
    q[qno].op = (char*)malloc(sizeof(char)*5);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op, "goto");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char jug[10];
    sprintf(jug,"%d", A[if_top]+1);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,jug));
    qno++;
    printf("L%d: \n",x);
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(x+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");

    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[] = "L";
    strcpy(q[qno].res,strcat(l1,jug1));
    qno++;
    label[++ltop]=lnum;
}

void endif_start_else()
{
    int y;
    y = label[ltop--];
	int tempnum=A[if_top--]+1;
	printf("L%d: \n",tempnum);
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(y+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    lnum++;
}

void endif()
{
		int res=A[if_top--];
		printf("L%d:\n",res);
		q[qno].op = (char*)malloc(sizeof(char)*6);
    		q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    		q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    		q[qno].res = (char*)malloc(sizeof(char)*(res+2));
                q[qno].valid=1;
    		strcpy(q[qno].op,"Label");
                strcpy(q[qno].arg1, "NULL");
		strcpy(q[qno].arg2, "NULL");

    		char jug1[10];
    		sprintf(jug1,"%d",res);
    		char l1[] = "L";
    		strcpy(q[qno].res,strcat(l1,jug1));
    		qno++;
		}


void start_while()
{
    lnum++;
    printf("L%d: \n",lnum++);
    
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
}



void end_while()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,stk[tops]);
    q[qno].op = (char*)malloc(sizeof(char)*4);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op,"not");
    strcpy(q[qno].arg1,stk[tops]);
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res,temp);
    qno++;
    printf("if %s goto L%d\n",temp,lnum);
    W[++while_top]=lnum++;
    q[qno].op = (char*)malloc(sizeof(char)*3);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"if");
    strcpy(q[qno].arg1,temp);
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",W[while_top]);
    char l[]="L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    temp_i++;
 }



void end1_while()
{
	int tempnum=W[while_top--]-1;
    printf("goto L%d \n",tempnum);
    q[qno].op = (char*)malloc(sizeof(char)*5);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(l_while+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"goto");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[]="L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    printf("L%d: \n",tempnum+1);lnum++;
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[qno].res,strcat(l1,x1));
    qno++;
}

void start_for()
{
    printf("%s = %s\n", ff[2],ff[0]);
    q[qno].op = (char*)malloc(sizeof(char));
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(ff[0]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(ff[2]));
    strcpy(q[qno].op, "=");
    strcpy(q[qno].arg1, ff[0]);
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res, ff[2]);
    q[qno].valid=1;
    qno++;
    lnum++;
    printf("L%d: \n",lnum++);    
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
}

void mid_for()
{

	strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
	temp_i++;
    printf("%s=%s < %s\n", temp,ff[2],ff[1]);
    
    q[qno].op = (char*)malloc(sizeof(char));
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(ff[2]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*strlen(ff[1]));
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op, "<");
    strcpy(q[qno].arg1, ff[2]);
    strcpy(q[qno].arg2, ff[1]);
    
    strcpy(q[qno].res, temp);
    qno++;

    sprintf(tmp_i, "%d", temp_i);
	
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[qno].arg1,temp);
	    strcpy(temp,"T");
    strcat(temp,tmp_i);
    printf("T%d = not T%d\n",temp_i,temp_i-1);
    q[qno].op = (char*)malloc(sizeof(char)*4);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op,"not");
    
    
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res,temp);
    qno++;
    printf("if %s goto L%d\n",temp,lnum);
    F[++for_top]=lnum++;
    q[qno].op = (char*)malloc(sizeof(char)*3);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"if");
    strcpy(q[qno].arg1,temp);
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",F[for_top]);
    char l[]="L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    temp_i++;
 }

void end_for()
{

    	strcpy(temp, "T");
	sprintf(tmp_i, "%d", temp_i);
	strcat(temp, tmp_i);
	printf("\t%s = %s + 1\n",temp,param[paramtop]);
	q[qno].op = (char*)malloc(sizeof(char)*2);
	q[qno].arg1 = (char*)malloc(sizeof(char)*5);
	q[qno].arg2 = (char*)malloc(sizeof(char)*5);
	q[qno].res = (char*)malloc(sizeof(char)*(l_while+2));
	q[qno].valid=1;
	strcpy(q[qno].op,"+");
	strcpy(q[qno].arg1,param[paramtop]);
	strcpy(q[qno].arg2,"1");
	strcpy(q[qno].res,temp);
	qno++;
	temp_i++;

	printf("\t%s = %s\n",param[paramtop],temp);
	q[qno].op = (char*)malloc(sizeof(char)*2);
	q[qno].arg1 = (char*)malloc(sizeof(char)*5);
	q[qno].arg2 = (char*)malloc(sizeof(char)*5);
	q[qno].res = (char*)malloc(sizeof(char)*(l_while+2));
	q[qno].valid=1;
	strcpy(q[qno].op,"=");
	strcpy(q[qno].arg1,temp);
	
	strcpy(q[qno].arg2,"NULL");
	strcpy(q[qno].res,param[paramtop]);
	qno++;
	paramtop--;
	
    int tempnum=F[for_top--]-1;
    printf("goto L%d \n",tempnum);
    q[qno].op = (char*)malloc(sizeof(char)*5);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(l_while+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"goto");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[]="L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    printf("L%d: \n",tempnum+1);lnum++;
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[qno].res,strcat(l1,x1));
    qno++;
}


void dispi(){
int i=0;
for(i=0;i<qno;i++)
		{
			if(q[i].valid)
			{
				if(strcmp(q[i].op,"Label")==0)
				{
					printf("%s:\n",q[i].res);
				}
				else if(strcmp(q[i].op,"goto")==0)
				{	
					printf("\tgoto %s\n",q[i].res);
				}
				else if(strcmp(q[i].op,"not")==0)
				{	
					printf("\t%s = not %s\n",q[i].res,q[i].arg1);
				}
				else if(strcmp(q[i].op,"if")==0)
				{	
					printf("\tif %s goto %s\n",q[i].arg1,q[i].res);
				}
				else if(strcmp(q[i].op,"=")==0)
				{	
					printf("\t%s = %s\n",q[i].res,q[i].arg1);
				}
				else if(strcmp(q[i].op,"param")==0){
					printf("\tparam %s\n\tcall print, 1\n\tpop param\n",q[i].arg1);
				}
				else if (strcmp(q[i].op,"call")==0 || strcmp(q[i].op,"pop")==0){
continue;}
				else
				{
					printf("\t%s = %s %s %s\n",q[i].res,q[i].arg1,q[i].op,q[i].arg2);
				}
					
			}
		}

}

void optimize1()
{
	char *targ1,*targ2,*tres,*topr,*res2;
	printf("\n");
	int i=0;
	for(i=0;i<qno;i++)
	{
          	int a=q[i].arg1[0];
		
		if((!(strcmp(q[i].arg2,"NULL")==0)) && (q[i].valid))
		{
			targ1=(char*)malloc(sizeof(char)*strlen(q[i].arg1));
			targ2=(char*)malloc(sizeof(char)*strlen(q[i].arg2));
			tres=(char*)malloc(sizeof(char)*strlen(q[i].res));
			topr=(char*)malloc(sizeof(char)*strlen(q[i].op));
			strcpy(targ1,q[i].arg1);
                        
			strcpy(targ2,q[i].arg2);
			strcpy(tres,q[i].res);
			strcpy(topr,q[i].op);
			int p=i+1;
			while( p<qno && !((strcmp(q[p].res,tres)==0) || (strcmp(q[p].res,targ1)==0) || (strcmp(q[p].res,targ2)==0))  ) 
			{
				if( (strcmp(q[p].arg1,targ1)==0) && (strcmp(q[p].arg2,targ2)==0) && (strcmp(q[p].op,topr)==0) )
				{
					q[p].valid=0;
					change=1;
					res2=(char*)malloc(sizeof(char)*strlen(q[p].res));
					strcpy(res2,q[p].res);
					int h=p+1;
					while(h<qno && !(strcmp(q[h].res,res2)==0))
					{
						if(strcmp(q[h].arg1,res2)==0)
						{
							//printf("%d arg1\n",h);
							strcpy(q[h].arg1,tres);
						}
						if(strcmp(q[h].arg2,res2)==0)
						{
							//printf("%d arg2\n",h);
							strcpy(q[h].arg2,tres);
						}
						h=h+1;
					}
					if(h!=qno)
					{
						if(strcmp(q[h].arg1,res2)==0)
						{
							strcpy(q[h].arg1,tres);
						}
						if(strcmp(q[h].arg2,res2)==0)
						{
							strcpy(q[h].arg2,tres);
						}		
					}
				}
				p=p+1;
			}
			
		}
	}
printf("After 1st stage:\n");
    
	display();
qno=glob;

for(i=0;i<qno;i++)
{
 strcpy(e[i].s,q[i].res);
 e[i].a = 0;
 count1++;
 length_arr++;
}
    int it=1;
    do{
        for(i=0;i<qno;i++)
        {
                strcpy(e[i].s,q[i].res);
                e[i].a = 0;
        }

        
        int k = 0;
        for(i=0;i<qno;i++)
        {
                if(strcmp(q[i].op,"pop")==0 ||strcmp(q[i].op,"param")==0 ||strcmp(q[i].op,"call")==0 )
                {e[i].a = 1;
                k++;
            }
        }
        count1 = 0;
        
        for(int i=0;i<length_arr;i++){
            char* str = (char*)malloc(sizeof(e[i].s));
            str = e[i].s;
            count1+=1;
            for(int j=0;j<qno;j++){
                char arg1[20],arg2[20];
                strcpy(arg1,q[j].arg1);
                strcpy(arg2,q[j].arg2);
                if(e[i].a==0 && (strcmp(str,arg1)==0 || strcmp(str,arg2)==0 || e[i].s[0]=='L')){  
                    e[i].a = 1;  
                    k++;
                    break;
                }
            }
        
            for(int j=0;j<qno1;j++){
                
                char arg1[20],arg2[20];
                strcpy(arg1,q1[j].arg1);
                strcpy(arg2,q1[j].arg2);
                //printf("%s %s %s\n",str,arg1,arg2);
                if(e[i].a==0 && (strcmp(str,arg1)==0 || strcmp(str,arg2)==0)){  
                    k++;
                    e[i].a = 1;  
                    break;
                }
            }

        }


        length_arr = k;
        int l = 0;
        int g=0;
        if(length_arr!=count1){
            change=1;
            for(int i=0;i<qno-1;i++){   
            
                if(strcmp(q[i].op,"param")==0 || strcmp(q[i].op,"call")==0 || strcmp(q[i].op,"pop")==0 || e[i].a==1){
                    strcpy(q[l].op,q[i].op);
                    strcpy(q[l].arg1,q[i].arg1);
                    strcpy(q[l].arg2,q[i].arg2);
                    strcpy(q[l++].res,q[i].res);
                }                    
                                
                if(e[i].a==1 && e[i+1].a==0 && strcmp(q[i].arg2,"NULL")!=0 && e[i+1].s[0]!='T'){
                    
                    q1[g].op = (char*)malloc(sizeof(char)*100);
                    q1[g].arg1 = (char*)malloc(sizeof(char)*100);
                    q1[g].arg2 = (char*)malloc(sizeof(char)*100);
                    q1[g].res = (char*)malloc(sizeof(char)*100);
                    strcpy(q1[g].op,q[i].op);
                    strcpy(q1[g].arg1,q[i].arg1);
                    strcpy(q1[g].arg2,q[i].arg2);
                    strcpy(q1[g++].res,q[i].res);
                }
            }

        if(e[qno-1].a==1){
            strcpy(q[l].op,q[qno-1].op);
            strcpy(q[l].arg1,q[qno-1].arg1);
            strcpy(q[l].arg2,q[qno-1].arg2);
            strcpy(q[l++].res,q[qno-1].res);		
        }
            }
        if(length_arr!=count1){
            qno = l;}
            qno1=g;
        length_arr=qno;
            for(int z=0;z<qno;z++){
        strcpy(e[z].s,q[z].res);
                e[z].a = 0;
        }  
	}while(length_arr!=count1);
     
	icg();
}

void icg()
{
	if(change==1)
	{
		printf("Optimized Intermidiate code is:\n\n");
		int i;
		dispi();
		display();
	}
	else
	{
		printf("No optimization can be performed\n\n\n");
		dispi();
		display();
	}
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
	optimize1();
	return 0;
}        


  
