#include "simulation_many.h"
#include <unistd.h>

ArrayQueue	*createArrayQueue(int queueSize)
{
	ArrayQueue	*queue;

	if (queueSize <= 0)
		return NULL;
	queue = malloc(sizeof(ArrayQueue));
	if (!queue)
		return (NULL);
	queue->pElement = malloc(sizeof(SimCustomer) * (queueSize + 1));
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

int	enQueue(ArrayQueue *queue, SimCustomer element)
{
	if (isQueueFull(queue))
		return (-1);
	queue->rear_index = (queue->rear_index + 1) % queue->queueSize;
	(queue->pElement + queue->rear_index)->status = element.status;
	(queue->pElement + queue->rear_index)->arrivalTime = element.arrivalTime;
	(queue->pElement + queue->rear_index)->serviceTime = element.serviceTime;
	(queue->pElement + queue->rear_index)->startTime = element.startTime;
	(queue->pElement + queue->rear_index)->endTime = element.endTime;
	return (0);
}

SimCustomer	*deQueue(ArrayQueue *queue)
{
	SimCustomer	*customer;

	if (isQueueEmpty(queue))
		return (0);
	customer = malloc(sizeof(SimCustomer));
	if (!customer)
		return (NULL);
	queue->front_index = (queue->front_index + 1) % queue->queueSize;
	customer->status = (queue->pElement + queue->front_index)->status;
	customer->arrivalTime = (queue->pElement + queue->front_index)->arrivalTime;
	customer->serviceTime = (queue->pElement + queue->front_index)->serviceTime;
	customer->startTime = (queue->pElement + queue->front_index)->startTime;
	customer->endTime = (queue->pElement + queue->front_index)->endTime;
	return (customer);
}

SimCustomer	*peekQueue(ArrayQueue *queue)
{
	if (isQueueEmpty(queue))
		return (0);
	return ((queue->pElement + (queue->front_index + 1)));
}

int	isQueueFull(ArrayQueue *queue)
{
	if (!queue)
		return (FALSE);
	if ((queue->rear_index + 1) % queue->queueSize == queue->front_index)
		return (TRUE);
	return (FALSE);
}

int	isQueueEmpty(ArrayQueue *queue)
{
	if (!queue)
		return (TRUE);
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

float simulation(ArrayQueue *arrivalQueue, ArrayQueue *waitQueue, int serviceCount) // + ?????????
{
	SimCustomer	*arrivedCustomer = NULL;
	SimCustomer	*serviceCustomer[serviceCount];
	int	i = 0, j = 0;
	int	sum = 0;
	int	customerCount = getQueueLength(waitQueue);

	for (int j = 0; j < serviceCount; j++)
		serviceCustomer[j] = NULL;
	while (1)
	{
		if (!isQueueEmpty(waitQueue) && peekQueue(waitQueue)->arrivalTime == i) // for
		{
			arrivedCustomer = deQueue(waitQueue);
			arrivedCustomer->status = arrival;
			printf("%d\tArrived Customer ===\n", i);
			enQueue(arrivalQueue, *arrivedCustomer);
			free(arrivedCustomer);
		}
		for (j = 0; j < serviceCount; j++)
		{
			if (!serviceCustomer[j] && !isQueueEmpty(arrivalQueue))
			{
				serviceCustomer[j] = deQueue(arrivalQueue);
				serviceCustomer[j]->startTime = i;
				serviceCustomer[j]->status = start;
				printf("%d\tService Start (arrived %d, employee #%d) ===\n", i, serviceCustomer[j]->arrivalTime, j);
				break;
			}
		}
		for (j = 0; j < serviceCount; j++)
		{
			if (serviceCustomer[j] && serviceCustomer[j]->startTime + serviceCustomer[j]->serviceTime == i)
			{
				serviceCustomer[j]->status = end;
				serviceCustomer[j]->endTime = i;
				sum += serviceCustomer[j]->startTime - serviceCustomer[j]->arrivalTime;
				printf("%d\tCustomer service end ===\n***\tArrival: %d | Service: %d | Start: %d | End : %d\t***\n", i, serviceCustomer[j]->arrivalTime, serviceCustomer[j]->serviceTime, serviceCustomer[j]->startTime, serviceCustomer[j]->endTime);
				free(serviceCustomer[j]);
				serviceCustomer[j] = NULL;
			}
		}
		if (isQueueEmpty(arrivalQueue) && isQueueEmpty(waitQueue))
		{
			for (j = 0; j < serviceCount; j++)
				if (serviceCustomer[j])
					break;
			if (j == serviceCount)
				break ;
		}
		i++;
	}
	return ((float) sum / (float) customerCount);
}

/*

????????? -> ????????? ???????????? ???????????? >> ??????????????? ???????????????????????????

????????? -> ?????? ?????? ?????? ????????? () ?????????????????? ???????????? ??????????????????


	???????????? ???????????????
1???		0		3
2???		2		2
3???		4		1
4???		6		1
5???		8		3

a, b = ?????? ?????????
i = 0;
sum = 0
while(!isQueueEmpty(?????????))
{
	if (????????? ?????? ->???????????? == i)
	{
		a = ????????? ???
		a->status = arrival
		???????????? a push
		free(a)
	}
	if (!b) // ????????? ?????? ????????? ??????
	{
		b = ????????? ??? // b??? ????????? ?????????
		b->starttime = i
		b->status = start
	}
	if (b && b->startTime + serviceTime == i)
	{
		b->status = end;
		free(b)
		b = NULL
		//???????????? ?????? ?????? sum += ???????????? endtime - arrival
	}
	i++;
}
return (sum / ??? ?????????)

*/



