#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

// Linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Count total nodes
int countNodes(struct ListNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Split the list
struct ListNode** splitListToParts(struct ListNode* head, int k) {
    int totalNodes = countNodes(head);
    int baseSize = totalNodes / k;
    int extra = totalNodes % k;

    struct ListNode** result = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);
    
    for (int i = 0; i < k; i++) {
        result[i] = head;
        int partSize = baseSize + (i < extra ? 1 : 0);

        for (int j = 1; j < partSize; j++) {
            if (head) head = head->next;
        }

        if (head) {
            struct ListNode* temp = head->next;
            head->next = NULL;
            head = temp;
        }
    }

    return result;
}

// Print linked list
void printList(struct ListNode* head) {
    if (!head) {
        printf("[]\n");
        return;
    }
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(", ");
        head = head->next;
    }
    printf("]\n");
}

int main() {
    char buffer[MAX_LEN];
    int k;

    printf("Enter linked list elements (space separated), then press Enter twice:\n");

    // Read first line input
    fgets(buffer, MAX_LEN, stdin);
    if (buffer[0] == '\n') {
        printf("Empty input.\n");
        return 0;
    }

    // Remove trailing newline
    buffer[strcspn(buffer, "\n")] = '\0';

    // Tokenize input into linked list
    struct ListNode* head = NULL, *tail = NULL;
    char* token = strtok(buffer, " ");
    while (token != NULL) {
        int val = atoi(token);
        struct ListNode* newNode = createNode(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        token = strtok(NULL, " ");
    }

    // Wait for an empty Enter
    fgets(buffer, MAX_LEN, stdin);

    // Read k
    printf("Enter number of parts (k): ");
    scanf("%d", &k);

    // Split list and print parts
    struct ListNode** parts = splitListToParts(head, k);

    printf("Output Parts:\n");
    for (int i = 0; i < k; i++) {
        printList(parts[i]);
    }

    free(parts);
    return 0;
}
