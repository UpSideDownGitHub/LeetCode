/*
Runtime: 7ms, 74.46%
Memory Usage: 7.62, 85.64%
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };

bool hasCycle(struct ListNode *head) {
    struct ListNode* current;
    for (int i = 0; i < 104; i++){
        if (head->next == NULL){
            return false;
        }
        head = head->next;
    }
    return  true;
}

void test(struct ListNode *head, bool expected) {
    bool result = hasCycle(head);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main(){
    struct ListNode* node1 = malloc(sizeof(struct ListNode));
    struct ListNode* node2 = malloc(sizeof(struct ListNode));
    struct ListNode* node3 = malloc(sizeof(struct ListNode));
    struct ListNode* node4 = malloc(sizeof(struct ListNode));
    node1->val = 3;
    node1->next = node2;
    node2->val = 2;
    node2->next = node3;
    node3->val = 0;
    node3->next = node4;
    node4->val = -4;
    node4->next = node2;
    test(node1, true);
}


/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node struct listitem* newItem = malloc(sizeof(struct listitem));in the list that can be reached again 
by continuously following the next pointer. Internally, pos is used to denote the index of the 
node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/