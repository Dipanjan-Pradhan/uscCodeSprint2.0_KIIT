#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

typedef struct Node {
    char val[100];
    struct Node *next;
} Node;

// Creates a new node with a given string value
Node* createNode(const char *val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->val, val);
    newNode->next = NULL;
    return newNode;
}

// Appends a node to the end of the list
void append(Node **headRef, const char *val) {
    Node *newNode = createNode(val);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node *temp = *headRef;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Prints the shopping list
void printList(Node *head) {
    printf("[");
    while (head) {
        printf("\"%s\"", head->val);
        if (head->next) printf(", ");
        head = head->next;
    }
    printf("]\n");
}

// Frees memory used by the list
void freeList(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Returns the total length of the list
int getListLength(Node *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Validates if the left and right indices are within bounds
int isValidIndex(int index, int length){
    return(index >= 1 && index <= length);
}

// Reverses the list between positions 'left' and 'right'
Node* reverseSegment(Node *head, int left, int right) {
    if (!head || left == right) return head;

    Node dummy;
    dummy.next = head;
    Node *prev = &dummy;

    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    Node *current = prev->next;
    Node *next = NULL;

    for (int i = 0; i < right - left; i++) {
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy.next;
}

// Main function
int main() {
    char input[MAX_LEN];
    int left, right;
    Node *head = NULL;

    // Input shopping list
    printf("Enter shopping list items: ");
    fgets(input, sizeof(input), stdin);

    // Tokenize and build linked list
    char *token = strtok(input, " \n");
    while (token) {
        append(&head, token);
        token = strtok(NULL, " \n");
    }

    // Get list length for validation
    int length = getListLength(head);

    // Input and validate indices
    printf("Enter left index (1-based): ");
    scanf("%d", &left);
    if (!isValidIndex(left, length)) {
        printf("!! Invalid Index !!\n");
        freeList(head);
        return 1;
    }
    printf("Enter right index (1-based): ");
    scanf("%d", &right);
    if (!isValidIndex(right, length)) {
        printf("!! Invalid Index !!\n");
        freeList(head);
        return 1;
    }
    
    // Check if indices are valid

    // Reverse and print the list
    head = reverseSegment(head, left, right);
    printf("Revised List = ");
    printList(head);

    freeList(head);
    return 0;
}
