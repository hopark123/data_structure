#include "queue.h"

ArrayQueue	*createArrayQueue(int queueSize)
{
	ArrayQueue	*queue;

	if (queueSize <= 0)
		return NULL;
	queue = malloc(sizeof(ArrayQueue));
	if (!queue)
		return (NULL);
	queue->pElement = malloc(sizeof(ArrayQueueNode) * (queueSize + 1));
	if (!queue->pElement)
	{
		free(queue);
		return (NULL);
	}
	queue->queueSize = queueSize;
	queue->front_index = 0;
	queue->rear_index = 0;
	return (queue);
}

int	enQueue(ArrayQueue *queue, ArrayQueueNode element)
{
	if (isQueueFull(queue))
		return (-1);
	queue->rear_index = (queue->rear_index + 1) % queue->queueSize;
	(queue->pElement + queue->rear_index)->data = element.data;
	return (0);
}

int	deQueue(ArrayQueue *queue)
{
	if (isQueueEmpty(queue))
		return (0);
	queue->front_index = (queue->front_index + 1) % queue->queueSize;
	return ((queue->pElement + queue->front_index)->data);
}

int	peekQueue(ArrayQueue *queue)
{
	if (isQueueEmpty(queue))
		return (0);
	return ((queue->pElement + (queue->front_index + 1) % queue->queueSize)->data);
}

int	isQueueFull(ArrayQueue *queue)
{
	if ((queue->rear_index + 1) % queue->queueSize == queue->front_index)
		return (TRUE);
	return (FALSE);
}

int	isQueueEmpty(ArrayQueue *queue)
{
	if (queue->front_index == queue->rear_index)
		return (TRUE);
	return (FALSE);
}

int	getQueueLength(ArrayQueue *queue)
{
	if (queue->front_index > queue->rear_index)
		return ((queue->rear_index + queue->queueSize) - queue->front_index);
	else
		return (queue->rear_index - queue->front_index);
}

int	deleteQueue(ArrayQueue *queue)
{
	free(queue->pElement);
	free(queue);
	return (0);
}
