CC = gcc
LIB_NAME = salmalloc
SRC1 = salmalloc.c
SRC2 = main.c
TSTS = Test_simple_insert.c
EXE = Test_simple_insert
SHARED_LIB_0 = salmalloc.o
BUILDDIR = build
SRCDIR = src
INCLUDE_DIR = include
TEST_DIR = tests
TEST_BUILD = tests/build/
SHARED_LIB_DIR = /home/salman/projects/salmalloc/build/
CFLAGS_INCLUDE = -I
CFLAGS_C = -c
CFLAGS_OUT = -o
CFLAGS_SHARED = -shared
CFLAGS_SHARED_LIB = -L
CFLAGS_LIBS_FLAG = -l
LIB_0 = libsalmalloc.so



$(EXE): $(LIB_0) 
	$(CC) $(CFLAGS_SHARED_LIB)$(SHARED_LIB_DIR) $(CFLAGS_INCLUDE)$(INCLUDE_DIR) $(TEST_DIR)/$(TSTS) $(CFLAGS_OUT) $(TEST_BUILD)/$(EXE) $(CFLAGS_LIBS_FLAG)$(LIB_NAME)

$(LIB_0): $(SHARED_LIB_0)
	$(CC) $(CFLAGS_SHARED) $(BUILDDIR)/$(SHARED_LIB_0) $(CFLAGS_OUT) $(BUILDDIR)/$(LIB_0)

$(SHARED_LIB_0) : $(SRCDIR)/$(SRC)
	$(CC) $(CFLAGS_INCLUDE)$(INCLUDE_DIR) $(CFLAGS_C) $(SRCDIR)/$(SRC1) $(CFLAGS_OUT) $(BUILDDIR)/$(SHARED_LIB_0)


clean :
	rm build/*.o build/*.so build/*~ build/*# build/salmalloc src/*~ tests/*~ tests/*.o tests/build/*
