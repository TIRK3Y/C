#include <stdio.h>
#include <stdlib.h>

// Queue node using a single linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue using an array
#define MAX_SIZE 100
typedef struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Create a new node for the single linked list
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize the queue using an array
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty using an array
int isQueueEmpty(Queue* q) {
    if (q->rear == -1) {
        return 1;
    }
    return 0;
}

// Check if the queue is full using an array
int isQueueFull(Queue* q) {
    if (q->rear == MAX_SIZE-1) {
        return 1;
    }
    return 0;
}

// Add an item to the queue using an array
void enqueue(Queue* q, int data) {
    if (isQueueFull(q)) {
        printf("Queue overflow!");
        exit(1);
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = data;
}

// Remove an item from the queue using an array
int dequeue(Queue* q) {
    int data;
    if (isQueueEmpty(q)) {
        printf("Queue underflow!");
        exit(1);
    }
    data = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return data;
}

// Add an item to the queue using a single linked list
void enqueueLinkedList(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Remove an item from the queue using a single linked list
int dequeueLinkedList(Node** head) {
    int data;
    if (*head == NULL) {
        printf("Queue underflow!");
        exit(1);
    }
    else {
        Node* temp = *head;
        *head = temp->next;
        data = temp->data;
        free(temp);
    }
    return data;
}

// Main function to test the Queue
int main() {
    Queue q;
    initQueue(&q);

    printf("Queue using array:\n");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front item is %d\n", q.items[q.front]);

    dequeue(&q);
    printf("Front item is %d\n", q.items[q.front]);

    printf("\nQueue using single linked list:\n");

    Node* head = NULL;
    enqueueLinkedList(&head, 10);
enqueueLinkedList(&head, 20);
enqueueLinkedList(&head, 30);

printf("Front item is %d\n", head->data);

dequeueLinkedList(&head);
printf("Front item is %d\n", head->data);

return 0;