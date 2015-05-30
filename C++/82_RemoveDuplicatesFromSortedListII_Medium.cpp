/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 

Tags: Linked List
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **p = &head;
        while(*p && (*p)->next) {
            ListNode *p1 = *p;
            ListNode *p2 = p1->next;
            while(p2 && p2->val == p1->val)
                p2 = p2->next;
            if(p1->next == p2)
                p = &(p1->next);
            else
                *p = p2;
        }
        return head;
    }
};
