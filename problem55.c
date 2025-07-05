#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_LENGTH 10001

typedef struct {
    char ch;
    int freq;
} CharFreq;

void swap(CharFreq *a, CharFreq *b) {
    CharFreq temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(CharFreq heap[], int n, int i) {
    int largest = i, left = 2*i + 1, right = 2*i + 2;
    if (left < n && heap[left].freq > heap[largest].freq) largest = left;
    if (right < n && heap[right].freq > heap[largest].freq) largest = right;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void heapifyUp(CharFreq heap[], int i) {
    while (i > 0 && heap[i].freq > heap[(i - 1) / 2].freq) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insertHeap(CharFreq heap[], int *size, CharFreq val) {
    heap[(*size)++] = val;
    heapifyUp(heap, *size - 1);
}

CharFreq removeMax(CharFreq heap[], int *size) {
    CharFreq top = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return top;
}

int memoryCheck(void *ptr) {
    if (!ptr) {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    return 0;
}

char *readInputString() {
    char *input = (char*)malloc(MAX_LENGTH * sizeof(char));
    if (memoryCheck(input)) return NULL;

    printf("Enter the initial banner string (lowercase letters only): ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;
    return input;
}

char *rearrangeString(char *s) {
    int len = strlen(s);
    int freq[ALPHABET_SIZE] = {0};

    for (int i = 0; i < len; i++) {
        if (!islower(s[i])) {
            printf("Invalid character detected.\n");
            return NULL;
        }
        freq[s[i] - 'a']++;
    }

    int maxFreq = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    if (maxFreq > (len + 1) / 2) {
        char *empty = (char*)malloc(1);
        if (memoryCheck(empty)) return NULL;
        empty[0] = '\0';
        return empty;
    }

    CharFreq heap[ALPHABET_SIZE];
    int heapSize = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i]) {
            CharFreq cf = { (char)(i + 'a'), freq[i] };
            insertHeap(heap, &heapSize, cf);
        }
    }

    char *result = (char*)malloc((len + 1) * sizeof(char));
    if (memoryCheck(result)) return NULL;
    int index = 0;

    CharFreq prev = { '#', 0 };

    while (heapSize > 0) {
        CharFreq current = removeMax(heap, &heapSize);
        result[index++] = current.ch;
        current.freq--;

        if (prev.freq > 0)
            insertHeap(heap, &heapSize, prev);

        prev = current;
    }

    result[index] = '\0';
    return result;
}

void displayResult(char *output) {
    printf("Rearranged Banner: ");
    if (strlen(output) == 0)
        printf("Impossible to arrange without repetition.\n");
    else
        printf("%s\n", output);
}

int main() {
    char *input = readInputString();
    if (!input) return 1;

    char *result = rearrangeString(input);
    if (!result) {
        free(input);
        return 1;
    }

    displayResult(result);

    free(input);
    free(result);
    return 0;
}
