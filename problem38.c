#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100005
#define MAX_LABEL_LENGTH 21
#define HASH_SIZE 10007 

typedef struct Node {
    char label[MAX_LABEL_LENGTH];
    int count;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

int hash(const char* str) {
    int h = 0;
    while (*str) {
        h = (h * 31 + *str++) % HASH_SIZE;
    }
    return h;
}

int getCount(const char* label) {
    int h = hash(label);
    Node* curr = hashTable[h];
    while (curr) {
        if (strcmp(curr->label, label) == 0) {
            return curr->count;
        }
        curr = curr->next;
    }
    return 0;
}

void incrementCount(const char* label) {
    int h = hash(label);
    Node* curr = hashTable[h];
    while (curr) {
        if (strcmp(curr->label, label) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->label, label);
    newNode->count = 1;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

void decrementCount(const char* label) {
    int h = hash(label);
    Node* curr = hashTable[h];
    Node* prev = NULL;
    while (curr) {
        if (strcmp(curr->label, label) == 0) {
            curr->count--;
            if (curr->count == 0) {
                if (prev) prev->next = curr->next;
                else hashTable[h] = curr->next;
                free(curr);
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

char stack[MAX_STACK_SIZE][MAX_LABEL_LENGTH];
int top = -1;

typedef struct {
    char type[10];
    char value[MAX_LABEL_LENGTH];
} Command;

Command commands[MAX_STACK_SIZE];
int output[MAX_STACK_SIZE];
int outputCount = 0;

int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char line[40];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0;

        if (strncmp(line, "PUSH", 4) == 0) {
            strcpy(commands[i].type, "PUSH");
            sscanf(line + 5, "%s", commands[i].value);
        } else {
            strcpy(commands[i].type, line);
        }
    }

    for (int i = 0; i < n; i++) {
        if (strcmp(commands[i].type, "PUSH") == 0) {
            strcpy(stack[++top], commands[i].value);
            incrementCount(commands[i].value);
        } else if (strcmp(commands[i].type, "POP") == 0) {
            if (top >= 0) {
                decrementCount(stack[top--]);
            }
        } else if (strcmp(commands[i].type, "COUNT") == 0) {
            if (top == -1) {
                output[outputCount++] = -1;
            } else {
                output[outputCount++] = getCount(stack[top]);
            }
        }
    }

    printf("\nOutput:\n");
    for (int i = 0; i < outputCount; i++) {
        if (output[i] == -1)
            printf("EMPTY\n");
        else
            printf("%d\n", output[i]);
    }

    return 0;
}
