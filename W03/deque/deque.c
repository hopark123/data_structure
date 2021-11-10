#include "deque.h"

Deque	*createDeque(void)
{
	Deque	*deque;
	DequeNode	*dummyFront;
	DequeNode	*dummyRear;

	deque = malloc(sizeof(Deque));
	if (!deque)
		return (NULL);
	dummyFront = malloc(sizeof(DequeNode));
	if (!dummyFront)
		return (NULL);
	dummyRear = malloc(sizeof(DequeNode));
	if (!dummyRear)
		return (NULL);
	dummyFront->pRLink = dummyRear;
	dummyFront->pLLink = NULL;
	dummyRear->pLLink = dummyFront;
	dummyRear->pRLink = NULL;
	deque->front = dummyFront;
	deque->rear = dummyRear;
	deque->currentElementCount = 0;
	return (deque);
}

int	insertFront(Deque *deque, DequeNode element)
{
	DequeNode	*new;

	new = malloc(sizeof(DequeNode));
	if (!new)
		return (-1);
	new->data = element.data;
	new->pRLink = deque->front->pRLink;
	new->pLLink = deque->front;
	deque->front->pRLink->pLLink = new;
	deque->front->pRLink = new;
	deque->currentElementCount++;
	return (0);
}

int	insertRear(Deque *deque, DequeNode element)
{
	DequeNode	*new;

	new = malloc(sizeof(DequeNode));
	if (!new)
		return (-1);
	new->data = element.data;
	new->pRLink = deque->rear;
	new->pLLink = deque->rear->pLLink;
	deque->rear->pLLink->pRLink = new;
	deque->rear->pLLink = new;
	deque->currentElementCount++;
	return (0);
}

DequeNode	*deleteFront(Deque *deque)
{
	DequeNode	*to_del;

	if (isDequeEmpty(deque))
		return (NULL);
	to_del = deque->front->pRLink;
	deque->front->pRLink = to_del->pRLink;
	to_del->pRLink->pLLink = deque->front;
	deque->currentElementCount--;
	return (to_del);
}


DequeNode	*deleteRear(Deque *deque)
{
	DequeNode	*to_del;

	if (isDequeEmpty(deque))
		return (NULL);
	to_del = deque->rear->pLLink;
	deque->rear->pLLink = to_del->pLLink;
	to_del->pLLink->pRLink = deque->rear;
	deque->currentElementCount--;
	return (to_del);
}

DequeNode	*peekFront(Deque *deque)
{
	if (!deque || isDequeEmpty(deque))
		return (NULL);
	return (deque->front->pRLink);
}

DequeNode	*peekRear(Deque *deque)
{
	if (!deque || isDequeEmpty(deque))
		return (NULL);
	return (deque->rear->pLLink);
}

int		isDequeEmpty(Deque *deque)
{
	if (!deque)
		return (TRUE);
	if (deque->currentElementCount > 0)
		return (FALSE);
	return (TRUE);
}

int	deleteDeque(Deque *deque)
{
	if (!deque)
		return (1);
	while (!isDequeEmpty(deque))
		free(deleteFront(deque));
	free(deque->front);
	free(deque->rear);
	free(deque);
	return (0);
}
