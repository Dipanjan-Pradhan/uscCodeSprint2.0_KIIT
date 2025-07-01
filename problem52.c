#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int frequency;
} Element;

// Function to sort by frequency (descending), then by value (ascending)
int compare(const void *a, const void *b) {
    Element *x = (Element *)a;
    Element *y = (Element *)b;

    if (x->frequency != y->frequency)
        return y->frequency - x->frequency; // Higher frequency first
    else
        return x->value - y->value;         // Lower number first if equal frequency
}

// Function to count how many times each number appears
int buildFrequencyMap(int *arr, int n, Element **freqArr) {
    int capacity = n;
    *freqArr = (Element *)malloc(capacity * sizeof(Element));
    if (!*freqArr) {
        printf("Oops! Couldn't allocate memory.\n");
        exit(1);
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < count; j++) {
            if ((*freqArr)[j].value == arr[i]) {
                (*freqArr)[j].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            (*freqArr)[count].value = arr[i];
            (*freqArr)[count].frequency = 1;
            count++;
        }
    }

    return count;
}

int main() {
    int n;

    // Step 1: Take number of crates
    printf(" How many crates are there? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("⚠️ You need to enter at least one crate.\n");
        return 1;
    }

    // Step 2: Allocate memory to store crate labels
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("💥 Memory allocation failed. Please try again.\n");
        return 1;
    }

    // Step 3: Take all crate labels from user
    printf("🔢 Please enter the labels of the crates:\n");
    for (int i = 0; i < n; i++) {
        printf("Label %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Step 4: Create frequency map
    Element *freqArr;
    int uniqueCount = buildFrequencyMap(arr, n, &freqArr);

    // Step 5: Sort crate labels by frequency and value
    qsort(freqArr, uniqueCount, sizeof(Element), compare);

    // Step 6: Display the result
    printf("\n✅ Sorted crate labels by frequency:\n");
    for (int i = 0; i < uniqueCount; i++) {
        for (int j = 0; j < freqArr[i].frequency; j++) {
            printf("%d ", freqArr[i].value);
        }
    }
    printf("\n");

    // Step 7: Clean up
    free(arr);
    free(freqArr);

    return 0;
}
