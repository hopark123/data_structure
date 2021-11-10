#include "linkedgraph.h"
#include "linkedlist.h"

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
    LinkedGraph *res;

	if (!(res = (LinkedGraph *)malloc(sizeof(LinkedGraph))))
        return (NULL);
    res->maxVertexCount = maxVertexCount;
    res->currentVertexCount = 0;
    res->currentEdgeCount = 0;
    res->graphType = 1;
	
	if (!(res->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList*) * maxVertexCount)))
	{
		free(res);
		return (NULL);
	}
	if (!(res->pVertex = (int *)calloc(maxVertexCount, sizeof(int))))
	{
		free(res->ppAdjEdge);
		free(res);
		return (NULL);
	}
	return (res);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
    LinkedGraph *res;
    
    if (!(res = createLinkedGraph(maxVertexCount)))
        return (NULL);
    res->graphType = 2;
    return res;
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{   
	if (!pGraph)
		return ;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i])
			deleteLinkedList(pGraph->ppAdjEdge[i]);
	}
	free(pGraph->pVertex);
    free(pGraph);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (0);
    return (pGraph->currentVertexCount == 0);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (0);
    pGraph->pVertex[vertexID] = 1;
    if (!(pGraph->ppAdjEdge[vertexID] = createLinkedList()))
		return (0);
    pGraph->currentVertexCount++;
    return (1);
    
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (0);
	if (!(pGraph->pVertex[fromVertexID] && pGraph->pVertex[toVertexID]))
		return (0);
	ListNode	add;

	add.weight = 1;
    add.destination = toVertexID;
	addLLElement(pGraph->ppAdjEdge[fromVertexID] , pGraph->ppAdjEdge[fromVertexID]->currentElementCount,  add);
	pGraph->currentEdgeCount++;
    if (pGraph->graphType == 1)
	{
		add.destination = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID] , pGraph->ppAdjEdge[toVertexID]->currentElementCount,  add);
		pGraph->currentEdgeCount++;
	}
    return 1;
    
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
   	if (!pGraph)
		return (0);
	if (!(pGraph->pVertex[fromVertexID] && pGraph->pVertex[toVertexID]))
		return (0);
	ListNode	add;

	add.weight = weight;
    add.destination = toVertexID;
	addLLElement(pGraph->ppAdjEdge[fromVertexID] , pGraph->ppAdjEdge[fromVertexID]->currentElementCount,  add);
	pGraph->currentEdgeCount++;
    if (pGraph->graphType == 1)
	{
		add.destination = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID] , pGraph->ppAdjEdge[toVertexID]->currentElementCount,  add);
		pGraph->currentEdgeCount++;
	}
    return 1;
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (0);
    return (pGraph->pVertex[vertexID] !=  0);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (0);
    deleteLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->pVertex[vertexID] = 0;
    pGraph->currentVertexCount--;
    return 1;
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (0);
	if (!(pGraph->pVertex[fromVertexID] && pGraph->pVertex[toVertexID]))
		return (0);

	int position;

	position = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	removeLLElement(pGraph->ppAdjEdge[toVertexID], position);
    pGraph->currentEdgeCount--;
	if (pGraph->graphType == 1)
	{
		position = findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		removeLLElement(pGraph->ppAdjEdge[toVertexID], position);
		pGraph->currentEdgeCount--;
	}
    return 1;
}

// void deleteGraphNode(LinkedList* pList, int delVertexID)
// {

// }

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	ListNode	*temp;

	temp = pList->headerNode->pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
    {
        if (temp->destination == vertexID)
			return (i);
		temp = temp->pLink;
    }
	return (0);
}

int getEdgeCountLG(LinkedGraph* pGraph)
{
    return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
    return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
    return (pGraph->graphType);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
    for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == 1)
		{
			printf("%d ->", i);
			displayLinkedList(pGraph->ppAdjEdge[i]);
		}
	}
}


// int main()
// {
// 	LinkedGraph *test;
    
//     // test = createLinkedGraph(5);
//     // test = createLinkedDirectedGraph(5);


// 	printf("=========NULL TEST=========\n");
// 	printf("display : \n");
// 	displayLinkedGraph(test);
// 	printf("\nremove VertexAG : \n");
// 	removeVertexLG(test, 4);
// 	printf("\nremove VertexEdgeAG : \n");
// 	removeEdgeLG(test, 2, 3);
// 	printf("display : \n");
// 	displayLinkedGraph(test);

    
// 	printf("\n\n=========BASIC TEST=========\n");
// 	printf("----- add VertexAG -----\n");
//     addVertexLG(test, 0);
//     addVertexLG(test, 2);
//     addVertexLG(test, 3);
//     addVertexLG(test, 4);
// 	displayLinkedGraph(test);
// 	printf ("-----------\n");
//     addEdgeLG(test, 0, 4);
//     addEdgeLG(test, 0, 2);
//     addEdgeLG(test, 0, 3);
//     addEdgeLG(test, 2, 3);
// 	displayLinkedGraph(test);
// 	printf("----- remove VertexAG -----\n");
//     removeVertexLG(test, 0);
// 	displayLinkedGraph(test);
// }
/*

0 
2
3
4
*/