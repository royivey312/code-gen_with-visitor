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
#line 1 "mini-turing.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <string.h>
#include <stack>

extern tree root; // declared in the driver program
extern int yylex(void);
extern int yyerror (char const *s);
extern char *yytext;
extern char *txt;
extern std::stack<char*> idStack;


#line 82 "y.tab.c" /* yacc.c:339  */

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
    Ident = 1,
    IntConst = 2,
    Exit = 3,
    When = 4,
    Begin = 5,
    Bind = 6,
    Record = 7,
    Mod = 8,
    Put = 9,
    Assert = 10,
    Then = 12,
    End = 13,
    While = 14,
    Do = 15,
    Else = 16,
    ElseIf = 17,
    Loop = 18,
    To = 19,
    TAssign = 20,
    Assign = 21,
    LParen = 22,
    RParen = 23,
    Plus = 24,
    Minus = 25,
    Star = 26,
    Slash = 27,
    Eq = 28,
    Ne = 29,
    Lt = 30,
    Le = 31,
    Gt = 32,
    Ge = 33,
    Var = 41,
    Integer = 42,
    Boolean = 43,
    Prog = 44,
    Comma = 45,
    Dot = 46,
    Real = 47,
    Not = 48,
    And = 49,
    Or = 50,
    If = 51,
    SColon = 52,
    RealT = 53,
    Div = 54
  };
#endif
/* Tokens.  */
#define Ident 1
#define IntConst 2
#define Exit 3
#define When 4
#define Begin 5
#define Bind 6
#define Record 7
#define Mod 8
#define Put 9
#define Assert 10
#define Then 12
#define End 13
#define While 14
#define Do 15
#define Else 16
#define ElseIf 17
#define Loop 18
#define To 19
#define TAssign 20
#define Assign 21
#define LParen 22
#define RParen 23
#define Plus 24
#define Minus 25
#define Star 26
#define Slash 27
#define Eq 28
#define Ne 29
#define Lt 30
#define Le 31
#define Gt 32
#define Ge 33
#define Var 41
#define Integer 42
#define Boolean 43
#define Prog 44
#define Comma 45
#define Dot 46
#define Real 47
#define Not 48
#define And 49
#define Or 50
#define If 51
#define SColon 52
#define RealT 53
#define Div 54

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "mini-turing.y" /* yacc.c:355  */
 int i; tree t; char *s; double d; 

#line 221 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     2,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     2,     2,     2,     2,     2,     2,
       2,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    38,    39,    41,    45,    47,    50,    51,
      52,    53,    56,    58,    62,    63,    64,    67,    69,    73,
      79,    81,    83,    85,    87,    89,    91,    95,    96,   109,
     111,   113,   117,   119,   121,   123,   125,   126,   129,   130,
     132,   134,   136,   138,   140,   144,   146,   147,   149,   153,
     154,   156,   158,   160,   164,   165,   166,   169,   170,   171,
     172
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Ident", "IntConst", "Exit", "When",
  "Begin", "Bind", "Record", "Mod", "Put", "Assert", "Then", "End",
  "While", "Do", "Else", "ElseIf", "Loop", "To", "TAssign", "Assign",
  "LParen", "RParen", "Plus", "Minus", "Star", "Slash", "Eq", "Ne", "Lt",
  "Le", "Gt", "Ge", "Var", "Integer", "Boolean", "Prog", "Comma", "Dot",
  "Real", "Not", "And", "Or", "If", "SColon", "RealT", "Div", "$accept",
  "program", "pStateDeclSeq", "idlist", "type", "field_list",
  "state_decls", "declaration", "statement", "ref", "end_if", "expr",
  "and_expr", "not_expr", "rel_expr", "bool_expr", "sum", "prod", "factor",
  "basic", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      22,   -27,    24,    14,    20,    14,    29,    20,    36,   -65,
      -6,    57,    39,    20,     9,    29,    73,    42,    54,   -65,
      20,    60,    60,   -65,    20,   -65,    59,   -65,    61,   -65,
      28,    10,   -65,   -65,    90,    67,    89,   105,   -65,    22,
      20,   -65,   -65,   100,   118,   103,   106,    22,    22,   -13,
     -65,   -65,   -65,    20,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,   107,    29,    19,    14,
     -65,    59,   124,   108,    19,   -65,   -65,   -65,   -65,    86,
     -65,    28,    28,    28,    28,    28,    28,    10,    10,   -65,
     -65,   -65,   -65,   -65,   -65,    29,   -65,   -65,   -65,    84,
      64,   -65,   124,   -65,    20,   110,   119,    22,    87,    14,
      20,   -65,   -65,   -65,    19,   125,   -65,   -65,   121,   123,
      91,   -65,    93,    14,    29,   -65,    64,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    27,    24,    14,     0,    14,     0,     0,     0,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
       0,     0,     0,    60,     0,    57,    45,    33,    37,    21,
      38,    46,    49,    56,     0,     6,     0,     0,     1,     3,
       0,    28,    25,     0,     0,     0,     0,     3,     3,     0,
      54,    55,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       4,    20,     0,     0,     0,    22,    16,    15,    58,    32,
      35,    39,    40,    41,    42,    43,    44,    47,    48,    53,
      50,    51,    52,    23,     7,     0,     8,    10,     9,     0,
       0,    18,     0,    17,     0,     0,     0,     3,     0,    14,
       0,    26,    19,    34,     0,     0,     5,    29,     0,     0,
      12,    11,     0,    14,     0,    30,     0,    13,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -32,     3,   -64,    15,    -4,   -65,    -1,     0,
      17,    40,   -65,   -18,   -65,     1,    58,    16,    34,    63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,   105,    99,   106,    16,    17,    10,    25,
     111,    26,    79,    27,    28,    29,    30,    31,    32,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    34,    18,    11,    18,    11,    52,    70,    37,    36,
     103,    78,    43,    12,    42,    76,    77,     1,    45,     2,
      62,     3,    14,     1,    19,     1,     4,     2,    95,     3,
      13,    53,    35,     5,     4,    80,    38,    63,    64,    11,
      39,     5,    41,    20,    44,    21,    22,    11,    11,    15,
     120,     1,    19,    60,    61,    96,    97,     6,    65,     7,
      49,    23,    24,     1,    19,   100,    98,     7,    18,    11,
      94,    20,   101,    21,    22,   116,    87,    88,   108,    40,
      71,   109,   110,    20,    50,    51,   113,    46,    47,    23,
      54,    55,    56,    57,    58,    59,    89,    90,    91,    92,
      48,    23,   112,    53,    66,   118,    67,    11,    18,    11,
      68,   119,    81,    82,    83,    84,    85,    86,    69,   126,
      72,    73,    18,    11,    74,    75,    93,     1,   102,   104,
     107,   114,   117,   115,   121,   122,   123,   124,   125,   127,
       0,     0,     0,   128
};

static const yytype_int8 yycheck[] =
{
       0,     5,     3,     3,     5,     5,    24,    39,     7,     6,
      74,    24,     3,    40,    13,    47,    48,     3,    15,     5,
      10,     7,     8,     3,     4,     3,    12,     5,     9,     7,
       6,    44,     3,    19,    12,    53,     0,    27,    28,    39,
      46,    19,     3,    23,    35,    25,    26,    47,    48,    35,
     114,     3,     4,    25,    26,    36,    37,    35,    48,    45,
      20,    41,    42,     3,     4,    69,    47,    45,    69,    69,
      67,    23,    72,    25,    26,   107,    60,    61,    14,    22,
      40,    17,    18,    23,    21,    22,   104,    14,    46,    41,
      29,    30,    31,    32,    33,    34,    62,    63,    64,    65,
      46,    41,   102,    44,    14,   109,    39,   107,   109,   109,
      21,   110,    54,    55,    56,    57,    58,    59,    13,   123,
      20,     3,   123,   123,    21,    19,    19,     3,    20,    43,
      46,    21,    45,    14,     9,    14,    13,    46,    45,   124,
      -1,    -1,    -1,   126
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,    12,    19,    35,    45,    50,    51,
      57,    58,    40,     6,     8,    35,    55,    56,    57,     4,
      23,    25,    26,    41,    42,    58,    60,    62,    63,    64,
      65,    66,    67,    68,    55,     3,    52,    64,     0,    46,
      22,     3,    64,     3,    35,    52,    14,    46,    46,    60,
      68,    68,    62,    44,    29,    30,    31,    32,    33,    34,
      25,    26,    10,    27,    28,    48,    14,    39,    21,    13,
      51,    60,    20,     3,    21,    19,    51,    51,    24,    61,
      62,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    67,    67,    19,    52,     9,    36,    37,    47,    53,
      55,    58,    20,    53,    43,    52,    54,    46,    14,    17,
      18,    59,    58,    62,    21,    14,    51,    45,    55,    64,
      53,     9,    14,    13,    46,    45,    55,    54,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    54,    54,    55,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    64,    65,    65,    65,    66,
      66,    66,    66,    66,    67,    67,    67,    68,    68,    68,
      68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     6,     1,     3,     1,     1,
       1,     4,     3,     5,     0,     3,     3,     4,     4,     5,
       3,     2,     4,     4,     1,     3,     5,     1,     3,     2,
       4,     5,     3,     1,     3,     1,     2,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     2,     2,     1,     1,     3,     1,
       1
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
#line 36 "mini-turing.y" /* yacc.c:1646  */
    { root = (yyvsp[0].t); }
#line 1399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 38 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[-2].t); (yyval.t)->next=(yyvsp[0].t);}
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 42 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Var, (yyvsp[-4].t), (yyvsp[-2].t), NULL); (yyval.t)->next=(yyvsp[0].t); }
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 46 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildStrTree(Ident, idStack.top()); idStack.pop(); }
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 48 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildStrTree(Ident, idStack.top()); idStack.pop(); (yyval.t)->next = (yyvsp[0].t);}
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildIntTree(Integer, 1); }
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 51 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildIntTree(RealT  , 2); }
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 52 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildIntTree(Boolean, 3); }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 53 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Record, (yyvsp[-2].t), NULL, NULL); }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 57 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(TAssign, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 59 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(TAssign, (yyvsp[-4].t), (yyvsp[-2].t), (yyvsp[0].t));}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 62 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 63 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[-2].t); (yyval.t)->next = (yyvsp[0].t); }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 64 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[-2].t); (yyval.t)->next = (yyvsp[0].t); }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 68 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(TAssign, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 70 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Bind, buildStrTree(Ident, idStack.top()), (yyvsp[0].t), NULL);
                          idStack.pop();
                        }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 74 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Bind, buildStrTree(Ident, idStack.top()), (yyvsp[0].t), NULL); 
                          idStack.pop();
                        }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 80 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Assign, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 82 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Assert, (yyvsp[0].t), NULL, NULL); }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 84 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Begin, (yyvsp[-2].t), NULL, NULL); }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 86 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Loop, (yyvsp[-2].t), NULL, NULL); }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 88 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 90 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Exit, (yyvsp[0].t), NULL, NULL); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 92 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(If, (yyvsp[-3].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildStrTree(Ident, idStack.top()); idStack.pop(); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 97 "mini-turing.y" /* yacc.c:1646  */
    { 
                              char * rhs = idStack.top();
                              idStack.pop();
                              char * lhs = idStack.top();
                              idStack.pop();
                              (yyval.t) = buildTree(Dot, buildStrTree(Ident, lhs)
                                            , buildStrTree(Ident, rhs)
                                            , NULL);
                        }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 110 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 112 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[-2].t); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 114 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(ElseIf, (yyvsp[-3].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 118 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Or, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 122 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(And, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 125 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Not, (yyvsp[0].t), NULL, NULL); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 126 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 131 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Eq, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 133 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Ne, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 135 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Lt, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 137 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Le, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 139 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Gt, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 141 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Ge, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 148 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Plus, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 150 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Minus, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 155 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Star, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 157 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Slash, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 159 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Div, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 161 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildTree(Mod, (yyvsp[-2].t), (yyvsp[0].t), NULL); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 164 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 165 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 166 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 170 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[-1].t); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 171 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = buildIntTree(IntConst, (yyvsp[0].i)); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 172 "mini-turing.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1721 "y.tab.c" /* yacc.c:1646  */
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
#line 174 "mini-turing.y" /* yacc.c:1906  */
