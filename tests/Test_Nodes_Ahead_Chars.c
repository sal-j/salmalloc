#include <stdio.h>
#include "salmalloc.h"

/*
  This test checks if characters are added
  correctly before and after skip nodes.
*/

ssize_t matchVal(char *ch)
{

  if (*ch == 'a' || *ch == 'b' || *ch == 'c' || *ch == 'd' ||
      *ch == 'e' || *ch == 'f' || *ch == 'g' || *ch == 'h' ||
      *ch == 'i' || *ch == 'j' || *ch == 'k') {
      return TRUE;
  } else {
    printf("ERROR: Test failed. Received %c.\n", *ch);
    return FALSE;
  }
}


ssize_t Test_List()
{
  sNode *temp = copy_list(4);

  while(temp != NULL) {

    char *ch = temp->memSegment + sizeof(smem_blk_seg);

    if (matchVal(ch) != TRUE) {
      return FALSE;
    }

    temp = (sNode*)temp->next;
  }

  return TRUE;
}

int main ()
{
  char *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;
  sNode *temp = NULL;

  /* Populate the array */
  a = (char *) salmalloc(sizeof(char));
  *a = 'a';
  b = (char *) salmalloc(sizeof(char));
  *b = 'b';
  c = (char *) salmalloc(sizeof(char));
  *c = 'c';
  d = (char *) salmalloc(sizeof(char));
  *d = 'd';
  e = (char *) salmalloc(sizeof(char));
  *e = 'e';
  f = (char *) salmalloc(sizeof(char));
  *f = 'f';
  g = (char *) salmalloc(sizeof(char));
  *g = 'g';
  h = (char *) salmalloc(sizeof(char));
  *h = 'h';
  i = (char *) salmalloc(sizeof(char));
  *i = 'i';
  j = (char *) salmalloc(sizeof(char));
  *j = 'j';

  if (Test_List() != TRUE) {
    printf("Test failed at step 1. List was not populated correctly.\n");
    return FALSE;
  }

  printf("\n\nTest before deleting char j passed.\n\n");
  
  k = (char *) salmalloc(sizeof(char));
  *k = 'k';

  if (Test_List() != TRUE) {
    printf("Test failed at step 2. Additional element was not populated correctly.\n");
    return FALSE;
  }

  printf("\n\nTest after adding char k passed.\n");
}
