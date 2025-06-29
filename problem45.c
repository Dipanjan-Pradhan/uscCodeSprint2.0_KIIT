#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INITIAL_SIZE 10
#define MAX_ROOM_JUMP 10000

// Doubly-ended queue node structure
typedef struct {
    int index;
    int value;
} Pair;

void getPointsArray(int **arr, int *count) {
    int size = INITIAL_SIZE;
    *count = 0;
    int num = 0, ch, reading = 0;

    *arr = malloc(size * sizeof(int));
    if (!(*arr)) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter room values (space-separated, press Enter to finish):\n");

    while ((ch = getchar()) != '\n') {
        if (isdigit(ch) || (ch == '-' && !reading)) {
            ungetc(ch, stdin);
            scanf("%d", &num);
            reading = 1;

            if (*count >= size) {
                size *= 2;
                int *temp = realloc(*arr, size * sizeof(int));
                if (!temp) {
                    printf("Memory reallocation failed.\n");
                    free(*arr);
                    exit(1);
                }
                *arr = temp;
            }

            (*arr)[(*count)++] = num;
        } else {
            reading = 0;
        }
    }
}

void getMaxRoomJump(int *k) {
    while (1) {
        printf("Enter max number of rooms you can jump (1 to %d): ", MAX_ROOM_JUMP);
        scanf("%d", k);
        if (*k >= 1 && *k <= MAX_ROOM_JUMP) break;
        printf("Invalid input. Try again.\n");
    }
}

// Dynamic Programming + Deque solution
int getMaxScore(int *arr, int n, int k) {
    int *dp = malloc(n * sizeof(int));
    if (!dp) {
        printf("Memory allocation failed for DP.\n");
        return 0;
    }

    dp[0] = arr[0];

    int *dq = malloc(n * sizeof(int));
    int front = 0, back = 0;
    dq[back++] = 0;

    for (int i = 1; i < n; i++) {
        if (dq[front] < i - k) front++;  // remove out-of-range indices

        dp[i] = arr[i] + dp[dq[front]];

        while (back > front && dp[i] >= dp[dq[back - 1]]) back--;  // maintain decreasing order
        dq[back++] = i;
    }

    int result = dp[n - 1];

    free(dp);
    free(dq);
    return result;
}

int main() {
    int *rooms = NULL, roomCount = 0, maxJump = 0;

    getPointsArray(&rooms, &roomCount);
    getMaxRoomJump(&maxJump);

    int score = getMaxScore(rooms, roomCount, maxJump);
    printf("\nMaximum path score: %d\n", score);

    free(rooms);
    return 0;
}
