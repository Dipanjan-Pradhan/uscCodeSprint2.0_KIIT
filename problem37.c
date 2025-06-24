#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPS 10000
#define MAX_LEN 50

typedef struct {
    int data[MAX_OPS];
    int top;
} Stack;

typedef struct {
    char type[10];
    int value;
} MinOutput;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

void processCommand(const char *command, Stack *mainStack, Stack *minStack, MinOutput *outputList, int *outputCount) {
    if (strncmp(command, "PUSH", 4) == 0) {
        int val;
        sscanf(command + 5, "%d", &val);
        push(mainStack, val);
        if (isEmpty(minStack) || val <= peek(minStack)) {
            push(minStack, val);
        }
    } else if (strcmp(command, "POP") == 0) {
        if (!isEmpty(mainStack)) {
            int removed = pop(mainStack);
            if (removed == peek(minStack)) {
                pop(minStack);
            }
        }
    } else if (strcmp(command, "MIN") == 0) {
        if (isEmpty(minStack)) {
            strcpy(outputList[*outputCount].type, "EMPTY");
        } else {
            strcpy(outputList[*outputCount].type, "VALUE");
            outputList[*outputCount].value = peek(minStack);
        }
        (*outputCount)++;
    } else {
        printf("Invalid command: %s\n", command);
    }
}

void printOutputs(MinOutput *outputList, int outputCount) {
    printf("\nOutput:\n");
    for (int i = 0; i < outputCount; i++) {
        if (strcmp(outputList[i].type, "EMPTY") == 0) {
            printf("EMPTY\n");
        } else {
            printf("%d\n", outputList[i].value);
        }
    }
}

int main() {
    Stack mainStack, minStack;
    initStack(&mainStack);
    initStack(&minStack);

    char commands[MAX_OPS][MAX_LEN];
    MinOutput outputList[MAX_OPS];
    int outputCount = 0;
    int n;

    printf("Enter number of operations: ");
    scanf("%d", &n);
    getchar();

    printf("Enter your %d operations:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(commands[i], sizeof(commands[i]), stdin);
        commands[i][strcspn(commands[i], "\n")] = '\0'; // Remove newline
    }

    for (int i = 0; i < n; i++) {
        processCommand(commands[i], &mainStack, &minStack, outputList, &outputCount);
    }

    printOutputs(outputList, outputCount);
    return 0;
}
