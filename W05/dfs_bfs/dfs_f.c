#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "../arraygraph/arraygraph.h"
//arraygraph

#define arr_size 5
#define cost_max 2147483647

int		ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

bool	check(int step[])
{
	for (int i = 0; i < arr_size; i++)
	{
		if (step[i] == 0)
			return (false);
	}
	return (true);
}


int		dfs(ArrayGraph *graph, int	*arr[] , int step[], int min, int cost, int here)
{
	printf("here %d | ", here);
	for (int i = 0; i < arr_size; i++)
		printf("%d ", step[i]);
	printf("\n");
	if (check(step))
	{
		cost = ft_min(cost, min);
		printf("@@%d\n", cost);
	}
	else
	{
		for (int j = 0; j < arr_size; j++)
		{
			if (step[j] != 1 && arr[here][j])
			{
				cost += arr[here][j];
				step[j] = 1;
				arr[here][j] = 0;
				arr[j][here] = 0;
				dfs(graph, arr, step, min, cost, j);
				step[j] = 0;
				arr[here][j] = graph->ppAdjEdge[here][j];
				arr[j][here] = graph->ppAdjEdge[j][here];
				cost -= arr[here][j];
			}
		}
	}
	return (min);
}



int main()
{
	int step[arr_size];
	int	res;
	int **arr;
	ArrayGraph *graph;
	
	arr = malloc(sizeof(int *) * arr_size);
	for(int i = 0; i < arr_size; i++)
		arr[i] = malloc(sizeof(int) * arr_size);
	graph = createArrayGraph(arr_size);
	for (int i = 0; i < arr_size; i++)
		addVertexAG(graph, i);
	addEdgewithWeightAG(graph, 0, 1, 2);
	addEdgewithWeightAG(graph, 0, 2, 5);
	// addEdgewithWeightAG(graph, 0, 3, 1);
	addEdgewithWeightAG(graph, 0, 4, 1);
	// addEdgewithWeightAG(graph, 1, 2, 1);
	addEdgewithWeightAG(graph, 1, 3, 7);
	addEdgewithWeightAG(graph, 1, 4, 2);
	addEdgewithWeightAG(graph, 2, 3, 3);
	// addEdgewithWeightAG(graph, 2, 4, 1);
	addEdgewithWeightAG(graph, 3, 4, 4);

	displayArrayGraph(graph);
	for (int i = 0 ; i < arr_size; i++)
		step[i] = 0;
	for (int i = 0 ; i < arr_size; i++)
		for(int j = 0; j < arr_size; j++)
			arr[i][j] = graph->ppAdjEdge[i][j];
	step[0] = 1;
	res = dfs(graph, arr, step, cost_max, 0, 0);
	// printf("res %d\n ", res);
}
