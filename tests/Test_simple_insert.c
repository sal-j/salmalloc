#include <stdio.h>
#include "salmalloc.h"



int main ()
{
  char *a, *b, *c, *d;
  sNode* temp;

  a = (char *) salmalloc(sizeof(char));
  *a = 'a';
  b = (char *) salmalloc(sizeof(char));
  *b = 'b';
  c = (char *) salmalloc(sizeof(char));
  *c = 'c';
  d = (char *) salmalloc(sizeof(char));
  *d = 'd';

  print_salmalloc();
  
  printf("initial: %p.\n", temp);
  
  copy_list_1(temp);

  printf("after: %p.\n", (temp->memSegment + sizeof(smem_blk_seg)));

  temp = copy_list();

  

  while(temp != NULL) {

    char *ch = temp->memSegment + sizeof(smem_blk_seg);

    //printf("ch: %p.\n", temp->memSegment + sizeof(smem_blk_seg));

    /*if (*ch != 'a' || *ch != 'b' || *ch != 'c' || *ch != 'd') {
      printf("ERROR: Test failed.\n");
      return -1;
      }*/
    
    temp = (sNode*)temp->next;
  }

  return 0;
}
  
