#include "polynomial.h"
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
	dummy->degree = 0;
	dummy->coefficient = 0;
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
	if (pList->currentElementCount < position || position < 0)
		return (ERROR);
	if (!(new = malloc(sizeof(ListNode))))
		return (ERROR);
	new->degree = element.degree;
	new->coefficient = element.coefficient;
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

void displayPolynomial(LinkedList* pList)
{
	ListNode	*temp;

	if (!pList)
		return ;
	if (pList->currentElementCount == 0)
		printf("0");
	temp = pList->headerNode->pLink;
	while (temp)
	{
		if (!temp->degree)
			printf("(%d)", temp->coefficient);
		else
		{
			if (temp->coefficient != 1)
				printf("(%dx^%d) ", temp->coefficient, temp->degree);
			else
				printf("(x^%d) ", temp->degree);
		}
		if (temp->pLink)
			printf("+ ");
		temp = temp->pLink;
	}
	printf("\n");
}

LinkedList	*add_polynomial(LinkedList *A, LinkedList *B)
{
	int i = 0;
	LinkedList	*res;
	ListNode	temp;
	ListNode	*curr;
	ListNode	*nodeA = A->headerNode->pLink;
	ListNode	*nodeB = B->headerNode->pLink;

	res = createLinkedList();
	while (nodeA && nodeB)
	{
		if (nodeA->degree == nodeB->degree)
		{
			temp.degree = nodeA->degree;
			temp.coefficient = nodeA->coefficient + nodeB->coefficient;
			addLLElement(res, i++, temp);
			nodeA = nodeA->pLink;
			nodeB = nodeB->pLink;
		}
		else if (nodeA->degree > nodeB->degree)
		{
			addLLElement(res, i++, (*nodeA));
			nodeA = nodeA->pLink;
		}
		else
		{
			addLLElement(res, i++, (*nodeB));
			nodeB = nodeB->pLink;
		}
	}
	curr = (nodeA) ? (nodeA) : (nodeB);
	while (curr)
	{
		addLLElement(res, i++, *curr);
		curr = curr->pLink;
	}
	return (res);
} 