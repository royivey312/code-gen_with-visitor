CC = gcc
HEAD = instr.h spaces.h globals.h
SRCS = run.c menu.c Load.c \
       super.c relative.c code_space.c data_space.c frame.c \
       math.c logical.c shift_test.c stack_man.c convert.c \
       quad_math.c spaces.c instr.c 
OBJS = run.o menu.o Load.o \
       super.o relative.o code_space.o data_space.o frame.o \
       math.o logical.o shift_test.o stack_man.o convert.o \
       quad_math.o spaces.o instr.o 
DOCS = doc/machine.tex doc/link-load.tex doc/instr.tex \
       doc/debugger.tex doc/Makefile
ORIG_SRCS = load.l run.c menu.c \
       super.c relative.c code_space.c data_space.c frame.c \
       math.c logical.c shift_test.c stack_man.c convert.c \
       quad_math.c spaces.c instr.c 

run: $(OBJS)
	$(CC) -o run $(OBJS) 
Load.c : load.l
	lex -t load.l >Load.c
$(OBJS) : $(HEAD)
Load.o : S_instr.h

docs:
	(cd doc; make all)
clean:
	rm *.o Load.c
	(cd doc; make clean)

Tar: $(HEAD) $(ORIG_SRCS) Makefile $(DOCS)
	tar cf Tar Makefile $(ORIG_SRCS) $(HEAD) $(DOCS)
