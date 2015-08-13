CC = gcc

SRC = salmalloc.c 
EXE = salmalloc

EXE : $(SRC)
	$(CC) $(SRC) -o $(EXE)


clean :
	rm *.o *~ *# salmalloc
