#ifndef _HEAP_
#define _HEAP_

#include <stdlib.h>
#include <stdio.h>

typedef struct heapNodeType
{
	int		dest;
	int		weight;
} heapNode;

typedef struct  heapType
{
	int     currentElementCount;
	int     maxElementCount;
	struct heapNodeType* pRootNode;  
} heap;

heap*       makeheap(int maxElementCount);
heapNode*   getRootNodeHP(heap* pheap);
int         insertChildNodeHP(heap* pheap, heapNode element);
void        swap_node(heap* pheap, int child, int parent);
int			isHeapEmpty(heap *pheap);
void        deleteheap(heap* pheap);
void        deleteheapNode(heap* pheap);
void        Inorder(heap *pheap, int i);


#endif

#define TRUE    1
#define FALSE   0
