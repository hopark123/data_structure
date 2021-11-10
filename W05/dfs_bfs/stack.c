#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

LinkedStack* createLinkedStack()
{
	LinkedStack	*LS;
	StackNode	*dummy;

	if (!(LS = malloc(sizeof(LinkedStack))))
		return (NULL);
	if (!(dummy = malloc(sizeof(StackNode))))
		return (NULL);
	dummy->pLLink = 0;
	dummy->pRLink = 0;
	LS->currentElementCount = 0;
	LS->pTopElement = dummy;
	return (LS);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*new;
	
	if (!pStack)
		return (ERROR);
	if (!(new = malloc(sizeof(StackNode))))
		return (ERROR);
	new->data = element.data;
	new->pRLink = 0;
	pStack->pTopElement->pRLink = new;
	new->pLLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *res;

	res = pStack->pTopElement;
	if (!pStack)
		return (NULL);
	if (pStack->currentElementCount < 1)
		return (NULL);
	pStack->pTopElement->pRLink = 0;
	pStack->pTopElement = pStack->pTopElement->pLLink;
	res->pLLink = 0;
	res->pRLink = 0;
	pStack->currentElementCount--;
	return (res);
} // free 유무는 설계의 차이인지?

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack || pStack->currentElementCount < 1)
		return (NULL);
	return (pStack->pTopElement);
}       // return 한걸 밖에서 free하면 top은 어떻게 되는지?

void deleteLinkedStack(LinkedStack* pStack)
{
	if (!pStack)
		return ;
	StackNode *curr = pStack->pTopElement;
	StackNode *next;
	while (curr)
	{
		next = curr->pLLink;
		free(curr);
		curr = next;
	}
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

StackNode	*createLinkedNode(int data)
{
	StackNode	*res;

	if (!(res = malloc(sizeof(StackNode))))
		return (NULL);
	res->data = data;
	res->pLLink = NULL;
	res->pRLink = NULL;
	return (res);
}

int checkBracketMatching(char *pSource)
{
    LinkedStack *bracket = createLinkedStack();
	StackNode	*node = NULL;

	if(!bracket)
		return(ERROR);
	int i = 0;
	while (pSource[i])
	{
		if (pSource[i] == '(' || pSource[i] == '{' || pSource[i] == '[')
		{
			node =createLinkedNode((int)pSource[i]);
			pushLS(bracket, *node);
			free(node);
		}
		else if (pSource[i] == ')')
		{
			if (peekLS(bracket)->data == '(')
				popLS(bracket);
			else
				return (FALSE);
		}
		else if (pSource[i] == '}')
		{
			if (peekLS(bracket)->data == '{')
				popLS(bracket);
			else
				return (FALSE);
		}
		else if (pSource[i] == ']')
		{
			if (peekLS(bracket)->data == '[')
				popLS(bracket);
			else
				return (FALSE);
		}
		i++;
	}
	return (isLinkedStackEmpty(bracket));
}
