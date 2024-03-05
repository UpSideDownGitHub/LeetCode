/*
Runtime: 1ms, 59.70%
Memory Usage: 5.42, 92.05%
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if(p==NULL || q==NULL || p->val != q->val)
        return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

void test(struct TreeNode* p, struct TreeNode* q, bool expected) {
    bool result = isSameTree(p, q);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main(){
    struct TreeNode node2_3 = {3, NULL, NULL}; 
    struct TreeNode node2_2 = {3, NULL, NULL}; 
    struct TreeNode node2_1 = {1, &node2_2, &node2_3}; 
    struct TreeNode node1_3 = {3, NULL, NULL}; 
    struct TreeNode node1_2 = {2, NULL, NULL}; 
    struct TreeNode node1_1 = {1, &node1_2, &node1_3}; 
    //[3,9,20,null,null,15,7]
    test(&node1_1, &node2_1, false);
    return 0;
}


/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:
The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
*/