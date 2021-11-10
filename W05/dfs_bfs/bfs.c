#include "queue.h"
#include "../linkedgraph/linkedgraph.h"
#include "../linkedgraph/linkedlist.h"

#define arr_size 5

void	bfs(LinkedGraph *graph)
{
	ArrayQueue *res = createArrayQueue(arr_size * 2);
	ArrayQueue *bfs = createArrayQueue(arr_size * 2);
	ArrayQueueNode	node;
	ListNode	*temp;
    int	visited[arr_size];

	for (int i = 0; i < arr_size; i++)
		visited[i] = 0;
	visited[0] = 1;
	node.data = 0;
	enQueue(res, node);
	enQueue(bfs, node);
	while (!isQueueEmpty(bfs))
	{
		temp = graph->ppAdjEdge[peekQueue(bfs)]->headerNode;
		while (temp)
		{
			if (visited[temp->destination] == 0)
			{
				visited[temp->destination] = 1;
				node.data = temp->destination;
				enQueue(bfs, node);
				enQueue(res, node);
				break ;
			}
			else
				temp = temp->pLink;
		}
		if (!temp)
			deQueue(bfs);
	}
	while (!isQueueEmpty(res))
	{
		node.data = deQueue(res);
		printf("%d ->", node.data);
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
	printf("===========bfs===========\n");

	displayLinkedGraph(graph);
	bfs(graph);
}