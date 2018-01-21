 #Makefile for Program Translation: Project 1

CC        = g++ -std=gnu++11 -g
LEX       = flex
MAIN_F    = scan.c lex.yy.c
MAIN      = turing
SYMB_OBJS = sym_tab.o lex.yy.o tree.o mini-turing.tab.o
SCAN_OBJS = scan.o lex.yy.o tree.o
TREE_OBJS = parse-tree.o tree.o lex.yy.o mini-turing.tab.o 

all: $(MAIN)

turing: $(SYMB_OBJS)
	$(CC) -o $@ $+ -lfl

turing-tree: $(TREE_OBJS)
	$(CC) -o $@ $+ -lfl

test: mini-turing.tab.o tree.o parse.o lex.yy.o
	$(CC) -o $@ $+ -lf

lex.yy.c: mini-turing.lex
	$(LEX) $<

lex.yy.o: lex.yy.c
	$(CC) -lfl -c $<
	
scan: $(SCAN_OBJS)
	$(CC) -o $@ $+

mini-turing.tab.c: mini-turing.y
	bison -Wconflicts-rr -vd $+

mini-turing.tab.h: mini-turing.tab.c

clean: 
	$(RM) *.o lex.yy.c scan mini-turing.tab.* mini-turing.output test turing-tree turing-symtab turing

