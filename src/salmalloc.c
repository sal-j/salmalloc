#include <stdio.h>
#include "salmalloc.h"
sList memlist = {0};

extern void *salmalloc(size_t size)
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

extern void salfree (void *ptr) 
{
  smem_blk_seg *seg = (ptr - sizeof(smem_blk_seg));

  printf("\n  freed ptr is at : 0x%x \n", seg);

  printf("%d \n", seg->isFree);
}


