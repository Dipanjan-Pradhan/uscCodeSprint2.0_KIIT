#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidString(char *str)
{
    int len = strlen(str);
    if (len < 1 || len > 100)
        return 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != '1' && str[i] != '0')
            return 0;
    }
    return 1;
}

char *getString()
{
    char temp[101];
    while (1)
    {
        printf("Enter single binary string (1 - 100): ");
        scanf("%s", temp);
        if (isValidString(temp))
        {
            char *str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
            if (str == NULL)
            {
                printf("Memory Allocation Failed\n");
                exit(0);
            }

            strcpy(str, temp);
            return str;
        }
        printf("!! Invalid Input !!\n");
    }
}

int checkSegment(char *str)
{
    int len = strlen(str);
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '1' && (i == 0 || str[i - 1] == '0'))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char *binaryString = getString();
    int moveSegment = checkSegment(binaryString);
    printf("%d", moveSegment);
    free(binaryString);
    return 0;
}