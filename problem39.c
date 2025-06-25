#include <stdio.h>
#include <string.h>

#define MAX_LEN 10005

// Function to take user input
void takeInput(char *s) {
    printf("Enter your string:  ");
    fgets(s, MAX_LEN, stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove trailing newline if any
}

// Function to validate if input is a valid parentheses string
int isValidParentheses(const char *s) {
    int balance = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') balance++;
        else if (s[i] == ')') balance--;
        else return 0;  // Found invalid character
        if (balance < 0) return 0;  // More closing brackets before matching opening
    }
    return balance == 0;
}

// Function to decode message by removing outermost parentheses from each primitive
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

// Main function
int main() {
    char input[MAX_LEN];
    char output[MAX_LEN];

    takeInput(input);

    // Validate input
    if (!isValidParentheses(input)) {
        printf("!! Invalid Input !!\n");
        printf(" Please use only '(' and ')' characters \n");
        return 1;
    }

    // Process and decode the message
    removeOuterParentheses(input, output);

    // Display result
    printf("Transformed String: ");

    if (output[0] == '\0')
        printf("(empty string)\n");
    else
        printf("%s\n", output);


    return 0;
}
