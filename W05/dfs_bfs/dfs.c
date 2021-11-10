#include "stack.h"
#include "../linkedgraph/linkedgraph.h"
#include "../linkedgraph/linkedlist.h"

#define arr_size 5

void	dfs(LinkedGraph *graph)
{
	LinkedStack *res = createLinkedStack();
	LinkedStack *dfs = createLinkedStack();
	StackNode	node;
	ListNode	*temp;
    int	visited[arr_size];

	for (int i = 0; i < arr_size; i++)
		visited[i] = 0;
	visited[0] = 1;
	node.data = 0;
	pushLS(res, node);
	pushLS(dfs, node);
	while (!isLinkedStackEmpty(dfs))
	{
		temp = graph->ppAdjEdge[peekLS(dfs)->data]->headerNode;
		while (temp)
		{
			if (visited[temp->destination] == 0)
			{
				visited[temp->destination] = 1;
				node.data = temp->destination;
				pushLS(dfs, node);
				pushLS(res, node);
				break ;
			}
			else
				temp = temp->pLink;
		}
		if (!temp)
			popLS(dfs);
	}
	while (!isLinkedStackEmpty(res))
	{
		node = *popLS(res);
		printf("<- %d", node.data);
	}
	printf("\n");
}

int main()
{
	LinkedGraph *graph;
	graph = createLinkedGraph(5);
	displayLinkedGraph(graph);
	for (int i = 0; i < arr_size; i++)
		addVertexLG(graph, i);
	addEdgewithWeightLG(graph, 0, 1, 2);
	addEdgewithWeightLG(graph, 0, 2, 5);
	addEdgewithWeightLG(graph, 0, 4, 1);
	addEdgewithWeightLG(graph, 1, 3, 7);
	addEdgewithWeightLG(graph, 1, 4, 2);
	addEdgewithWeightLG(graph, 3, 4, 4);
	printf("===========dfs===========\n");
	displayLinkedGraph(graph);
	dfs(graph);
}