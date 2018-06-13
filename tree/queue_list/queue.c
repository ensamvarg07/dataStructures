#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

/*
int main(){
int i=0;
Queue *my_queue = malloc(sizeof(Queue));
my_queue = initQueue(64);

treenode *temp = malloc(6*sizeof(treenode));
treenode *pophold = malloc(sizeof(treenode));

for( ; i<6; i++){
	temp[i].data  = i+1;
	temp[i].left  = NULL;
	temp[i].right = NULL;
}

for(i=0; i<6; i++)
	enque(my_queue, &temp[i]);

printQueue(my_queue);
deque(my_queue);
printQueue(my_queue);
deque(my_queue);
printQueue(my_queue);

pophold = popFrontQueue(my_queue);
printf("Popping front : %d\n", pophold->data);
pophold = popRearQueue(my_queue);
printf("Popping rear : %d\n", pophold->data);

return 0;
}
*/

Queue * initQueue(int capacity){

	struct queue *q = (Queue *)malloc(sizeof(Queue));
	
	q->array    = (treenode *)malloc(sizeof(treenode) * QUEUESIZE );
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

void enque(Queue *queue, treenode * node)
{
	if(queue->size == queue->capacity)
		printf("\nError: Queue Overflow");

	else{
		queue->rear += 1;
		queue->rear %= queue->capacity;
		queue-> array[queue->rear].data  = node->data;
		queue-> array[queue->rear].left  = node->left;
		queue-> array[queue->rear].right = node->right;
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

treenode * popFrontQueue(Queue *queue)
{
	return &queue->array[queue->front];
}

treenode * popRearQueue(Queue *queue)
{
	return &queue->array[queue->rear];
}

void printQueue(Queue *queue)
{
	int i=0;
	printf("\nQueue Contents: |");
	for(i= queue->front; i<=queue->rear; i++){
		printf("%d | ", queue->array[i].data);
	}
	printf("\n");	
}
