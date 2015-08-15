#include <stdio.h>
#include "salmalloc.h"

void main ()
{
  int *p = (int*)sbrk(0);
  char *q = NULL;
  char *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;
  
  //printf("\n  p : 0x%x \n", p);

  //p =  (int *)salmalloc(sizeof(int));
  
  //printf("\n  p after seg is at : 0x%x \n", p);


  q = (char *) salmalloc(sizeof(char));
  *q = 'q';
  printf("address: %p and character: %c.\n", q, *q);
  a = (char *) salmalloc(sizeof(char));
  *a = 'a';
  printf("address: %p and character: %c.\n", a, *a);
  b = (char *) salmalloc(sizeof(char));
  *b = 'b';
  /*c = (char *) salmalloc(sizeof(char));
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
  //j = (char *) salmalloc(sizeof(char));
  //k = (char *) salmalloc(sizeof(char));


  //salfree(p);

  //salfree(q);
  */
  print_salmalloc();
}


