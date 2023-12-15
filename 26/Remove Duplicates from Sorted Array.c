/*
Runtime: 10ms, 77.27%
Memory Usage: 8.23MB, 41.15%
*/

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i < numsSize - 1 && nums[i] == nums[i + 1]) {
            continue;
        }
        nums[count] = nums[i];
        count++;
    }
    return count;
}

int main(){
    int* nums1 = malloc(sizeof(int) * 2);
    nums1[0] = 1;
    nums1[1] = 1;

    int result = removeDuplicates(nums1, 2);
    printf("Result: ");
    printf("%d", result);
    printf("\nVar: ");
    for (size_t i = 0; i < 2; i++){
        printf("%d", nums1[i]);
        printf(", ");
    }
}