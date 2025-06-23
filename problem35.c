#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

// Function to check if a character is a valid bracket
int isOnlyBrackets(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '(' && str[i] != ')' &&
            str[i] != '{' && str[i] != '}' &&
            str[i] != '[' && str[i] != ']') {
            return 0; // Invalid character found
        }
    }
    return 1;
}

// Function to check if the brackets are balanced and valid
int isValidBracketString(const char* str) {
    char stack[MAX_LEN];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        // Handle closing brackets
        else {
            if (top == -1) return 0; // No matching opening bracket
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0; // Mismatched brackets
            }
        }
    }

    return top == -1; // Stack should be empty if all brackets matched
}

int main() {
    char input[MAX_LEN + 1];

    printf("Please enter your secret message: ");

    // Get user input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Couldn't read your input. Please try again.\n");
        return 1;
    }

    // Remove trailing newline
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Validate bracket-only input
    if (!isOnlyBrackets(input)) {
        printf("!! Invalid Input !!\n");
        return 1;
    }

    // Check validity of brackets
    printf("Code status: ");
    if (isValidBracketString(input)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
