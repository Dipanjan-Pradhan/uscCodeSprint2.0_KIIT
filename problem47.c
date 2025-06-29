#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

int memoryCheck(char *ptr)
{
    if (!ptr)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    return 0;
}

int isLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z') return 0;
    return 1;
}

void getStringInput(char **str, int *count)
{
    char ch;
    int size = 16;
    *count = 0;
    *str = (char *)malloc(size * sizeof(char));
    if (memoryCheck(*str))
    exit(1);
    
    printf("Enter the string in lowercase letter: ");
    while ((ch = getchar()) != '\n' && !isLowerCase(ch))
    {
        if (*count >= MAX_LEN)
            break;
        if (*count >= size - 1)
        {
            size *= 2;
            char *temp = realloc(*str, size * sizeof(char));
            if (memoryCheck(temp))
            {
                free(*str);
                exit(1);
            }
            *str = temp;
        }
        (*str)[(*count)++] = ch;
    }
    (*str)[*count] = '\0';
}

void checkRepeatChar(char *str, char *modifiedStr, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (modifiedStr[j] == str[i])
                modifiedStr[j] = '#';
        }
    }
    return;
}

void printStr(char *modifiedStr, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%c", modifiedStr[i]);
    }
}

int main()
{
    char *str = NULL;
    int count;

    getStringInput(&str, &count);
    char *modifiedStr = (char *)malloc((count + 1) * sizeof(char));
    if (memoryCheck(modifiedStr))
    {
        free(str);
        exit(1);
    }

    strcpy(modifiedStr, str);

    checkRepeatChar(str, modifiedStr, count);

    printf("Modified String = ");
    printStr(modifiedStr, count);

    free(str);
    free(modifiedStr);
    return 0;
}