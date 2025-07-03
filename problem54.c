#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100000

// Memory checker for safer malloc/realloc/calloc
int memoryCheck(void *ptr)
{
    if (!ptr)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    return 0;
}

// Reads space-separated integers dynamically
int *readInput(int *length)
{
    char input[BUFFER_SIZE];
    int capacity = 10, count = 0;
    int *arr = (int *)malloc(capacity * sizeof(int));
    if (memoryCheck(arr))
        return NULL;

    printf("Enter the enchantment codes (space-separated): ");
    fgets(input, BUFFER_SIZE, stdin);

    char *token = strtok(input, " \n");
    while (token)
    {
        int val = atoi(token);
        if (count >= capacity)
        {
            capacity *= 2;
            arr = (int *)realloc(arr, capacity * sizeof(int));
            if (memoryCheck(arr))
                return NULL;
        }
        arr[count++] = val;
        token = strtok(NULL, " \n");
    }

    *length = count;
    return arr;
}

// Finds the duplicate and missing number from the enchantment list
void findDuplicateAndMissing(int *nums, int n, int *duplicate, int *missing)
{
    int *freq = (int *)calloc(n + 1, sizeof(int));
    if (memoryCheck(freq))
        return;

    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
            *missing = i;
        else if (freq[i] == 2)
            *duplicate = i;
    }

    free(freq);
}

// Displays the final result
void displayResult(int duplicate, int missing)
{
    printf("\n[%d, %d]\n", duplicate, missing);
}

int main()
{
    int *nums = NULL, n = 0;
    int duplicate = -1, missing = -1;

    nums = readInput(&n);
    if (!nums)
        return 1;

    findDuplicateAndMissing(nums, n, &duplicate, &missing);
    displayResult(duplicate, missing);

    free(nums);
    return 0;
}
