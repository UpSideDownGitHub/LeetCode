/*
Runtime: 3ms, 84.10%
Memory Usage: 8.10, 49.90%
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    // depth first search keeping track of the deepest achived
    if (!root)
        return 0;
    else{
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (leftDepth > rightDepth)
            return ++leftDepth;
        return ++rightDepth;
    }
}

void test(struct TreeNode *root, int expected) {
    int result = maxDepth(root);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main(){
    struct TreeNode node5 = {7, NULL, NULL}; 
    struct TreeNode node4 = {15, NULL, NULL}; 
    struct TreeNode node3 = {20, &node4, &node5}; 
    struct TreeNode node2 = {9, NULL, NULL}; 
    struct TreeNode node1 = {3, &node2, &node3}; 
    //[3,9,20,null,null,15,7]
    test(&node1, 3);
    return 0;
}

/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2
 
Constraints:
The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/