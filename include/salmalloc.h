#include <stdlib.h>


#define ZERO 0
#define TEN 10
#define HUNDRED 100
#define THOUSAND 1000
#define THREE 3


typedef struct mem_blk_seg {
  ssize_t isFree;
  size_t size;
}smem_blk_seg;

typedef enum nodeType {
  eNormal,
  eTens,
  eHundreds,
  eThousands
}nodeType;

typedef struct Node {
  struct sNode *next;
  void *memSegment;
  size_t magicVal;
}sNode;


typedef struct List {
  sNode *head;
  size_t length;
  sNode vPrevNodes[THREE];
}sList;



extern void *salmalloc(size_t);
extern void salfree(void *);

