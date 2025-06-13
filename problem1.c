#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100
bool canBuyIceCream(int budget, int *iceCreamPrices, int count){
    for (int i = 0; i < count; i++){
        if (iceCreamPrices[i] == budget)
            return true;
    }
    return false;
}


int main()
{
    int budget;
    int *iceCreamPrices = NULL;
    int count = 0;
    char line[MAX_SIZE];

    printf("budget = ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &budget);

    printf("iceCreamPrices = ");
    while (1)
    {
        if (fgets(line, sizeof(line), stdin) == NULL)
            break;
        if (strcmp(line, "\n") == 0)
            break;

        int price;
        if (sscanf(line, "%d", &price) == 1)
        {
            int *temp = realloc(iceCreamPrices, (count + 1) * sizeof(int));
            if (temp == NULL)
            {
                free(iceCreamPrices);
                return 1;
            }

            iceCreamPrices = temp;
            iceCreamPrices[count++] = price;
        }
    }

        if (canBuyIceCream(budget, iceCreamPrices, count))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }

        return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>

// #define MAX_LINE 100

// bool canBuyIceCream(int budget, int* iceCreamPrices, int count) {
//     for (int i = 0; i < count; i++) {
//         if (iceCreamPrices[i] == budget) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int budget;
//     int* iceCreamPrices = NULL;
//     int count = 0;
//     char line[MAX_LINE];

//     printf("budget = ");
//     fgets(line, sizeof(line), stdin);
//     sscanf(line, "%d", &budget);

//     printf("iceCreamPrices = ");
//     while (1) {
//         if (fgets(line, sizeof(line), stdin) == NULL) break;
//         if (strcmp(line, "\n") == 0) break;

//         int price;
//         if (sscanf(line, "%d", &price) == 1) {
//             int* temp = realloc(iceCreamPrices, (count + 1) * sizeof(int));
//             if (temp == NULL) {
//                 free(iceCreamPrices);
//                 return 1;
//             }
//             iceCreamPrices = temp;
//             iceCreamPrices[count++] = price;
//         }
//         else {
//             printf("Please enter a valid number.\n");
//         }
//     }

//     if (canBuyIceCream(budget, iceCreamPrices, count)) {
//         printf("true\n");
//     } else {
//         printf("false\n");
//     }

//     free(iceCreamPrices);
//     return 0;
// }
