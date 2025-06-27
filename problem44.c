#include <stdio.h>
#include <stdlib.h>

void getStudentsNo(int *n){
    while (1)
    {
        printf("Enter the no of students (1 - 1000): ");
        scanf("%d", n);
        if(*n >= 1 && *n <= 1000) break;
        printf("!! Invalid Input !!\n");
    }   
}

int memoryCheck(int *memory){
    if(memory == NULL){
        printf("Memory Allocation Failed\n");
        return 1;
    }
    return 0;
}

void entryStudent(int *student, int n){
    printf("Enter student preferences (0 / 1): ");
    for(int i = 0; i < n; i++){
        scanf("%d", &student[i]);
        if(student[i] != 1 && student[i] != 0){
            printf("!! Invalid Input !!\n");
            i--;
        }
    }
}

void entrySandwich(int *sandwich, int n){
    printf("Enter sandwich stack (0 / 1): ");
    for(int i = 0; i < n; i++){
        scanf("%d", &sandwich[i]);
        if(sandwich[i] != 1 && sandwich[i] != 0){
            printf("!! Invalid Input !!\n");
            i--;
        }
    }
}

void entryOfList(int *list, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
        if(list[i] != 1 && list[i] != 0){
            printf("!! Invalid Input !!\n");
            i--;
        }
    }
}


void popFirstElement(int *student, int *sandwich, int *n){
    for(int i = 0; i < *n - 1; i++){
        student[i] = student[i+1];
        sandwich[i] = sandwich[i+1];
    }
    (*n)--;
}

void studentStackUpdate(int *student, int n){
    int temp = student[0];
    for(int i = 0; i < n - 1; i++){
        student[i] = student[i+1];
    }
    student[n - 1] = temp;
}

int checkUnableStudent(int *student, int *sandwich, int n){
    int unableStudent = 0;
    while (n > 0 && unableStudent < n)
    {
        if (student[0] == sandwich[0]){
            popFirstElement(student, sandwich, &n);
            unableStudent = 0;
        }
        else{
            studentStackUpdate(student, n);        
            unableStudent++;
        }
        
    }
    return n;
}




int main(){
    int n;
    getStudentsNo(&n);

    int *student = (int*)malloc(n * sizeof(int));
    if(memoryCheck(student)) return 1;

    int *sandwich = (int*)malloc(n * sizeof(int));
    if(memoryCheck(sandwich)){
        free(student);
        return 1;
    }

    printf("Enter student preferences (0 / 1): ");
    entryOfList(student, n);

    printf("Enter sandwich stack (0 / 1): ");
    entryOfList(sandwich, n);

    int unableStudent = checkUnableStudent(student, sandwich, n);

    printf("No of students unable to eat: %d\n", unableStudent);
    free(student);
    free(sandwich);
    return 0;
}