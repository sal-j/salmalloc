CC = gcc

SRC = salmalloc.c 
EXE = salmalloc
BUILDDIR = build


EXE : $(SRC)
	$(CC) $(SRC) -o $(BUILDDIR)/$(EXE)


clean :
	rm build/*.o build/*~ build/*# build/salmalloc
