#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000
#define MAX_TOKEN 1000

int isOperator(const char *token) {
    return strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 || strcmp(token, "/") == 0;
}

int toInt(const char *str) {
    return atoi(str);
}

int applyOperator(int a, int b, const char *op) {
    if (strcmp(op, "+") == 0) return a + b;
    if (strcmp(op, "-") == 0) return a - b;
    if (strcmp(op, "*") == 0) return a * b;
    if (strcmp(op, "/") == 0) return a / b;  
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

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0';

    char *token = strtok(input, " ");
    while (token != NULL && tokenCount < MAX_TOKEN) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " ");
    }


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
