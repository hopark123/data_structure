#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[]) {
	int i = 0;
	int LinkedCount = 0;
	LinkedList *pList = NULL;
	ListNode *pValue = NULL;

	pList = createLinkedList();
	if (pList != NULL)
	{
		ListNode node;

		node.data = 1;
		addLLElement(pList, 0, node);

		node.data = 3;
		addLLElement(pList, 1, node);

		node.data = 5;
		addLLElement(pList, 2, node);
		displayLinkedList(pList);

		removeLLElement(pList, 0);
		displayLinkedList(pList);

		LinkedCount = getLinkedListLength(pList);
		for(i = 0; i < LinkedCount; i++) {
			pValue = getLLElement(pList, i);
			printf("position : [%d]-[%d]\n", i, pValue->data);
		}
		deleteLinkedList(pList);
	}
	return 0;
}