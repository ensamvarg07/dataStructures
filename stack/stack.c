#include<stdio.h>
#define STACKSIZE 256

static int top = 0;
static int stack[STACKSIZE];
static void initStack();
static void push(int);
static int pop();
static void printStackVertical();

void push(int data)
{
	if(top < STACKSIZE){
		stack[top] = data;
		top += 1;
	}
	else printf("\nError: Stack-Overflow. No more space in stack\n");
}

int pop()
{
	int local=0;
	if(top < 0) printf("\nError: Stack-Underflow. Stack is empty\n");

	else{
		local = stack[top];
		top--;
		return local;
	}
}

void initStack(){
	top=0;
}

void printStackVertical()
{
	int i;
	printf("\nStack from latest to oldest\n----\n");
	for(i=top-1; i>=0; i--)
	printf("%d\n----\n", stack[i]);
}
