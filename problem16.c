#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse characters in a string between given indices
void reverse(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

// This function removes leading, trailing, and extra spaces
char *cleanSpaces(char *str) {
    int i = 0, j = 0;

    // Skip initial spaces
    while (str[i] && isspace(str[i])) i++;

    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = str[i++];
        } else {
            // Replace multiple spaces with a single one
            str[j++] = ' ';
            while (isspace(str[i])) i++;
        }
    }

    // Remove trailing space if any
    if (j > 0 && str[j - 1] == ' ') j--;

    str[j] = '\0';
    return str;
}

// This function reverses each word and then the whole sentence
void reverseWords(char *sentence) {
    cleanSpaces(sentence); // Step 1: Clean unnecessary spaces
    int len = strlen(sentence);

    // Step 2: Reverse the entire cleaned sentence
    reverse(sentence, 0, len - 1);

    // Step 3: Reverse each individual word
    int start = 0;
    for (int end = 0; end <= len; end++) {
        if (sentence[end] == ' ' || sentence[end] == '\0') {
            reverse(sentence, start, end - 1);
            start = end + 1;
        }
    }
}

// Dynamically reads a line of input from the user
char *getInputLine() {
    int capacity = 100, size = 0;
    char *line = (char *)malloc(capacity * sizeof(char));

    if (!line) {
        printf("❌ Memory allocation failed.\n");
        exit(1);
    }

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (size >= capacity - 1) {
            capacity *= 2;
            char *temp = realloc(line, capacity);
            if (!temp) {
                free(line);
                printf("❌ Memory reallocation failed.\n");
                exit(1);
            }
            line = temp;
        }
        line[size++] = ch;
    }
    line[size] = '\0';
    return line;
}

int main() {
    printf("🗣️  Enter Anubhav's sentence: ");
    char *speechLine = getInputLine();

    reverseWords(speechLine);

    printf("✅ Final cleaned-up sentence:\n%s\n", speechLine);

    free(speechLine); // Don't forget to release allocated memory!
    return 0;
}
