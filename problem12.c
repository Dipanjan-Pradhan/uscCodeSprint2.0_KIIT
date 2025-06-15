#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getPatientEntries(int *n)
{
    while (1)
    {
        printf("Enter the no of patient entries of the day (1 - 100): ");
        scanf("%d", n);
        if (*n >= 1 && *n <= 100)
            break;
        printf("!! Invalid Input !!\n");
    }
}

int isValidName(char *str)
{
    int len = strlen(str);
    if (len < 1 || len > 50)
    {
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(str[i]))
            return 0;
    }
    return 1;
}

void getPatientNames(int n, char **names)
{
    char temp[100];
    getchar();
    printf("Enter names of the patients: \n");
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            if ((scanf("%s", temp) == 1) && isValidName(temp))
                break;
            printf("!! Invalid Input !!\n");
        }

        names[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        if (names[i] == NULL)
        {
            printf("Memory Allocation Failed\n");
            for (int j = 0; j < i; j++)
            {
                free(names[j]);
            }
            free(names);
            exit(2);
        }
        strcpy(names[i], temp);
    }
    return;
}

int checkVowel(int n, char **names, char ***vowelNames)
{
    int count = 0;
    *vowelNames = (char **)malloc(n * sizeof(char *));
    if (*vowelNames == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        char ch = names[i][0];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            int isDuplicate = 0;

            for (int j = 0; j < count; j++)
            {
                if (strcmp((*vowelNames)[j], names[i]) == 0)
                {
                    isDuplicate = 1;
                    break;
                }
            }
            if (!isDuplicate)
            {
                (*vowelNames)[count] = malloc((strlen(names[i]) + 1));
                if (!(*vowelNames)[count])
                    return 1;
                strcpy((*vowelNames)[count++], names[i]);
            }
        }
    }
    return count;
}

void printNames(int count, char **vowelNames)
{
    if (count > 0)
    {
        printf("%d ", count);
        for (int i = 0; i < count; i++)
        {
            printf("%s\n", vowelNames[i]);
            free(vowelNames[i]);
        }
        free(vowelNames);
    }
}

int main()
{
    int n;
    getPatientEntries(&n);

    char **names = (char **)malloc(n * sizeof(char *));
    if (names == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    getPatientNames(n, names);

    char **vowelNames = NULL;
    int countVowelNames = checkVowel(n, names, &vowelNames);
    printNames(countVowelNames, vowelNames);

    for (int i = 0; i < n; i++)
    {
        free(names[i]);
    }
    free(names);
    return 0;
}