#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "queue_list/queue.h"

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *create_node(int);
struct node *insert_node(struct node *,int);
void printTree(struct node *, int depth);
int treeDepth(struct node *);

int main()
{
	int i=0,depth;
	int arr[7] = {6,2,1,4,3,5,7};
	struct node *rootNode;

	rootNode = create_node(arr[i]);
	
	for (i=1; i<7 ; i++)
		insert_node(rootNode, arr[i]);
	
	depth = treeDepth(rootNode);
	printf("\nTree depth:%d\n",depth);
	printTree(rootNode,depth);
}

struct node *create_node(int data){
	struct node *new_node =  (struct node *) malloc(sizeof(struct node)) ;
	
	new_node -> data  = data;
	new_node -> left  = NULL;
	new_node -> right = NULL;
	
	return new_node;
}


struct node *insert_node(struct node *root, int data){

	if(root == NULL)
		return create_node(data);

	if(data  > root->data)
		root->right = insert_node(root->right ,data);	

	if(data < root->data)
		root->left = insert_node(root->left ,data);
	
	return root;
}

void printTree(struct node *root, int depth){
	treenode * top=0;
	Queue *queue;
	queue = initQueue(64);
	
	treenode *temp= (treenode *)malloc(sizeof(struct node *));
	treenode *newline = (treenode *)malloc(sizeof(struct node *));
	newline->data='\n';

	temp = (struct treenode *)root;
	enque(queue, temp);
	enque(queue, newline);
	
	printf("\nTree Contents:\n");
	while( isQueueEmpty(queue) != 1 ){
		top = popFrontQueue(queue);
		
		if(top->data != '\n') {
			printf("%d ", top->data);
			if(top->left) enque(queue,top->left);
			if(top->right) enque(queue, top->right);			
			enque(queue, newline);		
		}
	
		else
			printf("\n");

		deque(queue);		
	}	
	
}

int treeDepth(struct node *root){

	if(root == NULL)
		return 0;
		
	else{
		int lDepth, rDepth;
		int depth;
		lDepth = treeDepth(root-> left);
		rDepth = treeDepth(root-> right);
		depth = lDepth>rDepth ? lDepth+1 : rDepth+1 ;
		return depth;
	}

}
