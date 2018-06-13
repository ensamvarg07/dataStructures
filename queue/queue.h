#define QUEUESIZE 256

struct queue{
	int *array;
	int front;
	int rear;
	int capacity;
	int size;
};
typedef struct queue Queue;

Queue * initQueue(int capacity);
void enque(Queue *, int data);
void deque(Queue *);
int popFrontQueue(Queue *);
int popRearQueue(Queue *);
int isQueueEmpty(Queue *);
void printQueue(Queue *);


