//singly linked list
#include<stdlib.h>    // Include header files for library functions
#include<stdio.h>

struct Node{    // Defining user defined data type
    int data;    // variable to store data
    struct Node* next;    // variable for storing address of next node
};

struct Node* head=NULL;    // Initializing head pointer variable

void insert_at_first(){    // Defining function to insert node at first position
    struct Node* newnode;    // Creating new node
    newnode=(struct Node*)malloc(sizeof(struct Node));    // Allocating memory to new node
    printf("Enter data:\n");    // Print message on console
    scanf("%d",&(newnode->data));    // Taking data as input
    if(head==NULL){    // check if head is null
        head=newnode;    // assign newnode to head if it is null
        newnode->next=NULL;    // assign next of new node to NULL
        return;    // return from function
    }
    newnode->next=head;    // assign next of new node to head
    head=newnode;    // assign head to newnode
}

void insert_at_end(){    // Defining function to insert node at last position
    struct Node* newnode;    // Create new node
    newnode=(struct Node*)malloc(sizeof(struct Node));    // Allocate memory to new node
    printf("Enter data:\n");    // Print message on console
    scanf("%d",&(newnode->data));    // Take data as input
    newnode->next=NULL;    // Assign next of newnode to NULL
    if(head==NULL)    // Check if head is null
        head=newnode;    // assign new node to head if it is null
    else{
        struct Node* temp=head;    // Create temporary variable to traverse linked list
        while(temp->next!=NULL)    // Iterate till temp->next is not null
            temp=temp->next;    // Assign next node address to temp
        temp->next=newnode;    // Assign next of last node to newnode
    }
}

void insert_at_anyPoint(){    // Function to insert node at any position
    int pos;    // variable to store position
    printf("Enter position:\n");    // Print message on console
    scanf("%d",&pos);    // Take position as input
    if(pos==1){    // Check if position is 1
        insert_at_first();    
        return;    
    } 
    if(head==NULL){    // Check if head is null
        printf("List is empty.\n");    // Print message on console
        return;
    }
    int cnt =1; 
    struct Node* temp = head; 
    while (cnt < pos-1) {    // Iterate till cnt is less than position-1
        cnt++; 
        if(temp->next==NULL){    // Check if next node of temp is null
            printf("Invalid position.\n");    // Print message on console
            return;
        }
        temp = temp->next; 
    } 
    if(temp->next == NULL)
    {    // if next node is null
        insert_at_end();    // insert at end of list
        return;    
    } 
    int value; 
    printf("Enter the data:\n");    // Print message on console
    scanf("%d",&value);    // Take data as input
    struct Node* newnode; 
    newnode=(struct Node*)malloc(sizeof(struct Node));    // Create new node
    newnode->data=value;    // Assign value to data of newnode
    newnode->next=temp->next;    // Assign next of newnode to next of temp
    temp->next=newnode;    // Assign next of temp to newnode
}

void delete(){    // Function to delete node
    int key,flag=0;
    printf("Enter the data:\n");    // Print message on console
    scanf("%d",&key);    // Take data as input
    if(head==NULL){    // Check if head is null
        printf("List is empty.\n");    // Print message on console
        return;
    }
    struct Node* temp=head;
    struct Node* prev=NULL;
    while(temp){    // Iterate till temp is not null
        if(temp->data==key){    // Check if data of temp is equal to key
            if(prev==NULL){    // Check if prev is null
                head=temp->next;    // Assign next node address to head
                flag++;
                break;
            }
            else{
                prev->next=temp->next;    // Assign next of prev to next of temp
                flag++;
                break;
            }
        }
        prev=temp;    // Assign temp to prev
        temp=temp->next;    // Assign next node address to temp
    }
    if(flag==0){    // Check if flag is equal to 0
        printf("Data not found.\n");    // Print message on console
        return;
    }
    free(temp);    // Free memory of temp
}

void search(){    // Function to search node in linked list
    int key;
    printf("Enter the data:\n");    // Print message on console
    scanf("%d",&key);    // Take data as input
    if(head==NULL){    // Check if head is null
        printf("List is empty.\n");    // Print message on console
        return;
    }
    struct Node* temp=head;    // Create variable to traverse linked list
    while(temp){    // Iterate till temp is not null
        if(temp->data==key){    // Check if data of temp is equal to key
            printf("Data found.\n");    // Print message on console
            return;
        }
        temp=temp->next;    // Assign address of next node to temp
    }
    printf("Data not found.\n");    // Print message on console
}

void display(){    // Function to display linked list
    if(head==NULL)
        printf("List is empty.\n");    // Print message on console
    else{
        struct Node* temp=head;    // Create variable to traverse linked list
        while(temp){    // Iterate till temp is not null
            printf("%d -> ",temp->data);    // Print data of node on console
            temp=temp->next;    // Assign address of next node to temp
        }
        printf("NULL\n");    // Print NULL on console
    }
}

void main(){    // main function
    int choice;
    while(1){    // infinite loop
        printf("Enter your choice:\n1.Insert at first\n2.Insert at last\n3.Insert at any point\n4.Delete\n5.Search\n6.Display\n7.Exit\n");    // Print message on console
        scanf("%d",&choice);    // Take choice as input
        switch(choice){    // switch case statement
            case 1:
                insert_at_first();    // Call function to insert node at first position
                break;
            case 2:
                insert_at_end();    // Call function to insert node at last position
                break;
            case 3:
                insert_at_anyPoint();    // Call function to insert node at any position
                break;
            case 4:
                delete();    // Call function to delete node
                break;
            case 5:
                search();    // Call function to search node in linked list
                break;
            case 6:
                display();    // Call function to display linked list
                break;
            case 7:
                exit(0);    // Exit from program
            default:
                printf("Invalid choice.\n");    // Print message on console
        }
    }
}
