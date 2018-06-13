#define QUEUESIZE 256

struct treenode{
	int data;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode treenode;

struct queue{
	treenode *array;	
	int front;
	int rear;
	int capacity;
	int size;
};
typedef struct queue Queue;

Queue * initQueue(int capacity);
void enque(Queue *, treenode * data);
void deque(Queue *);
treenode * popFrontQueue(Queue *);
treenode * popRearQueue(Queue *);
int isQueueEmpty(Queue *);
void printQueue(Queue *);


