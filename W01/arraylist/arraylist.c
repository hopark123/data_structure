#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList	*createArrayList(int maxElementcount)
{
	ArrayList	*res;
	ArrayListNode	*nodes;

	if (!(res = malloc(sizeof(ArrayList))) || res->maxElementCount < 0)
		return (NULL);
	res->maxElementCount = maxElementcount;
	res->currentElementCount = 0;
	if (!(nodes = malloc(sizeof(ArrayListNode) * maxElementcount)))
		return (NULL);
	res->pElement = nodes;
	return(res);
}

void	deleteArrayList(ArrayList *pList)
{
	free(pList->pElement);
	free(pList);
}

int	isArrayListFull(ArrayList *pList)
{
	if (!pList)
		return (ERROR);
	if (pList->currentElementCount >= pList->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int	isArrayListEmpty(ArrayList *pList)
{
	if (!pList)
		return (ERROR);
	if (pList->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

int	addALElement(ArrayList *pList, 	int position, ArrayListNode element)
{
	if (!pList)
		return (ERROR);
	if (position > pList->currentElementCount || position >= pList->maxElementCount || position < 0)
		return (ERROR);
	if (isArrayListFull(pList))
		return (ERROR);
	for (int i = pList->currentElementCount - 1; i >= position; i--)
		pList->pElement[i + 1].data = pList->pElement[i].data;
	pList->pElement[position].data = element.data;
	pList->currentElementCount++;
	return (TRUE);
}

int	removeALElement(ArrayList *pList, int position)
{
	if (!pList)
		return (ERROR);
	if (position > pList->currentElementCount || position >= pList->maxElementCount || position < 0)
		return (ERROR);
	if (isArrayListEmpty(pList))
		return (ERROR);
	for (int i = position; i < pList->currentElementCount; i++)
		pList->pElement[i].data = pList->pElement[i + 1].data;
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode *getALElement(ArrayList *pList, int position)
{
	if (!pList)
		return (NULL);
	if (position > pList->currentElementCount || position >= pList->maxElementCount || position < 0)
		return (NULL);
	if (isArrayListEmpty(pList))
		return (NULL);
	return (&(pList->pElement[position]));
}

void	displayArrayList(ArrayList *pList)
{
	if (!pList)
	{
		printf("pList is NULL\n");
		return ;
	}
	printf("maxElementCount : %d\ncurrentElementCount : %d\n", pList->maxElementCount, pList->currentElementCount);
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("[%3d]", pList->pElement[i].data);
	printf("\n");
}

void	clearArrayList(ArrayList *pList)
{
	if (!pList)
		return ;
	for (int i = 0; i < pList->maxElementCount; i++)
		pList->pElement[i].data = 0;
}

int	getArrayListLength(ArrayList *pList)
{
	if (!pList)
		return (ERROR);
	return (pList->currentElementCount);
}