#include<stdio.h>
#include<malloc.h>


typedef struct node{

struct node* next;
struct node* prev;
int value;

}node_t;


node_t * head = NULL;


int pop();
void printl();
void delete();

void init();
void clean();

void add_node_forward(int value)
{
	node_t * node ;
	node = malloc(sizeof(node_t));
	node_t * current = head;
	if(current==NULL)
	{
		node->value= value;
		node->next= NULL;
		node->prev= NULL;
		head=node;			
	}
	else 
	{
		while(current->next!=NULL)
	 	{
			current=current->next;
		}
		
		node->value=value;
		current->next=node;
		node->next=NULL;
		node->prev=current;
		
	}

}

void delete(int value)
{
	int j=0;
	node_t *current= head;
	node_t *temp;
	if(current==NULL)
	{
		return NULL;
	}	
	else 
	{
		while(current->next!=NULL)
		{
			if(current->value==value)
			{
				temp=current;				
				current->prev->next=current->next;
				current->next->prev=current->prev;
				j=1;	
			}			
			
			current=current->next;
			/*if(j==1) It is giving an error check this out
			 {			 	
				 free(temp);
			 }*/	 		

		}
	}
}


void printl()
{
	node_t *current=head;
	int i=0;
	while(current->next!=NULL)
	{
		printf("current->value=%d....%d\n",current->value,i++);
		current=current->next;	
	}
}

void clean()
{
	node_t *current= head;
	node_t *tmp;
	
	while(current->next!=NULL)
	{
		tmp=current;		
		current=current->next;		
		free(tmp);		
	}

}

int main()
{
	int i;
	for(i=0;i<7;i++)
	add_node_forward(i);
	
	printl();
	delete(3);	
	printf("printing again\n");	
	printl();	
	clean();
	
printf("hello lets make a doubley linked list\n");

return 0;
}

