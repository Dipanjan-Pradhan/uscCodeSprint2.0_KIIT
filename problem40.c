#include <stdio.h>
#include <stdlib.h>

int *takeInput(int *n){
  printf("Enter the number of elements in the array: ");
  scanf("%d", n);

  if(*n <= 0){
    printf("!! Invalid Input !!\n");
    exit(1);
  }

  int *arr = (int *)malloc((*n) * sizeof(int));
  if(!arr){
    printf("Memory Allocation Failed\n");
    exit(1);
  }

  printf("Enter %d integers: ", *n);
  for(int i = 0; i < *n; i++){
    scanf("%d", &arr[i]);
  }
  
  return arr;
}

void findNextGreater(int *arr, int *nextGreater, int n){
  int *stack = (int *)malloc(n * sizeof(int));
  int top = -1;

  for(int i = n - 1; i >= 0; i--){
    while(top >= 0 && arr[stack[top]] <= arr[i])
      top--;
    nextGreater[i] = (top == -1) ? -1 : stack[top];
    stack[++top] = i;
  }
  free(stack);
}

void solveMysticalArray(int *arr, int *nextGreater, int *result, int n){
  for(int i = 0; i < n; i++){
    int ng = nextGreater[i];
    if(ng == -1){
      result[i] = -1;
      continue;
    }

    int found = 0;
    for(int j = ng + 1; j < n; j++){
      if(arr[j] < arr[ng]){
        result[i] = arr[j];
        found = 1;
        break;
      }
    }
    if(!found) result[i] = -1;
  }
}

void displayResult(int *result, int n){
  printf("Output: ");
  for(int i = 0; i < n; i++){
    printf("%d", result[i]);
  }
}


int main(){
  int n;
  int *arr = takeInput(&n);
  int *nextGreater = (int*)malloc(n * sizeof(int));
  int *result = (int*)malloc(n * sizeof(int));

  if(!nextGreater || !result){
    printf("Memory Allocation Failed\n");
    free(arr);
    exit(1);
  }

  findNextGreater(arr, nextGreater, n);
  solveMysticalArray(arr, nextGreater, result, n);
  displayResult(result, n);

  free(arr);
  free(nextGreater);
  free(result);

  return 0;
}
