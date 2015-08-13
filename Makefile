CC = gcc

SRC = salmalloc.c 
EXE = salmalloc
BUILDDIR = build
SRCDIR = src
INCLUDEDIR = include
CFLAGS = -I

EXE : $(SRCDIR)/$(SRC)
	$(CC) $(CFLAGS)$(INCLUDEDIR) $(SRCDIR)/$(SRC) -o $(BUILDDIR)/$(EXE)


clean :
	rm build/*.o build/*~ build/*# build/salmalloc
