#include <stdio.h>
#include <stdlib.h>

void getTemperature(int n, int *temp)
{
    printf("Enter the temperature for each day(-1000 - 1000): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (temp + i));
        if (temp[i] > 1000 || temp[i] < -1000)
        {
            printf("!! Range Exceed !!\n");
            i--;
        }
    }
    return;
}

int findLongSubarray(int n, int *temp)
{
    int currLen = 1, longLen = 1;
    for (int i = 1; i < n; i++)
    {
        if (temp[i] > temp[i - 1])
            currLen++;

        // it can be done using nested if else condition
        else if (currLen > longLen)
        {
            longLen = currLen;
            currLen = 1;
        }
        else
            currLen = 1;
    }
    if (currLen > longLen)
        longLen = currLen;

    return longLen;
}

int main()
{
    int n;
    printf("Enter the number of days: ");
    scanf("%d", &n);

    int *temperature = (int *)malloc(n * sizeof(int));
    if (temperature == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    getTemperature(n, temperature);

    int longSubarray = findLongSubarray(n, temperature);

    printf("Length of longest strictly increasing subarray = %d", longSubarray);

    free(temperature);
    return 0;
}
