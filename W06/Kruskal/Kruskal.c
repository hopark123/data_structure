#include "../linkedgraph/linkedgraph.h"
#include "../linkedgraph/linkedlist.h"

#define arr_size 6

static void swap_int(int *A, int *B)
{
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

static void	swap_list(ListNode *A, ListNode *B)
{
	swap_int(&(A->destination), &(B->destination));
	swap_int(&(A->weight), &(B->weight));
	swap_int(&(A->visited), &(B->visited)); //heap으로 하는게 더 좋을듯
}

static void		sort_weight(LinkedList *List)
{
	ListNode	*temp;
	ListNode	*next;
	temp = List->headerNode->pLink;
	if (!temp)
		return ;
	while (temp)
	{
		next = temp->pLink;
		while (next)
		{
			if (temp->weight > next->weight)
				swap_list(temp, next);
			next = next->pLink;
		}
		temp = temp->pLink;
	}
}

static LinkedList	*make_AdjEdge(LinkedGraph *graph)
{
	LinkedList	*res = createLinkedList();
	ListNode	node;
	ListNode	*temp;

	for (int i = 0; i < graph->currentVertexCount; i++)
	{
		temp = graph->ppAdjEdge[i]->headerNode->pLink;
		while (temp)
		{
			if (temp->destination >= i)
			{
				node.destination = temp->destination;
				node.weight = temp->weight;
				node.visited = i;
				addLLElement(res, res->currentElementCount, node);
			}
			temp = temp->pLink;
		}
	}
	sort_weight(res);
	temp = res->headerNode->pLink;
	while(temp)
	{
		printf("%d -> %d %d\n", temp->visited, temp->destination, temp->weight);
		temp = temp->pLink;
	}
	printf("===\n");
	return (res);
}

void Kruskal(LinkedGraph *graph)
{
	LinkedList	*edge;
	ListNode	*temp;
	int			arr[arr_size];
	for (int i = 0; i < arr_size; i++)
		arr[i] = 0;
	edge = make_AdjEdge(graph);
	temp  = edge->headerNode->pLink;
	while (temp)
	{
		// if (!(arr[temp->visited] && arr[temp->destination]))/
			printf("%d <-> %d\n", temp->visited, temp->destination);
		if (!arr[temp->visited])
			arr[temp->visited] = 1;
		if (!arr[temp->destination])
			arr[temp->destination] = 1;
		temp = temp->pLink;
	}
	return ;
}

int main()
{
	LinkedGraph *graph;
	int			*res;

	graph = createLinkedGraph(arr_size);
	displayLinkedGraph(graph);
	for (int i = 0; i < arr_size; i++)
		addVertexLG(graph, i);
	addEdgewithWeightLG(graph, 0, 1, 4);
	addEdgewithWeightLG(graph, 0, 2, 3);
	addEdgewithWeightLG(graph, 1, 2, 2);
	addEdgewithWeightLG(graph, 2, 3, 1);
	addEdgewithWeightLG(graph, 3, 4, 1);
	addEdgewithWeightLG(graph, 3, 5, 5);
	addEdgewithWeightLG(graph, 4, 5, 6);
	displayLinkedGraph(graph);
	printf("===========Kruskal===========\n");
	Kruskal(graph);
}