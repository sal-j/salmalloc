#include <stdio.h>
#include "salmalloc.h"



void main ()
{
  char *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t;
  char *ka, *la, *ma, *na, *oa, *pa, *qa, *ra, *sa, *ta;
  
  //printf("\n  p : 0x%x \n", p);

  //p =  (int *)salmalloc(sizeof(int));
  
  //printf("\n  p after seg is at : 0x%x \n", p);


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

  printf("length: %d.\n", get_length());

    
  print_salmalloc();

  //  print_skip_nodes(eTens);
  salfree(j);

  print_salmalloc();


  j = (char *) salmalloc(sizeof(char));
  *j = 'k';
  
  print_salmalloc();

}
