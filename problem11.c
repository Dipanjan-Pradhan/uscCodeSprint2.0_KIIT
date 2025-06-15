#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidString(char *str)
{
    int len = strlen(str);
    if (len < 1 || len > 50)
    {
        printf("!! Invalid Input !!\n");
        return 1;
    }

    while (*str)
    {
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
        {
            printf("!! Invalid Input !!\n");
            return 1;
        }
        str++;
    }
    return 0;
}

char *readString()
{
    char *str = NULL;
    int size = 0;
    int capacity = 7;
    char ch;

    str = (char *)malloc(capacity * sizeof(char));
    if (str == NULL)
    {
        printf("!! Memory Allocation Failed !!\n");
        return NULL;
    }

    while (1)
    {
        size = 0;
        while ((ch = getchar()) != '\n' && (ch != EOF))
        {
            if (size >= capacity - 1)
            {
                capacity *= 2;
                char *temp = realloc(str, capacity * sizeof(char));
                if (temp == NULL)
                {
                    free(str);
                    printf("!! Memory Allocation Failed !!\n");
                    return NULL;
                }
                str = temp;
            }
            str[size++] = ch;
        }
        str[size] = '\0';

        if (!isValidString(str))
            break;
        printf("!! Try Again with valid Input: ");
    }
    return str;
}

int countJewels(char *jewels, char *stones)
{
    int jewelLen = strlen(jewels);
    int stoneLen = strlen(stones);
    int jewelCount = 0;
    for (int i = 0; i < stoneLen; i++)
    {
        for (int j = 0; j < jewelLen; j++)
        {
            if (stones[i] == jewels[j])
                jewelCount++;
        }
    }
    return jewelCount;
}

int main()
{
    printf("Enter the stones that are jewels: ");
    char *jewels = readString();

    printf("Enter the type of stones: ");
    char *stones = readString();

    int jewelsNo = countJewels(jewels, stones);
    printf("The no of stones that are jewels: %d", jewelsNo);

    free(jewels);
    free(stones);
    return 0;
}