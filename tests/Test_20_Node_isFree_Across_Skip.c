#include <stdio.h>
#include "salmalloc.h"
#include <stdint.h>

/*
  This test checks if 
  1. Elements are correctly added and freed
  2. If new elements are added at correct places
  3. If previously freed places were repopulated if same size objects
     were requested.
  4. If num nodes ahead are correctly updated.
*/


ssize_t testIsFree24Item()
{
        size_t i = 0;
        sNode *temp = copy_list(4);
        while (temp != NULL) {
	  smem_blk_seg *seg = temp->memSegment;
	  
	  switch (i) {
	  case 24: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  }

	  temp = (sNode*) temp->next;
	  i++;
        }
        return TRUE;

}

ssize_t testIsFree()
{
        size_t i = 0;
        sNode *temp = copy_list(4);
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
	  case 22: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  case 24: { if (seg->isFree != TRUE) {printf("Test failed."); return FALSE;} break; }
	  }

	  temp = (sNode*) temp->next;
	  i++;
        }
        return TRUE;
}

ssize_t testAllFree()
{
        size_t i = 0;
        sNode *temp = copy_list(4);
        while (temp != NULL) {
	  smem_blk_seg *seg = temp->memSegment;
	  //printf("i == %zu and ch: %zd.\n", i, seg->isFree);

	  if (seg->isFree == TRUE) {printf("Test failed."); return FALSE; }
	  temp = (sNode*) temp->next;
	  i++;
        }
        return TRUE;
}


ssize_t testAdditionOfLargerElementAtEndOfList()
{
        size_t i = 0;
        sNode *temp = copy_list(4);
	ssize_t result = FALSE;
        while (temp != NULL) {
	  smem_blk_seg *seg = temp->memSegment;
	  if (seg->size == 8) { result = TRUE; return result; }
	  temp = (sNode*) temp->next;
	}
	return result;
}

ssize_t testSkipNodes_Edge_Cases()
{
        size_t i = 0;
        sNode *temp = copy_list(4);
        while (temp != NULL) {
        	int ch = temp->numNodesAhead;
	        //printf("i == %zu and ch: %zd.\n", i, ch);
		switch (i) {
		case 0: {if (ch != 10) {printf("Test case failed in Edge cases evalulation.\n"); return FALSE;} break;}
		case 1: {if (ch != 10) {printf("Test case failed in Edge cases evalulation.\n"); return FALSE;} break;}
		case 2: {if (ch != 2) {printf("Test case failed in Edge cases evalulation.\n"); return FALSE;} break;}
		default: {printf("Test case failed in Edge cases evalulation.\n"); return FALSE;}
	     
		}
		temp = temp->skipNodes.fwd_tenSpecialNode;
        	i++;
        }
        return TRUE;
}




int main()
{
  ssize_t *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10, *a11, *a12, *a13, *a14, *a15, *a16, *a17, *a18, *a19, *a20, *a21, *a22, *a23;
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

	if (testSkipNodes_Edge_Cases() != TRUE) {
	  return FALSE;
	}
	  
	/* printf("Part 1 of test case passed. Edge cases evaluated correctly.\n"); */

	testSkipNodes_Edge_Cases();

	/* Free random positions in list */
       	salfree(a0);
       	salfree(a1);
	salfree(a8);
	salfree(a9);
	salfree(a10);
	salfree(a11);
	salfree(a12);
	salfree(a20);
	salfree(a21);

	/* Check if positions were correctly freed. */
	if (testIsFree() != TRUE) {
	  return FALSE;
        }
	
      	/* printf("Part 2 of test case passed. Free was evaluated correctly.\n"); */
	
	/* repopulate these positions.*/
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

	if (testAllFree() != TRUE) {
	  printf("Test failed at step 2b. All that were freed where not populated.\n");
	  return FALSE;
	}

	/* add a larger sized element and ensure that it is populated at the end of list */
	b = (uint64_t*) salmalloc(sizeof(uint64_t));
	*b = 22;
	
	/*  Test if element was added correctly. */
	if (testAdditionOfLargerElementAtEndOfList() != TRUE) {
	  printf("Test failed at insertion of b which is size 8.\n");
	}

	/* printf("Part 3 of test case passed. Larger sized element was added correctly at the end.\n"); */

	/* Add a new node */
	a23 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a23 = 23;

	/* Free this node */
	salfree(a23);

	/* Check if positions were correctly freed. */
	if (testIsFree24Item() != TRUE) {
	  printf("Test failed at step 4.\n");
	  return FALSE;
	}

	/* printf("Part 4 of test case passed. Free was evaluated correctly.\n"); */
	
	a23 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a23 = 23;

	if (testAllFree() != TRUE) {
	  printf("Test failed at step 5. All that were freed where not populated.\n");
	  return FALSE;
	}

	/* printf("Part 5 of test case passed. Free was evaluated correctly.\n"); */

	printf("Test_20_Node_isFree_Across_Skip.c passed.\n");
	
	return TRUE;
}


