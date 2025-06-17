#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = newNode;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Sort 0s, 1s, and 2s
Node* sortColors(Node* head) {
    int count[3] = {0, 0, 0};
    Node* curr = head;

    while (curr) {
        count[curr->data]++;
        curr = curr->next;
    }

    curr = head;
    for (int i = 0; i < 3; i++) {
        while (count[i]--) {
            curr->data = i;
            curr = curr->next;
        }
    }

    return head;
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

// Main function
int main() {
    Node* head = NULL;
    char input[MAX_INPUT];
    char fullInput[MAX_INPUT] = "";
    int enterCount = 0;

    printf("Enter package colors (0, 1, 2). Press Enter twice to stop:\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "\n") == 0) {
            enterCount++;
            if (enterCount == 2)
                break;
        } else {
            strcat(fullInput, input);
            enterCount = 0;
        }
    }

    // Tokenize and build list
    char* token = strtok(fullInput, " \n");
    while (token) {
        int value = atoi(token);
        if (value < 0 || value > 2) {
            printf("Skipping invalid input: %s\n", token);
        } else {
            insertAtEnd(&head, value);
        }
        token = strtok(NULL, " \n");
    }

    head = sortColors(head);

    printf("Sorted List: ");
    printList(head);

    freeList(head);
    return 0;
}
