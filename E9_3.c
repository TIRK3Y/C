#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = 0, *temp;

void insertElements()
{
    struct node *newnode, *nextnode;
    int v;

    printf("\nEnter the value: ");
    scanf("%d", &v);

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = v;
    temp->left = 0;
    temp->right = 0;

    if(root == 0)
    {
        root = temp;
    }
    else
    {
        newnode = root;
        while(newnode != 0)
        {
            nextnode = newnode;
            if(v < newnode->data)
                newnode = newnode->left;
            else
                newnode = newnode->right;
        }

        if(v < nextnode->data)
        {
            nextnode->left = temp;
        }
        else
        {
            nextnode->right = temp;
        }
    }
}

void preOrder(struct node *temp)
{
    if(temp != 0)
    {
        printf("%d\t", temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

struct node *search(struct node *temp, int x)
{
    if(temp == NULL || temp->data == x)
        return temp;

    if(x < temp->data)
        return search(temp->left, x);

    return search(temp->right, x);
}

int main()
{
    int ch, x;
    struct node *result;

    while(1)
    {
        printf("\n1.Insert Elements\n2.Preorder\n3.Search\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            insertElements();
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            printf("\nEnter the value to search: ");
            scanf("%d", &x);
            result = search(root, x);
            if (result != NULL)
                printf("\nValue found\n");
            else
                printf("\nValue not found\n");
            break;
        case 4:
            printf("\nExiting...");
            exit(1);
            break;
        default:
            printf("\nInvalid operation, Re-enter.\n");
        }
    }

    return  0;
}