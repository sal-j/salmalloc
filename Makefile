CC = gcc

SRC1 = salmalloc.c
SRC2 = main.c
TSTS = Test_simple_insert.c
EXE = Test_simple_insert
BUILDDIR = tests
SRCDIR = src
INCLUDE_DIR = include
TEST_DIR = tests
CFLAGS = -I


EXE : $(SRCDIR)/$(SRC)
	$(CC) $(CFLAGS)$(INCLUDE_DIR) $(SRCDIR)/$(SRC1)  $(TEST_DIR)/$(TSTS) -o $(BUILDDIR)/$(EXE)


clean :
	rm build/*.o build/*~ build/*# build/salmalloc src/*~ tests/*~ tests/Test_simple_insert
