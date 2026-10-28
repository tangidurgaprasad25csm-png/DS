#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;


void insertAtBeginning(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("Node inserted.\n");
}


void insertAtEnd(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Node inserted.\n");
}


void insertAtPosition(int value, int position) {
    struct Node *newNode;
    struct Node *current;
    int i;

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    if (last == NULL) {
        printf("Position is out of range.\n");
        return;
    }

    current = last->next;
    for (i = 1; i < position - 1 && current != last; i++) {
        current = current->next;
    }

    if (i != position - 1) {
        printf("Position is out of range.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;

    if (current == last) {
        last = newNode;
    }

    printf("Node inserted.\n");
}


void deleteAtPosition(int position) {
    struct Node *current;
    struct Node *previous;
    int i;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    current = last->next;
    previous = last;

    for (i = 1; i < position && current != last; i++) {
        previous = current;
        current = current->next;
    }

    if (i != position) {
        printf("Position is out of range.\n");
        return;
    }

    if (current == last && current == last->next) {
        last = NULL;
    } else {
        previous->next = current->next;

        if (current == last) {
            last = previous;
        }
    }

    free(current);
    printf("Node deleted.\n");
}


void display(void) {
    struct Node *current;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    current = last->next;
    printf("List: ");

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != last->next);

    printf("(back to first node)\n");
}

int main(void) {
    int choice;
    int value;
    int position;

    do {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at position\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                if (scanf("%d %d", &value, &position) != 2) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insertAtPosition(value, position);
                break;

            case 4:
                printf("Enter position: ");
                if (scanf("%d", &position) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                deleteAtPosition(position);
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

    
    while (last != NULL) {
        deleteAtPosition(1);
    }

    return 0;
}