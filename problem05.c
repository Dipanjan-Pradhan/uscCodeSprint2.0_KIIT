#include <stdio.h>
#include <stdlib.h>

void getValue(int *r, int *c)
{
    while (1)
    {
        printf("Enter the no of warehouse and product type respectively(1 - 100): ");
        scanf("%d %d", r, c);

        if (*r >= 1 && *c >= 1 && *r <= 100 && *c <= 100)
            break;

        printf("!! Range Exceed !!\n");
    }
    return;
}

void getStockData(int r, int c, int *stock)
{
    printf("Enter the stock levels for each warehouse:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &stock[i * c + j]);
            if (stock[i * c + j] < 0 || stock[i * c + j] > 1000)
            {
                printf("!! Stock Value Over Exceed !!\n");
                j--;
                continue;
            }
        }
    }
}

int checkOverStock(int r, int c, int *stock)
{
    int overStock = 0;
    int currStock = 0;
    for (int i = 0; i < r; i++)
    {
        currStock = 0;
        for (int j = 0; j < c; j++)
        {
            if (stock[i * c + j] >= 100)
                currStock++;
        }
        if (currStock >= 3)
            overStock++;
    }
    return overStock;
}

int main()
{
    int r, c;
    getValue(&r, &c);

    int *stockData = (int *)malloc(r * c * sizeof(int));
    if (stockData == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    getStockData(r, c, stockData);

    int overStock = checkOverStock(r, c, stockData);

    printf("Total Over Stocked Warehouses = %d\n", overStock);

    free(stockData);
    return 0;
}
