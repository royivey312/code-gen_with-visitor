#Makefile for Program Translation: Project 1

CC     = cc
LEX    = flex
MAIN_F = scan.c lex.yy.c
MAIN   = scan

all: $(MAIN)

lex.yy.c: mini-turing.lex
	$(LEX) $<

lex.yy.o: lex.yy.c
	$(CC) -lfl -c $<

scan.o: scan.c
	$(CC) -c $<

scan: scan.o lex.yy.o
	$(CC) -o $@ $+

clean: 
	$(RM) *.o lex.yy.c scan

