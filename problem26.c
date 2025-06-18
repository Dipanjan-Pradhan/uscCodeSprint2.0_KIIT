#include <stdio.h>
#include <stdlib.h>

// Define structure for a doubly linked list node
typedef struct DListNode {
    int value;
    struct DListNode* prev;
    struct DListNode* next;
} DListNode;

// Create a new node with the given value
DListNode* createNode(int value) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Append a new node to the end of the list
void appendNode(DListNode** head, DListNode** tail, int value) {
    DListNode* newNode = createNode(value);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Swap the values of two nodes
void swapNodes(DListNode* a, DListNode* b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

// Bubble sort to sort the doubly linked list
void sortList(DListNode* head) {
    if (!head) return;

    int swapped;
    DListNode* current;
    DListNode* lastSorted = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != lastSorted) {
            if (current->value > current->next->value) {
                swapNodes(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }

        lastSorted = current;
    } while (swapped);
}

// Print the doubly linked list in <-> format
void printList(DListNode* head) {
    while (head) {
        printf("%d", head->value);
        if (head->next) {
            printf(" <-> ");
        }
        head = head->next;
    }
    printf("\n");
}

// Free the memory allocated for the list
void freeList(DListNode* head) {
    while (head) {
        DListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid number of nodes.\n");
        return 0;
    }

    DListNode* head = NULL;
    DListNode* tail = NULL;

    printf("Enter %d space-separated integers:\n", n);
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Exiting.\n");
            freeList(head);
            return 0;
        }
        appendNode(&head, &tail, value);
    }

    sortList(head);

    printf("Sorted output: ");
    printList(head);

    freeList(head);
    return 0;
}
