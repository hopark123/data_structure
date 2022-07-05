#include "../arraygraph/arraygraph.h"

#define arr_size 6
#define INT_MAX 2147483647

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
			if (pGraph->ppAdjEdge[i][j] == INT_MAX / 2)
				printf("[  X]");
			else
				printf("[%3d]", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}

int Floyd(ArrayGraph *graph)
{
	for(int i = 0; i < arr_size; i++) //출발
	{
		for (int j = 0; j < arr_size; j++) //목적
		{
			if (i != j)
			{
				for (int k = 0; k < arr_size; k++) //경유
				{
					if (graph->ppAdjEdge[i][k] + graph->ppAdjEdge[k][j] < graph->ppAdjEdge[i][j])
					{
						graph->ppAdjEdge[i][j] = graph->ppAdjEdge[i][k] + graph->ppAdjEdge[k][j];
						return (0);
					}
				}
			}
		}
	}
	return (1);
}

int main()
{
	ArrayGraph *graph;
	int			res = 0;

	graph = createArrayGraph(arr_size);
	displayArrayGraph2(graph);
	for (int i = 0; i < arr_size; i++)
		addVertexAG(graph, i);
	for (int i = 0; i < arr_size; i++)
		for (int j = 0; j < arr_size; j++)
			graph->ppAdjEdge[i][j] = INT_MAX / 2;
	addEdgewithWeightAG(graph, 0, 1, 1);
	addEdgewithWeightAG(graph, 0, 2, 4);
	addEdgewithWeightAG(graph, 1, 2, 2);
	addEdgewithWeightAG(graph, 2, 3, 1);
	addEdgewithWeightAG(graph, 3, 4, 8);
	addEdgewithWeightAG(graph, 3, 5, 3);
	addEdgewithWeightAG(graph, 4, 5, 4);
	displayArrayGraph2(graph);
	printf("===========Floyd===========\n");
	while (res == 0)
		res = Floyd(graph);
	displayArrayGraph2(graph);
}