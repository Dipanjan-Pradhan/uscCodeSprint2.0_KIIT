#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000

typedef struct Stack {
    char *data[MAX_LEN];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, const char *str) {
    if (stack->top < MAX_LEN - 1) {
        stack->data[++(stack->top)] = strdup(str);
    } else {
        printf("Stack overflow! Too many elements.\n"); 
        exit(1);
    }
}

char *pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    } else {
        printf("Stack underflow! Nothing to pop.\n");
        exit(1);
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int main() {
    char input[MAX_LEN + 1];
    Stack stack;
    initStack(&stack);

    printf("🔁 Enter postfix expression: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("!! Invalid Input !!\n"); 
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            push(&stack, operand);
        } else if (isOperator(ch)) {
            if (stack.top < 1) {
                printf("Not enough operands for operator '%c'.\n", ch);
                return 1;
            }

            char *right = pop(&stack);
            char *left = pop(&stack);

            size_t size = strlen(left) + strlen(right) + 2;
            char *newExpr = (char *)malloc(size);

            if (newExpr == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            sprintf(newExpr, "%c%s%s", ch, left, right); 
            push(&stack, newExpr);

            free(left); 
            free(right);
            free(newExpr); 
        } else {
            printf("!! Invalid Input !!\n");
            return 1;
        }
    }

    if (stack.top == 0) {
        printf("Prefix expression: %s\n", stack.data[0]);
        free(stack.data[0]);
    } else {
        printf("!! Invalid Input: More than one element left in stack.\n");
    }

    return 0;
}
