#include <stdio.h>
#include <stdlib.h>

void getDaysNo(int *n)
{
    while (1)
    {
        printf("Enter the no of days (2 - 100): ");
        scanf("%d", n);
        if (*n >= 2 && *n <= 100)
            break;
        printf("!! Invalid Input !!\n");
    }
}

void getStockPrice(int n, int *stock)
{
    printf("Enter the stock Prices: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", stock + i);
    }
}

void printMaxProfit(int n, int *stock)
{
    int minPrice = stock[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        if (stock[i] - minPrice >= 2)
        {
            int profit = stock[i] - minPrice;
            if (profit > maxProfit)
                maxProfit = profit;
        }
        if (stock[i] < minPrice)
            minPrice = stock[i];
    }

    printf("Maximum Profit = %d\n", maxProfit);
}

int main()
{
    int n;
    getDaysNo(&n);
    int *stock = (int *)malloc(n * sizeof(int));
    getStockPrice(n, stock);
    printMaxProfit(n, stock);
    free(stock);
    return 0;
}