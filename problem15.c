#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void getInputData(int *target, int *n){
  while(1){
    printf("Enter target calories: ");
    scanf("%d", target);
  
    printf("Enter number of workout sessions: ");
    scanf("%d", n);
    if(*target >= 1 && *target <= 1e9 && *n >= 1 && *n <= 1e5) break;
    printf("!! Invalid Input !!\n");
  }
}

int *getSessionData(int n){
  int *sessions = (int *)malloc(n * sizeof(int));
  if(sessions == NULL){
    printf("Memory Allocation Failed\n");
    exit(1);
  }

  printf("Enter calories burned in each sessions: ");
  for(int i = 0; i < n; i++){
    scanf("%d", &sessions[i]);
    if(sessions[i] < 1 || sessions[i] > 1e4){
      printf("!! Invalid Input !!\n");
      i--;
      }
  }

  return sessions;
}


int findMinLen(int target, int *sessions, int n){
  int minLen = INT_MAX;
  int start = 0, sum = 0;

  for(int end = 0; end < n; end++){
    sum += sessions[end];

    while(sum >= target){
      int currLen = end - start + 1;
      if(currLen < minLen) minLen = currLen;
      sum -= sessions[start];
      start++;
    }
  }

  return (minLen == INT_MAX) ? 0 : minLen;
}


int main(){
  int target, n;
  getInputData(&target, &n);

  int *sessions = getSessionData(n);

  int result = findMinLen(target, sessions, n);

  printf("Minimum number of consecutive sessions: %d\n", result);

  free(sessions);
  return 0;
}
