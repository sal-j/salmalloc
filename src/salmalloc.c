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

extern void link_skip_nodes(sNode *temp)
{
    /* Set node type. */
    if (memlist.length % HUNDRED == ZERO) {
      temp->vNodeType = eHundreds;
    } else if (memlist.length % TEN == ZERO) {
      temp->vNodeType = eTens;
      
      if (memlist.length == TEN) {

       	/*
	  a -> fwd_special = j;
	  j -> prev_special = a;
	  a -> prev_special = j;
	  j -> fwd_special = a;
	  memlist.tensSpecial = j;
	 */

	memlist.head->skipNodes.fwd_tenSpecialNode = temp;
	memlist.head->skipNodes.prev_tenSpecialNode = temp;

	temp->skipNodes.prev_tenSpecialNode = memlist.head;
	temp->skipNodes.fwd_tenSpecialNode = memlist.head;

	memlist.skipNodes.prev_tenSpecialNode = temp;
	
	memlist.head->numNodesAhead = TEN;
	temp->numNodesAhead = EMPTY;

	memlist.head->vNodeType = eTens;

      } else {

	/*
	    prev = memlist.tenSpecial
	    temp -> prev_special = prev;
	    temp -> fwd_special  = head;

	    prev -> fwd_special  = temp;
	    memlist.tenSpecial   = temp;
	*/

	sNode *prev = (sNode*) memlist.skipNodes.prev_tenSpecialNode;

	temp->skipNodes.prev_tenSpecialNode = (void*)prev;	
	temp->skipNodes.fwd_tenSpecialNode = (void*)memlist.head;

	prev->skipNodes.fwd_tenSpecialNode = (void*)temp;
	memlist.skipNodes.prev_tenSpecialNode = temp;
      }
   }
}

extern void *insert_salmalloc(size_t size)
{
  smem_blk_seg *seg = NULL; /* memory segment  */
  void *sNodeLocation = NULL;
  sNode* temp = NULL;

  sNodeLocation = (void*) sbrk(0);

  /* extend heap by sNode */
  temp = (sNode *)sbrk(sizeof(sNode));

  /* 
     Get current end of heap.
     Algorithm is: sNode + mem_seg. sNode carries 
     metadata about the mem_seg, for example if it
     is free or not.
  */
  seg = (smem_blk_seg *)sbrk(0);

  /* Extend heap */
  temp->memSegment = (void *)sbrk(size + sizeof(smem_blk_seg));

  seg->isFree = FALSE;
  seg->size = size;

  seg->locationOfsNode = sNodeLocation;
  
  temp->vNodeType = eNormal;

  return temp;
}


/*
  Function to add a node to linked list. 
  @param size is the size of the object.
  ToDo: Make it more dynamic. 
*/
extern void *salmalloc(size_t size)
{
  smem_blk_seg *seg = NULL; /* memory segment  */
  void *sNodeLocation = NULL;

  /* If list is currently NULL add a new node. */
  if (memlist.head == NULL) {


    memlist.head = (sNode*) insert_salmalloc(size);

    memlist.head->numNodesAhead = EMPTY;

    memlist.head->next = NULL;
    memlist.length = 1;
    /* return start of our memory segment. */
    return memlist.head->memSegment + sizeof(smem_blk_seg);
  } else {
    
    sNode *temp = memlist.head, *prev = NULL, *newNode = NULL;
    
    if (whereToInsertNode(temp) == TRUE) {
      size_t count = 0;
      smem_blk_seg *seg1 = temp->memSegment;

      while(seg1->isFree == FALSE) {
	temp = (sNode*) temp->next;
	seg1 = temp->memSegment;
      }
      
      if (seg1->size >= size) {	
	printf("seg size: %d and size: %d.\n", seg1->size, size);
	seg1->isFree = FALSE;
	return temp->memSegment + sizeof(smem_blk_seg);
      }
    }

    /* Go to the last node */
    while(temp->next != NULL) {
      prev = temp;
      temp = (sNode *) temp->next;
    }    
    
    /* Get end of heap */
    seg = (smem_blk_seg *) sbrk(0);
    sNodeLocation = (void *) sbrk(0);
    
    temp->next = (struct sNode *)insert_salmalloc(size);

    /* set next node to nULL */
    temp = (sNode*) temp->next;
    temp->next = NULL;

    /* extend length of list. */
    memlist.length++;

    link_skip_nodes(temp);
    
    /* return memory segment */
    return temp->memSegment + sizeof(smem_blk_seg);
  }
}

extern size_t whereToInsertNode(sNode *temp)
{
  if (temp->vNodeType == eTens) {
    if ((temp->numNodesAhead > EMPTY) && (temp->numNodesAhead < TEN)) {
      printf("I am here. numNodesAhead: %d\n", temp->numNodesAhead);
      return TRUE;
    }
  } 

  return FALSE;
}

extern void salfree (void *ptr) 
{
  smem_blk_seg *seg = (ptr - sizeof(smem_blk_seg));
  sNode *temp = NULL;

  seg->isFree = TRUE;

  temp = seg->locationOfsNode;

  if (temp->vNodeType == eNormal) {
    while(temp->vNodeType != eTens) {
      temp = (sNode*) temp->next;
    }
  }

  temp = temp->skipNodes.fwd_tenSpecialNode;
}


extern void print_salmalloc()
{
  sNode *temp = memlist.head;
  size_t listIndex = 0;

  while(temp != NULL) {
    char *ch = temp->memSegment + sizeof(smem_blk_seg);
    smem_blk_seg *seg = temp->memSegment;
    printf("listIndex: %d. Location of sNode: %p. isFree %d. character in address %p and print: %c.\n", listIndex, seg->locationOfsNode, seg->isFree, (temp->memSegment) + sizeof(smem_blk_seg), 
	 *ch);
    listIndex++;
    temp = (sNode* ) temp->next;
  }

}


extern void print_skip_nodes(nodeType type)
{
  if (type == eTens) {
    size_t i = 5;
    sNode *temp = memlist.head;    

    while (i > 0) {
      char *ch = temp->memSegment + sizeof(smem_blk_seg);
      printf("i == %d and ch: %c.\n", i, *ch);
      temp = temp->skipNodes.fwd_tenSpecialNode;
      //printf("%p.\n", temp->memSegment + sizeof(smem_blk_seg));
      i--;
    }

  }
}

extern size_t get_length()
{
  return memlist.length;
}

extern sNode* copy_list()
{
  return memlist.head;
}

extern void copy_list_1(sNode *temp)
{
  temp = (sNode*) memlist.head;
  char *ch = temp->memSegment + sizeof(smem_blk_seg);
  printf("ch: %p.\n",  temp->memSegment + sizeof(smem_blk_seg));

}

