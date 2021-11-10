#include "ArrayStack.h"
#include <stdio.h>
#include <unistd.h>

static void	displayStack(ArrayStack *pStack)
{
	if (!pStack)
	{
		printf("pStack is NULL\n");
		return ;
	}
	if (pStack->currentElementCount > 1)
		printf("maxElementCount : %d\nTop Element : %d\n", pStack->maxElementCount, pStack->pTopElement[pStack->currentElementCount - 1].data);
	else
		printf("maxElementCount : %d\nElement : Empty\n", pStack->maxElementCount);
	for (int i = 0; i < pStack->currentElementCount; i++)
		printf("[%3d]", pStack->pTopElement[i].data);
	printf("\n");
}

int main()
{
	// ArrayStack *AS = NULL;

	// AS = createArrayStack(3);
	// if (AS != NULL)
	// {
	// 	StackNode node;
	// 	StackNode *pop;
	// 	printf("---------------- NULL TEST ----------------\n");
	// 	printf("**null display**\n");
	// 	displayStack(AS);
	// 	printf("**null delete**\n");
	// 	// pop = popAS(AS);
	// 	// printf("pop : [%3d]\n", pop->data);
	// 	displayStack(AS);
	// 	printf("---------------- ONE TEST ----------------\n");
	// 	node.data = 1;
	// 	pushAS(AS, node);
	// 	displayStack(AS);
	// 	printf("**one delete**\n");
	// 	pop = popAS(AS);
	// 	printf("pop : [%3d]\n", pop->data);
	// 	displayStack(AS);
	// 	printf("---------------- BASIC TEST ----------------\n");
	// 	node.data = 2;
	// 	pushAS(AS, node);
	// 	printf("push : [%3d]\n", node.data);
	// 	node.data = 3;
	// 	pushAS(AS, node);
	// 	printf("push : [%3d]\n", node.data);
	// 	node.data = 4;
	// 	printf("push : [%3d]\n", node.data);
	// 	pushAS(AS, node);
	// 	displayStack(AS);
	// 	pop = popAS(AS);
	// 	printf("pop : [%3d]\n", pop->data);
	// 	node.data = 5;
	// 	printf("push : [%3d]\n", node.data);
	// 	pushAS(AS, node);
	// 	node.data = 6;
	// 	printf("push : [%3d]\n", node.data);
	// 	pushAS(AS, node);
	// 	node.data = 7;
	// 	printf("push : [%3d]\n", node.data);
	// 	pushAS(AS, node);
	// 	displayStack(AS);
	// }
	char *true = "{2 - (1 + [3])} * (4 + 5)";
	char *false = "[{2 - (1 + 3)} * {(4 + 5)}";
	char *false2 = "{2 - (1 + 3)} * (4 + 5}";

	printf("TRUE TEST : %s\n", true);
	printf("%d\n", checkBracketMatching(true));
	printf("FALSE TEST : %s\n", false);
	printf("%d\n", checkBracketMatching(false));
	printf("FALSE TEST2 : %s\n", false2);
	printf("%d\n", checkBracketMatching(false2));
}

// test 수정 및 peak test 추가 요망
