%a 1850
%o 2600
L	[A-Za-z]
D	[0-9]
LD	({L}|{D})
H	([0-9A-Fa-f])
ID	({L}{LD}*)
UN	({D}+|0[xX]{H}+)
N	[-+]?{UN}[bBwWlLqQfF]?
F	[-+]?({UN}\.{UN}?|\.{UN})([Ee]{D}{1,3})?[Ff]?
%{
#include <ctype.h>
#include "envir.h"
#define	NO_MEMONIC	-1

extern Quad entry;

	/* function prototypes */
static int look_mem(), insert(), look_up();
static void fix_fwd(), put(),	put_here();	
static Quad get ();

	/* internal variables */
static int line_no = 1, size, arg_pos, yylval;

#define		CS	0
#define		DS	1
static int	csn = CS, rs =  CS;
static Quad	curr_pos = Q0, load_addr = Q0;
static struct { Quad	pos, load;} Sect[2] = {{Q0, Q0}, {Q0,Q0}};

struct Fnode { 
	Quad loc; 
	int size, sect; 
	struct Fnode *next;
};
typedef struct Fnode *Fptr;
typedef struct {
	char	name[15];
	Quad	value; 
	int	sect, decl_size;
	Fptr	fptr; /* nill ptr ==> no fwd refs */
} STentry;
static STentry	ST[1000] = {"<undef>", {-1,-1}, -1, 0, 0L};

%}
%s	COM N R RO Q 
%%
[ \t\r]+		{	/* white space */ }
"\n"			{	line_no ++; }
"/*"			{	BEGIN (COM); }
<COM>"*/"	{	BEGIN (INITIAL); }
<COM>"*"		|
<COM>[^*\n]+	{	/* all characters in comment*/ }

"."CODE	{	Sect[csn].pos = curr_pos; Sect[csn].load = load_addr;
				csn = CS; 
				curr_pos = Sect[csn].pos; load_addr = Sect[csn].load; 
			}
"."DATA	{	Sect[csn].pos = curr_pos; Sect[csn].load = load_addr;
				csn = DS; 
				curr_pos = Sect[csn].pos; load_addr = Sect[csn].load; 
			}

{UN}":"	{	yytext[--yyleng] = '\000'; 
				curr_pos = qadd (strtoq(yytext), load_addr);
			}
{ID}":"	{	int val; 
				yytext[--yyleng] = '\000'; 
				if ((val = look_up(yytext)) > 0) {	/* in ST */
					STentry *p = &ST[val];
					if (p->fptr == 0L)		/* no fwd ref ==> already defined */
						yyerror ("Warning: Duplicate definition");
					else {
						p->value = curr_pos; p->sect = csn; p->decl_size = 8;
						fix_fwd (p->fptr, curr_pos); p->fptr = 0L;
					}
				}
				else {		/* not in ST */
					STentry *p = &ST[insert(yytext)];
					p->value = curr_pos; p->sect = csn; p->decl_size = 8;
					p->fptr = 0L;
				}
			}
{ID}"="	{	BEGIN (Q); yytext[--yyleng] = '\000';
				if ((yylval = look_up(yytext)) == 0) {
					yylval = insert(yytext); ST[yylval].fptr = 0L;
				}
			}
<Q>{ID}	{	STentry *p = &ST[yylval], *q = &ST[look_up(yytext)];
				BEGIN (INITIAL);
				p->value = q->value; p->sect = q->sect;
				p->decl_size = q->decl_size;
				fix_fwd (p->fptr, p->value); p->fptr = 0L;
			}
<Q>{N}	{	STentry *p = &ST[yylval]; char c = yytext[yyleng-1];
				BEGIN (INITIAL);
				p->value = strtoq(yytext); p->decl_size = 2;
				if (isalpha(c)) switch (c) {
						case 'y': case 'Y': p->decl_size = 1; break;
						case 'w': case 'W': p->decl_size = 2; break;
						case 'l': case 'L': p->decl_size = 4; break;
						case 'q': case 'Q': p->decl_size = 8; break;
					}
				fix_fwd (p->fptr, p->value); p->fptr = 0L;
			}
<Q>"."	{	STentry *p = &ST[yylval];
				BEGIN INITIAL;
				p->value = curr_pos; p->sect = csn; p->decl_size = 8;
				fix_fwd (p->fptr, curr_pos); p->fptr = 0L;
			}

"."ENTRY	{	BEGIN (N); }
<N>{ID}	{	BEGIN (INITIAL); entry = ST[look_up(yytext)].value; }
<N>{UN}	{	BEGIN (INITIAL); entry = qadd (strtoq(yytext), Sect[CS].load); }

"."RELOCB	{	BEGIN (R); size = 1; }
"."RELOCW	{	BEGIN (R); size = 2; }
"."RELOCL	{	BEGIN (R); size = 4; }
"."RELOCQ	{	BEGIN (R); size = 8; }
<R>"("	{	BEGIN (RO); }
<RO>{UN}	{	Quad loc; loc = strtoq(yytext);
				put (csn, size, loc, qadd (get (csn, size, loc), Sect[rs].load));
			}
<RO>")"	{	BEGIN (INITIAL);	}

{N}		{	char c = yytext[yyleng-1]; int size = 0;
				Quad val; val = strtoq (yytext);
				if (isalpha(c)) switch (c) {
						case 'y': case 'Y': size = 1; break;
						case 'w': case 'W': size = 2; break;
						case 'l': case 'L': size = 4; break;
						case 'q': case 'Q': size = 8; break;
						case 'f': case 'F': {
								union {float f; lword l;} u;
								if (strchr(yytext, '.') == 0L) break;
								yytext[yyleng-1]='\000';
								sscanf (yytext, "%f", &(u.f));
								val.bot = u.l; size = 4;
							}
							break;
					}
				put_here (val, size);
			}
{F}		{	union { float f; lword l;} u; Quad v;
				if (toupper(yytext[yyleng-1])=='F')yytext[yyleng-1]='\000';
				sscanf (yytext, "%f", &(u.f)); v.bot = u.l;
				put_here (v, 4);
			}

{ID}		{	int	val;
				if ((val = look_mem (yytext)) != NO_MEMONIC) {
					put (csn, 1, curr_pos, i2q (yylval = val));
					curr_pos = qadd (curr_pos, q1);
					arg_pos = 0;
				}
				else	if ((val = look_up(yytext)) > 0) {	/*in ST */
					STentry *p = &ST[val];
					if ((arg_pos >= instrs[yylval].no_arg) && (csn==CS))
							yyerror ("Illegal Memonic");
					if (p->fptr == 0L) {		/* already defined */
						put_here (p->value, 0);
					}
					else {		/* add to fwd ref pointers */
						Fptr q = (Fptr)malloc(sizeof(struct Fnode));
						q->loc = curr_pos; q->sect = csn;
						q->size = 4; curr_pos = qadd (curr_pos, q4);
						q->next = p->fptr; p->fptr = q;
					}
				}
				else { 			/* not in ST */
					STentry *p = &ST[val = insert(yytext)];
					Fptr q = (Fptr)malloc(sizeof(struct Fnode));
					q->loc = curr_pos; q->sect = csn;
					q->size = 4; curr_pos = qadd (curr_pos, q4);
					q->next = 0L; p->fptr = q;
				}
			}

.			{	yyerror ("Unknown Symbol"); }
%%
#include "S_instr.h"
#define SIsize (sizeof(S_instr)/sizeof(struct I))
static int look_mem(s)
char	s[];
{
	int i;
	for (i=0; i<SIsize; i++)
		if (strcmp(s, S_instr[i].name) == 0) return (S_instr[i].value);
	return NO_MEMONIC;
}

static int pos = 0;
static int insert(s)
char	s[];
{
	int i;
	for (i=1; i<= pos; i++)
		if (strcmp(s, ST[i].name)==0) {
			yyerror ("Symbol already defined"); return i;
		}
	pos ++; strcpy (ST[pos].name, s); return pos;
}
static int look_up(s)
char	s[];
{
	int i;
	for (i=1; i<= pos; i++)
		if (strcmp (s, ST[i].name) == 0) return i;
	return 0;
}
Quad symb_value (s)
char	s[];
{
	int	i = look_up (s);
	if (i == 0) printf ("Symbol %s not defined\n", s);
	else return ST[i].value;
	return q0;
}
void printST()
{
	int i=0;
	printf ("\n/* Symbols */\n");
	printf ("%-10s\t%-2s %-16s (%-6s) %s\n",
		"Name", "S", "Val-Hex", "  Dec", "Defined");
	for ( ; i <= pos; i++) {
		STentry *p = &ST[i];
		printf ("%-10s\t%2d %08x%08x (%06d) %s\n",
			p->name, p->sect, p->value.top, p->value.bot,
			p->value.bot, p->fptr==0L?"true":"false");
	}
}

static void fix_fwd(fptr, val)
Fptr fptr;
lword val;
{
	while (fptr != 0L) {
		Fptr n = fptr->next;
		put (fptr->sect, fptr->size, fptr->loc, val);
		free (fptr); fptr = n;
	}
}

static Quad get (sect, size, loc)
int	sect, size;
Quad	loc;
{
	Quad val; val.top = 0;
	if (sect == CS)
		switch (size) {
			case 1 : val.bot = get_code_byte (loc); break;
			case 2 : val.bot = get_code_word (loc); break;
			case 4 : val.bot = get_code_long (loc); break;
			case 8 : val = get_code_quad (loc); break;
		}
	else
		switch (size) {
			case 1 : val.bot = get_data_byte (loc); break;
			case 2 : val.bot = get_data_word (loc); break;
			case 4 : val.bot = get_data_long (loc); break;
			case 8 : val = get_data_quad (loc); break;
		}
	return val;
}

static void put (sect, size, loc, val)
int	sect, size;
Quad  loc, val;
{
	if (sect == CS)
		switch (size) {
			case 1 : put_code_byte (loc, (byte)val.bot&0xff); break;
			case 2 : put_code_word (loc, (word)val.bot&0xffff); break;
			case 4 : put_code_long (loc, val.bot); break;
			case 8 : put_code_quad (loc, val); break;
		}
	else
		switch (size) {
			case 1 : put_data_byte (loc, (byte)val.bot&0xff); break;
			case 2 : put_data_word (loc, (word)val.bot&0xffff); break;
			case 4 : put_data_long (loc, val.bot); break;
			case 8 : put_data_quad (loc, val); break;
		}
}

static void put_here (val, size)
Quad	val;
int	size;
{
	if (size > 0) {
		put (csn, size, curr_pos, val); 
		curr_pos = qadd (curr_pos, i2q(size));
	}
	else {			/* pick the proper size */
		if (csn == DS) { /* in the data section */
			put (csn, 1, curr_pos, val); curr_pos = qadd (curr_pos, q1);
		}
		else if (arg_pos >= instrs[yylval].no_arg) {	/* an instr */
			put (csn, 1, curr_pos, i2q (yylval = val.bot)); 
			curr_pos = qadd (curr_pos, q1);
			arg_pos = 0;
		}
		else {
			size = instrs[yylval].arg_size[arg_pos];
			put (csn, size, curr_pos, val);
			curr_pos = qadd (curr_pos, i2q(size)); arg_pos ++;
		}
	}
}

yyerror (s)
char	*s;
{
	fprintf (stderr, "%s at text %s on line %d\n", s, yytext, line_no);
}

static int nf;
static char *files[20];

int yywrap()
{	int i;
	Sect[csn].pos = curr_pos;
	if (nf != 0) {
		Quad cssz, dssz;
		cssz = qsub (Sect[CS].pos, Sect[CS].load);
		dssz = qsub (Sect[DS].pos, Sect[DS].load);
		printf ("; size: CS %d, DS %d\n", cssz.bot, dssz.bot);
	}
	while (files[nf] != 0L) {
		printf ("Loading file %s", files[nf]);
		line_no = 1;
		if ((yyin = fopen(files[nf++], "r")) == NULL) {
			printf ("--bad file name\n"); continue; }
		Sect[CS].load = Sect[CS].pos; Sect[DS].load = Sect[DS].pos; 
		csn = CS; load_addr = curr_pos = Sect[CS].pos; 
		printf ("--load: CS %d, DS %d", Sect[CS].load.bot, Sect[DS].load.bot);
		return 0;
	}
	printf ("Entry point: %d\n", entry.bot);
	for (i = 1; i <= pos; i++) {
		STentry	*p = &ST[i];
		if (p->fptr != 0L) 
			printf ("Symbol %s used and undefined\n", p->name);
	}
	return 1;
}

void get_load_files()
{
	int i = 0; char ch = getchar();
	while (-1) {
		char *p = (char*)malloc(20); int j = 0;
		while (ch == ' ' || ch == '\t') ch = getchar();
		if (ch == '\n') break;
		do {p[j] = ch; j++; } while (!isspace(ch=getchar()));
		p[j] = '\000'; files[i++] = p;
	}
	files[i] = 0L; nf = 0; yyin = fopen ("/dev/null", "r");
}

void initial_load_files(argc, argv)
int	argc;
char	*argv[];
{
	int i = 1;
	for (i; i<argc; i++){
		files[i-1] = argv[i];
	}
	files[i] = 0L; nf = 0; yyin = fopen ("/dev/null", "r");
}

void init_load ()
{	csn = CS; rs =  CS; 
	curr_pos = q0; load_addr = q0;
	Sect[0].pos = Sect[0].load = Sect[1].pos = Sect[1].load = q0;
	pos = 0; /* reset ST */
	entry = q0;
}
