#include "deque.h"

void	printDeque(Deque *deque)
{
	DequeNode	*node;

	node = deque->front->pRLink;
	if (!node)
		return ;
	while (node != deque->rear)
	{
		printf("%c ", node->data);
		node = node->pRLink;
	}
	printf("\n");
}

int	main(void)
{
	Deque		*deque = createDeque();
	DequeNode	*to_del;
	DequeNode	node;

	printf("------ NULL TEST ------\n");
	printDeque(deque);
	printf("------ BASIC TEST ------\n");
	for (int i = 0; i < 3; i ++)
	{
		node.data = 'a' + i;
		insertFront(deque, node);
		printf("front %c : \t", node.data);
		printDeque(deque);
	}
	for (int i = 0; i < 3; i ++)
	{
		node.data = 'z' - i;
		insertRear(deque, node);
		printf("rear %c : \t", node.data);
		printDeque(deque);
	}
	printf("------ PEEK TEST ------\n");
	printf("peek front : %c\n", peekFront(deque)->data);
	printf("peek rear : %c\n", peekRear(deque)->data);
	printDeque(deque);
	printf("------ DEL TEST ------\n");
	for (int i = 0 ; i < 2; i ++)
	{
		to_del = deleteFront(deque);
		printf("del front : %c\n", to_del->data);
		free(to_del);
		printDeque(deque);
	}
	for (int i = 0 ; i < 2; i ++)
	{
		to_del = deleteRear(deque);
		printf("del rear : %c\n", to_del->data);
		free(to_del);
		printDeque(deque);
	}
	deleteDeque(deque);
}
