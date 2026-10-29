#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node
{

int data;
struct Node *left;
struct Node *right;
};

struct Node *stack[MAX];
int top = -1;

void push(struct Node *node)
{
if (top == MAX - 1)
{
printf("Stack Overflow\n");
return;
}
stack[++top] = node;
}

struct Node* pop()
{
if (top == -1)
return NULL;
return stack[top--];
}

int isEmpty()

{
return top == -1;
}

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
return createNode(value);
if (value < root->data)
root->left = insert(root->left, value);
else if (value < root->data)
root->right = insert(root->right, value);

return root;
}


void inorder(struct Node *root)
{
struct Node *current = root;
while (current != NULL || !isEmpty())
{

while (current != NULL)
{
push(current);
current = current->left;
}

current = pop();
printf("%d ", current->data);

current = current->right;
}
}
// Non-recursive Preorder Traversal
void preorder(struct Node *root)
{
struct Node *current;
if (root == NULL)
return;
push(root);
while (!isEmpty())

{
current = pop();
printf("%d ", current->data);

if (current->right != NULL)
push(current->right);

if (current->left != NULL)
push(current->left);
}
}

void postorder(struct Node *root)
{
struct Node *current;
struct Node *lastVisited = NULL;
current = root;
while (current != NULL || !isEmpty())
{
if (current != NULL)
{
push(current);
current = current->left;
}
else
{

current = stack[top];
if (current->right != NULL &&lastVisited != current->right)
{
current = current->right;
}
else
{
printf("%d ", current->data);
lastVisited = current;
pop();
current = NULL;
}
}
}
}
int main()
{
struct Node *root = NULL;

int elements[] = {
6, 9, 5, 2, 8, 15,
24, 14, 7, 8, 5, 2
};
int n = 12;
int choice;

int i;
do
{

printf("\n1. Create BST");
printf("\n2. Inorder Traversal");
printf("\n3. Preorder Traversal");
printf("\n4. Postorder Traversal");
printf("\n5. Exit");
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
top = -1;
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
top = -1;
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

top = -1;
printf("\nPostorder Traversal: ");
postorder(root);
}
break;
case 5:
printf("\nExiting program...");
break;
default:
printf("\nInvalid choice! Please try again.");
}
} while (choice != 5);
return 0;
}