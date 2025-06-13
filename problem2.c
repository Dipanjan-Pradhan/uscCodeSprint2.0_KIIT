#include <stdio.h>
#include <stdlib.h>

void checkShot(int n, int *shots, int *goodShot, int *badShot){
    for (int i = 0; i < n; i++){
        if (*(shots + i) >= 7)
            (*goodShot)++;
        else if (*(shots + i) < 7)
            (*badShot)++;
    }
    return;
}

int main(){
    int n, goodShot = 0, badShot = 0;
    scanf("%d", &n);

    int *shots = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &shots[i]);
        if (shots[i] > 10 || shots[i] < 0)
        {
            printf("Invalid Score\n");
            i--;
        }
    }

    checkShot(n, shots, &goodShot, &badShot);
    printf("%d %d", goodShot, badShot);

    free(shots);
    return 0;
}