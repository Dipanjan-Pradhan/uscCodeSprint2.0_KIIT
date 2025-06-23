#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000


int isOnlyBrackets(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '(' && str[i] != ')' &&
            str[i] != '{' && str[i] != '}' &&
            str[i] != '[' && str[i] != ']') {
            return 0; 
        }
    }
    return 1;
}

int isValidBracketString(const char* str) {
    char stack[MAX_LEN];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

       
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
       
        else {
            if (top == -1) return 0; 
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    char input[MAX_LEN + 1];

    printf("Please enter your secret message: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Couldn't read your input. Please try again.\n");
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (!isOnlyBrackets(input)) {
        printf("!! Invalid Input !!\n");
        return 1;
    }

    printf("Code status: ");
    if (isValidBracketString(input)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
