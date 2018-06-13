#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

Queue * initQueue(int capacity){

	struct queue *q = (Queue *)malloc(sizeof(Queue));
	
	q->array    = (int *)malloc(sizeof(int));
	q->front    =  0;
	q->rear	    = -1;	
	q->capacity = capacity;
	q->size     = 0;

return q;
}

int isQueueEmpty(Queue *queue)
{
if(queue->size == 0) return 1;
else  return 0;
}

void enque(Queue *queue, int data)
{
	if(queue->size == queue->capacity)
		printf("\nError: Queue Overflow");

	else{
		queue->rear += 1;
		queue->rear %= queue->capacity;
		queue->array[queue->rear] = data;
		queue->size += 1;
	}
}

void deque(Queue *queue)
{
	if( isQueueEmpty(queue)==1)
		printf("\nError: Queue Underflow");
	
	else{
		queue->front = (queue->front+1) % queue->capacity ;
		queue->size -= 1;
	}
}

int popFrontQueue(Queue *queue)
{
	return queue->array[queue->front];
}

int popRearQueue(Queue *queue)
{
	return queue->array[queue->rear];
}

void printQueue(Queue *queue)
{
	int i=0;
	printf("\nQueue Contents: |");
	for(i= queue->front; i<=queue->rear; i++)
		printf("%d | ", queue->array[i]);
	printf("\n");	
}
