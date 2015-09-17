#include <stdio.h>
#include "salmalloc.h"



ssize_t testList() 
{
 		sNode *temp = copy_list(4);
		ssize_t count = 0;
       		while(temp != NULL) {
       			ssize_t *compare = temp->memSegment + sizeof(smem_blk_seg);
			if (*compare != count) {
				printf("Test failed at count %zd when compare was %zd.\n", count, *compare);
       				return FALSE;
       			}
       			temp = (sNode*)temp->next;
        		count++;
       		}
       		return TRUE;
}


ssize_t testSkipNodes()
{
        size_t i = 0;
        sNode *temp = copy_list(4);
        while (temp != NULL) {
        	int ch = temp->numNodesAhead;
	        //printf("i == %zu and ch: %zd.\n", i, ch);
		if (ch != 10) {
		  printf("Test failed. Skip count are not what were expected.\n");
		  return FALSE;
		}
		temp = temp->skipNodes.fwd_tenSpecialNode;
        	i++;
        }
        return TRUE;
}

ssize_t testSkipNodes_Edge_Cases()
{
        size_t i = 0;
        sNode *temp = copy_list(4);
        while (temp != NULL) {
        	int ch = temp->numNodesAhead;
	        //printf("i == %zu and ch: %zd.\n", i, ch);
		if (ch != 10 && ch != 9 && ch != 0 && ch != 2) {
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
  ssize_t *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10, *a11, *a12, *a13, *a14, *a15, *a16, *a17, *a18, *a19, *a20, *a21;


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

	a10 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a10 = 10;

	a11 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a11 = 11;
	
	a12 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a12 = 12;
	
	
	a13 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a13 = 13;

	a14 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a14 = 14;

	a15 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a15 = 15;

	a16 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a16 = 16;

	a17 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a17 = 17;

	a18 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a18 = 18;

	a19 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a19 = 19;
	
	if (testList() != TRUE) {
		return FALSE;
	}

	/* printf("Test part 1 was successful.\n"); */

	if (testSkipNodes() != TRUE) {
	  return FALSE;
	}

	/* printf("Test part 2 was successful.\n"); */

	a20 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a20 = 20;

	a21 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a21 = 21;


	if (testSkipNodes_Edge_Cases() != TRUE) {
	  return FALSE;
	}

	/* printf("Test part 3 was successful.\n"); */

	printf("Test_20_Node_Skip_Count.c passed.\n");

	return TRUE;
}


