#ifndef _CIRCULAR_QUEUE_
#define _CIRCULAR_QUEUE_

#include <stdlib.h>
#include <stdio.h>

typedef struct ArrayQueueNodeType
{
	char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int	queueSize;
	int	front_index;
	int	rear_index;
	ArrayQueueNode *pElement;
} ArrayQueue;

ArrayQueue	*createArrayQueue(int maxElementCount);
int			enQueue(ArrayQueue *queue, ArrayQueueNode element);
char		deQueue(ArrayQueue *queue);
char		peekQueue(ArrayQueue *queue);
int			isQueueFull(ArrayQueue *queue);
int			isQueueEmpty(ArrayQueue *queue);
int			getQueueLength(ArrayQueue *queue);
int			deleteQueue(ArrayQueue *queue);

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
