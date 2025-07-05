#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SCORE 1000000000
#define MAX_RANK_LEN 20
#define BUFFER_SIZE 100000

typedef struct {
    int score;
    int originalIndex;
} Robot;

int memoryCheck(void *ptr){
    if (!ptr) {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    return 0;
}

int isSameScore(int *scores, int currScore, int n){
    for (int i = 0; i < n; ++i) {
        if (scores[i] == currScore) return 1;
    }
    return 0;
}

int compareScores(const void *a, const void *b){
    return ((Robot*)b)->score - ((Robot*)a)->score;
}

void assignRanks(char **ranks, Robot *robots, int n){
    for (int i = 0; i < n; ++i) {
        int idx = robots[i].originalIndex;
        ranks[idx] = (char *)malloc(MAX_RANK_LEN * sizeof(char));
        if (memoryCheck(ranks[idx])) {
            for (int j = 0; j < i; j++) free(ranks[j]);
            free(ranks);
            exit(1);
        }

        if (i == 0) strcpy(ranks[idx], "Gold Medal");
        else if (i == 1) strcpy(ranks[idx], "Silver Medal");
        else if (i == 2) strcpy(ranks[idx], "Bronze Medal");
        else sprintf(ranks[idx], "%d", i + 1);
    }
}

int main() {
    char input[BUFFER_SIZE];
    int *scores = NULL;
    int capacity = 10, count = 0;

    scores = (int *)malloc(capacity * sizeof(int));
    if (memoryCheck(scores)) return 1;

    printf("Enter the scores:\n");
    fgets(input, BUFFER_SIZE, stdin);

    char *token = strtok(input, " \n");
    while (token) {
        int num = atoi(token);

        if (num < 0 || num > MAX_SCORE) {
            printf("!! Invalid Score %d !! Skipping...\n", num);
            token = strtok(NULL, " \n");
            continue;
        }

        if (isSameScore(scores, num, count)) {
            printf("!! Duplicate Score %d Ignored !!\n", num);
            token = strtok(NULL, " \n");
            continue;
        }

        if (count >= capacity) {
            capacity *= 2;
            scores = (int *)realloc(scores, capacity * sizeof(int));
            if (memoryCheck(scores)) return 1;
        }

        scores[count++] = num;
        token = strtok(NULL, " \n");
    }

    if (count == 0) {
        printf("No valid scores entered.\n");
        free(scores);
        return 0;
    }

    Robot *robots = (Robot *)malloc(count * sizeof(Robot));
    char **ranks = (char **)malloc(count * sizeof(char *));
    if (memoryCheck(robots) || memoryCheck(ranks)) {
        free(scores);
        free(robots);
        free(ranks);
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        robots[i].score = scores[i];
        robots[i].originalIndex = i;
    }

    qsort(robots, count, sizeof(Robot), compareScores);
    assignRanks(ranks, robots, count);

    printf("\nFinal Rankings:\n[");
    for (int i = 0; i < count; ++i) {
        printf("\"%s\"", ranks[i]);
        if (i != count - 1) printf(", ");
        free(ranks[i]);
    }
    printf("]\n");
 
    free(scores);
    free(robots);
    free(ranks);
    return 0;
}
