/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Tags: Linked List, Math

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
*/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *dummy = new ListNode(0);
        ListNode *dp = dummy;
        int sum = 0;
        while(p1 != NULL || p2 != NULL) {
            if(p1 != NULL) {
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL) {
                sum += p2->val;
                p2 = p2->next;
            }
            dp->next = new ListNode(sum % 10);
            dp = dp->next;
            sum /= 10;
        }
        if(sum == 1)
            dp->next = new ListNode(1);
        return dummy->next;
    }
};
