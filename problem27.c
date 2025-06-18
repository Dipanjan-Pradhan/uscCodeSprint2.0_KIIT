#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent each child in the parade
typedef struct ListNode {
    int badgeNumber;
    struct ListNode *next;
} ListNode;

// Create a new node for a child with the given badge number
ListNode* createChild(int badgeNumber) {
    ListNode* newChild = (ListNode*)malloc(sizeof(ListNode));
    newChild->badgeNumber = badgeNumber;
    newChild->next = NULL;
    return newChild;
}

// Add a child to the end of the linked list
void addChild(ListNode** head, ListNode** tail, int badgeNumber) {
    ListNode* newChild = createChild(badgeNumber);
    if (*head == NULL) {
        *head = *tail = newChild;
    } else {
        (*tail)->next = newChild;
        *tail = newChild;
    }
}

// Find the leader (middle child or second middle if even count)
ListNode* findParadeLeader(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Print the parade lineup from the leader onward
void printLineFromLeader(ListNode* leader) {
    printf("Required children: ");
    while (leader) {
        printf("%d", leader->badgeNumber);
        if (leader->next) {
            printf(" -> ");
        }
        leader = leader->next;
    }
    printf("\n");
}

// Free memory
void cleanUp(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main driver function
int main() {
    char inputLine[1024];
    printf("Enter the students badge no: ");

    if (!fgets(inputLine, sizeof(inputLine), stdin)) {
        printf("Failed to read input.\n");
        return 1;
    }

    ListNode *head = NULL, *tail = NULL;

    char* token = strtok(inputLine, " \n");
    int badgeCount = 0;

    while (token != NULL) {
        // Check if token is a valid number
        int valid = 1;
        for (int i = 0; token[i]; i++) {
            if (!isdigit(token[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("!! Invalid Input !!\n");
            cleanUp(head);
            return 1;
        }

        int badgeNumber = atoi(token);
        if (badgeNumber <= 0) {
            printf("!! Invalid Input !!\n");
            cleanUp(head);
            return 1;
        }

        addChild(&head, &tail, badgeNumber);
        badgeCount++;
        token = strtok(NULL, " \n");
    }

    if (badgeCount == 0) {
        printf("!! Invalid Input !!\n");
        return 1;
    }

    ListNode* leader = findParadeLeader(head);
    printLineFromLeader(leader);

    cleanUp(head);
    return 0;
}
