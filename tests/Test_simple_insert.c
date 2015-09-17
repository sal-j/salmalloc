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

  temp = copy_list(4);

  

  while(temp != NULL) {

    char *ch = temp->memSegment + sizeof(smem_blk_seg);

    printf("ch adress: %p and val %c.\n", temp->memSegment + sizeof(smem_blk_seg), *ch);

    if (*ch == 'a' || *ch == 'b' || *ch == 'c' || *ch == 'd') {
    } else {
      printf("ERROR: Test failed. \n");
      return -1;
    }
    
    temp = (sNode*)temp->next;
  }

  printf("Test passed.\n");

  return 0;
}
  
