#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

int isFull(void) {
    return (front == 0 && rear == MAX - 1) ||
           (front == rear + 1);
}

int isEmpty(void) {
    return front == -1;
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full.\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at the front.\n", value);
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full.\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at the rear.\n", value);
}

void deleteFront(void) {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deleted from front: %d\n", deque[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear(void) {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deleted from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display(void) {
    int i;

    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque (front to rear): ");
    i = front;

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear) {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n--- Double Ended Queue ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display deque\n");
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
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
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