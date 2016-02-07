#include<iostream>
#include<stdio.h>


struct node{

struct node* next;
struct node* prev;
int value;

}node_t;

int push();
int pop();
int print();


int main()
{
printf("hello lets make a doubley linked list");

return 0;
}

