#include <stdio.h>
#include <string.h>

#define MAX_LEN 10005

void takeInput(char *s) {
    printf("Enter your string:  ");
    fgets(s, MAX_LEN, stdin);
    s[strcspn(s, "\n")] = '\0';
}

int isValidParentheses(const char *s) {
    int balance = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') balance++;
        else if (s[i] == ')') balance--;
        else return 0; 
        if (balance < 0) return 0;  
    }
    return balance == 0;
}

void removeOuterParentheses(const char *s, char *result) {
    int balance = 0, resIndex = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            if (balance > 0)
                result[resIndex++] = '(';
            balance++;
        } else if (s[i] == ')') {
            balance--;
            if (balance > 0)
                result[resIndex++] = ')';
        }
    }
    result[resIndex] = '\0';
}

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN];

    takeInput(input);

    if (!isValidParentheses(input)) {
        printf("!! Invalid Input !!\n");
        printf(" Please use only '(' and ')' characters \n");
        return 1;
    }

    removeOuterParentheses(input, output);

    printf("Transformed String: ");

    if (output[0] == '\0')
        printf("(empty string)\n");
    else
        printf("%s\n", output);

    return 0;
}
