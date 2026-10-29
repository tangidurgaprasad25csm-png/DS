#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node *left;
struct Node *right;
};

struct Node* createNode(int value)
{
struct Node *newNode;
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}


struct Node* insert(struct Node *root, int value)
{
if (root == NULL)

{
return createNode(value);
}
if (value < root->data)
{
root->left = insert(root->left, value);
}
else if (value <root->data)
{
root->right = insert(root->right, value);
}
return root;
}

void inorder(struct Node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

void preorder(struct Node *root)
{
if (root != NULL)
{
printf("%d ", root->data);

preorder(root->left);
preorder(root->right);
}
}

void postorder(struct Node *root)
{
if (root != NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}

struct Node* search(struct Node *root, int key)
{
if (root == NULL || root->data == key)
{
return root;
}
if (key <root->data)
{
return search(root->left, key);
}
else
{
return search(root->right, key);
}

}
int main()
{
struct Node *root = NULL;
struct Node *result;
int choice, key;

int elements[] = {
13, 3, 4, 12, 14, 10, 5, 1,
8, 2, 7, 9, 11, 6, 18
};
int n = 15;
int i;

do
{

printf("\n1. Create BST");
printf("\n2. Inorder Traversal");
printf("\n3. Preorder Traversal");
printf("\n4. Postorder Traversal");
printf("\n5. Search");
printf("\n6. Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
root = NULL;

for (i = 0; i < n; i++)
{
root = insert(root, elements[i]);
}
printf("\nBST created successfully.");
break;
case 2:
if (root == NULL)
{
printf("\nPlease create the BST first.");
}
else
{
printf("\nInorder Traversal: ");
inorder(root);
}
break;
case 3:
if (root == NULL)
{
printf("\nPlease create the BST first.");
}
else
{
printf("\nPreorder Traversal: ");
preorder(root);
}
break;
case 4:

if (root == NULL)
{
printf("\nPlease create the BST first.");
}
else
{
printf("nPostorder Traversal: ");
postorder(root);
}
break;
case 5:
if (root == NULL)
{
printf("\nPlease create the BST first.");
}
else
{
printf("\nEnter the element to search: ");
scanf("d", &key);
result = search(root, key);
if (result != NULL)
{
printf("\nKEY %d is found in the BST.", key);
}
else
{
printf("\nKEY %d is not found in the BST.", key);
}
}

break;
case 6:
printf("\nExiting program...");
break;
default:
printf("\nInvalid choice! Please try again.");
}
} while (choice != 6);
return 0;
}