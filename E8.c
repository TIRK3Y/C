#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(struct node* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    else if (data <= root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

void inorder(struct node* temp) {
    if (temp == NULL) {
        return;
    }
    inorder(temp->left);
    printf("%d \t", temp->data);
    inorder(temp->right);
}

int main() {
    int ch, num, data;
    struct node* root = NULL;
    while (1) {
        printf("Enter the choice\n 1.insert\n 2.search\n 3.inorder\n 4.exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data\n");
                scanf("%d", &num);
                root = insert(root, num);
                break;
            case 2:
                printf("Enter the number to be searched\n");
                scanf("%d", &data);
                if (search(root, data) == true) {
                    printf("Found\n");
                }
                else {
                    printf("Not found\n");
                }
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
