#include <stdio.h>
#include "salmalloc.h"
#include <stdint.h>


ssize_t testIsFree()
{
        size_t i = 0;
        sNode *temp = copy_list();
        while (temp != NULL) {
	  smem_blk_seg *seg = temp->memSegment;
	  //printf("i == %zu and ch: %zd.\n", i, seg->isFree);

	  switch (i) {
	  case 0: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 1: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 8: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 9: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 10: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 11: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 12: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 20: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 21: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  }

	  temp = (sNode*) temp->next;
	  i++;
        }
        return TRUE;
}

ssize_t testSkipNodes_Edge_Cases()
{
        size_t i = 0;
        sNode *temp = copy_list();
        while (temp != NULL) {
        	int ch = temp->numNodesAhead;
	        printf("i == %zu and ch: %zd.\n", i, ch);
		temp = temp->skipNodes.fwd_tenSpecialNode;
        	i++;
        }
        return TRUE;
}


int main()
{
  ssize_t *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10, *a11, *a12, *a13, *a14, *a15, *a16, *a17, *a18, *a19, *a20, *a21;
  uint64_t *b;

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
	
	a20 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a20 = 20;

	a21 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a21 = 21;

	testSkipNodes_Edge_Cases();

       	salfree(a0);
       	salfree(a1);
	salfree(a8);
	salfree(a9);
	salfree(a10);
	salfree(a11);
	salfree(a12);
	salfree(a20);
	salfree(a21);

	if (testIsFree() != FALSE) {
	  printf("Test passed.\n");
	}
	
	//print_salmalloc();

	//printf("long size: %d.\n", sizeof(uint64_t));

	/*b = (uint64_t *) salmalloc(sizeof(uint64_t));
	 *b = 21;*/

	//print_salmalloc();	
	testSkipNodes_Edge_Cases();

	print_salmalloc();

	a0 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a0 = 0;
	a1 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a1 = 1;
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
	a20 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a20 = 20;
	a21 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a21 = 21;
	
	print_salmalloc();	
	testSkipNodes_Edge_Cases();

	return TRUE;
}


