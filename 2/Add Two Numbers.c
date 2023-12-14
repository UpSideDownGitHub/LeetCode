/*
Runtime: 32 ms, 6.45%
Memory Usage: 8.5 MB, 28.95%
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // previouseNode == the start of the linked list
    int carry = 0;
    struct ListNode* activeNode1;
    activeNode1 = malloc(sizeof(struct ListNode));
    struct ListNode* activeNode2;
    activeNode2 = malloc(sizeof(struct ListNode));
    activeNode1 = l1;
    activeNode2 = l2;
    struct ListNode* startNode;
    startNode = malloc(sizeof(struct ListNode));
    struct ListNode* previousNode;
    previousNode = malloc(sizeof(struct ListNode));
    int i = 0;
    printf("Order: ");
    while (activeNode1 != NULL || activeNode2 != NULL || carry != 0){
        int value = 0;
        if (activeNode1 != NULL && activeNode2 != NULL && carry != 0){
            // add the numbers and add the carry
            printf("ALL");
            int total = activeNode1->val + activeNode2->val + carry; 
            value = total % 10;
            carry = total / 10;    
        }
        else if (activeNode1 != NULL && carry != 0){
            printf("1C");
            int total = activeNode1->val + carry; 
            value = total % 10;
            carry = total / 10; 
        }
        else if (activeNode2 != NULL && carry != 0){
            printf("2C");
            int total = activeNode2->val + carry; 
            value = total % 10;
            carry = total / 10; 
        }
        else if (activeNode1 != NULL && activeNode2 != NULL){
            printf("12");
            int total = activeNode1->val + activeNode2->val; 
            value = total % 10;
            carry = total / 10; 
        }
        else if (activeNode1 != NULL){
            printf("1");
            int total = activeNode1->val; 
            value = total % 10;
            carry = total / 10; 
        }
        else if (activeNode2 != NULL){
            printf("2");
            int total = activeNode2->val; 
            value = total % 10;
            carry = total / 10; 
        }
        else if (carry != 0){
            printf("c");
            int total = carry; 
            value = total % 10;
            carry = total / 10; 
        }

        struct ListNode* nextNode;
        nextNode = malloc(sizeof(struct ListNode));

        // Final Part
        printf("Value(");
        printf("%d", value); 
        printf("), "); 

        if (activeNode1 != NULL) 
            activeNode1 = activeNode1->next;
        if (activeNode2 != NULL)
            activeNode2 = activeNode2->next;
        if (i == 0)
        {
            startNode->val = value;
            if (activeNode1 != NULL || activeNode2 != NULL || carry != 0)
            {
                startNode->next = nextNode;
                previousNode = nextNode;
            }
            else
            {
                 startNode->next = NULL;
            }
        }
        else
        {
            previousNode->val = value;
            if (activeNode1 != NULL || activeNode2 != NULL || carry != 0)
            {
                previousNode->next = nextNode;
                previousNode = nextNode;
            }
            else
            {
                 previousNode->next = NULL;
            }
        }
        i++;
    }
    printf("\n");
    previousNode->next = NULL;
    return startNode;
}

int main(){

    // Init Nodes
    struct ListNode *head;
    struct ListNode *one;
    struct ListNode *two;
    // Allocate Memory
    head = malloc(sizeof(struct ListNode));
    one = malloc(sizeof(struct ListNode));
    two = malloc(sizeof(struct ListNode));
    // Assign Data
    head->val = 0;
    //one->val = 4;
    //two->val = 3;
    // Assign Next
    head->next = NULL;
    //one->next = two;
    //two->next = NULL;

    // result
    struct ListNode *result;
    result = malloc(sizeof(struct ListNode));
    result = addTwoNumbers(head, head);
    while (result != NULL){
        printf("Val: ");
        printf("%d", result->val);
        printf("\n");
        result = result->next;
    }
    

    return 0;
}