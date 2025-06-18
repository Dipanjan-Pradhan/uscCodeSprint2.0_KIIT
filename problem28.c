#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node with the given value
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    while (head != NULL) {
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

// Double the number represented by the linked list
Node* doubleNumber(Node* head) {
    head = reverseList(head);
    Node* current = head;
    int carry = 0;
    Node* last = NULL;

    while (current != NULL) {
        int total = current->data * 2 + carry;
        current->data = total % 10;
        carry = total / 10;
        last = current;
        current = current->next;
    }

    if (carry > 0) {
        last->next = createNode(carry);
    }

    return reverseList(head);
}

// Print the list in comma-separated format
void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) {
            printf(",");
        }
        head = head->next;
    }
    printf("\n");
}

// Free the memory used by the linked list
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char input[10005];
    printf("Enter the number: ");
    scanf("%s", input);

    Node* head = NULL;
    Node* tail = NULL;

    // Build the linked list from input digits
    for (int i = 0; input[i] != '\0'; ++i) {
        Node* newNode = createNode(input[i] - '0');
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* result = doubleNumber(head);
    printList(result);

    // Free memory to avoid leaks
    freeList(head);

    return 0;
}
