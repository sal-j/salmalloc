#include <stdio.h>
#include "salmalloc.h"

/*
  This test verifies that if memory
  at head is correctly allocated and freed.
*/


int main ()
{
  char *a;
  sNode* temp;

  smem_blk_seg *seg;
  

  a = (char *) salmalloc(sizeof(char));
  *a = 'a';

  temp = (sNode*) copy_list(4);

  seg = temp->memSegment;


  if (seg->isFree != FALSE) {
    printf("Test failed. Memory was not allocated correctly.\n");
    return FALSE;
  }

  salfree(a);

  if (seg->isFree != TRUE) {
    printf("Test failed. Memory was not de-allocated correctly.\n");
    return FALSE;
  }

  printf("Test_sNode_Position.c passed.\n");
  
  return 0;
}
  
