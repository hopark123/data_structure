#ifndef _DEQUE_
#define _DEQUE_

#include <stdlib.h>
#include <stdio.h>

typedef struct DequeNodeType
{
	char data;
	struct DequeNodeType *pLLink;
	struct DequeNodeType *pRLink;
}	DequeNode;

typedef struct DequeType
{
	int	currentElementCount;
	DequeNode *front;
	DequeNode *rear;
}	Deque;

Deque		*createDeque(void);
int			insertFront(Deque *deque, DequeNode element);
int			insertRear(Deque *deque, DequeNode element);
DequeNode	*deleteFront(Deque *deque);
DequeNode	*deleteRear(Deque *deque);
int			isDequeEmpty(Deque *deque);
DequeNode	*peekFront(Deque *deque);
DequeNode	*peekRear(Deque *deque);
int			deleteDeque(Deque *deque);


#define TRUE		1
#define FALSE		0

#endif
