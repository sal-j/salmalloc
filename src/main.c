#include <stdio.h>
#include "salmalloc.h"

void main ()
{
  int *p = (int*)sbrk(0);
  char *q = NULL;
  char *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;
  
  printf("\n  p : 0x%x \n", p);

  p =  (int *)salmalloc(sizeof(int));
  
  printf("\n  p after seg is at : 0x%x \n", p);


  q = (char *) salmalloc(sizeof(char));
  a = (char *) salmalloc(sizeof(char));
  b = (char *) salmalloc(sizeof(char));
  c = (char *) salmalloc(sizeof(char));
  d = (char *) salmalloc(sizeof(char));
  e = (char *) salmalloc(sizeof(char));
  f = (char *) salmalloc(sizeof(char));
  g = (char *) salmalloc(sizeof(char));
  h = (char *) salmalloc(sizeof(char));
  i = (char *) salmalloc(sizeof(char));
  //j = (char *) salmalloc(sizeof(char));
  //k = (char *) salmalloc(sizeof(char));


  salfree(p);

  salfree(q);
}


