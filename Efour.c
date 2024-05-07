#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int value) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    if (top == NULL) {
        newnode->next = NULL;
    } else {
        newnode->next = top;
    }
    top = newnode;
    printf("node is inserted \n");
}

int pop() {
    if (top == NULL) {
        printf("\n stack underflow \n");
        return -1;
    } else {
        struct node* temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    if (top == NULL) {
        printf("the stack is empty\n");
    } else {
        printf("the stack is: ");
        struct node* temp = top;
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, value;
    printf("\n implementation of using linked list");
    while (1) {
        printf("\n1. push \n2. pop \n3. display \n4. exit");
        printf("\n enter your choice :");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n enter the value to insert :");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                printf("\n popped element is : %d", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n wrong choice \n");
        }
    }
    return 0;
}
