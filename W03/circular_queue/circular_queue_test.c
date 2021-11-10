#include "circular_queue.h"

void	printQueue(ArrayQueue *queue)
{
	int	i;

	i = queue->front_index;
	printf("==QUEUE==\n");
	if (isQueueEmpty(queue))
		printf("Queue is now empty!\n");
	while (i++ < queue->rear_index)
	{
		if (i > queue->queueSize)
			i %= queue->queueSize;
		printf("%c ", queue->pElement[i].data);
	}
	printf("\nlength: %d\n\n", getQueueLength(queue));
}

int main(void)
{
	ArrayQueue *queue = createArrayQueue(5);
	ArrayQueueNode node;

	printf("------ NULL TEST ------\n");
	printQueue(queue);
	printf("------ ENQUEUE TEST ------\n");
	for (int i = 0; i < 5; i ++)
	{
		node.data = 'a' + i;
		printf("push %c\t", node.data);
		if (enQueue(queue, node) < 0)
			printf("Enque Failed!!\n");
		printQueue(queue);
	}
	printf("------ PEEK TEST ------\n");
	printf("peekqueue : %c\n", peekQueue(queue));
	printQueue(queue);
	printf("------ DEQUEUE TEST ------\n");
	for (int i = 0 ; i < 5; i ++)
	{
		printf("dequeue : %c\n", deQueue(queue));
		printQueue(queue);
	}
}
