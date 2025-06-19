#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 500

// Node definition for Doubly Linked List
typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a new node with a given value
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Append a node to the end of the list
void append(Node** headRef, int val) {
    Node* newNode = createNode(val);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* temp = *headRef;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Remove all nodes containing the cursed value
Node* removeCursedBeads(Node* head, int target) {
    Node* current = head;
    while (current) {
        if (current->val == target) {
            Node* toDelete = current;
            if (current->prev) current->prev->next = current->next;
            else head = current->next;

            if (current->next) current->next->prev = current->prev;

            current = current->next;
            free(toDelete);
        } else {
            current = current->next;
        }
    }
    return head;
}

// Print the doubly linked list
void printList(Node* head) {
    if (!head) {
        printf("(empty list)\n");
        return;
    }
    Node* temp = head;
    while (temp) {
        printf("%d", temp->val);
        if (temp->next) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

// Free memory of the list
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    char line[MAX_LINE];
    Node* head = NULL;

    printf("Enter head: ");
    if (!fgets(line, sizeof(line), stdin)) {
        printf("!! Invalid input !!\n");
        return 1;
    }

    // Read each value and append to list
    char* token = strtok(line, " \n");
    while (token != NULL) {
        int val;
        if (sscanf(token, "%d", &val) == 1) {
            append(&head, val);
        } else {
            printf("!! Invalid input !!\n");
            return 1;
        }
        token = strtok(NULL, " \n");
    }

    int target;
    printf("Enter target: ");
    if (scanf("%d", &target) != 1) {
        printf("!! Invalid input !!\n");
        return 1;
    }

    head = removeCursedBeads(head, target);

    printf("\nModified head: ");
    printList(head);

    freeList(head);
    return 0;
}
