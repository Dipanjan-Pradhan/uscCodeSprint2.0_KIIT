#include <stdio.h>
#include <stdlib.h>

// This function calculates how much rainwater can be trapped
int calculateTrappedWater(int *height, int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                totalWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                totalWater += rightMax - height[right];
            }
            right--;
        }
    }

    return totalWater;
}

int main() {
    int n;

    printf("How many buildings are there? ");
    scanf("%d", &n);

    // Basic input check
    if (n <= 0) {
        printf("Number of buildings must be greater than zero.\n");
        return 1;
    }

    // Allocate space to store building heights
    int *heights = (int *)malloc(n * sizeof(int));
    if (heights == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // Ask user to enter the building heights
    printf("Enter the height of each building :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);

        if (heights[i] < 0) {
            printf("!! Invalid Input !!\n");
            free(heights);
            return 1;
        }
    }

    // Call the function and display the result
    int trapped = calculateTrappedWater(heights, n);
    printf("The total amount of trapped rainwater is: %d units\n", trapped);

    // Free the memory used
    free(heights);

    return 0;
}
