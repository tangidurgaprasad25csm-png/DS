#include <stdio.h>

#define MAX 100

struct Item {
    int value;
    int priority;
};

struct Item queue[MAX];
int count = 0;


void enqueue(int value, int priority) {
    if (count == MAX) {
        printf("Priority queue is full.\n");
        return;
    }

    queue[count].value = value;
    queue[count].priority = priority;
    count++;

    printf("Item added to the priority queue.\n");
}


void dequeue(void) {
    int i;
    int highestIndex;
    struct Item removed;

    if (count == 0) {
        printf("Priority queue is empty.\n");
        return;
    }

    highestIndex = 0;

    for (i = 1; i < count; i++) {
        if (queue[i].priority < queue[highestIndex].priority) {
            highestIndex = i;
        }
    }

    removed = queue[highestIndex];

    for (i = highestIndex; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }

    count--;

    printf("Removed item: %d (priority %d)\n",
           removed.value, removed.priority);
}


void display(void) {
    int i;

    if (count == 0) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("\nItems in the priority queue:\n");
    printf("Value\tPriority\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%d\n", queue[i].value, queue[i].priority);
    }
}

int main(void) {
    int choice;
    int value;
    int priority;

    do {
        printf("\n--- Priority Queue ---\n");
        printf("1. Insert item\n");
        printf("2. Delete highest-priority item\n");
        printf("3. Display queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                if (scanf("%d %d", &value, &priority) != 2) {
                    printf("Invalid input.\n");
                    return 1;
                }
                enqueue(value, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
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
