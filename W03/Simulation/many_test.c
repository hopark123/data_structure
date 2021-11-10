#include "simulation_many.h"

int main(void)
{
	ArrayQueue	*arrivalQueue, *waitQueue;
	SimCustomer	element;
	float		average;

	arrivalQueue = createArrayQueue(10);
	waitQueue = createArrayQueue(10);

	maketest(waitQueue);
	average = simulation(arrivalQueue, waitQueue, 2);

	printf("\nAverage Waiting Time: %f\n", average);
	deleteQueue(arrivalQueue);
	deleteQueue(waitQueue);
	return (0);
}

void	maketest(ArrayQueue *waitQueue)
{
	SimCustomer element;

	element.arrivalTime = 0;
	element.serviceTime = 13;
	enQueue(waitQueue, element);
	element.arrivalTime = 2;
	element.serviceTime = 12;
	enQueue(waitQueue, element);
	element.arrivalTime = 4;
	element.serviceTime = 11;
	enQueue(waitQueue, element);
	element.arrivalTime = 6;
	element.serviceTime = 11;
	enQueue(waitQueue, element);
	element.arrivalTime = 8;
	element.serviceTime = 13;
	enQueue(waitQueue, element);
	element.arrivalTime = 11;
	element.serviceTime = 15;
	enQueue(waitQueue, element);
	element.arrivalTime = 14;
	element.serviceTime = 12;
	enQueue(waitQueue, element);
	element.arrivalTime = 16;
	element.serviceTime = 14;
	enQueue(waitQueue, element);
	element.arrivalTime = 24;
	element.serviceTime = 13;
	enQueue(waitQueue, element);
}
