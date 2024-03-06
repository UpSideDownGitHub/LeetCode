/*
Runtime: 3ms, 53.63%
Memory Usage: 5.74mb, 73.52%
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
}

void test(struct TreeNode* root, struct TreeNode* expected) {
    struct TreeNode* result = invertTree(root);    
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
Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/