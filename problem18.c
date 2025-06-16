#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 101       // A prime number for hashing
#define BASE 256      // Number of possible characters (for extended ASCII)

// Helper function to compute initial hash
unsigned long long computeHash(char *str, int len) {
    unsigned long long hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (hash * BASE + str[i]) % MOD;
    }
    return hash;
}

// This function updates the hash by removing the first character and adding the next
unsigned long long updateHash(char *text, int start, int len, unsigned long long oldHash, unsigned long long highestPower) {
    oldHash = (oldHash + MOD - (text[start] * highestPower) % MOD) % MOD;
    oldHash = (oldHash * BASE + text[start + len]) % MOD;
    return oldHash;
}

// Main function to find all matching indices using Rabin-Karp algorithm
int* findMatches(char *text, char *pattern, int *matchCount) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);

    *matchCount = 0;
    if (patLen > textLen) return NULL;

    unsigned long long patHash = computeHash(pattern, patLen);
    unsigned long long currHash = computeHash(text, patLen);

    // Precompute BASE^(patLen-1)
    unsigned long long highestPower = 1;
    for (int i = 0; i < patLen - 1; i++) {
        highestPower = (highestPower * BASE) % MOD;
    }

    int *indices = (int *)malloc(textLen * sizeof(int)); // Worst case allocation

    for (int i = 0; i <= textLen - patLen; i++) {
        if (patHash == currHash) {
            // Match hashes — verify by comparing actual strings
            if (strncmp(text + i, pattern, patLen) == 0) {
                indices[(*matchCount)++] = i;
            }
        }

        // Roll the hash for the next window
        if (i < textLen - patLen) {
            currHash = updateHash(text, i, patLen, currHash, highestPower);
        }
    }

    return indices;
}

int main() {
    char text[100005], pattern[1005];
    
    // Taking input for text and pattern
    printf("Enter the main text: ");
    scanf("%s", text);

    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    int count = 0;
    int *positions = findMatches(text, pattern, &count);

    printf("Matching indices: [");
    for (int i = 0; i < count; i++) {
        printf("%d", positions[i]);
        if (i != count - 1) printf(", ");
    }
    printf("]\n");

    free(positions);
    return 0;
}
