struct node{
	int node_number;
	struct node *next;
};

struct list {
int num_edges;
struct node *nodelist;
};

struct Graph {
	int num_nodes;
	struct list *array;
};

typedef struct Graph Graph;

