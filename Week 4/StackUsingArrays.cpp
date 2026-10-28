#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow. Stack is full.\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed onto the stack.\n", value);
}

void pop(void) {
    if (top == -1) {
        printf("Stack underflow. Stack is empty.\n");
        return;
    }

    printf("Popped value: %d\n", stack[top--]);
}

void peek(void) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top value: %d\n", stack[top]);
}

void display(void) {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom):\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n--- Stack Using Array ---\n");
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

    return 0;
}