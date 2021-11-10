#include "ArrayStack.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack *createArrayStack(int maxElementCount)
{
	ArrayStack *AS = malloc(sizeof(ArrayStack));
	StackNode *SN;
	
	if (!AS)
		return (NULL);
	if (!(SN = malloc(sizeof(StackNode) * maxElementCount)))
		return (NULL);
	AS->maxElementCount = maxElementCount;
	AS->currentElementCount = 0;
	AS->pTopElement = SN;
	return (AS);
}

int	pushAS(ArrayStack* pStack, StackNode element)
{
	if (!pStack)
		return (ERROR);
	if (isArrayStackFull(pStack))
	{
		StackNode *SN;

		pStack->maxElementCount *= 2;
		if (!(SN = malloc(sizeof(StackNode) * pStack->maxElementCount)))
			return (ERROR);
		for (int i = 0; i < pStack->currentElementCount ; i++)
			SN[i] = pStack->pTopElement[i];
		free(pStack->pTopElement);
		pStack->pTopElement = SN;
	}
	pStack->pTopElement[pStack->currentElementCount].data = element.data;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popAS(ArrayStack* pStack)
{
	StackNode *temp;

	if (!pStack)
		return (NULL);
	if (isArrayStackEmpty(pStack))
		return (NULL);
	temp = malloc(sizeof(StackNode));
	if(!temp)
		return (NULL);
	pStack->currentElementCount--;
	temp->data = pStack->pTopElement[pStack->currentElementCount].data;
	return (temp);
}


StackNode* peekAS(ArrayStack* pStack)
{
	if (!pStack)
		return (NULL);
	return (&pStack->pTopElement[pStack->currentElementCount - 1]);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return ;
	free(pStack->pTopElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack)
		return (ERROR);
	return (pStack->currentElementCount  == pStack->maxElementCount ? TRUE : FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack)
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}


StackNode	*createArrayNode(int data)
{
	StackNode	*res;

	if (!(res = malloc(sizeof(StackNode))))
		return (NULL);
	res->data = data;
	return (res);
}

int checkBracketMatching(char *pSource)
{
	ArrayStack *bracket = createArrayStack(5);
	StackNode	*node = NULL;

	if(!bracket)
		return(ERROR);
	int i = 0;

	while (pSource[i])
	{
		if (pSource[i] == '(' || pSource[i] == '{' || pSource[i] == '[')
		{
			node = createArrayNode((int)pSource[i]);
			pushAS(bracket, *node);
			free(node);
		}
		else if (pSource[i] == ')')
		{
			if (peekAS(bracket)->data == '(')
				popAS(bracket);
			else
				return (FALSE);
		}
		else if (pSource[i] == '}')
		{
			if (peekAS(bracket)->data == '{')
				popAS(bracket);
			else
				return (FALSE);
		}
		else if (pSource[i] == ']')
		{
			if (peekAS(bracket)->data == '[')
				popAS(bracket);
			else
				return (FALSE);
		}
		i++;
	}
	return (isArrayStackEmpty(bracket));
}

