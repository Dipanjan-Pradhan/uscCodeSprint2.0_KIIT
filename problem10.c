#include <stdio.h>
#include <stdlib.h>

void getSize(int *n)
{
    while (1)
    {
        printf("Enter the size of the hall (1 - 50): ");
        scanf("%d", n);
        if (*n >= 1 && *n <= 50)
            break;
        printf("!! Invalid Input !!\n");
    }
}

void printSeats(int n, int *seat)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", seat[i * n + j]);
        }
        printf("\n");
    }
}

int getValidSeat(int n, int *seat)
{
    int validSeats = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 == 0)
            {
                seat[i * n + j] = 1;
                validSeats++;
            }
        }
    }

    printSeats(n, seat);
    return validSeats;
}

int main()
{
    int n;
    getSize(&n);

    int *totalSeats = (int *)calloc(n * n, sizeof(int));
    int validSeat = getValidSeat(n, totalSeats);

    printf("Total student seated: %d\n", validSeat);
    free(totalSeats);
    return 0;
}