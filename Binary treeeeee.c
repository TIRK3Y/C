#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
	
};

struct node* createnode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;
	return node;
	
};

struct node* insert(struct node* node, int data)
{
	if(node==NULL)
	{
		return createnode(data);
		
	}
	if(data < node->data)
	{
		node -> left = insert(node->left ,data);
		
	}
	else if (data>node ->data)
	{
		node -> right= insert(node -> right,data);
		
	}
	return node;
	
}

void preorder(struct node* node)
{

if(node ==NULL)
{
	return;
	
}
printf("%d",node -> data);
preorder(node -> left);
preorder(node->right);
}


void inorder(struct node*node)
{
	if(node == NULL)
	{
		return;
		
	}
inorder(node -> left);
printf("%d",node -> data);
inorder(node -> right);
}


void postorder(struct node* node)
{
	if(node == NULL)
	{
		return;
		
	}
	postorder(node -> left);
	postorder(node -> right);
	printf("%d", node -> data);
	
}

int main()
{
	struct node* root= NULL;
	root = insert(root,50);
	insert(root,3);
	insert(root,2);
	insert(root,4);
	insert(root,7);
	insert(root,6);
	insert(root,8);
	printf("pre order traversal:");
	preorder(root);
	printf("\n");
	printf("in-order traversal:");
	inorder(root);
	printf("\n");
	printf("post order traversal:");
	postorder(root);
	printf("\n");
	return 0;
}
