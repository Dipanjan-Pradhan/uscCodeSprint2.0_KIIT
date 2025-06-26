#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 10000

int countNumbers(char *line){
    int count = 0, inNumber = 0;
    for(int i = 0; line[i]; i++){
        if (isdigit(line[i])){
            if (!inNumber){
                count++;
                inNumber = 1;
            }
        } else if (isspace(line[i])){
            inNumber = 0;
        }
    }
    return count;
}

int* parseTickets(char *line, int *n){
    *n = countNumbers(line);
    if (*n == 0){
        printf("No tickets entered.\n");
        exit(1);
    }

    int *arr = (int *)malloc((*n) * sizeof(int));
    if (!arr){
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int index = 0;
    char *token = strtok(line, " ");
    while (token){
        arr[index++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

int calculateTime(int *tickets, int n, int k){
    int time = 0;
    for (int i = 0; i < n; i++){
        if (i <= k)
            time += (tickets[i] < tickets[k]) ? tickets[i] : tickets[k];
        else
            time += (tickets[i] < tickets[k]) ? tickets[i] : (tickets[k] - 1);
    }
    return time;
}

int main(){
    char input[MAX_LINE];
    int n, k;

    printf("Enter the no of tickets array:\n");
    fgets(input, sizeof(input), stdin);

    int *tickets = parseTickets(input, &n);

    printf("Enter k(target visitor) = ");
    scanf("%d", &k);

    if (k < 0 || k >= n){
        printf("Invalid index k.\n");
        free(tickets);
        return 1;
    }

    int result = calculateTime(tickets, n, k);
    printf("Total time = %d seconds\n", result);

    free(tickets);
    return 0;
}
