//doubly linked list    // Comment the line
#include<stdlib.h>    // Include the standard library
#include<stdio.h>    // Include the standard library

struct Node{    // Define Node structure
    int data;    // Declare int variable data
    struct Node* prev;    // Declare pointer variable prev of type Node
    struct Node* next;    // Declare pointer variable next of type Node
};

struct Node* head=NULL;    // Initialize head variable with NULL value

void insert_at_first(){    // Define function insert_at_first()
    struct Node* newnode;    // Declare pointer variable newnode of type Node
    newnode=(struct Node*)malloc(sizeof(struct Node));    // Allocate memory for newnode
    printf("Enter data:\n");    // Print message on console
    scanf("%d",&(newnode->data));    // Take data from user
    if(head==NULL){    // Check if head is NULL
        head=newnode;    // Assign value of newnode to head
        newnode->prev=NULL;    // Assign NULL value to prev pointer
        newnode->next=NULL;    // Assign NULL value to next pointer
        return;    // Exit the function
    }
    newnode->next=head;    // Assign the value of head to next pointer
    head->prev=newnode;    // Assign the value of newnode to prev pointer
    newnode->prev=NULL;    // Assign NULL value to prev pointer
    head=newnode;    // Assign value of newnode to head
}

void insert_at_end(){    // Define function insert_at_end()
    struct Node* newnode;    // Declare pointer variable newnode of type Node
    newnode=(struct Node*)malloc(sizeof(struct Node));    // Allocate memory for newnode
    printf("Enter data:\n");    // Print message on console
    scanf("%d",&(newnode->data));    // Take data from user
    newnode->next=NULL;    // Assign NULL value to next pointer
    if(head==NULL){    // Check if head is NULL
        newnode->prev=NULL;    // Assign NULL value to prev pointer
        head=newnode;    // Assign value of newnode to head
    }
    else{
        struct Node* temp=head;    // Declare pointer variable temp of type Node
        while(temp->next!=NULL)    // Loop till temp's next pointer is not NULL
            temp=temp->next;
        temp->next=newnode;    // Assign value of newnode to temp's next pointer
        newnode->prev=temp;    // Assign value of temp to newnode's prev pointer
    }
}

void insert_at_anyPoint(){    // Define function insert_at_anyPoint()
    int pos;    // Declare int variable pos
    printf("Enter position:\n");    // Print message on console
    scanf("%d",&pos);    // Take position from user
    if(pos==1){    // Check if position is 1
        insert_at_first();     // Call function insert_at_first()
        return;     // Exit the function
    } 
    if(head==NULL){    // Check if head is NULL
        printf("List is empty.\n");    // Print message on console
        return;    // Exit the function
    }
    int cnt =1; 
    struct Node* temp = head; 
    while (cnt < pos-1) { 
        cnt++; 
        if(temp->next==NULL){    // Check if temp's next pointer is NULL
            printf("Invalid position.\n");    // Print message on console
            return;    // Exit the function
        }
        temp = temp->next; 
    } 
    if(temp->next == NULL)    // Check if temp's next pointer is NULL
    { 
        insert_at_end();    // Call function insert_at_end()
        return;     // Exit the function
    } 
    int value; 
    printf("Enter the data:\n");     // Print message on console
    scanf("%d",&value);    // Take data from user
    struct Node* newnode; 
    newnode=(struct Node*)malloc(sizeof(struct Node)); 
    newnode->data=value;    // Assign value to newnode's data variable
    newnode->prev=temp;    // Assign value of temp to newnode's prev pointer
    newnode->next=temp->next;    // Assign value of temp's next pointer to newnode's next pointer
    temp->next->prev=newnode;    // Assign value of newnode to temp's next pointer's prev pointer
    temp->next=newnode;    // Assign value of newnode to temp's next pointer
}

void delete(){    // Define function delete()
    int key,flag=0;    // Declare int variables key and flag
    printf("Enter the data:\n");    // Print message on console
    scanf("%d",&key);    // Take data from user
    if(head==NULL){    // Check if head is NULL
        printf("List is empty.\n");    // Print message on console
        return;
    }
    struct Node* temp=head;    // Declare pointer variable temp of type Node
    while(temp){    // Loop till temp is not NULL
        if(temp->data==key){    // Check if temp's data variable is equal to key
            if(temp->prev==NULL){    // Check if temp's prev pointer is NULL
                head=temp->next;    // Assign value of temp's next pointer to head
                head->prev=NULL;    // Assign NULL value to head's prev pointer
                flag++;    // Increase flag by 1
                break;    // Break the loop
            }
            else{    // else body
                temp->prev->next=temp->next;    // Assign value of temp's next pointer to temp's prev pointer's next pointer
                temp->next->prev=temp->prev;    // Assign value of temp's prev pointer to temp's next pointer's prev pointer
                flag++;    // Increase flag by 1
                break;    // Break the loop
            }
        }
        temp=temp->next;    // Assign value of temp's next pointer to temp
    }
    if(flag==0){    // Check if flag is 0
        printf("Data not found.\n");    // Print message on console
        return;
    }
    free(temp);    // Free the memory allocated for temp
}

void search(){    // Define function search()
    int key;    // Declare int variable key
    printf("Enter the data:\n");    // Print message on console
    scanf("%d",&key);    // Take data from user
    if(head==NULL){    // Check if head is NULL
        printf("List is empty.\n");    // Print message on console
        return;
    }
    struct Node* temp=head;    // Declare pointer variable temp of type Node
    while(temp){    // Loop till temp is not NULL
        if(temp->data==key){    // Check if temp's data variable is equal to key
            printf("Data found.\n");    // Print message on console
            return;
        }
        temp=temp->next;    // Assign value of temp's next pointer to temp
    }
    printf("Data not found.\n");    // Print message on console
}

void display(){    // Define function display()
    if(head==NULL)
        printf("List is empty.\n");    // Print message on console
    else{
        struct Node* temp=head;    // Declare pointer variable temp of type Node
        while(temp){    // Loop till temp is not NULL
            printf("%d -> ",temp->data);    // Print the value of temp's data variable
            temp=temp->next;    // Assign value of temp's next pointer to temp
        }
        printf("NULL\n");    // Print NULL
    }
}

void main(){    // Define main() function
    int choice;    // Declare int variable choice
    while(1){
        printf("Enter your choice:\n1.Insert at first\n2.Insert at last\n3.Insert at any point\n4.Delete\n5.Search\n6.Display\n7.Exit\n");    // Print message on console
        scanf("%d",&choice);    // Take input from user
        switch(choice){    // switch-case block
            case 1:    // Case 1
                insert_at_first();    // Call function insert_at_first()
                break;    // break
            case 2:    // Case 2
                insert_at_end();    // Call function insert_at_end()
                break;    // break
            case 3:    // Case 3
                insert_at_anyPoint();    // Call function insert_at_anyPoint()
                break;    // break
            case 4:    // Case 4
                delete();    // Call function delete()
                break;    // break
            case 5:    // Case 5
                search();    // Call function search()
                break;    // break
            case 6:    // Case 6
                display();    // Call function display()
                break;    // break
            case 7:    // Case 7
                exit(0);    // Exit the program
            default:    // Default case
                printf("Invalid choice.\n");    // Print message on console
        }
    }
}
