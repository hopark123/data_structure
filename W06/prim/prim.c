#include "../linkedgraph/linkedgraph.h"
#include "../linkedgraph/linkedlist.h"

#define arr_size 6
#define INT_MAX 2147483647
LinkedGraph *primG(LinkedGraph *graph,int start);

int main()
{
	LinkedGraph *graph;
    LinkedGraph *ret;

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
	printf("===========Prim===========\n");
    ret = primG(graph, 0);
    displayLinkedGraph(ret);
}

ListNode *FindNext(LinkedGraph *ret, LinkedGraph *graph,int start,int *from){
    int min = INT_MAX, curr = start, idx = 0;

    ListNode *copy;
    ListNode *tmp = NULL;
    for(int i = 0; i < ret->currentVertexCount; i++){
        tmp = graph->ppAdjEdge[curr]->headerNode->pLink;
        while(tmp){
            if (min > tmp->weight && ret->pVertex[tmp->destination] != 1){
                min = tmp->weight;
                copy = tmp;
                *from = curr;
            }
            tmp = tmp->pLink;
        }

        idx = curr + 1;
        while (ret->pVertex[idx] == 0 && idx < ret->currentVertexCount){ // from찾기
            idx++;
        }
        curr = idx;
    }
    if (min == INT_MAX)
        return (NULL);
    return(copy);
}


LinkedGraph *primG(LinkedGraph *graph, int start){
    LinkedGraph *ret;
    int from = 0;
    ListNode *tmp;

    ret = createLinkedGraph(arr_size);
    addVertexLG(ret, start);
    ret->pVertex[start] = 1;
    for (int i = 0; i < graph->currentVertexCount - 1 ; i++){
        tmp = FindNext(ret,graph,start, &from);
        if (!tmp)
            break ;
        ret->pVertex[tmp->destination] = 1;
        addVertexLG(ret, tmp->destination);
        addEdgeLG(ret, from, tmp->destination);
    }
    return ret;
}