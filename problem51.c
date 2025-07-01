#include <stdio.h>
#include <stdlib.h>

#define MAX_TARGET 10000000
#define MIN_TARGET -10000000
#define MAX_VALUE 100000
#define MIN_VALUE -100000

void getCrystalNo(int *n){
    while (1){
        printf("Enter the number of crystals (3 - 1000): ");
        scanf("%d", n);
        if(*n >= 3 && *n <= 1000) break;
        printf("!! Invalid Input !!\n");
    }
}

void getTarget(int *target){
    while (1){
        printf("Enter the target warp energy: ");
        scanf("%d", target);
        if(*target >= MIN_TARGET && *target <= MAX_TARGET) break;
        printf("!! Invalid Input !!\n");
    }
}

void getEnergyValues(int *arr, int n){
    printf("Enter the energy values of crystals: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(!(arr[i] >= MIN_VALUE && arr[i] <= MAX_VALUE)){
            printf("!! Invalid Input at index %d !!\n", i+1);
            i--;
        } 
    }
}

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int closestTripletSum(int *arr, int n, int target){
    qsort(arr, n, sizeof(int), compare);

    int closestSum = arr[0] + arr[1] + arr[2];

    for (int i = 0; i < n - 2; i++){
        int left = i + 1, right = n - 1;

        while (left < right){
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum == target)
                return currentSum;

            if (abs(currentSum - target) < abs(closestSum - target) || 
                (abs(currentSum - target) == abs(closestSum - target) && currentSum > closestSum))
            {
                closestSum = currentSum;
            }

            if (currentSum < target)
                left++;
            else
                right--;
        }
    }

    return closestSum;
}


int main(){
    int n, target;
    getCrystalNo(&n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr){
        printf("Memory allocation failed.\n");
        return 1;
    }

    getEnergyValues(arr, n);
    getTarget(&target);

    int result = closestTripletSum(arr, n, target);
    printf("Output:\n%d\n", result);

    free(arr);
    return 0;
}
