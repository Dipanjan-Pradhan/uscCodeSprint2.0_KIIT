#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 500

// Definition for singly-linked list node
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Function to create a new node with a given value
ListNode* createNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (!node) {
        printf("!! Memory allocation failed !!\n");
        exit(1);
    }
    node->val = val;
    node->next = NULL;
    return node;
}

// Append a new node at the end of the linked list
void appendNode(ListNode** headRef, int val) {
    ListNode* newNode = createNode(val);
    if (!*headRef) {
        *headRef = newNode;
    } else {
        ListNode* temp = *headRef;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to read a line of space-separated digits and create a linked list
ListNode* readListFromLine(const char* label) {
    char line[MAX_LINE];
    ListNode* head = NULL;
    int val;

    printf("Enter %s: ", label);

    if (!fgets(line, sizeof(line), stdin)) {
        printf("!! Invalid Input !!\n");
        exit(1);
    }

    char* token = strtok(line, " \n");
    while (token != NULL) {
        if (isdigit(token[0])) {
            val = atoi(token);
            if (val >= 0 && val <= 9) {
                appendNode(&head, val);
            } else {
                printf("!! Invalid Input !!\n");
                exit(1);
            }
        } 
        else {
            printf("!! Invalid Input !!\n");
            exit(1);
        }
        token = strtok(NULL, " \n");
    }

    return head;
}

// Function to add two numbers represented by reversed linked lists
ListNode* addTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummyHead = createNode(0), *current = dummyHead;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }

    ListNode* result = dummyHead->next;
    free(dummyHead); // Free unused dummy head
    return result;
}

// Print linked list in readable format
void printList(ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(", ");
        head = head->next;
    }
}

// Free memory used by linked list
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    ListNode* l1 = readListFromLine("L1");
    ListNode* l2 = readListFromLine("L2");

    ListNode* result = addTwoLists(l1, l2);

    printf("Sum of the two numbers (in reverse order): [");

    printList(result);
    printf("]\n");

    // Clean up memory
    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
// End of problem30.c
// This code implements a solution to the problem of adding two numbers represented by reversed linked lists.