#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100000
#define MAX_LINE_LENGTH 1000000

void zigZagReorder(int appointments[], int n){
  int result[n];
  int start = 0, end = n - 1, index = 0;


  while(start <= end){
    if(start == end){
      result[index++] = appointments[start++];
    }
    else{
      result[index++] = appointments[start++];
      result[index++] = appointments[end--];
    }
  }

  printf("Reordered Appointments in Zig-Zag Pattern:\n");
  for(int i = 0; i < n; i++){
    printf("%d", result[i]);
    if(i < n - 1) printf(", ");
  }

  printf("\n");
}

int main(){
  int appointments[MAX_APPOINTMENTS];
  int n = 0;
  char line[MAX_LINE_LENGTH];

  printf("Enter appointment IDs: ");
  if(fgets(line, sizeof(line), stdin) == NULL || line[0] == '\n'){
    printf("No appointments entered\n");
    return 1;    
  }

  char *token = strtok(line, " \n");
  while(token != NULL){
    appointments[n++] = atoi(token);
    token = strtok(NULL, " \n");
  }

  if(n == 0){
    printf("!! Invalid Input !!\n");
    return 1;
  }


  zigZagReorder(appointments, n);
  return 0;  
}