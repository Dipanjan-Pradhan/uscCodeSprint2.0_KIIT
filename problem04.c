#include <stdio.h>
#include <stdlib.h>

int getNoOfDays()
{
    int n;
    printf("Enter the no of days in the marathon (3-100): ");
    scanf("%d", &n);
    if (n < 3 || n > 100)
    {
        printf("Range exceed\n");
        n = getNoOfDays();
    }
    return n;
}

void getScore(int n, int *scores)
{
    printf("Enter the scores for each day: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (scores + i));
    }
    return;
}

int checkMagicalDay(int n, int *scores)
{
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if ((scores[i] > scores[i - 1]) && (scores[i] > scores[i + 1]))
            count++;
    }
    return count;
}

int main()
{
    int n;
    n = getNoOfDays();

    int *scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    getScore(n, scores);

    int magicalDay = checkMagicalDay(n, scores);

    printf("\nTotal no of magical days = %d\n", magicalDay);

    free(scores);
    return 0;
}