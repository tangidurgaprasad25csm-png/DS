#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(int value) {
    struct Node *newNode;
    struct Node *current;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
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

    current = head;
    for (i = 1; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
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
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

void deleteAtBeginning(void) {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Node deleted.\n");
}

void deleteAtEnd(void) {
    struct Node *current;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    current = head;

    if (current->next == NULL) {
        free(current);
        head = NULL;
        printf("Node deleted.\n");
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);
    printf("Node deleted.\n");
}

void deleteAtPosition(int position) {
    struct Node *current;
    int i;

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    current = head;
    for (i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is out of range.\n");
        return;
    }

    current->prev->next = current->next;

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node deleted.\n");
}

void display(void) {
    struct Node *current;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    current = head;
    printf("List: NULL <- ");

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" <-> ");
        }

        current = current->next;
    }

    printf(" -> NULL\n");
}

int main(void) {
    int choice;
    int value;
    int position;

    do {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1) {
                    insertAtBeginning(value);
                } else {
                    printf("Invalid input.\n");
                    return 1;
                }
                break;

            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1) {
                    insertAtEnd(value);
                } else {
                    printf("Invalid input.\n");
                    return 1;
                }
                break;

            case 3:
                printf("Enter value and position: ");
                if (scanf("%d %d", &value, &position) == 2) {
                    insertAtPosition(value, position);
                } else {
                    printf("Invalid input.\n");
                    return 1;
                }
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter position: ");
                if (scanf("%d", &position) == 1) {
                    deleteAtPosition(position);
                } else {
                    printf("Invalid input.\n");
                    return 1;
                }
                break;

            case 7:
                display();
                break;

            case 0:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    while (head != NULL) {
        deleteAtBeginning();
    }

    return 0;
}