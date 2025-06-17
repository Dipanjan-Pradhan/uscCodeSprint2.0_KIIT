#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1000

// Linked List Node
typedef struct Node {
    int temp;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int temp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->temp = temp;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertAtEnd(Node** head, int temp) {
    Node* newNode = createNode(temp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = newNode;
}

// Print list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        printf("%d", curr->temp);
        if (curr->next)
            printf(" -> ");
        curr = curr->next;
    }
    printf("\n");
}

// Sort by actual value (in-place insertion sort)
Node* sortByActualValues(Node* head) {
    if (!head || !head->next)
        return head;

    Node* sorted = NULL;
    while (head) {
        Node* curr = head;
        head = head->next;

        if (!sorted || curr->temp < sorted->temp) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->temp < curr->temp)
                temp = temp->next;
            curr->next = temp->next;
            temp->next = curr;
        }
    }
    return sorted;
}

// Free memory
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main
int main() {
    Node* head = NULL;
    char input[MAX_INPUT];
    char fullInput[MAX_INPUT] = "";
    int enterCount = 0;

    printf("Enter temperatures: \n");

    // Read multi-line input until two consecutive newlines
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "\n" ) == 0) {
            enterCount++;
            if (enterCount == 2) break;
        } else {
            strcat(fullInput, input);
            enterCount = 0;
        }
    }

    // Parse input string
    char* token = strtok(fullInput, " \n");
    while (token) {
        int temp = atoi(token);
        insertAtEnd(&head, temp);
        token = strtok(NULL, " \n");
    }

    head = sortByActualValues(head);

    printf("\nSorted by Actual Temperatures:\n");
    printList(head);

    freeList(head);
    return 0;
}
