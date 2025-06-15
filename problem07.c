#include <stdio.h>
#include <stdlib.h>

void getSize(int *n)
{
    while (1)
    {
        printf("Enter the size of the sq matrix (3 - 100): ");
        scanf("%d", n);

        // if the upper bound was 100 it'd be better one
        if (*n >= 3 && *n <= 1000 && *n % 2 == 1)
            break;
        printf("!! Invalid Input !!\n");
    }
}

void setValue(int n, int *puzzle)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                puzzle[i * n + j] = i + 1;
            else if (i + j == n - 1)
                puzzle[i * n + j] = n - i;
            else
                puzzle[i * n + j] = (int)'-';
        }
    }
    return;
}

void printPuzzle(int n, int *puzzle)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (puzzle[i * n + j] == '-')
            {
                printf("%c ", puzzle[i * n + j]);
                continue;
            }
            printf("%d ", puzzle[i * n + j]);
        }
        printf("\n");
    }
    return;
}

int main()
{
    int n;
    getSize(&n);
    int *puzzle = (int *)malloc(n * n * sizeof(int));
    if (puzzle == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    setValue(n, puzzle);
    printPuzzle(n, puzzle);
    free(puzzle);
    return 0;
}