#include <stdio.h>
#include <stdlib.h>
#include "doublylist.h"

int main(int argc, char *argv[]) {
	int i = 0;
	int DoublyCount = 0;
	DoublyList *pList = NULL;
	DoublyListNode *pValue = NULL;

	pList = createDoublyList();
	if (pList != NULL)
	{
		printf("---------------- NULL TEST ----------------\n");
		printf("**null display**\n");
		displayDoublyList(pList);
		printf("**null delete**\n");
		removeDLElement(pList, 0);
		displayDoublyList(pList);
		printf("---------------- ONE TEST ----------------\n");
		DoublyListNode node;
		node.data = 1;
		addDLElement(pList, 0, node);
		displayDoublyList(pList);
		printf("**one delete**\n");
		removeDLElement(pList, 0);
		displayDoublyList(pList);
		printf("---------------- BASIC TEST ----------------\n");
		node.data = 3;
		addDLElement(pList, 0, node);
		node.data = 5;
		addDLElement(pList, 1, node);
		node.data = 7;
		addDLElement(pList, 2, node);
		displayDoublyList(pList);
		removeDLElement(pList, 0);
		displayDoublyList(pList);
		DoublyCount = getDoublyListLength(pList);
		deleteDoublyList(pList);
	}
	return 0;
}