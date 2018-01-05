 #Makefile for Program Translation: Project 1

CC         = g++ -g
LEX        = flex
MAIN_F     = scan.c lex.yy.c
MAIN       = turing
PARSE_OBJS = main.o tree.o lex.yy.o mini-turing.tab.o 
SCAN_OBJS  = scan.o lex.yy.o tree.o

all: $(MAIN)

turing: $(PARSE_OBJS)
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
	$(RM) *.o lex.yy.c scan mini-turing.tab.* mini-turing.output test turing

