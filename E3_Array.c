#include<stdio.h>
#include<conio.h>

int stack[100], choice, n, top = -1, x, i;
void push();
void pop();
void display();
int main() {
    printf("\n Enter the size of the stack: ");
    scanf("%d", &n);

    printf("\n Stack operations using array");
    do {
        printf("\n1. push \n2. pop \n3. display \n4. exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n Exit point");
                break;
            default:
                printf("\n Please enter a valid choice (1/2/3/4)");
        }
    } while(choice != 4);

    return 0;
}

void push() {
    if(top >= n - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if(top <= -1) {
        printf("Underflow\n");

    } else {
        printf("The popped element is: %d\n", stack[top]);
        top--;
    }
}
void display() {
    if(top >= 0) {
        printf("\n Elements in the stack: \n");
        for(i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("\n The stack is empty\n");
    }
}
