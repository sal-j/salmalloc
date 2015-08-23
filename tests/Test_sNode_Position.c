#include <stdio.h>
#include "salmalloc.h"



int main ()
{
  char *a;

  a = (char *) salmalloc(sizeof(char));
  *a = 'a';

  print_salmalloc();

  salfree(a);

  return 0;
}
  
