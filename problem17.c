#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_COUNT 26

// Compare frequency arrays to check anagram
int isAnagram(int *freq1, int *freq2) {
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (freq1[i] != freq2[i]) return 0;
    }
    return 1;
}

// Dynamically find all anagram start indices
int* findAnagrams(char* logStream, char* pattern, int* returnSize) {
    int lenS = strlen(logStream);
    int lenP = strlen(pattern);

    int capacity = 10;
    int* result = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    if (lenS < lenP) return result;

    int patternFreq[CHAR_COUNT] = {0};
    int windowFreq[CHAR_COUNT] = {0};

    for (int i = 0; i < lenP; i++) {
        patternFreq[pattern[i] - 'a']++;
        windowFreq[logStream[i] - 'a']++;
    }

    if (isAnagram(patternFreq, windowFreq)) {
        result[(*returnSize)++] = 0;
    }

    for (int i = lenP; i < lenS; i++) {
        windowFreq[logStream[i] - 'a']++;
        windowFreq[logStream[i - lenP] - 'a']--;

        if (isAnagram(patternFreq, windowFreq)) {
            if (*returnSize >= capacity) {
                capacity *= 2;
                result = realloc(result, capacity * sizeof(int));
                if (result == NULL) {
                    printf("Memory reallocation failed\n");
                    exit(1);
                }
            }
            result[(*returnSize)++] = i - lenP + 1;
        }
    }

    // Shrink to exact size
    result = realloc(result, (*returnSize) * sizeof(int));
    return result;
}

// Get dynamic input string
char* getInputString() {
    int size = 0, capacity = 100;
    char* str = (char*)malloc(capacity * sizeof(char));
    if (!str) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (size >= capacity - 1) {
            capacity *= 2;
            str = realloc(str, capacity * sizeof(char));
            if (!str) {
                printf("Memory reallocation failed!\n");
                exit(1);
            }
        }
        str[size++] = ch;
    }
    str[size] = '\0';
    return str;
}

int main() {
    printf("Enter logStream: ");
    char* logStream = getInputString();

    printf("Enter pattern: ");
    char* pattern = getInputString();

    int returnSize;
    int* indices = findAnagrams(logStream, pattern, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", indices[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    // Cleanup
    free(logStream);
    free(pattern);
    free(indices);

    return 0;
}
