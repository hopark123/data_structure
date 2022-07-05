#include "heap.h"

heap*       makeheap(int maxElementCount)
{
    heap        *res;

    if (!(res = malloc(sizeof(heap))))
        return (NULL);
    if (!(res->pRootNode = malloc(sizeof(heapNode) * maxElementCount)))
    {
        free(res);
        return (NULL);
    }
    res->currentElementCount = 0;
    res->maxElementCount = maxElementCount;
    return (res);
}

heapNode*   getRootNodeHP(heap* pheap)
{
    if (!pheap)
        return (FALSE);
    if (pheap->currentElementCount == 0)
        return (FALSE);
    return (pheap->pRootNode + 1);
}

static int  resizing(heap *pheap)
{
    heapNode*   temp_node;

    if (!(temp_node = malloc(sizeof(heapNode) * pheap->maxElementCount * 2)))
        return (FALSE);
    for (int i = 0; i < pheap->maxElementCount; i++)
    {
        temp_node[i].weight = pheap->pRootNode[i].weight;
        temp_node[i].dest = pheap->pRootNode[i].dest;

    }
    free(pheap->pRootNode);
    pheap->pRootNode = temp_node;
    pheap->maxElementCount *= 2;
    return (TRUE);
}

int   insertChildNodeHP(heap* pheap, heapNode element)
{
    int index_child;

    if (!pheap)
        return (FALSE);
    pheap->currentElementCount++;
    if (pheap->currentElementCount == pheap->maxElementCount && resizing(pheap))
        return (FALSE);
    pheap->pRootNode[pheap->currentElementCount].weight = element.weight;
    pheap->pRootNode[pheap->currentElementCount].dest = element.dest;
    index_child = pheap->currentElementCount;
    while (pheap->pRootNode[index_child].weight <= pheap->pRootNode[(int)(index_child / 2)].weight
            && index_child != 1)
    {
        swap_node(pheap, index_child, (int)(index_child / 2));
        index_child = (int)(index_child / 2);
    }
    return (TRUE);
}

void        swap_node(heap* pheap, int child, int parent)
{
    heapNode    temp;

    temp = pheap->pRootNode[child];
    pheap->pRootNode[child] = pheap->pRootNode[parent];
    pheap->pRootNode[parent] = temp;
}

int	isHeapEmpty(heap *pheap)
{
    return (pheap->currentElementCount == 0);
}

void        deleteheap(heap* pheap)
{
    if (!pheap)
        return ;
    free(pheap->pRootNode);
    free(pheap);
}

void        deleteheapNode(heap* pheap)
{
    int i;
    
    if (!pheap)
        return ;
    if (pheap->currentElementCount == 0)
        return ;
    pheap->pRootNode[1] = pheap->pRootNode[pheap->currentElementCount];
    i = 2;
    while (i <= pheap->currentElementCount)
    {
        if (i < pheap->currentElementCount && pheap->pRootNode[i].weight >= pheap->pRootNode[i + 1].weight)
            i++;
        if (pheap->pRootNode[i].weight >= pheap->pRootNode[(int)(i / 2)].weight)
            break ;
        else
            swap_node(pheap, i, (int)(i / 2));
        i *= 2;
    }
    pheap->currentElementCount--;
}
/*
   18
 16   3
1  5 14 7
  
   16
  7   14
1  5 3
    
    
   14
  7  3
1  5

   7
  5  3
1

 5
1 3

 3
1

1
*/
void        Inorder(heap *pheap, int i)
{
    if (!pheap)
        return ;
    if (i > pheap->currentElementCount)
		return ;
	Inorder(pheap, i * 2);
	printf("Inorder dest : %d weight : %d \n", pheap->pRootNode[i].dest, pheap->pRootNode[i].weight);
	Inorder(pheap, i * 2 + 1);
}
