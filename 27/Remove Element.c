/*
Runtime: 4ms, 49.54%
Memory Usage: 6.69MB, 63.38%
*/

#include <stdio.h>
#include <stdlib.h>


int removeElement(int* nums, int numsSize, int val) {
    int removed = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == val &&  i < numsSize - removed){
            printf("Found At: ");
            printf("%d", i);
            for (int j = i; j < numsSize; j++){
                if (j != numsSize - 1)
                    nums[j] = nums[j + 1];
            }
            removed++;
            i--;
        }
    }
    return numsSize - removed;
}

int main(){
    int* nums1 = malloc(sizeof(int) * 8);
    nums1[0] = 0;
    nums1[1] = 1;
    nums1[2] = 2;
    nums1[3] = 2;
    nums1[4] = 3;
    nums1[5] = 0;
    nums1[6] = 4;
    nums1[7] = 2;

    int result = removeElement(nums1, 8, 2);
    printf("Result: ");
    printf("%d", result);
    printf("\nVar: ");
    for (size_t i = 0; i < 8; i++){
        printf("%d", nums1[i]);
        printf(", ");
    }
}