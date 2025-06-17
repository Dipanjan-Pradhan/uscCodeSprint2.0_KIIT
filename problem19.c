#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *keypadMap[] = {
    "",     "",     "abc",  "def",
    "ghi",  "jkl",  "mno",  "pqrs",
    "tuv",  "wxyz"
};

void backtrack(char *digits, int index, char *current, char **result, int *returnSize) {
    if (digits[index] == '\0') {
        result[*returnSize] = (char *)malloc(strlen(current) + 1);
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    char *letters = keypadMap[digit];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0') return NULL;

    int maxLen = 1;
    for (int i = 0; digits[i] != '\0'; i++) {
        int digit = digits[i] - '0';
        if (digit < 2 || digit > 9) continue;
        maxLen *= strlen(keypadMap[digit]);
    }

    char **result = (char **)malloc(sizeof(char *) * maxLen);
    char *current = (char *)malloc(strlen(digits) + 1);
    current[strlen(digits)] = '\0';

    backtrack(digits, 0, current, result, returnSize);

    free(current);
    return result;
}

int main() {
    char digits[10];
    printf("Enter digits (2-9): ");
    scanf("%s", digits);

    int count = 0;
    char **combinations = letterCombinations(digits, &count);

    printf("Combinations:\n[");
    for (int i = 0; i < count; i++) {
        printf("\"%s\"", combinations[i]);
        if (i != count - 1) printf(", ");
        free(combinations[i]);
    }
    printf("]\n");

    free(combinations);
    return 0;
}
