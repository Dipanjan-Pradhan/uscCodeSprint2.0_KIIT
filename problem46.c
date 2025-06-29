#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

int isValidSenateString(const char *senate) {
    for (int i = 0; senate[i]; i++) {
        if (senate[i] != 'R' && senate[i] != 'D') {
            return 0;
        }
    }
    return 1;
}

void getUserInput(char **senate) {
    *senate = malloc((MAX_LEN + 1) * sizeof(char));
    if (!(*senate)) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    while (1) {
        printf("Enter the senate string (only R and D): ");
        scanf("%10000s", *senate); // limit to MAX_LEN chars
        if (isValidSenateString(*senate)) break;
        printf("Invalid input! Please use only 'R' and 'D'.\n");
    }
}

char* predictPartyVictory(const char *senate) {
    int n = strlen(senate);
    int *radiant = malloc(n * sizeof(int));
    int *dire = malloc(n * sizeof(int));
    int rFront = 0, rBack = 0;
    int dFront = 0, dBack = 0;

    if (!radiant || !dire) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            radiant[rBack++] = i;
        } else {
            dire[dBack++] = i;
        }
    }

    while (rFront < rBack && dFront < dBack) {
        int rIdx = radiant[rFront++];
        int dIdx = dire[dFront++];
        if (rIdx < dIdx) {
            radiant[rBack++] = rIdx + n;
        } else {
            dire[dBack++] = dIdx + n;
        }
    }

    free(radiant);
    free(dire);

    return (rFront < rBack) ? "Radiant" : "Dire";
}

int main() {
    char *senate = NULL;

    getUserInput(&senate);
    char *winner = predictPartyVictory(senate);

    printf("Winning Party: %s\n", winner);

    free(senate);
    return 0;
}
