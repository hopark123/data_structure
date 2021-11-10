#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList* createLinkedList(void)
{
	LinkedList	*list;
	ListNode	*dummy;

	if (!(list = malloc(sizeof(LinkedList))))
		return (NULL);
	list->currentElementCount = 0;
	if (!(dummy = malloc(sizeof(ListNode))))
		return (NULL);
	dummy->destination = 0;
	dummy->weight = 0;
	dummy->pLink = NULL;
	list->headerNode = dummy;
	return (list);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*ret;

	if (!pList)
		return (NULL);
	if (pList->currentElementCount <= position || position < 0)
		return (NULL);
	ret = pList->headerNode->pLink;
	for (int i = 0; i < position; i++)
		ret = ret->pLink;
	return (ret);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*prev;
	ListNode	*new;

	if (!pList)
		return (ERROR);
	if (position < 0)
		return (ERROR);
	if (position > pList->currentElementCount)
		position = pList->currentElementCount;
	if (!(new = malloc(sizeof(ListNode))))
		return (ERROR);
	new->destination = element.destination;
	new->weight = element.weight;

	if (position == 0)
		prev = pList->headerNode;
	else
		prev = getLLElement(pList, position - 1);
	new->pLink = prev->pLink;
	prev->pLink = new;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{

	ListNode	*prev;
	ListNode	*now;

	if (!pList)
		return (ERROR);
	if (pList->currentElementCount <= position || position < 0)
		return (ERROR);
	if (position == 0)
		prev = pList->headerNode;
	else
		prev = getLLElement(pList, position - 1);
	now = getLLElement(pList, position);
	prev->pLink = now->pLink;
	pList->currentElementCount--;
	free(now);
	return (TRUE);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	ListNode	*prev;

	if (!pList)
		return ;
	curr = pList->headerNode;
	while (curr)
	{
		prev = curr;
		curr = curr->pLink;
		free(prev);
	}
	pList->currentElementCount = 0;       /////////질문!!!!!!!!!
}

int getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (ERROR);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	ListNode	*prev;

	if (!pList)
		return ;
	curr = pList->headerNode;
	while (curr)
	{
		prev = curr;
		curr = curr->pLink;
		free(prev);
	}
	free(pList);
}

void displayLinkedList(LinkedList* pList)
{
	ListNode	*temp;

	if (!pList)
		return ;
	temp = pList->headerNode->pLink;
	// printf("currentElementCount : %d\n",pList->currentElementCount);
	while (temp)
	{
		printf("[%d] > ", temp->destination);
		temp = temp->pLink;
	}
	printf("[END]\n");
}