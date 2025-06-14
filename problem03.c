#include <stdio.h>
#include <stdlib.h>

void getVehicleNo(int n, int *vehicles){
    for (int i = 0; i < n; i++)
        scanf("%d", (vehicles + i));
    return;
}

int checkJamHour(int n, int *vehicles){
    int count = 0;
    for (int i = 1; i < n; i++){
        if (*(vehicles + i) >= 50 && (*(vehicles + i) > *(vehicles + i - 1)))
            count++;
    }
    return count;
}

int main(){
    int n;
    printf("Enter the total no of hours: ");
    scanf("%d", &n);

    int *vehicles = (int *)malloc(n * sizeof(int));
    if (vehicles == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    printf("Enter the no of vehicles for each hour:");
    getVehicleNo(n, vehicles);

    int jamHour = checkJamHour(n, vehicles);

    printf("Total Critical Jam Hour = %d", jamHour);
    free(vehicles);
    
    return 0;
}