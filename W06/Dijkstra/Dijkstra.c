#include "../arraygraph/arraygraph.h"
#include "heap.h"
#include <unistd.h>

#define arr_size 6
#define MAX_COST 100000

static void	print_res(int res[], int start)
{
	printf("=== start : %d ===\n", start);
	for (int i = 0 ; i < arr_size; i++)
		printf("|  %d|", i);
	printf("\n");
	for (int i = 0 ; i < arr_size; i++)
	{
		if (res[i] == MAX_COST)
			printf("[  0]");
		else
			printf("[%3d]", res[i]);
	}
	printf("\n");
}

static void displayArrayGraph2(ArrayGraph* pGraph)
{
	if (!pGraph)
		return ;
	printf("  ");
	for (int i = 0; i< pGraph->maxVertexCount; i++){
		printf (" %3d ",i);
	}
	printf("\n");
	for (int i = 0 ; i < pGraph->maxVertexCount; i++)
	{
		printf("%d ", i);
		for (int j = 0 ; j < pGraph->maxVertexCount; j++)
		{
			if (pGraph->ppAdjEdge[i][j] == MAX_COST)
				printf("[  X]");
			else
				printf("[%3d]", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}

int *Dijkstra(ArrayGraph *graph, int start)
{
	heap		*heap = makeheap(arr_size);
	heapNode	temp;
	heapNode	temp2;

	heapNode	*head;
	int			*res;
	int			flag;
	if (!(res = malloc(sizeof(int) * arr_size)))
		return (NULL);
	for (int i = 0; i < arr_size; i++)
		res[i] = graph->ppAdjEdge[start][i];
	for (int i = 0; i < arr_size; i++)
	{
		if (i != start)
		{
			temp.dest = i;
			temp.weight = graph->ppAdjEdge[start][i];
			insertChildNodeHP(heap, temp);
		}
	}
	// for (int i = 0 ; i < arr_size - 1; i ++)
	// {
	// 	head = getRootNodeHP(heap);
	// 	printf("%d [%d : %d]\n", i +1,  head->dest, head->weight);
	// 	deleteheapNode(heap);
	// }
	while (!isHeapEmpty(heap))
	{
		head = getRootNodeHP(heap);
		temp.dest = head->dest;
		temp.weight = head->weight;
		deleteheapNode(heap);
		printf("pop : %d->%d %d\n", start, temp.dest, temp.weight);
		for (int i = 0; i < arr_size; i++)
		{
			if (i != start && i != temp.dest && graph->ppAdjEdge[temp.dest][i] != MAX_COST)
			{
			printf("%d->%d->%d", start, temp.dest, i);
			printf("  [%d ? %d(%d) + %d]\n", res[i], res[temp.dest], temp.weight,  graph->ppAdjEdge[temp.dest][i]);
				if (res[i] > res[temp.dest] + graph->ppAdjEdge[temp.dest][i])
				{
					res[i] = res[temp.dest] + graph->ppAdjEdge[temp.dest][i];
					graph->ppAdjEdge[start][i] = res[i];
					graph->ppAdjEdge[i][start] = res[i];
					// deleteheapNode(heap);
					flag = 1;
					temp2.dest = i;
					temp2.weight = res[i];
					printf("push : %d->%d %d\n", start, temp2.dest, temp2.weight);
					insertChildNodeHP(heap, temp2);
					i = 0;
				}
			}
		}
		// if (flag == 0)
			// deleteheapNode(heap);
	}

	return (res);
}
int main()
{
	ArrayGraph *graph;
	int			*res;
	int			start = 0;

	graph = createArrayGraph(arr_size);
	for (int i = 0; i < arr_size; i++)
		addVertexAG(graph, i);
	for (int i = 0; i < arr_size; i++)
		for (int j = 0; j < arr_size; j++)
			graph->ppAdjEdge[i][j] = MAX_COST;
	addEdgewithWeightAG(graph, 0, 1, 1);
	addEdgewithWeightAG(graph, 0, 2, 4);
	addEdgewithWeightAG(graph, 1, 2, 2);
	addEdgewithWeightAG(graph, 2, 3, 1);
	addEdgewithWeightAG(graph, 3, 4, 8);
	addEdgewithWeightAG(graph, 3, 5, 3);
	addEdgewithWeightAG(graph, 4, 5, 4);
	displayArrayGraph2(graph);
	printf("===========Dijkstra===========\n");
	for (int start = 2 ; start < 3; start++)
	{
		res = Dijkstra(graph, start);
		if (!res)
			return (0);
		print_res(res, start);
	}
}