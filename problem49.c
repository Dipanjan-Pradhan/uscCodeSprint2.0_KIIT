#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int hasTripletSum(int *arr, int n, int target){
    qsort(arr, n, sizeof(int), compare); 


    for (int i = 0; i < n - 2; i++){
        int left = i + 1;
        int right = n - 1;

        while (left < right){
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == target) return 1; 
            else if (sum < target) left++;
            else right--;
        }
    }
    return 0; 
}

int main(){
    int n, target;

    printf("Enter the number of magical stones: ");
    scanf("%d", &n);

    if (n < 3){
        printf("At least 3 stones are required.\n");
        return 1;
    }

    int *stones = (int *)malloc(n * sizeof(int));
    if (stones == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the stone values (space separated):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &stones[i]);

    printf("Enter the target sum: ");
    scanf("%d", &target);


    if (hasTripletSum(stones, n, target))
        printf("\ntrue\n");
    else
        printf("\nfalse\n"); 
    

    free(stones);
    return 0;
}
