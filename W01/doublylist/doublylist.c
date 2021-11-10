#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList(void)
{
	DoublyList	*list;
	DoublyListNode	*dummy;

	if (!(list = malloc(sizeof(DoublyList))))
		return (NULL);
	list->currentElementCount = 0;
	if (!(dummy = malloc(sizeof(DoublyListNode))))
		return (NULL);
	dummy->data = 0;
	dummy->pRLink = NULL;
	dummy->pLLink = NULL;
	list->headerNode = dummy;
	return (list);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*ret;

	if (!pList)
		return (NULL);
	if (pList->currentElementCount <= position || position < 0)
		return (NULL);
	ret = pList->headerNode->pRLink;
	for (int i = 0; i < position; i++)
		ret = ret->pRLink;
	return (ret);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode	*curr;
	DoublyListNode	*new;

	if (!pList)
		return (ERROR);
	if (position < 0)
		return (ERROR);
	if (position > pList->currentElementCount)
		position = pList->currentElementCount;
	if (!(new = malloc(sizeof(DoublyListNode))))
		return (ERROR);
	if (position == 0)
		curr = pList->headerNode;
	else
		curr = getDLElement(pList, position - 1);
	new->data = element.data;
	new->pRLink = curr->pRLink;
	if (curr->pRLink)
		curr->pRLink->pLLink = new;
	curr->pRLink = new;
	new->pLLink = curr;
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{

	DoublyListNode	*prev;
	DoublyListNode	*curr;

	if (!pList)
		return (ERROR);
	if (pList->currentElementCount <= position || position < 0)
		return (ERROR);
	curr = getDLElement(pList, position);
	prev = curr->pLLink;
	prev->pRLink = curr->pRLink;
	if (curr->pRLink)
		curr->pRLink->pLLink = prev;
	pList->currentElementCount--;
	free(curr);
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode	*curr;
	DoublyListNode	*prev;

	if (!pList)
		return ;
	curr = pList->headerNode;
	while (curr)
	{
		prev = curr;
		curr = curr->pRLink;
		free(prev);
	}
	pList->currentElementCount = 0;       /////////질문!!!!!!!!!
}

int getDoublyListLength(DoublyList* pList)
{
	if (!pList)
		return (ERROR);
	return (pList->currentElementCount);
}

void deleteDoublyList(DoublyList* pList)
{
	DoublyListNode	*curr;
	DoublyListNode	*prev;

	if (!pList)
		return ;
	curr = pList->headerNode;
	while (curr)
	{
		prev = curr;
		curr = curr->pRLink;
		free(prev);
	}
	free(pList);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode	*temp;

	if (!pList)
		return ;
	temp = pList->headerNode->pRLink;
	printf("currentElementCount : %d\n",pList->currentElementCount);
	while (temp)
	{
		if (temp->pLLink != pList->headerNode)
			printf("[%3d]", temp->pLLink->data);
		else
			printf("[dum]");
		printf(" < [%3d] > ", temp->data);
		if (temp->pRLink)
			printf("[%3d]\n", temp->pRLink->data);
		else
			printf("[END]\n");
		temp = temp->pRLink;
	}
	printf("\n");
}
