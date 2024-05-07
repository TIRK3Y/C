#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void InsertAtHead()
{
    int value;
    printf("Enter the value\n");
    scanf("%d",&value);
    struct Node* newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    if(head == NULL){
        head = newnode;
    } else{

head=newnode;
        newnode->next=NULL;
}
}
void InsertAtEnd()
{
    struct Node* temp=head;
    int value;
    printf("Enter the value\n");
    scanf("%d",&value);
    struct Node* newNode1;
    newNode1=(struct Node*)malloc(sizeof(struct Node));
    newNode1->data = value;
    while(temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next= newNode1;
    newNode1->next=NULL;
}
void InsertAtAny()
{
    struct Node* temp=head;
    struct Node* prev=head;
    int pos,value;
    printf("enter the position ");
    scanf("%d",&pos);
    printf("Enter the Value to be inserted");
    scanf("%d",&value);
    struct Node* newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    for(int i=1;i<pos;i++)
    {
        if(temp->next==NULL)
        {
            return;
        }
        else{
            prev=temp;
            temp=temp->next;
            }
    }
    prev->next=newNode;
    newNode->next=temp;
}
void deleteNode()
{
    struct Node* temp=head;
    struct Node* prev = NULL;
    int value;
    printf("Enter the element to be deleted\n");
    scanf("%d",&value);
        if(temp==NULL)
    {
        printf("Empty list....");
        return;
    }
    else if(temp->data==value)
    {
        
        head=temp->next;
        free(temp);
        printf("Node Deleted.....!");
        return;
    }
    else{
        while(temp->next!=NULL)
        {
            if(temp->data==value)
            {
                prev->next=temp->next;
                free(temp);
                printf("Node Delete.....!");
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }
}
void search()
{
    struct Node* temp=head;
    int value,flag=0;
    printf("Enter the element\n");
    scanf("%d",&value);
    while(temp->next!=NULL)
    {
        if(temp->data==value)
        {
                flag=0;
            break;
        }
        else
        {
            flag=1;
        }
    
        temp=temp->next;     
    }
    if(flag==0)
    {
        printf("Found.......");
    }
    else
 {
        printf("not found......");
    }
    

}
void display()
{
    struct Node* temp=head;
    while(temp != NULL)
    {
        printf("%d",temp -> data);
        printf("\t");
        temp = temp->next;
    }
    printf("%d",temp->data);
    
}
int main()
{
    while (1)
    { 
    int choice;
    printf("Enter the choice \n 1.InsertAtHead\n 2.InsertAtEnd \n 3.InsertAtMid \n 4.Search \n 5.Delete\n 6.Display\n 7.Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
       
 InsertAtHead();
        break;
    case 2:
        InsertAtEnd();
        break;
    case 3:
        InsertAtAny();
        break;
    case 4:
        search();
        break;
    case 5:
        deleteNode();
        break;
    case 6:
        display();
        break;
    case 7:
        exit(0);
    default:
        printf("Invalid Choice.......!");
        
    }
    }
}
