#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_VAL 10000
#define MAX_POWER 1000000

int memoryCheck(void *ptr){
    if(ptr == NULL){
        printf("Memory Allocation Failed\n");
        return 1;
    }
    return 0;
}

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int *readTokens(int *tokenCount){
    char *line = (char*)malloc(100005 * sizeof(char));
    if(memoryCheck(line)) return NULL;

    printf("Enter the power values: ");
    if(fgets(line, 100005, stdin) == NULL){
        free(line);
        return NULL;
    }

    int *tokens = (int*)malloc(sizeof(int) * 10000);
    if(memoryCheck(tokens)){
        free(line);
        return NULL;
    }

    char *ptr = strtok(line, " ");
    int count = 0;
    while(ptr != NULL){
        int val = atoi(ptr);
        if(val < 0 || val > MAX_TOKEN_VAL){
            printf("!! Invalid Input !!\n");
            free(line);
            free(tokens);
            return NULL;
        }
        tokens[count++] = val;
        ptr = strtok(NULL, " ");
    }

    *tokenCount = count;
    free(line);
    return tokens;
}

int readInitialPower(){
    int power;
    printf("Initial Power: ");
    if(scanf("%d", &power) != 1 || power < 0 || power > MAX_POWER){
        printf("!! Invalid Input !!\n");
        return -1;
    }
    return power;
}

int maxScore(int *tokens, int n, int power){
    qsort(tokens, n, sizeof(int), compare);
    int left = 0, right = n - 1;
    int score = 0, maxScore = 0;

    while(left <= right){
        if(power >= tokens[left]){
            power -= tokens[left++];
            score++;
            if(score > maxScore) maxScore = score;
        }
        else if(score > 0){
            power += tokens[right--];
            score--;
        }
        else break;
    }
    return maxScore;
}

int main(){
    int tokenCount = 0;
    int *tokens = readTokens(&tokenCount);
    if(!tokens) return 1;

    int power = readInitialPower();
    if(power == -1){
        free(tokens);
        return 1;
    }

    int result = maxScore(tokens, tokenCount, power);
    printf("%d\n", result);

    free(tokens);
    return 0;
}
