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

static void print_mem(sNode*);
static void print_debug();

extern void link_skip_nodes(sNode *temp)
{
    /* Set node type. */
    if (memlist.length % HUNDRED == ZERO) {

      if (memlist.length == HUNDRED) {
	
	sNode *prev = (sNode*) memlist.skipNodes.prev_tenSpecialNode;

	/* 
	   Previous special node points to 100th node
	   which is also a tenSpecialNode.
	*/
	prev->skipNodes.fwd_tenSpecialNode = temp;
	
	memlist.head->skipNodes.fwd_hundredSpecialNode = temp;
	memlist.head->vNodeType = eHundreds;
	
	temp->vNodeType = eHundreds;
	temp->skipNodes.prev_tenSpecialNode = prev;
	temp->skipNodes.prev_hundredSpecialNode = memlist.head;
	temp->skipNodes.fwd_hundredSpecialNode  = NULL;

	memlist.skipNodes.prev_tenSpecialNode = temp;
	
	temp->numNodesAhead = ZERO;

      } else {

	sNode *prev = (sNode*) memlist.skipNodes.prev_tenSpecialNode;
	sNode *prevHundred = (sNode*) memlist.skipNodes.prev_hundredSpecialNode;
	
	prev->skipNodes.fwd_tenSpecialNode  = temp;
	temp->skipNodes.prev_tenSpecialNode = prev;
	
	temp->vNodeType = eHundreds;

      }
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
	memlist.head->skipNodes.prev_tenSpecialNode = NULL;

	temp->skipNodes.prev_tenSpecialNode = memlist.head;
	temp->skipNodes.fwd_tenSpecialNode = NULL;

	memlist.skipNodes.prev_tenSpecialNode = temp;
	
	//memlist.head->numNodesAhead = ZERO;
	//temp->numNodesAhead = EMPTY;

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

	//prev->numNodesAhead = TEN;

	temp->skipNodes.prev_tenSpecialNode = (void*)prev;	
	temp->skipNodes.fwd_tenSpecialNode = NULL;

	prev->skipNodes.fwd_tenSpecialNode = (void*)temp;
	memlist.skipNodes.prev_tenSpecialNode = temp;
	
	temp->numNodesAhead = ZERO;
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

    memlist.head->numNodesAhead = ZERO;

    memlist.head->next = NULL;
    memlist.length = ZERO;    
    memlist.flagUpdateCurrIsFree = 0;

    //print_mem(memlist.head);

    memlist.skipNodes.prev_tenSpecialNode = memlist.head;

    /* return start of our memory segment. */
    return memlist.head->memSegment + sizeof(smem_blk_seg);

  } else {
    
    sNode *temp = memlist.head, *prev = NULL, *specialNode = NULL;
    size_t flag = 0;
    ssize_t *ch = 0;
    /*if (whereToInsertNode(temp) == TRUE) {
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
    }*/

    /* There are two possibilities here as to where to insert this node
       1. Either the node is free. so just return.
       2. Node is not free. got to allocate a new one. In this case,
       we need to return the previous node.       
    */
    temp = placeToInsertNode(size);

    /* If there is free space. */
    if (memlist.length != ZERO && memlist.flagUpdateCurrIsFree == TRUE) {
      seg = temp->memSegment;
      seg->isFree = FALSE;
      //print_mem(temp);
      return temp->memSegment + sizeof(smem_blk_seg); 
    }

    printf("salman.\n");
    /* First check is useless. Will update later.
       Second check happens if NULL is returned that
       only happens if only HEAD has been populated yet.
    */
    if (temp == NULL && memlist.length != ZERO) {
      ssize_t *ch = 0;
      //printf("Flag updated.\n");
      temp = memlist.skipNodes.prev_tenSpecialNode;
      ch = temp->memSegment + sizeof(smem_blk_seg);
      //printf("val: %zd.\n", *ch);
    } else if (temp == NULL) {
      temp = memlist.head;
    }

    /* Go to the last node 
    while(temp->next != NULL) {
      prev = temp;
      temp = (sNode *) temp->next;
    }    
    */

    //print_mem(temp);

    temp->next = (struct sNode *)insert_salmalloc(size);

    /* set next node to NULL */
    temp = (sNode*) temp->next;
    temp->next = NULL;

    /* extend length of list. */
    set_length();

    link_skip_nodes(temp);

    if (temp->vNodeType == eNormal) {
      //print_length();
      sNode *aheadNodes = (sNode *) memlist.skipNodes.prev_tenSpecialNode;
      aheadNodes->numNodesAhead++;
    }


    /*if (get_length() <= TEN) {
      memlist.head->numNodesAhead == EMPTY ? memlist.head->numNodesAhead = ONE : memlist.head->numNodesAhead++;
      printf("numNodes head: %zd.\n", memlist.head->numNodesAhead);
    } else if (){
      specialNode = (sNode*) memlist.skipNodes.prev_tenSpecialNode;
      printf("numNodes newNode: %zd.\n", specialNode->numNodesAhead);
      specialNode->numNodesAhead == EMPTY ? specialNode->numNodesAhead = ONE : specialNode->numNodesAhead++;
      }*/
    
    /* return memory segment */
    return temp->memSegment + sizeof(smem_blk_seg);
  }
}

extern sNode* placeToInsertNode(size_t sizeObject)
{
  sNode *tempTenSkipNode = memlist.head;  
  sNode *temp;

  /* If there are no nodes yet ahead, so return NULL and add new node. */
  if (tempTenSkipNode->numNodesAhead == ZERO) { return NULL; }

  /* 
     Now for each ten Skip node, check
     two things. 1) Is this skip node free to be populated? If yes
     return it. 2) Are the number of elements in front of this skip Node
     less than 9? Now there are two possibilities. Either there is a node
     which is now free which was previously populated. In this case just
     return the node which is to be repopulated. Or number of nodes are
     less than 9. In this case, we need to add another node in front of
     the second last node, so return the second last node and inform
     insert and it needs to append this node.

     What if this Skip Node does not have space? Well, then move forward
     to next skip node until all Skip nodes are done for. If there is still
     no space, create another skip node and start populating it.
  */
  while(tempTenSkipNode != NULL) {

    smem_blk_seg *seg = tempTenSkipNode->memSegment;

    
    /* If this free space */
    if (seg->isFree == TRUE && seg->size >= sizeObject) {
      memlist.flagUpdateCurrIsFree = 1;
      seg->isFree = FALSE;
      return tempTenSkipNode;
    } 
    /* If there is space for a node in front. */
    else if (tempTenSkipNode->numNodesAhead < NINE) {
      sNode *temp = NULL;

      /* Nodes ahead are zero so just add a new node. */
      if (tempTenSkipNode->numNodesAhead == 0 && tempTenSkipNode->next == NULL) { /* printf("salman.\n"); */ return tempTenSkipNode; }

      //print_mem(tempTenSkipNode);
      temp = (sNode*) parse_eNormal_Nodes((sNode*)tempTenSkipNode->next, sizeObject);

      if (memlist.flagUpdateCurrIsFree == 1) { tempTenSkipNode->numNodesAhead++; return temp; }

      seg = temp->memSegment;

      if (temp != NULL && seg->size >= sizeObject) {
	print_mem(temp);
	seg->isFree = FALSE;
	
	//memlist.flagUpdateCurrIsFree = 1;
	return temp;
      } 
    }
    
    /* If next fwd_TenSpecialNode is null, then we just return 
       the second last node to that null node and list is appended
       from front of it.
    */
    if (tempTenSkipNode->skipNodes.fwd_tenSpecialNode == NULL) {
      temp = tempTenSkipNode;
      while(temp->next != NULL) {
	temp = (sNode*) temp->next;
      }
      return temp;
    }  

    //print_mem(tempTenSkipNode->skipNodes.fwd_tenSpecialNode);
    //printf("I am here.\n");
    tempTenSkipNode = tempTenSkipNode->skipNodes.fwd_tenSpecialNode;
  }
  
  return NULL;
}

extern void salfree (void *ptr) 
{
  smem_blk_seg *seg = (ptr - sizeof(smem_blk_seg));
  sNode *temp = NULL;

  seg->isFree = TRUE;

  /* This is our node. Now either it is a normal node in which case
     we move forward to next skip node and then find our way back
     and update our node numNodes ahead. Or if it is a skip node,
     just move to prev_tenSpecialNode and decrement numNodesAhead.
  */
  temp = seg->locationOfsNode;

  if (temp->vNodeType == eNormal) {
    while(temp != NULL && temp->vNodeType != eTens) {      
      temp = (sNode*) temp->next;
    }
    
    if (temp == NULL) {temp = memlist.skipNodes.prev_tenSpecialNode;}
    else { temp = temp->skipNodes.prev_tenSpecialNode; }

    //printf("address: %p and num nodes ahead: %zd.\n", temp, temp->numNodesAhead);
    temp->numNodesAhead--;
    print_debug(temp->numNodesAhead);

  } else { /*print_debug(temp->numNodesAhead); temp->numNodesAhead > 0 ? temp->numNodesAhead--  : 0 ; print_debug(temp->numNodesAhead);*/}

}


extern void print_salmalloc()
{
  sNode *temp = memlist.head;
  size_t listIndex = 0;

  while(temp != NULL) {
    ssize_t *ch = temp->memSegment + sizeof(smem_blk_seg);
    smem_blk_seg *seg = temp->memSegment;
    printf("listIndex: %d. Location of sNode: %p. isFree %d. character in address %p and print: %zd. Size is %d.\n", listIndex, seg->locationOfsNode, seg->isFree, (temp->memSegment) + sizeof(smem_blk_seg), 
	   *ch, seg->size);
    listIndex++;
    temp = (sNode* ) temp->next;
  }

}


extern void print_skip_nodes(nodeType type)
{
  if (type == eTens) {
    size_t i = 0;
    sNode *temp = memlist.head;    

    while (temp != NULL) {
      ssize_t *ch = temp->memSegment + sizeof(smem_blk_seg);
      printf("i == %d and ch: %zd.\n", i, *ch);
      temp = temp->skipNodes.fwd_tenSpecialNode;
      //printf("%p.\n", temp->memSegment + sizeof(smem_blk_seg));
      i++;
    }

  }
}

extern size_t get_length()
{
  return memlist.length;
}

extern size_t set_length()
{
  return memlist.length++;
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

extern void print_length()
{
  printf("Length of list: %zd.\n", memlist.length);
}

extern void *parse_eNormal_Nodes(sNode* temp, size_t objectSize)
{
  sNode *prev = (sNode*) temp;

  //printf("temp type: %d.\n", temp->vNodeType);  
  
  while(temp != NULL && temp->vNodeType == eNormal) {
    smem_blk_seg *seg = temp->memSegment;
    if (seg->isFree == TRUE && seg->size >= objectSize) {
      /* If this is 1 that means add a new node in front of previous node */
      seg->isFree = FALSE;
      memlist.flagUpdateCurrIsFree = 1;
      return temp;
    } 
    prev = temp;
    temp = (sNode*) temp->next;
  }
  //print_mem(prev);
  return prev;
}

static void print_mem(sNode* temp)
{
   smem_blk_seg *seg = temp->memSegment;
   ssize_t *ch = temp->memSegment + sizeof(smem_blk_seg);
   printf("temp address: %p and value: %zd. isFree: %d.\n", temp->memSegment + sizeof(smem_blk_seg), *ch, seg->isFree);
}

static void print_debug(size_t size)
{
   { printf("I am salman. size is: %zd.\n", size); }
}
