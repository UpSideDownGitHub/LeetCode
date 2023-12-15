/*
Runtime: 6 ms, 12.96%
Memory Usage: 6.63 MB, 87.39%
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int inserted = 0;
    for (int i = 0; i < m + n; i++)
    {
        for (int j = inserted; j < n; j++)
        {
            if (nums2[j] <= nums1[i] || (i >= m + inserted && nums1[i] == 0))
            {
                // insert the number here
                for (int k = (m + n) - 1; k > i; k--)
                {
                    nums1[k] = nums1[k - 1];
                }
                nums1[i] = nums2[j]; 
                inserted++;
                break;
            }
        }
    }
}

int main(){
    int* nums1 = malloc(sizeof(int) * 6);
    int* nums2 = malloc(sizeof(int) * 3);
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 3;
    nums1[3] = 0;
    nums1[4] = 0;
    nums1[5] = 0;

    nums2[0] = 2;
    nums2[1] = 5;
    nums2[2] = 6;

    merge(nums1, sizeof(int) * 6, 3, nums2, sizeof(int) * 3, 3);
    printf("Var: ");
    for (size_t i = 0; i < 6; i++)
    {
        printf("%d", nums1[i]);
        printf(", ");
    }
}