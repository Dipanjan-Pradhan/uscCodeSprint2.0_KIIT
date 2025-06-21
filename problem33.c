#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

// Stack structure
typedef struct {
    char data[MAX_LEN];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to push a character onto the stack
void push(Stack *stack, char ch) {
    if (stack->top < MAX_LEN - 1) {
        stack->data[++(stack->top)] = ch;
    } else {
        printf("Stack is full\n");
        exit(1);
    }
}

// Function to pop a character from the stack
char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int main() {
    char input[MAX_LEN];
    Stack stack;
    initStack(&stack);

    printf("🔤 Please enter your sentence below:\n> ");

    // Read the full input line
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Push characters onto the stack
    for (int i = 0; input[i] != '\0'; i++) {
        push(&stack, input[i]);
    }

    // Display reversed string
    printf("Reversed Sentence:\n> ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}
