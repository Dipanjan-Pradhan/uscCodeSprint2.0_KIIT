#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findUpperCase(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            printf("!! Upper Case Found !!\n");
            return 1;
        }
        if (str[i] < 'a' || str[i] > 'z')
        {
            printf("!! Another Character Found !!\n");
            return 1;
        }
    }
    return 0;
}

void getName(char *str)
{
    while (1)
    {
        printf("Enter the word in lowercase(1 - 1000): ");
        scanf("%s", str);
        while (getchar() != '\n')
            ;
        if (!findUpperCase(str) && strlen(str) >= 1 && strlen(str) <= 1000)
            break;
        printf("!! Invalid Input !!\n");
    }
}

int checkCharFreq(char *str)
{
    int len = strlen(str);
    int *freq = (int *)calloc(26, sizeof(int));
    if (freq == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    for (int i = 0; i < len; i++)
    {
        freq[str[i] - 'a']++;
    }

    int target = 0;
    int isBalanced = 1;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            if (target == 0)
                target = freq[i];
            else if (freq[i] != target)
            {
                isBalanced = 0;
                break;
            }
        }
    }

    if (isBalanced)
    {
        printf("Aashriya smiles: Emotional balance found\n");
    }
    else
        printf("Aashriya wonders: These thoughts were scattered\n");

    free(freq);
}

int main()
{
    char *str = (char *)malloc(1000 * sizeof(char));
    if (str == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    getName(str);

    checkCharFreq(str);

    free(str);
    return 0;
}