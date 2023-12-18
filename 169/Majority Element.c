/*
Runtime: 784 ms 5.6%
Memory Usage: 8.6 MB 11.33%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int majorityElement(int* nums, int numsSize) {
    int highest = 0;
    int value;
    for (int i = 0; i < numsSize; i++){
        int counter = 0;
        if (nums[i] == value)
            continue;
        for (int j = 0; j < numsSize; j++){
            if (nums[i] == nums[j]){
                counter++;
            }
        }
        printf("\nCounter: %d  -- Value: %d", counter, nums[i]);
        if (counter >= highest){
            highest = counter;
            value = nums[i];
            if (highest > numsSize / 2)
                return value;
        }
    }
    return value;
}

int main(){
    int input[] = {-1,1,1,1,2,1};
    int answer = majorityElement(input, 6);
    printf("Answer: ");
    printf("%d", answer);
}