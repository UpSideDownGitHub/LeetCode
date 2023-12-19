/*
Runtime: 95 ms 58.4%
Memory Usage: 13.7 MB 45.38%
*/
#define max(a,b) (((a) > (b)) ? (a) : (b))

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxProfit(int* prices, int pricesSize) {
    int highestProfit = 0;
    int currentSell = -2147483647;
    for (int i = 0; i < pricesSize; i++)
    {
        highestProfit = max(highestProfit, currentSell + prices[i]);
        currentSell = max(currentSell, -prices[i]);
    }
    return highestProfit;
}


int main(){
    int input[] = {7,1,5,3,6,4};
    int answer = maxProfit(input, 6);
    printf("\nAnswer: %d", answer);
}