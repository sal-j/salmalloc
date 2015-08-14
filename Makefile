CC = gcc

SRC1 = salmalloc.c
SRC2 = main.c
EXE = salmalloc
OBJ = salmalloc.o
BUILDDIR = build
SRCDIR = src
INCLUDE_DIR = include
CFLAGS = -I


EXE : $(SRCDIR)/$(SRC)
	$(CC) $(CFLAGS)$(INCLUDE_DIR) $(SRCDIR)/$(SRC1) $(SRCDIR)/$(SRC2) -o $(BUILDDIR)/$(EXE)


clean :
	rm build/*.o build/*~ build/*# build/salmalloc src/*~
