#include "simulation.h"
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

float simulation(ArrayQueue *arrivalQueue, ArrayQueue *waitQueue)
{
	SimCustomer	*arrivedCustomer = NULL, *serviceCustomer = NULL;
	int	i = 0;
	int	sum = 0;
	int	customerCount = getQueueLength(waitQueue);

	while (1)
	{
		if (!isQueueEmpty(waitQueue) && peekQueue(waitQueue)->arrivalTime == i)
		{
			arrivedCustomer = deQueue(waitQueue);
			arrivedCustomer->status = arrival;
			printf("%d\tArrived Customer ===\n", i);
			enQueue(arrivalQueue, *arrivedCustomer);
			free(arrivedCustomer);
		}
		if (!serviceCustomer && !isQueueEmpty(arrivalQueue))
		{
			serviceCustomer = deQueue(arrivalQueue);
			serviceCustomer->startTime = i;
			serviceCustomer->status = start;
			printf("%d\tService Start (arrived %d) ===\n", i, serviceCustomer->arrivalTime);
		}
		if (serviceCustomer && serviceCustomer->startTime + serviceCustomer->serviceTime == i)
		{
			serviceCustomer->status = end;
			serviceCustomer->endTime = i;
			sum += serviceCustomer->startTime - serviceCustomer->arrivalTime;
			printf("%d\tCustomer service end ===\n***\tArrival: %d | Service: %d | Start: %d | End : %d\t***\n", i, serviceCustomer->arrivalTime, serviceCustomer->serviceTime, serviceCustomer->startTime, serviceCustomer->endTime);
			free(serviceCustomer);
			serviceCustomer = NULL;
		}
		if (isQueueEmpty(arrivalQueue) && isQueueEmpty(waitQueue) && serviceCustomer == NULL)
			break;
		i++;
	}
	return ((float) sum / (float) customerCount);
}

/*

대기큐 -> 서비스 받으려고 대기하는 >> 시간이되면 서비스를받으러간다

도착큐 -> 아직 출발 안한 사람들 () 미래가있는데 시간되면 대기로넘긴다


	도착시간 서비스시간
1번		0		3
2번		2		2
3번		4		1
4번		6		1
5번		8		3

a, b = 손님 포인터
i = 0;
sum = 0
while(!isQueueEmpty(도착큐))
{
	if (도착큐 피크 ->도착시간 == i)
	{
		a = 도착큐 팝
		a->status = arrival
		대기큐에 a push
		free(a)
	}
	if (!b) // 서비스 받는 사람이 없음
	{
		b = 대기큐 팝 // b는 서비스 받는중
		b->starttime = i
		b->status = start
	}
	if (b && b->startTime + serviceTime == i)
	{
		b->status = end;
		free(b)
		b = NULL
		//대기시간 총합 계신 sum += 대기시간 endtime - arrival
	}
	i++;
}
return (sum / 총 인원수)

*/



