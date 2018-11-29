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
#line 1 "synt.y" /* yacc.c:339  */

#include <stdio.h>
#include "Tab_Symbole.h"
#include "Quadruplet.h"

int Bib_Calcule=0,Bib_Boucle=0,Bib_Tab=0;
int Ind_Operand=0,Ind_Declaration=0;
int sauv_BR,sauv_br_to_cond,wich_cond=0;
int yylex();
int yyerror(char *s);

#line 78 "synt.tab.c" /* yacc.c:339  */

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
   by #include "synt.tab.h".  */
#ifndef YY_YY_SYNT_TAB_H_INCLUDED
# define YY_YY_SYNT_TAB_H_INCLUDED
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
    mc_pgm = 258,
    mc_integer = 259,
    mc_real = 260,
    mc_const = 261,
    mc_if = 262,
    mc_while = 263,
    mc_exec = 264,
    bib_calcul = 265,
    bib_tab = 266,
    bib_boucle = 267,
    sb_eg = 268,
    sb_diff = 269,
    sb_inf = 270,
    sb_infeg = 271,
    sb_sup = 272,
    sb_supeg = 273,
    sb_aff = 274,
    sp_var = 275,
    id = 276,
    val_entiere = 277,
    val_reelle = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "synt.y" /* yacc.c:355  */

char*  chaine;
int entier;
float real;
struct Str{char *val;char* type;}Str;
struct Str2{char* op;char* res;}Str2;

#line 150 "synt.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 167 "synt.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   70

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

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
      34,    35,    29,    28,    26,    31,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    25,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    41,    42,    43,    44,    49,    60,    71,
      83,    86,    87,    90,    91,    94,    97,    98,   101,   127,
     136,   139,   140,   143,   144,   149,   150,   151,   154,   155,
     158,   158,   200,   213,   226,   229,   242,   256,   259,   260,
     263,   267,   274,   263,   286,   288,   286,   301,   343,   344,
     345,   346,   347,   348
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_pgm", "mc_integer", "mc_real",
  "mc_const", "mc_if", "mc_while", "mc_exec", "bib_calcul", "bib_tab",
  "bib_boucle", "sb_eg", "sb_diff", "sb_inf", "sb_infeg", "sb_sup",
  "sb_supeg", "sb_aff", "sp_var", "id", "val_entiere", "val_reelle", "'{'",
  "'}'", "','", "';'", "'+'", "'*'", "'/'", "'-'", "'['", "']'", "'('",
  "')'", "$accept", "S", "BIBL", "CALCUL", "TAB", "BOUCLE", "DEC", "CONST",
  "MOREDEC", "NVAR", "MOREVAR", "VAR", "INDEX", "TYPE", "CST", "INST",
  "MOREINST", "INST_AFF", "$@1", "EXP1", "EXP2", "EXP3", "INST_IF", "$@2",
  "$@3", "$@4", "INST_WHL", "$@5", "$@6", "COND", "COMPARATEUR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   123,   125,    44,    59,    43,    42,
      47,    45,    91,    93,    40,    41
};
# endif

#define YYPACT_NINF -44

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,   -44,   -44,   -44,    10,    39,    13,    13,    13,   -44,
      22,   -44,   -44,   -44,    20,     1,   -44,   -44,    -5,    40,
     -44,   -44,    15,   -44,    23,    -5,    -5,    -5,   -44,    24,
      16,    -5,    29,   -44,    30,   -44,   -44,   -44,   -44,   -44,
      25,    33,     9,   -44,    21,     9,     1,    24,   -44,   -44,
     -44,   -44,   -44,     4,   -16,     7,    26,    48,   -44,    31,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     9,
       9,     9,     9,     9,   -44,    28,   -44,   -44,   -44,   -44,
     -44,   -44,    32,     9,    -5,   -44,    34,    35,   -44,   -44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     7,     8,     9,     0,     0,     6,     6,     6,     1,
       0,     3,     4,     5,     0,     0,    21,    22,     0,    12,
      44,    40,    20,    30,     0,    29,    29,    29,    11,     0,
       0,     0,     0,    18,     0,     2,    28,    25,    26,    27,
       0,    17,     0,    41,     0,     0,    14,     0,    15,    23,
      24,    38,    39,     0,    34,    37,     0,     0,    19,     0,
      13,    10,    16,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,    45,     0,    31,    47,    32,    33,
      35,    36,     0,     0,     0,    42,     0,     0,    46,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,    27,   -44,   -44,   -44,    11,   -44,   -44,    17,
     -44,   -18,   -44,   -44,   -44,   -17,    12,   -44,   -44,   -43,
     -32,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -23,
     -44
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    18,    29,    61,    40,
      48,    51,    33,    19,    52,    36,    37,    25,    34,    53,
      54,    55,    26,    31,    57,    87,    27,    30,    82,    56,
      69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    24,    59,    20,    21,    16,    17,    23,    23,    23,
       9,    41,    70,    23,    43,    71,    22,    63,    64,    65,
      66,    67,    68,     1,     2,     3,    77,    78,    79,    41,
      22,    49,    50,    11,    12,    13,    72,    73,    38,    39,
      80,    81,    10,    14,    15,    22,    28,    32,    35,    45,
      42,    44,    46,    47,    58,    75,    84,    60,    76,    88,
      85,    74,    83,     0,    62,     0,    23,    86,     0,     0,
      89
};

static const yytype_int8 yycheck[] =
{
      18,    18,    45,     8,     9,     4,     5,    25,    26,    27,
       0,    29,    28,    31,    31,    31,    21,    13,    14,    15,
      16,    17,    18,    10,    11,    12,    69,    70,    71,    47,
      21,    22,    23,     6,     7,     8,    29,    30,    26,    27,
      72,    73,     3,    21,    24,    21,     6,    32,    25,    19,
      34,    22,    27,    20,    33,     7,    24,    46,    27,    25,
      83,    35,    34,    -1,    47,    -1,    84,    84,    -1,    -1,
      35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    12,    37,    38,    39,    40,    41,     0,
       3,    38,    38,    38,    21,    24,     4,     5,    42,    49,
       8,     9,    21,    47,    51,    53,    58,    62,     6,    43,
      63,    59,    32,    48,    54,    25,    51,    52,    52,    52,
      45,    47,    34,    51,    22,    19,    27,    20,    46,    22,
      23,    47,    50,    55,    56,    57,    65,    60,    33,    55,
      42,    44,    45,    13,    14,    15,    16,    17,    18,    66,
      28,    31,    29,    30,    35,     7,    27,    55,    55,    55,
      56,    56,    64,    34,    24,    65,    51,    61,    25,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    38,    39,    40,    41,
      42,    43,    43,    44,    44,    45,    46,    46,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    52,    52,
      54,    53,    55,    55,    55,    56,    56,    56,    57,    57,
      59,    60,    61,    58,    63,    64,    62,    65,    66,    66,
      66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     2,     2,     0,     1,     1,     1,
       5,     1,     0,     1,     0,     2,     2,     0,     2,     3,
       0,     1,     1,     1,     1,     2,     2,     2,     1,     0,
       0,     5,     3,     3,     1,     3,     3,     1,     1,     1,
       0,     0,     0,     9,     0,     0,     9,     3,     1,     1,
       1,     1,     1,     1
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
#line 38 "synt.y" /* yacc.c:1646  */
    { printf("\n\nLe programme est syntaxiquement correct !\n"); }
#line 1303 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 50 "synt.y" /* yacc.c:1646  */
    { 
        if (Bib_Calcule==0) { 
            Inserer("CALCUL","mc","/",0);
            Bib_Calcule=1; 
        } else {
            printf("\nBibliotheque CALCUL deja declaree");
        } 
    }
#line 1316 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "synt.y" /* yacc.c:1646  */
    { 
        if (Bib_Tab==0) {
            Inserer("TAB","mc","/",0);
            Bib_Tab=1;
        } else { 
            printf("\nBibliotheque TAB deja déclaée");
        }
    }
#line 1329 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 72 "synt.y" /* yacc.c:1646  */
    { 
        if (Bib_Boucle==0) { 
            Inserer("BOUCLE","mc","/",0);
            Bib_Boucle=1;
        } else {
            printf("\nBibliotheque BOUCLE deja declare");
        }
    }
#line 1342 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 86 "synt.y" /* yacc.c:1646  */
    { type_const=1;  }
#line 1348 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 87 "synt.y" /* yacc.c:1646  */
    { type_const=0; }
#line 1354 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 91 "synt.y" /* yacc.c:1646  */
    { fin_dec=1; }
#line 1360 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 98 "synt.y" /* yacc.c:1646  */
    { Vider_LD(); }
#line 1366 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 102 "synt.y" /* yacc.c:1646  */
    { 
        if( fin_dec == 0 ) { // partie declaration
            Inserer_LD((yyvsp[-1].chaine),index_val);
        } else { // partie instructions
            if ( Rechercher((yyvsp[-1].chaine)) == NULL ) {
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Variable %s non declaree !",nbligne,nbcolonne,(yyvsp[-1].chaine));	
                Ind_Declaration=1; //faut sortir sinon yrouh ychercher 3la null donc lazem n7absso
            }
            if (index_val ==-1 && get_taille((yyvsp[-1].chaine)) > 1) {
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Acces a un tableau sans preciser d indice !",nbligne,nbcolonne);
            } else if (index_val>get_taille((yyvsp[-1].chaine))) {
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Depassement de la taille de tableau !",nbligne,nbcolonne);
            } else if (get_taille((yyvsp[-1].chaine))==1 && index_val != -1 ) {
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Variable simple utilisee comme un tableau !",nbligne,nbcolonne);
            }
            if ( Rechercher((yyvsp[-1].chaine))!=NULL)
            {
                (yyval.Str).val=strdup((yyvsp[-1].chaine));
                (yyval.Str).type=getType((yyvsp[-1].chaine));
            }
            //printf("wach kayen %s\n",$$.type);
        }
    }
#line 1394 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 128 "synt.y" /* yacc.c:1646  */
    { 
        if(!Bib_Tab) printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation de tableau sans import de la biblioteque !",nbligne,nbcolonne);
        if (!fin_dec) {
            if((yyvsp[-1].entier)==0) printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Declaration de tableau de taille egale a zero  !",nbligne,nbcolonne);
            if((yyvsp[-1].entier)==1) printf("\nL%2d C%2d | AVERTISSEMENT: Le tableau de taille 1 a ete transforme en variable simple  !",nbligne,nbcolonne);
        }
        index_val = (yyvsp[-1].entier);
    }
#line 1407 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "synt.y" /* yacc.c:1646  */
    { index_val = -1; }
#line 1413 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 139 "synt.y" /* yacc.c:1646  */
    { type_courant = strdup("INTEGER"); }
#line 1419 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "synt.y" /* yacc.c:1646  */
    { type_courant = strdup("REAL"); }
#line 1425 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 143 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).type=strdup("INTEGER");  char t[10]; sprintf(t,"%d",(yyvsp[0].entier)); (yyval.Str).val=strdup(t);}
#line 1431 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).type=strdup("REAL");     char t[10]; sprintf(t,"%f",(yyvsp[0].real)); (yyval.Str).val=strdup(t);}
#line 1437 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 158 "synt.y" /* yacc.c:1646  */
    {
                    if ( getNature((yyvsp[0].Str).val)==1){ 
                    printf ("\nL%2d C%2d | ERREUR SEMANTIQUE: %s est une constante",nbligne,nbcolonne,(yyvsp[0].Str).val);
                    }
                }
#line 1447 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 165 "synt.y" /* yacc.c:1646  */
    {
                    if ( ! Bib_Calcule ) {
                        printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation d'operations arithmetiques sans import de biblioteque !",nbligne,nbcolonne); 
                    }
                    if ( Ind_Declaration==0 && Ind_Operand == 0)
                    {
                        if ( strcmp((yyvsp[-4].Str).type,(yyvsp[-1].Str).type)!=0){
                        printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation de %s à %s !",nbligne,nbcolonne,(yyvsp[-1].Str).type,(yyvsp[-4].Str).type);
                        }
                    }

                    if ( Ind_Declaration==0 && Ind_Operand ==1)
                        {
                            printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation non permise!",nbligne,nbcolonne);
                            Ind_Operand=0;
                            }

                    if ( Ind_Declaration==1 && Ind_Operand ==0)
                        {
                            printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation de %s à %s NON DECLARER!",nbligne,nbcolonne,(yyvsp[-1].Str).type,(yyvsp[-4].Str).val);
                            Ind_Declaration=0;
                        }

                    if ( Ind_Declaration==1 && Ind_Operand ==1)
                        {
                            printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation à %s NON DECLARER!",nbligne,nbcolonne,(yyvsp[-4].Str).val);
                            printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation non permise!",nbligne,nbcolonne);
                            Ind_Operand=0;
                            Ind_Declaration=0;
                            }
                    Ajouter_Quad("=",(yyvsp[-4].Str).val,(yyvsp[-1].Str).val,"");
                    
                }
#line 1485 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 201 "synt.y" /* yacc.c:1646  */
    {
            if ( strcmp((yyvsp[-2].Str).type,(yyvsp[0].Str).type)!=0){ printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands addition %s avec %s !",nbligne,nbcolonne,(yyvsp[-2].Str).type,(yyvsp[0].Str).type);
            Ind_Operand=1;
            }
            else{
                    (yyval.Str).type=(yyvsp[-2].Str).type; 
                    char t[10]; sprintf(t,"T%d",Cpt_temp); 
                    Cpt_temp++;
                    Ajouter_Quad("+",(yyvsp[-2].Str).val,(yyvsp[0].Str).val,t);
                    (yyval.Str).val=strdup(t);
            }
        }
#line 1502 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 214 "synt.y" /* yacc.c:1646  */
    {
            if ( strcmp((yyvsp[-2].Str).type,(yyvsp[0].Str).type)!=0){ printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands différence %s avec %s !",nbligne,nbcolonne,(yyvsp[-2].Str).type,(yyvsp[0].Str).type);
            Ind_Operand=1;
            }
            else{
                    (yyval.Str).type=(yyvsp[-2].Str).type; 
                    char t[10]; sprintf(t,"T%d",Cpt_temp); 
                    Cpt_temp++;
                    Ajouter_Quad("-",(yyvsp[-2].Str).val,(yyvsp[0].Str).val,t);
                    (yyval.Str).val=strdup(t);
            }
        }
#line 1519 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 226 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=(yyvsp[0].Str).val; (yyval.Str).type=(yyvsp[0].Str).type;}
#line 1525 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 230 "synt.y" /* yacc.c:1646  */
    {
            if ( strcmp((yyvsp[-2].Str).type,(yyvsp[0].Str).type)!=0){ printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands multiplucation %s avec %s !",nbligne,nbcolonne,(yyvsp[-2].Str).type,(yyvsp[0].Str).type);
            Ind_Operand=1;
            }
            else{
                    (yyval.Str).type=(yyvsp[-2].Str).type; 
                    char t[10]; sprintf(t,"T%d",Cpt_temp); 
                    Cpt_temp++;
                    Ajouter_Quad("*",(yyvsp[-2].Str).val,(yyvsp[0].Str).val,t);
                    (yyval.Str).val=strdup(t);
            }
        }
#line 1542 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 243 "synt.y" /* yacc.c:1646  */
    {
            if ( strcmp((yyvsp[-2].Str).type,(yyvsp[0].Str).type)!=0){ printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands division %s avec %s !",nbligne,nbcolonne,(yyvsp[-2].Str).type,(yyvsp[0].Str).type);
            Ind_Operand=1;
            //return 0;
            }
            else{
                    (yyval.Str).type=(yyvsp[-2].Str).type; 
                    char t[10]; sprintf(t,"T%d",Cpt_temp); 
                    Cpt_temp++;
                    Ajouter_Quad("/",(yyvsp[-2].Str).val,(yyvsp[0].Str).val,t);
                    (yyval.Str).val=strdup(t);
            }
        }
#line 1560 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 256 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=(yyvsp[0].Str).val; (yyval.Str).type=(yyvsp[0].Str).type;}
#line 1566 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 259 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=(yyvsp[0].Str).val; (yyval.Str).type=(yyvsp[0].Str).type;}
#line 1572 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 260 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=(yyvsp[0].Str).val; (yyval.Str).type=(yyvsp[0].Str).type;}
#line 1578 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 263 "synt.y" /* yacc.c:1646  */
    {
                    Ajouter_Quad("BR","","","");
                    empiler_if(Num_Qc);
                  }
#line 1587 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 267 "synt.y" /* yacc.c:1646  */
    {        
                    empiler_if(Num_Qc);
                    Ajouter_Quad("BR","","","");
                    sauv_br_to_cond=Num_Qc;
          }
#line 1597 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 274 "synt.y" /* yacc.c:1646  */
    {
                sauv_BR=depiler_if();
                int Deb_Inst=depiler_if();
                int id=Num_Qc-1;
                MAJ_quad_if(id,Deb_Inst);
                MAJ_quad_if(Deb_Inst-1,sauv_br_to_cond);
                id++;
                MAJ_quad_if(sauv_BR,id);
          }
#line 1611 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 286 "synt.y" /* yacc.c:1646  */
    {   wich_cond=1; }
#line 1617 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 288 "synt.y" /* yacc.c:1646  */
    {
                empiler_if(Num_Qc-1);
            }
#line 1625 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 292 "synt.y" /* yacc.c:1646  */
    {
                int Qc_cond_While=depiler_if();
                printf("%d %d",Qc_cond_While,Num_Qc);
                MAJ_quad_if(Qc_cond_While,Num_Qc);
                if(!Bib_Boucle) { printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation de boucle sans import de la biblioteque !",nbligne,nbcolonne); }

            }
#line 1637 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 302 "synt.y" /* yacc.c:1646  */
    {
            if ( strcmp((yyvsp[-2].Str).type,(yyvsp[0].Str).type)!=0){
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands lors de la comparaison %s avec %s !",nbligne,nbcolonne,(yyvsp[-2].Str).val,(yyvsp[0].Str).val);
            }
            else{
                    
                    printf("16s\n");
                    char t[10]; sprintf(t,"T%d",Cpt_temp);
                    Cpt_temp++;
                    Ajouter_Quad("-",(yyvsp[-2].Str).val,(yyvsp[0].Str).val,t);
                    if ( wich_cond == 0 ){
                        /* CAS LA CONDITION EST DECLENCHER A PARTIR DU INST IF */
                        if ( strcmp((yyvsp[-1].Str).val,"==")==0){
                            Ajouter_Quad("BE","","",t);
                        }
                        if ( strcmp((yyvsp[-1].Str).val,"!=")==0){
                            Ajouter_Quad("BNE","","",t);
                        }
                        if ( strcmp((yyvsp[-1].Str).val,"<")==0){
                            Ajouter_Quad("BL","","",t);
                        }
                        if ( strcmp((yyvsp[-1].Str).val,"<=")==0){
                            Ajouter_Quad("BLE","","",t);
                        }
                        if ( strcmp((yyvsp[-1].Str).val,">")==0){
                            Ajouter_Quad("BG","","",t);
                        }
                        if ( strcmp((yyvsp[-1].Str).val,">=")==0){
                            Ajouter_Quad("BGE","","",t);
                        }
                    }
                    else{
                        /* CAS LA CONDITION EST DECLENCHER A PARTIR DU INST WHILE */
                        make_condWhile_quad( (yyvsp[-1].Str).val,t);
                    }
                    

            }
        }
#line 1681 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 343 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=strdup("==");}
#line 1687 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 344 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=strdup("!=");}
#line 1693 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 345 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=strdup("<");}
#line 1699 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 346 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=strdup("<=");}
#line 1705 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 347 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=strdup(">");}
#line 1711 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 348 "synt.y" /* yacc.c:1646  */
    {(yyval.Str).val=strdup(">=");}
#line 1717 "synt.tab.c" /* yacc.c:1646  */
    break;


#line 1721 "synt.tab.c" /* yacc.c:1646  */
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
#line 351 "synt.y" /* yacc.c:1906  */

int main()
{yyparse(); 
 AfficherTS(TS);
 Affichage_Quad();
}

int yywrap()
{return 1;}

int yyerror(char *msg) 
{printf("\nL%2d C%2d | ERREUR SYNTAXIQUE",nbligne,nbcolonne);	return 1;}
