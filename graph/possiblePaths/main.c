#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<time.h>
#include "graphStruct.h"
#include "fetch.c" //contains definitions for fetchLine() and fetchWord()

#define BUFFER_SIZE 256

int verbose=0;
int global_counter=0;
clock_t start_time, end_time;

// graphCreate allocates memory for required number of nodes and initializes all nodes to null
Graph * graphCreate(int nodes)
{
	Graph *gr = (Graph *)malloc(sizeof(Graph));
	gr->array = (struct list *)malloc(nodes*sizeof(struct list));

	gr->num_nodes = nodes;
	for(int i=0; i<nodes; i++){
		gr->array[i].nodelist=NULL;
		gr->array[i].num_edges=0;
	}
	
	return gr;
}

// createEdge connects two nodes (or) creates an edge between two nodes
void createEdge(Graph *gr, int start, int end){
	struct node *newnode = malloc(sizeof(struct node));
	newnode->node_number = end;
	newnode ->next = NULL;

	if( gr->array[start].nodelist == NULL){ 
	gr->array[start].nodelist = newnode;
	}

	else{
		struct node *temp = malloc(sizeof(struct node));
		temp = gr->array[start].nodelist;
		while( temp-> next != NULL)
			temp = temp->next;
	
		temp->next = newnode;
	}

	gr->array[start].num_edges += 1;
}

void printGraph(Graph *gr)
{
	printf("\nGRAPH CONTENTS:\n");
	for(int i=0; i<9; i++){
		struct node *temp = malloc(sizeof(struct node));
		temp = gr->array[i].nodelist;
		printf("Node %c: ",i+'A');
		while( temp-> next != NULL){
			printf("%c-", temp->node_number+'A' );
			temp = temp->next;
		}
		printf("%c\n",temp->node_number+'A');
	}
	printf("\n");
}

void print_possiblePaths(int array[], int limit)

{
	int i;
	global_counter += 1;
	(global_counter<10)? printf("\nPath %d : ",global_counter) : printf("\nPath %d: ",global_counter);
	for(i=0; i<limit; i++)
		printf("%c ",array[i]+'A'); 
}

/*
*   name      : traverse()
*   called by : possiblePaths()
*   calls     : print_possiblePaths()
*   Recursive : YES
*   Usage     : traverse() dives deep into the graph until it reaches the required length. 
*				Once it reaches the required length, it prints the path.
*
*				int visited[] - an array that keeps track of visited notes to avoid a cycle
*				int content[] - an array that stores the path that needs to be printed
*				int index     - variable to keep track of the index of content[]
*/
void traverse(Graph *graph, int ref, int len, int visited[], int content[], int index ){
	int num_edges = graph->array[ref].num_edges;

	visited[ref]=1;		// Mark node as visited
	content[index]=ref; // Store it to print the path later
	index += 1;			

	struct node *temp = malloc(sizeof(struct node *));
	
	//Print the contents once it travelled for required length
	if(index==len)
		print_possiblePaths(content, index);

	else{
		temp = graph->array[ref].nodelist;
		for(int i=0; i<num_edges; i++ ){
			ref = temp->node_number;	
			//If a node is univisted visit it by calling traverse()
			if( visited[ref] == 0) traverse( graph, ref, len, visited, content, index);
			if(temp->next != NULL) temp = temp->next;
		}
	}
	visited[ref]=0;
	index--;
}

/*
*   name      : possiblePaths()
*   called by : main()
*   calls     : traverse()
*   Usage     : possiblePaths() takes in graph, starting node  and length to traverse and 
*				calls traverse() which is a recursive function
*/
void possiblePaths(Graph *graph, int ref, int len)
{

	printf("\n"); //Note: This line is important as it flushes out the IO buffer. 
				  //In Unix systems, without this line, you will not see the output
	int i, j,local_ref, num_nodes, num_edges;
	int visited[num_nodes], content[num_nodes], index;
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	num_nodes = graph->num_nodes;
	local_ref = ref;
	
	for(int i=0; i<num_nodes; i++){
		visited[i]=0;
		content[i]=0;
	}	
	index=0;
	
	start_time =clock();
	traverse(graph, ref, len, visited, content, index);	
	end_time =clock();
	
	if(verbose==1) printf("\nRun Time: %f us", ( (double)(end_time-start_time)/CLOCKS_PER_SEC) * 1000000 );
}


int main(int argc, char *argv[])
{
	int fd,i;
	char buf,buffer[BUFFER_SIZE], line[32], word[16];
	char *lineptr, *wordptr;
	int num_nodes, nodeIndex;
	int g_reference, g_distance;

	Graph *graph;

	if(argc <3)
		printf("\nError:Illegal input format\nCorrect Format: ./main B 4");
	else{
		*argv++;
		g_reference=**argv-'A';
		*argv++;
		g_distance=atoi(*argv);
		if(argc==4){
			*argv++;
			if( **argv == 'v' || **argv == 'V')
				verbose = 1;
			else
				verbose = 0;
		}
	}
	
	fd=open("graph_info.txt", O_RDONLY);
	fd<0 ? printf("\nError in opening input file") : printf(" ");

	for(i=0; read(fd, &buf, 1) > 0 ; i++)
		buffer[i]= buf;

	buffer[i]='\0';
	lineptr=buffer;
	
	lineptr = fetchLine(line,lineptr); //returns a single line from the file
	num_nodes = atoi(line);

	if(g_distance > num_nodes){
		printf("\nFatal Error: Second argument to ./main should not be greater than maximum number of nodes\nProgram will not run. Returning -1\n");
		return -1;
	}

	graph=graphCreate(num_nodes);

	while( *lineptr != '\0'){
		lineptr = fetchLine(line,lineptr);
		wordptr = line;
		wordptr = fetchWord(word, wordptr); // returns a single word from the line
		if( word[0] != ' ' && word[0] != '\n' && word[0] != '\0') 
			nodeIndex = word[0]-'A';
		while( *wordptr != '\n'){
			wordptr = fetchWord(word, wordptr);
			createEdge(graph, nodeIndex, word[0]-'A');		
		}
	}

	printGraph(graph);
	possiblePaths(graph,g_reference, g_distance);
	global_counter = 0;
	
printf("\n\n");
close(fd);
return 0;
}
