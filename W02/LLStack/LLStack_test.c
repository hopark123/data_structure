#include "LLStack.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void	displayStack(LinkedStack *pStack)
{
	StackNode *temp;

	if (!pStack)
	{
		printf("pStack is NULL\n");
		return ;
	}
	if (pStack->currentElementCount > 1)
		printf("ElementCount : %d\nTop Element : %d\n", pStack->currentElementCount, pStack->pTopElement->data);
	else
		printf("ElementCount : %d\nElement : Empty\n", pStack->currentElementCount);

	temp = pStack->pTopElement;
	while (temp->pLLink)
	{
		printf("[%3d]", temp->data);
		temp = temp->pLLink;
	}
	printf("\n");
}

int main()
{
	LinkedStack *LS = NULL;

	LS = createLinkedStack();
	if (LS != NULL)
	{
		StackNode node;
		StackNode *pop;
		printf("---------------- NULL TEST ----------------\n");
		printf("**null display**\n");
		displayStack(LS);
		printf("**null delete**\n");
		pop = popLS(LS);
		if (pop)
		{
			printf("pop : [%3d]\n", pop->data);
			free(pop);
		}
		displayStack(LS);
		printf("---------------- ONE TEST ----------------\n");
		node.data = 1;
		pushLS(LS, node);
		displayStack(LS);
		printf("**one delete**\n");
		pop = popLS(LS);
		if (pop)
		{
			printf("pop : [%3d]\n", pop->data);
			free(pop);
		}
		displayStack(LS);
		printf("---------------- BLSIC TEST ----------------\n");
		node.data = 2;
		pushLS(LS, node);
		printf("push : [%3d]\n", node.data);
		node.data = 3;
		pushLS(LS, node);
		printf("push : [%3d]\n", node.data);
		node.data = 4;
		printf("push : [%3d]\n", node.data);
		pushLS(LS, node);
		displayStack(LS);
		pop = popLS(LS);
		if (pop)
		{
			printf("pop : [%3d]\n", pop->data);
			free(pop);
		}
		node.data = 5;
		printf("push : [%3d]\n", node.data);
		pushLS(LS, node);
		node.data = 6;
		printf("push : [%3d]\n", node.data);
		pushLS(LS, node);
		node.data = 7;
		printf("push : [%3d]\n", node.data);
		pushLS(LS, node);
		displayStack(LS);
	}
	deleteLinkedStack(LS);
	char *true = "{2 - (1 + [3])} * (4 + 5)";
	char *false = "{2 - (1 + 3)} * {[(4 + 5)}";
	char *false2 = "{2 - (1 + 3)} * (4 + 5}";

	printf("TRUE TEST : %s\n", true);
	printf("%d\n", checkBracketMatching(true));
	printf("FALSE TEST : %s\n", false);
	printf("%d\n", checkBracketMatching(false));
	printf("FALSE TEST2 : %s\n", false2);
	printf("%d\n", checkBracketMatching(false2));
}

// test 수정 및 peak test 추가 요망
