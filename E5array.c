#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void enqueue();
void dequeue();
void display();
int front= -1, rear= -1;
int queue[maxsize];
void main()
{
	int choice;
	while(1)
	{
		printf("\n1. enqueue \n2. dequeue \n3. display");
		printf("\n enter your choice:");
		scanf("%d", & choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("\n enter valid choice\n:");
		}
	}
}
void enqueue()
{
	int item;
	printf("enter the elements:");
	scanf("\n %d", & item);
	if(rear == maxsize-1)
	{
		printf("overflow");
		return;
	}
	if(front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		rear= rear+1;
	}
	queue[rear] = item;
	printf(" value inserted");
}
void dequeue()
{
	int item;
	if(front == -1 || front>rear)
	{
		printf("\n underflow");
		return;
	}
	else
	{
		item= queue[front];
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = front+1;
		}
	}
}
void display()
{
	int i;
	if(rear == -1)
	{
		printf("\n empty queue");}
		else{
			printf("printing values\n");
			for(i= front; i<= rear; i++)
			{
				printf("\n %d", queue[i]);
			}
		}
}
