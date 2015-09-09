#include <stdio.h>
#include "salmalloc.h"


/*
  This test checks if skip list with under 10
  nodes performs correctly with inserting and
  free routines.
*/

ssize_t testNodes_Under_10_Insert_Free()
{
        size_t i = 0;
        sNode *temp = copy_list();
        while (temp != NULL) {
        	int ch = temp->numNodesAhead;
	        //printf("i == %zu and ch: %zd.\n", i, ch);
		if (ch != 9 && ch != 8 && ch != 0 && ch != 1) {
		  printf("Test failed. Skip count are not what were expected.\n");
		  return FALSE;
		}
		temp = temp->skipNodes.fwd_tenSpecialNode;
        	i++;
        }
        return TRUE;
}



int main()
{
  	ssize_t *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10;


	a0 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a0 = 0;	
	
	a1 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a1 = 1;
	
	a2 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a2 = 2;

	a3 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a3 = 3;
	
	a4 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a4 = 4;

	a5 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a5 = 5;

	a6 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a6 = 6;

	a7 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a7 = 7;

	a8 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a8 = 8;

	a9 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a9 = 9;

	if (testNodes_Under_10_Insert_Free() != TRUE) {
	  return FALSE;
	}

	printf("Test part 1 was successful.\n");


	salfree(a0);
	salfree(a1);
	salfree(a2);
	salfree(a3);
	salfree(a4);
	salfree(a5);
	salfree(a6);
	salfree(a7);
	salfree(a8);
	salfree(a9);

	if (testNodes_Under_10_Insert_Free() != TRUE) {
	  return FALSE;
	}

	printf("Test part 2 was successful.\n");


	a4 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a4 = 4;

	if (testNodes_Under_10_Insert_Free() != TRUE) {
	  return FALSE;
	}

	printf("Test part 3 was successful.\n");


	a7 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a7 = 7;

	testNodes_Under_10_Insert_Free();

	printf("Test part 4 was successful.\n");


	a0 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a0 = 0;	
	
	a1 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a1 = 1;
	
	a2 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a2 = 2;

	a3 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a3 = 3;
	
	a5 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a5 = 5;

	a6 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a6 = 6;

	a8 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a8 = 8;

	a9 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a9 = 9;

	testNodes_Under_10_Insert_Free();

	printf("Test part 5 was successful.\n");

	return TRUE;
}


