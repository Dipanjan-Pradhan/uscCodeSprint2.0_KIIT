#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to check if any triplet sums to the target
int hasTripletSum(int *arr, int n, int target)
{
    qsort(arr, n, sizeof(int), compare); // Sort the array first

    // Try each number as the first element of the triplet
    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        // Two-pointer approach
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == target) return 1; // Found a triplet
            else if (sum < target) left++;
            else right--;
        }
    }
    return 0; // No such triplet
}

int main()
{
    int n, target;

    printf("Enter the number of magical stones: ");
    scanf("%d", &n);

    if (n < 3){
        printf("At least 3 stones are required.\n");
        return 1;
    }

    // Allocate memory dynamically for the stones
    int *stones = (int *)malloc(n * sizeof(int));
    if (stones == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the stone values (space separated):\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &stones[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Check if a valid triplet exists
    if (hasTripletSum(stones, n, target))
        printf("\ntrue\n"); // Triplet found
    else
        printf("\nfalse\n"); // No triplet matches the target
    

    free(stones); // Clean up
    return 0;
}
