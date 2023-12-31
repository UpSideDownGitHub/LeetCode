/*
Runtime: 231 ms, 11.27%
Memory Usage: 26.9 MB, 36.62%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int latest_index;
    int key;
    int val;
    struct Node *next;
};

#define SIZE 1000
int getPos(int n){
    long long num=n;
    if(num<0)
        num=-1*num;
    return num%SIZE;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    struct Node** hashMap=calloc(SIZE+1, sizeof(struct Node *));
    for(int i=0;i<numsSize;i++){
        int pos=getPos(nums[i]);
        struct Node* iter=hashMap[pos];
        struct Node* prev=hashMap[pos];
        while(iter){
            if(iter->key==nums[i]){
                if(iter->val>=1){
                    if(i <= iter->latest_index+k){
                        return true;
                    }
                }
                iter->latest_index=i;
                iter->val++;
                break;
            }
            prev=iter;
            iter=iter->next;
        }
        if(iter==NULL){
            struct Node *tmp=malloc(sizeof(struct Node));
            tmp->key=nums[i];
            tmp->val=1;
            tmp->latest_index=i;
            tmp->next=NULL;
            if(prev){
                prev->next=iter;
            }
            else{
                hashMap[pos]=tmp;
            }
        }
    }
    
    return false;
}

void test(int* nums, int numsSize, int k, bool expected) {
    bool result = containsNearbyDuplicate(nums, numsSize, k);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    test((int[]){1,2,3,1}, 4, 4, true);
    test((int[]){1,0,1,1}, 4, 1, true);
    test((int[]){1,2,3,1,2,3}, 6, 2, false);
}

/*
Given an integer array nums and an integer k, 
return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 
Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/