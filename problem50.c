#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 12
#define MAX_TILES 10000
#define MAX_VALUE 1000000000

void getTilesNo(int *n)
{
    while (1)
    {
        printf("Enter the no of tiles (1 - %d): ", MAX_TILES);
        scanf("%d", n);
        if (*n >= 1 && *n <= MAX_TILES)
            break;
        printf("!! Invalid Input !!\n");
    }
}

int memoryCheck(void *ptr)
{
    if (!ptr)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    return 0;
}

void getTilesValue(char **tiles, int n)
{
    printf("Enter the tile number: ");
    for (int i = 0; i < n; i++)
    {
        long long num;
        scanf("%lld", &num);
        tiles[i] = (char *)malloc(MAX_DIGITS * sizeof(char));
        if (memoryCheck(tiles[i]))
        {
            for (int j = 0; j < i; j++)
            {
                free(tiles[j]);
            }
            free(tiles);
            exit(1);
        }
        sprintf(tiles[i], "%lld", num);
    }
}

int compare(const void *a, const void *b)
{
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;

    char ab[MAX_DIGITS * 2], ba[MAX_DIGITS * 2];
    strcpy(ab, s1);
    strcat(ab, s2);

    strcpy(ba, s2);
    strcat(ba, s1);

    return strcmp(ba, ab);
}

void printMaxNumber(char **tiles, int n)
{
    if (strcmp(tiles[0], "0") == 0)
        printf("0\n");
    else
    {
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("%s", tiles[i]);
            free(tiles[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    getTilesNo(&n);

    char **tiles = (char **)malloc(n * sizeof(char *));
    if (memoryCheck(tiles))
        exit(1);
    getTilesValue(tiles, n);

    qsort(tiles, n, sizeof(char *), compare);
    printMaxNumber(tiles, n);

    free(tiles);
    return 0;
}
