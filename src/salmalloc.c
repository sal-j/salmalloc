#include <stdio.h>
#include "salmalloc.h"
sList memlist = {0};

/*
	**************************
		sNode
	**************************
		mem_Seg
		   +
	     sizeOf Object
	**************************
		mem_seg has 
		metadata
	**************************
	      return to use
	       where memSeg
	      ends and when
	     to free subtract
	     memSeg from user
	     pointer to move
	   at start of object.
	**************************
*/



/*
  Function to add a node to linked list. 
  @param size is the size of the object.
  ToDo: Make it more dynamic. 
*/
extern void *salmalloc(size_t size)
{
  smem_blk_seg *seg = NULL; /* memory segment  */

  /* If list is currently NULL add a new node. */
  if (memlist.head == NULL) {

    /* extend heap by sNode */
    memlist.head = (sNode *)sbrk(sizeof(sNode));

    /* 
       Get current end of heap.
       Algorithm is: sNode + mem_seg. sNode carries 
       metadata about the mem_seg, for example if it
       is free or not.
    */
    seg = (smem_blk_seg *)sbrk(0);

    /* Extend heap */
    memlist.head->memSegment = (void *)sbrk(size + sizeof(smem_blk_seg));

    memlist.head->magicVal = 90;
    seg->isFree = 123;
    seg->size = size;

    memlist.head->next = NULL;
    memlist.length = 1;
    /* return start of our memory segment. */
    return memlist.head->memSegment + sizeof(smem_blk_seg);
  } else {
    
    sNode *temp = memlist.head, *prev = NULL, *newNode = NULL;
    
    printf("second node.\n");
    
    /* Go to the last node */
    while(temp->next != NULL) {
      prev = temp;
      temp = (sNode *) temp->next;
      printf("I am here.");
    }    
    
    printf("ends.\n");

    /* Get end of heap */
    seg = (smem_blk_seg *) sbrk(0);

    printf("memlist length is 1.\n");    

    if (memlist.length == 1) {
      sNode *newNode1 = NULL;

      /* extend heap by sNode */
      newNode1 = (sNode *)sbrk(sizeof(sNode));

      /* 
	 Get current end of heap.
	 Algorithm is: sNode + mem_seg. sNode carries 
	 metadata about the mem_seg, for example if it
	 is free or not.
      */
      seg = (smem_blk_seg *)sbrk(0);

      /* Extend heap */
      newNode1->memSegment = (void *)sbrk(size + sizeof(smem_blk_seg));

      newNode1->magicVal = 90;
      seg->isFree = 123;
      seg->size = size;

      memlist.head->next = (struct sNode*)newNode1;
      memlist.length = 2;
      /* return start of our memory segment. */
      return newNode1->memSegment + sizeof(smem_blk_seg);       
    }

    /* extend heap by sNode */
    temp->next = (struct sNode *)sbrk(sizeof(sNode));

    /* 
       Get current end of heap.
       Algorithm is: sNode + mem_seg. sNode carries 
       metadata about the mem_seg, for example if it
       is free or not.
    */
    seg = (smem_blk_seg *)sbrk(0);

    temp = (sNode*)temp->next;

    /* Allocate memory */
    temp->memSegment = (void *) sbrk(size + sizeof(smem_blk_seg));
    
    seg->isFree = 129;
    seg->size = size;
    
    /* set next node to nULL */
    temp->next = NULL;

    /* extend length of list. */
    memlist.length++;

    /* Set node type. */
    if (memlist.length % HUNDRED == ZERO) {
      temp->vNodeType = eHundreds;
    } else if (memlist.length % TEN == ZERO) {
      temp->vNodeType = eTens;
      
    if (memlist.length == 9) {
      memlist.head->specialNode = temp;
      temp->specialNode = memlist.head;
      memlist.tens = temp;
    }
      
   }
    
    printf("third node added.\n");

    /* return memory segment */
    return temp->memSegment + sizeof(smem_blk_seg);
  }
}

extern void salfree (void *ptr) 
{
  smem_blk_seg *seg = (ptr - sizeof(smem_blk_seg));

  //printf("\n  freed ptr is at : 0x%x \n", seg);

  printf("%d \n", seg->isFree);
}


extern void print_salmalloc()
{
  sNode *temp = memlist.head;
  size_t listIndex = 0;

  while(temp != NULL) {
    char *ch = temp->memSegment + sizeof(smem_blk_seg);
    printf("listIndex: %d. character in address %p and print: %c.\n", listIndex, (temp->memSegment) + sizeof(smem_blk_seg), 
	 *ch);

    listIndex++;
    temp = (sNode* ) temp->next;
  }

}
