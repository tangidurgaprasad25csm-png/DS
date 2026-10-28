#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed onto the stack.\n", value);
}

void pop(void) {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack underflow. Stack is empty.\n");
        return;
    }

    temp = top;
    printf("Popped value: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek(void) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top value: %d\n", top->data);
}

void display(void) {
    struct Node *current;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    current = top;
    printf("Stack (top to bottom):\n");

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n--- Stack Using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 0:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    while (top != NULL) {
        pop();
    }

    return 0;
}
