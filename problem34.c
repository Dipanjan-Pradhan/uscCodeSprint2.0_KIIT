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
        stack->data[++(stack->top)] = strdup(str); // ✅ Keeps a copy of the string
    } else {
        printf("❌ Stack overflow! Too many elements.\n"); // ✅ Better message
        exit(1);
    }
}

char *pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    } else {
        printf("❌ Stack underflow! Nothing to pop.\n"); // ✅ Better message
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
        printf("❌ Couldn't read your input.\n"); // ✅ Spelling corrected from "Counldn't"
        return 1;
    }

    // ✅ Remove trailing newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (isspace(ch)) continue; // ✅ Skip whitespace

        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            push(&stack, operand);
        } else if (isOperator(ch)) {
            if (stack.top < 1) { // ✅ Check if there are at least 2 operands
                printf("❌ Not enough operands for operator '%c'.\n", ch);
                return 1;
            }

            char *right = pop(&stack);
            char *left = pop(&stack);

            // ✅ Allocate memory for the new expression
            size_t size = strlen(left) + strlen(right) + 2; // Operator + left + right + '\0'
            char *newExpr = (char *)malloc(size);

            if (newExpr == NULL) { // ✅ Safe check for malloc
                printf("❌ Memory allocation failed.\n");
                return 1;
            }

            sprintf(newExpr, "%c%s%s", ch, left, right); // ✅ Prefix expression
            push(&stack, newExpr); // ✅ Uses strdup inside push()

            free(left);  // ✅ Prevent memory leaks
            free(right);
            free(newExpr); // ✅ newExpr is strdup-ed inside push(), so we can safely free it here
        } else {
            printf("❌ Invalid character '%c' in input. Only use A-Z, a-z, 0-9, and + - * /.\n", ch); // ✅ More informative
            return 1;
        }
    }

    // ✅ Final result should be the only element on the stack
    if (stack.top == 0) {
        printf("✅ Prefix expression: %s\n", stack.data[0]);
        free(stack.data[0]); // ✅ Free memory
    } else {
        printf("❌ Something went wrong. Check your postfix expression.\n");
    }

    return 0;
}
