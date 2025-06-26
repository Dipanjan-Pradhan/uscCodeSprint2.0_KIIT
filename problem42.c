#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 10000

typedef struct {
    int *data;
    int front, rear, size;
} Deque;

Deque* createDeque(int capacity) {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(capacity * sizeof(int));
    dq->front = dq->rear = 0;
    dq->size = capacity;
    return dq;
}

void pushFront(Deque *dq, int val) {
    dq->front = (dq->front - 1 + dq->size) % dq->size;
    dq->data[dq->front] = val;
}

void pushBack(Deque *dq, int val) {
    dq->data[dq->rear] = val;
    dq->rear = (dq->rear + 1) % dq->size;
}

int popBack(Deque *dq) {
    dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    return dq->data[dq->rear];
}

int isEmpty(Deque *dq) {
    return dq->front == dq->rear;
}

void freeDeque(Deque *dq) {
    free(dq->data);
    free(dq);
}

int countNumbers(const char *line) {
    int count = 0, inside = 0;
    for (int i = 0; line[i]; i++) {
        if (isdigit(line[i])) {
            if (!inside) {
                count++;
                inside = 1;
            }
        } else if (isspace(line[i])) {
            inside = 0;
        }
    }
    return count;
}

int* parseInput(char *line, int *n) {
    *n = countNumbers(line);
    if (*n == 0) {
        printf("No numbers entered. Try again.\n");
        exit(1);
    }

    int *arr = (int*)malloc(*n * sizeof(int));
    int idx = 0;

    char *token = strtok(line, " ");
    while (token) {
        arr[idx++] = atoi(token);
        token = strtok(NULL, " ");
    }

    return arr;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void performMagicTrick(int *cards, int n) {
    qsort(cards, n, sizeof(int), compare);

    Deque *dq = createDeque(2 * n);

    for (int i = n - 1; i >= 0; i--) {
        if (!isEmpty(dq)) {
            int last = popBack(dq);
            pushFront(dq, last);
        }
        pushFront(dq, cards[i]);
    }

    int *finalDeck = (int*)malloc(n * sizeof(int));
    int idx = 0;
    while (!isEmpty(dq)) {
        finalDeck[idx++] = dq->data[dq->front];
        dq->front = (dq->front + 1) % dq->size;
    }

    qsort(finalDeck, n, sizeof(int), compare);
    printf("Initial deck order in increasing order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", finalDeck[i]);
    }
    printf("\n");

    free(finalDeck);
    freeDeque(dq);
}

int main() {
    char line[MAX_INPUT];

    printf("Enter the card values (space-separated): ");
    fgets(line, sizeof(line), stdin);

    int n;
    int *deck = parseInput(line, &n);

    performMagicTrick(deck, n);

    free(deck);
    return 0;
}
