#ifndef _SIMULATION_
#define _SIMULATION_


#include <stdlib.h>
#include <stdio.h>

typedef enum SimStatusType
{
	arrival = 0,
	start,
	end,
} SimStatus;

typedef struct SimCustomerType
{
	SimStatus	status;
	int	arrivalTime;
	int	serviceTime;
	int	startTime;
	int	endTime;
} SimCustomer;

typedef struct ArrayQueueType
{
	int	queueSize;
	int	front_index;
	int	rear_index;
	SimCustomer *pElement;
} ArrayQueue;

// Queue Functions
ArrayQueue	*createArrayQueue(int maxElementCount);
int			enQueue(ArrayQueue *queue, SimCustomer element);
SimCustomer	*deQueue(ArrayQueue *queue);
SimCustomer	*peekQueue(ArrayQueue *queue);
int			isQueueFull(ArrayQueue *queue);
int			isQueueEmpty(ArrayQueue *queue);
int			getQueueLength(ArrayQueue *queue);
int			deleteQueue(ArrayQueue *queue);

//Simulation Functions
float		simulation(ArrayQueue *arrivalQueue, ArrayQueue *waitQueue);
void		maketest(ArrayQueue *waitQueue);

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
