#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000
#define MAX_TOKEN 1000

// Function to check if a string is an operator
int isOperator(const char *token) {
    return strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 || strcmp(token, "/") == 0;
}

// Function to convert string to integer safely
int toInt(const char *str) {
    return atoi(str);
}

// Function to perform the operation on two integers
int applyOperator(int a, int b, const char *op) {
    if (strcmp(op, "+") == 0) return a + b;
    if (strcmp(op, "-") == 0) return a - b;
    if (strcmp(op, "*") == 0) return a * b;
    if (strcmp(op, "/") == 0) return a / b;  // Integer division truncates toward zero
    return 0;
}

int main() {
    char input[MAX_LEN + 1];
    char *tokens[MAX_TOKEN];
    int tokenCount = 0;

    printf("Enter the postfix expression: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0';

    // Tokenize the input
    char *token = strtok(input, " ");
    while (token != NULL && tokenCount < MAX_TOKEN) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " ");
    }

    // Stack to evaluate the postfix expression
    int stack[MAX_TOKEN];
    int top = -1;

    for (int i = 0; i < tokenCount; i++) {
        if (isOperator(tokens[i])) {
            if (top < 1) {
                printf("Not enough operands for operator");
                return 1;
            }
            int b = stack[top--];
            int a = stack[top--];
            int result = applyOperator(a, b, tokens[i]);
            stack[++top] = result;
        } else {
            // Assume valid integer input as per constraints
            stack[++top] = toInt(tokens[i]);
        }
    }

    if (top != 0) {
        printf("!! Invalid Expression !!\n");
        return 1;
    }

    printf("Result: %d\n", stack[top]);
    return 0;
}
