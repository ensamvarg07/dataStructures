#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *head=NULL;

node* create_node(int);
void insert(node* );
void delete(int );
void display();

int main()
{
node* ret;
ret = create_node(10);
insert(ret);
ret = create_node(20);
insert(ret);
ret = create_node(30);
insert(ret);
ret = create_node(40);
insert(ret);
ret = create_node(50);
insert(ret);
display();
printf("\ndeleting 30");
delete(30);
display();

return 0;
}

node* create_node(int data){
node *temp = (node*) malloc(sizeof(node));

temp->data = data;
temp->next = NULL;  

return temp;
}


void insert(node* current){
node *temp=(node *)malloc(sizeof(node));

if(head == NULL){
    head =(node *)malloc(sizeof(node));
    head = current;
}
    
else{
    temp=head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = current;
}

}

void delete(int rec){

node *prev =(node *)malloc(sizeof(node)); 
node *z    =(node *)malloc(sizeof(node));
z=head;

while(z->next != NULL){
    if(z->data == rec){
        prev->next = z->next;
    }
    
    prev=z;
    z=z->next;
}


}

void display(){
node *z=(node *)malloc(sizeof(node));
z=head;

printf("\n");
while( z->next != NULL){
    printf(" %d-> ",z->data);
    z=z->next;
}
printf("%d -> NULL\n",z->data);

}
