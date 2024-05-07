#include <stdio.h>
#include <stdlib.h>

// Structure for AVL node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

// Get the height of a node
int height(struct Node *N) {
    if (N == NULL) return 0;
    return N->height;
}

// Find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node with the given key
struct Node* newNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return (node);
}

// Right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of node N
int getBalance(struct Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

// Insert a node with the given key in the AVL tree
struct Node* insert(struct Node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == NULL) return (newNode(key));

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else { // Equal keys are not allowed in BST
        return node;
    }

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Case 1: Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Case 2: Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Case 3: Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Print the inorder traversal of the AVL tree
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Program main
int main() {
    struct Node *root = NULL;
    int n, key;
    printf("Enter number of nodes to be inserted: ");
    scanf("%d", &n);
    printf("Enter %d keys to be inserted: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
        printf("Inorder Traversal after inserting %d: ", key);
        inorderTraversal(root);
        printf("\n");
    }
    return 0;
}
