#include "salmalloc.h"
#include <stdio.h>

sList memlist = {0};

void *salmalloc(size_t size)
{
  smem_blk_seg *seg = NULL;
  if (memlist.head == NULL) {

    memlist.head = (sNode *)sbrk(sizeof(sNode));

    seg = (smem_blk_seg*)sbrk(0);
    memlist.head->memSegment = (void *)sbrk(size + sizeof(smem_blk_seg));

    memlist.head->magicVal = 90;
    seg->isFree = 123;
    seg->size = size;

    memlist.head->next = NULL;
    memlist.length = 0;
    return memlist.head->memSegment + sizeof(smem_blk_seg);
  } else {
    sNode *temp = memlist.head, *prev = NULL;

    while(memlist.head->next != NULL) {
      prev = temp;
      temp = (sNode *) temp->next;
    }    
    
    seg = (smem_blk_seg *) sbrk(0);
    temp->memSegment = (void *) sbrk(size + sizeof(smem_blk_seg));
    
    seg->isFree = 129;
    seg->size = size;

    if (prev != NULL) {
      prev->next = (struct sNode *) temp;
    } else {
      memlist.head->next = (struct sNode *) temp;
    }
    temp->next = NULL;

    memlist.length++;

    if (memlist.length % HUNDRED == ZERO) {
      temp->vNodeType = eHundreds;
    } else if (memlist.length % TEN == ZERO) {
      temp->vNodeType = eTens;
    }

    return temp->memSegment + sizeof(smem_blk_seg);
  }
}

void salfree (void *ptr) 
{
  smem_blk_seg *seg = (ptr - sizeof(smem_blk_seg));

  printf("\n  freed ptr is at : 0x%x \n", seg);

  printf("%d \n", seg->isFree);
}

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
