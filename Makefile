CC = gcc

SRC = salmalloc.c 
EXE = salmalloc
BUILDDIR = build
SRCDIR = src

EXE : $(SRCDIR)/$(SRC)
	$(CC) $(SRCDIR)/$(SRC) -o $(BUILDDIR)/$(EXE)


clean :
	rm build/*.o build/*~ build/*# build/salmalloc
