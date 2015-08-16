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

  k = (char *) salmalloc(sizeof(char));
  *k = 'k';
  
  l = (char *) salmalloc(sizeof(char));
  *l = 'l';
  m = (char *) salmalloc(sizeof(char));
  *m = 'm';
  n = (char *) salmalloc(sizeof(char));
  *n = 'n';
  o = (char *) salmalloc(sizeof(char));
  *o = 'o';
  p = (char *) salmalloc(sizeof(char));
  *p = 'p';
  q = (char *) salmalloc(sizeof(char));
  *q = 'q';
  r = (char *) salmalloc(sizeof(char));
  *r = 'r';
  s = (char *) salmalloc(sizeof(char));
  *s = 's';
  t = (char *) salmalloc(sizeof(char));
  *t = 't';

  ka = (char *) salmalloc(sizeof(char));
  *ka = '1';
  la = (char *) salmalloc(sizeof(char));
  *la = '2';
  ma = (char *) salmalloc(sizeof(char));
  *ma = '3';
  na = (char *) salmalloc(sizeof(char));
  *na = '4';
  oa = (char *) salmalloc(sizeof(char));
  *oa = '5';
  pa = (char *) salmalloc(sizeof(char));
  *pa = '6';
  qa = (char *) salmalloc(sizeof(char));
  *qa = '7';
  ra = (char *) salmalloc(sizeof(char));
  *ra = '8';
  sa = (char *) salmalloc(sizeof(char));
  *sa = '9';
  ta = (char *) salmalloc(sizeof(char));
  *ta = '0';

  print_salmalloc();





  print_skip_nodes(eTens);
}



