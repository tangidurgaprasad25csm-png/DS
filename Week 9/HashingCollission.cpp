#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int linearTable[TABLE_SIZE];
int quadraticTable[TABLE_SIZE];

struct Node {
    int key;
    struct Node *next;
};

struct Node *chainTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}


void initLinear(void) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        linearTable[i] = -1;
}

void insertLinear(int key) {
    int index, i, probe;

    index = hashFunction(key);

    for (i = 0; i < TABLE_SIZE; i++) {
        probe = (index + i) % TABLE_SIZE;

        if (linearTable[probe] == -1) {
            linearTable[probe] = key;
            printf("Key %d inserted at index %d (linear probing).\n", key, probe);
            return;
        }
    }

    printf("Hash table is full! Cannot insert key %d.\n", key);
}

void displayLinear(void) {
    int i;

    printf("\nLinear Probing Table:\n");
    printf("Index\tValue\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        if (linearTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, linearTable[i]);
    }
}


void initQuadratic(void) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        quadraticTable[i] = -1;
}

void insertQuadratic(int key) {
    int index, i, probe;

    index = hashFunction(key);

    for (i = 0; i < TABLE_SIZE; i++) {
        probe = (index + i * i) % TABLE_SIZE;

        if (quadraticTable[probe] == -1) {
            quadraticTable[probe] = key;
            printf("Key %d inserted at index %d (quadratic probing).\n", key, probe);
            return;
        }
    }

    printf("Hash table is full or no free slot was found for key %d.\n", key);
}

void displayQuadratic(void) {
    int i;

    printf("\nQuadratic Probing Table:\n");
    printf("Index\tValue\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        if (quadraticTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, quadraticTable[i]);
    }
}


void initChaining(void) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        chainTable[i] = NULL;
}

void insertChaining(int key) {
    int index;
    struct Node *newNode;
    struct Node *temp;

    index = hashFunction(key);
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->key = key;
    newNode->next = NULL;

    if (chainTable[index] == NULL) {
        chainTable[index] = newNode;
    } else {
        temp = chainTable[index];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Key %d inserted at index %d (separate chaining).\n", key, index);
}

void displayChaining(void) {
    int i;
    struct Node *temp;

    printf("\nSeparate Chaining Table:\n");
    printf("Index\tChain\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
        temp = chainTable[i];

        if (temp == NULL) {
            printf("-");
        } else {
            while (temp != NULL) {
                printf("%d -> ", temp->key);
                temp = temp->next;
            }
            printf("NULL");
        }

        printf("\n");
    }
}

void freeChaining(void) {
    int i;
    struct Node *temp;
    struct Node *nextNode;

    for (i = 0; i < TABLE_SIZE; i++) {
        temp = chainTable[i];

        while (temp != NULL) {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }

        chainTable[i] = NULL;
    }
}

int main(void) {
    int choice, key;

    initLinear();
    initQuadratic();
    initChaining();

    while (1) {
        printf("\n----- HASHING - COLLISION RESOLUTION TECHNIQUES -----\n");
        printf("1. Insert using Linear Probing\n");
        printf("2. Insert using Quadratic Probing\n");
        printf("3. Insert using Separate Chaining\n");
        printf("4. Display Linear Probing Table\n");
        printf("5. Display Quadratic Probing Table\n");
        printf("6. Display Separate Chaining Table\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            freeChaining();
            return 1;
        }

        switch (choice) {
            case 1:
            case 2:
            case 3:
                printf("Enter key to insert: ");

                if (scanf("%d", &key) != 1) {
                    printf("Invalid input. Exiting program.\n");
                    freeChaining();
                    return 1;
                }

                if (choice == 1)
                    insertLinear(key);
                else if (choice == 2)
                    insertQuadratic(key);
                else
                    insertChaining(key);
                break;

            case 4:
                displayLinear();
                break;

            case 5:
                displayQuadratic();
                break;

            case 6:
                displayChaining();
                break;

            case 7:
                printf("Exiting program.\n");
                freeChaining();
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}



