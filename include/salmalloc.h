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

typedef struct skip_list_nodes {
  void *prev_tenSpecialNode;
  void *prev_hundredSpecialNode;
  void *prev_thousandSpecialNode;
  void *fwd_tenSpecialNode;
  void *fwd_hundredSpecialNode;
  void *fwd_thousandSpecialNode;  
}skip_list_nodes;

typedef struct Node {
  struct sNode *next;
  void *memSegment;
  size_t magicVal;
  nodeType vNodeType;
  skip_list_nodes skipNodes;
}sNode;


typedef struct List {
  sNode *head;
  size_t length;
  sNode *tens;
  sNode *hundreds;
  sNode *thousands;
  skip_list_nodes skipNodes;
}sList;




extern void *salmalloc(size_t);
extern void salfree(void *);
extern void print_salmalloc();
extern void link_skip_nodes(sNode*);
extern void print_skip_nodes(nodeType);
extern size_t get_length();
extern sNode* copy_list();
extern void copy_list_1(sNode*);
