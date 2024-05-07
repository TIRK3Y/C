//doubly linked list
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head=NULL;

void insert_at_first(){
    struct Node* newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d",&(newnode->data));
    if(head==NULL){
        head=newnode;
        newnode->prev=NULL;
        newnode->next=NULL;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=NULL;
    head=newnode;
}

void insert_at_end(){
    struct Node* newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
    }
    else{
        struct Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void insert_at_anyPoint(){
    int pos;
    printf("Enter position:\n");
    scanf("%d",&pos);
    if(pos==1){
        insert_at_first(); 
        return; 
    } 
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    int cnt =1; 
    struct Node* temp = head; 
    while (cnt < pos-1) { 
        cnt++; 
        if(temp->next==NULL){
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next; 
    } 
    if(temp->next == NULL)
    { 
        insert_at_end();
        return; 
    } 
    int value; 
    printf("Enter the data:\n"); 
    scanf("%d",&value); 
    struct Node* newnode; 
    newnode=(struct Node*)malloc(sizeof(struct Node)); 
    newnode->data=value;
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
}

void delete(){
    int key,flag=0;
    printf("Enter the data:\n");
    scanf("%d",&key);
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node* temp=head;
    while(temp){
        if(temp->data==key){
            if(temp->prev==NULL){
                head=temp->next;
                head->prev=NULL;
                flag++;
                break;
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                flag++;
                break;
            }
        }
        temp=temp->next;
    }
    if(flag==0){
        printf("Data not found.\n");
        return;
    }
    free(temp);
}

void search(){
    int key;
    printf("Enter the data:\n");
    scanf("%d",&key);
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node* temp=head;
    while(temp){
        if(temp->data==key){
            printf("Data found.\n");
            return;
        }
        temp=temp->next;
    }
    printf("Data not found.\n");
}

void display(){
    if(head==NULL)
        printf("List is empty.\n");
    else{
        struct Node* temp=head;
        while(temp){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

void main(){
    int choice;
    while(1){
        printf("Enter your choice:\n1.Insert at first\n2.Insert at last\n3.Insert at any point\n4.Delete\n5.Search\n6.Display\n7.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert_at_first();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_anyPoint();
                break;
            case 4:
                delete();
                break;
            case 5:
                search();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}