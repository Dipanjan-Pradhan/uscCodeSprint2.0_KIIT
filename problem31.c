#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 500

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, int val) {
    Node* newNode = createNode(val);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* temp = *headRef;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

void printList(Node* head) {
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

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

Node* parseInputLine(char* line) {
    Node* head = NULL;
    char* token = strtok(line, " \n");
    while (token) {
        int val;
        if (sscanf(token, "%d", &val) == 1) {
            append(&head, val);
        }
        token = strtok(NULL, " \n");
    }
    return head;
}

int isSorted(Node* head) {
    while (head && head->next) {
        if (head->val > head->next->val)
            return 0;
        head = head->next;
    }
    return 1;
}

int main() {
    char line1[MAX_LEN], line2[MAX_LEN];

    printf("List 1 = ");
    fgets(line1, sizeof(line1), stdin);
    Node* list1 = parseInputLine(line1);

    if (!isSorted(list1)) {
        printf("List 1 is not sorted\n");
        freeList(list1);
        return 1;
    }

    printf("List 2 = ");
    fgets(line2, sizeof(line2), stdin);
    Node* list2 = parseInputLine(line2);

    if (!isSorted(list2)) {
        printf("List 2 is not sorted\n");
        freeList(list1);
        freeList(list2);
        return 1;
    }

    Node* merged = mergeSortedLists(list1, list2);

    printf("Merged List = ");
    printList(merged);

    freeList(merged);
    return 0;
}
