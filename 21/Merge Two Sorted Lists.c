/*
Runtime: 6ms, 21.61%
Memory Usage: 5.98, 74.34%
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head = {0, NULL}; 
    struct ListNode *p = &head;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    
    // chain remaining
    if (l1) p->next = l1;
    if (l2) p->next = l2;

    return head.next;
}

void test(struct ListNode *list1, struct ListNode *list2, char* expected) {
    struct ListNode* result = mergeTwoLists(list1, list2);

    printf("Result: ");
    while(result != NULL){
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\nExpected: %s\n", expected);
}

int main(){
    struct ListNode* list1_1 = malloc(sizeof(struct ListNode));
    struct ListNode* list1_2 = malloc(sizeof(struct ListNode));
    struct ListNode* list1_3 = malloc(sizeof(struct ListNode));
    list1_1->val = 1;
    list1_2->val = 2;
    list1_3->val = 4;
    list1_1->next = list1_2;
    list1_2->next = list1_3;
    list1_3->next = NULL; 

    struct ListNode* list2_1 = malloc(sizeof(struct ListNode));
    struct ListNode* list2_2 = malloc(sizeof(struct ListNode));
    struct ListNode* list2_3 = malloc(sizeof(struct ListNode));
    list2_1->val = 1;
    list2_2->val = 3;
    list2_3->val = 4;
    list2_1->next = list2_2;
    list2_2->next = list2_3;
    list2_3->next = NULL; 

    test(list1_1, list2_1, "1 1 2 3 4 4");

    // Free allocated memory
    free(list1_1);
    free(list1_2);
    free(list1_3);
    free(list2_1);
    free(list2_2);
    free(list2_3);

    return 0;
}

/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing 
together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 
Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/