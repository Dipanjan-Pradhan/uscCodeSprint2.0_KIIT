#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

typedef struct {
    char data[MAX_LEN];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char ch) {
    if (stack->top < MAX_LEN - 1) {
        stack->data[++(stack->top)] = ch;
    } else {
        printf("Stack is full\n");
        exit(1);
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int main() {
    char input[MAX_LEN];
    Stack stack;
    initStack(&stack);

    printf("🔤 Please enter your sentence below:\n> ");

    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    for (int i = 0; input[i] != '\0'; i++) {
        push(&stack, input[i]);
    }

    printf("Reversed Sentence:\n> ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}
