#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate value %d ignored.\n", value);

    return root;
}

struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

struct Node *findMinimum(struct Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct Node *deleteNode(struct Node *root, int key) {
    struct Node *temp;

    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        
        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        
        temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void displayInorder(struct Node *root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    struct Node *root;
    struct Node *found;
    int choice;
    int value;

    root = NULL;

    while (1) {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for a key\n");
        printf("4. Display tree (inorder)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeTree(root);
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeTree(root);
                    return 1;
                }
                root = insert(root, value);
                break;

            case 2:
                printf("Enter the value to delete: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeTree(root);
                    return 1;
                }

                if (search(root, value) == NULL) {
                    printf("%d was not found in the tree.\n", value);
                } else {
                    root = deleteNode(root, value);
                    printf("%d deleted.\n", value);
                }
                break;

            case 3:
                printf("Enter the key to search for: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeTree(root);
                    return 1;
                }

                found = search(root, value);
                if (found != NULL)
                    printf("%d was found in the tree.\n", value);
                else
                    printf("%d was not found in the tree.\n", value);
                break;

            case 4:
                printf("Inorder traversal: ");
                displayInorder(root);
                printf("\n");
                break;

            case 5:
                freeTree(root);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}