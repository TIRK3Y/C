#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue()
{
    int d;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    
    printf("\nEnter the data: ");

    scanf("%d", &d);
    newnode -> data = d;
    newnode -> next = NULL;
 if(front == NULL)
    {
        front = rear = newnode;
        newnode -> next = front;
    }
    else
    {
        rear -> next = newnode;
        rear = newnode;
        newnode -> next = front;
    }
    printf("\nEnqueued element is: %d\n", d);
}
void dequeue()
{
    if(front == NULL && rear == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    struct node *temp = front;
    if(front == rear)

    {
        front = rear = NULL;
    }
    else

    {
        front = front -> next;
        rear -> next = front;
    }

    printf("%d is deleted\n", temp -> data);
    free(temp);
}
void display()
{
    struct node *temp;
    temp = front;

    if(front == NULL && rear == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }
    else
    {
        printf("\nElements in the queue are: \n");
        do
        {
            printf("%d\t", temp -> data);
            temp = temp -> next;

        } while(temp != front);
    }
}

int main()
{
    
while(1)
    {
        int choice;

        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

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

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice. Re-enter.\n");

        }
    }

    return 0;
}
