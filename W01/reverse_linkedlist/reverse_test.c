#include "../../hopark_mchun00/linkedlist/linkedlist.h"
#include <stdio.h>

int main()
{
	int i = 0;
	int LinkedCount = 0;
	LinkedList *pList = NULL;
	ListNode *pValue = NULL;

	pList = createLinkedList();
	if (pList != NULL)
	{
		ListNode node;

		for (int i = 0 ; i < 7; i++)
		{
			node.data = i;
			addLLElement(pList, i, node);
		}
		printf("Befor\n");
		displayLinkedList(pList);
		reverseLinkedList(pList);
		printf("After\n");
		displayLinkedList(pList);
		for(i = 0; i < LinkedCount; i++) {
			pValue = getLLElement(pList, i);
			printf("position : [%d]-[%d]\n", i, pValue->data);
		}
		deleteLinkedList(pList);
	}
}