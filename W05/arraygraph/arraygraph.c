#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *ret;

	if (!(ret = (ArrayGraph *)malloc(sizeof(ArrayGraph))))
		return (NULL);
	ret->maxVertexCount = maxVertexCount;
	ret->currentVertexCount = 0;
	ret->graphType = 1;
	if (!(ret->ppAdjEdge = (int **)malloc(sizeof(int*) * maxVertexCount)))
	{
		free(ret);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		if(!(ret->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int))))
		{
			for (int j = i - 1; j >= 0; j--)
				free(ret->ppAdjEdge[j]);
			free(ret);
			return(NULL);
		}
	}
	if (!(ret->pVertex = (int *)calloc(maxVertexCount, sizeof(int))))
	{
		for (int i = 0; i < maxVertexCount; i++)
			free(ret->ppAdjEdge[i]);
		free(ret->ppAdjEdge);
		free(ret);
		return (NULL);
	}
	return (ret);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph *ret;

    if (!(ret = createArrayGraph(maxVertexCount)))
		return (NULL);
    ret->graphType = 2;
    return (ret);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
	// pGraph = NULL ??
} 

int isEmptyAG(ArrayGraph* pGraph)
{
	if (!pGraph)
		return (0);
	return (pGraph->currentVertexCount == 0);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (0);
	pGraph->pVertex[vertexID] = 1;
	pGraph->currentVertexCount++;
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (0);
	if (!(pGraph->pVertex[fromVertexID] && pGraph->pVertex[toVertexID]))
		return (0); 
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	if (pGraph->graphType == 1)
    	pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
    return 1;
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph)
		return (0);
	if (!(pGraph->pVertex[fromVertexID] && pGraph->pVertex[toVertexID]))
		return (0); 
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == 1)
    	pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return 1;
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (0);
	return (pGraph->pVertex[vertexID] != 0);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph || !pGraph->pVertex[vertexID])
		return (0);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[i][vertexID] = 0;
		pGraph->ppAdjEdge[vertexID][i] = 0;
	}
	pGraph->currentVertexCount--;
    pGraph->pVertex[vertexID] = 0;
    return 1;
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
    if (!pGraph)
        return 0;
	if (!(pGraph->pVertex[fromVertexID] && pGraph->pVertex[toVertexID]))
		return (0); 
	pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
        return ;
	printf("  ");
    for (int i = 0; i< pGraph->maxVertexCount; i++){
        printf (" %d ",i);
    }
	printf("\n");
	for (int i = 0 ; i < pGraph->maxVertexCount; i++)
	{
		printf("%d ", i);
		for (int j = 0 ; j < pGraph->maxVertexCount; j++)
			printf("[%d]", pGraph->ppAdjEdge[i][j]);
		printf("\n");
	}
}


// int main()
// {
// 	ArrayGraph *test;
    
//     test = createArrayGraph(5);
//     // test = createArrayDirectedGraph(5);


// 	printf("=========NULL TEST=========\n");
// 	printf("display : \n");
// 	displayArrayGraph(test);
// 	printf("\nremove VertexAG : \n");
// 	removeVertexAG(test, 4);
// 	printf("\nremove VertexEdgeAG : \n");
// 	removeEdgeAG(test, 2, 3);
// 	printf("display : \n");
// 	displayArrayGraph(test);

    
// 	printf("\n\n=========BASIC TEST=========\n");
// 	printf("----- add VertexAG -----\n");
//     addVertexAG(test, 0);
//     addVertexAG(test, 2);
//     addVertexAG(test, 3);
//     addVertexAG(test, 4);
// 	displayArrayGraph(test);
// 	printf ("\n");
//     addEdgeAG(test, 0, 4);
//     addEdgeAG(test, 2, 3);
//    	displayArrayGraph(test);
// 	printf("----- remove VertexAG -----\n");
//     removeVertexAG(test, 0);
//    	displayArrayGraph(test);
// }