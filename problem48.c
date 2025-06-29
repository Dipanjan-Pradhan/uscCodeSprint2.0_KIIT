#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_LEN 100000
#define MAX_ID 1000000000

void getCitizensNo(int *n){
    while (1){
        printf("Enter the no of citizens in the queue (1 - %d): ", MAX_QUEUE_LEN);
        scanf("%d", n);
        if (*n >= 1 && *n <= MAX_QUEUE_LEN)
            break;
        printf("!! Invalid Input !!\n");
    }
}

int isValidId(int n){
    if (n >= 0 && n <= MAX_ID)
        return 1;
    return 0;
}

void getQueueId(int *queue, int n){
    printf("Enter the ID's of the citizens (0 - %d): ", MAX_ID);
    for (int i = 0; i < n; i++){
        scanf("%d", &queue[i]);
        if (!isValidId(queue[i])){
            printf("!! Invalid ID !!\n");
            i--;
        }
    }
}

void reverseQueue(int *queue, int n){
    int temp;
    for (int i = 0; i < n / 2; i++){
        temp = queue[i];
        queue[i] = queue[n - i - 1];
        queue[n - i - 1] = temp;
    }
}

void printQueue(int *queue, int n){
    printf("Reversed Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", queue[i]);
    
}

int main(){
    int n;
    getCitizensNo(&n);
    int *queue = (int *)malloc(n * sizeof(int));
    if (!queue){
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    getQueueId(queue, n);
    reverseQueue(queue, n);
    printQueue(queue, n);

    free(queue);
    return 0;
}