#include <stdio.h>
#include <stdlib.h>

void motivationMsg()
{
    printf("THE PAIN YOU FEEL TODAY IS THE STRENGTH YOU FEEL TOMORROW\n");
    return;
}

void getWorkoutDays(int *n)
{
    while (1)
    {
        printf("Enter the no of training days (1 - 20): ");
        scanf("%d", n);
        if (*n >= 1 && *n <= 20)
        {
            if (*n > 10)
                motivationMsg();
            break;
        }
        printf("!! Invalid Input !!\n");
    }
}

void printWaveChart(int n)
{
    int totalNumbers = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        if (i % 2 == 1)
        {
            for (int k = 1; k <= i; k++)
            {
                printf("%3d", k);
                totalNumbers++;
            }
        }
        else
        {
            for (int k = i; k >= 1; k--)
            {
                printf("%3d", k);
                totalNumbers++;
            }
        }
        printf("\n");
    }

    printf("Total numbers printed: %d", totalNumbers);
    return;
}

int main()
{
    int n;
    getWorkoutDays(&n);
    printWaveChart(n);
    return 0;
}