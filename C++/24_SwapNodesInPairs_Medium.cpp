/*
 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
    
        ListNode *pre = head;
        ListNode *cur = pre->next;
        ListNode *nxt = cur->next;
        head = cur;
    
        while(nxt != NULL) {
            if(nxt->next == NULL) {
                cur->next = pre;
                pre->next = nxt;
                return head;
            }
            else {
                cur->next = pre;
                pre->next = nxt->next;
    
                pre = nxt;
                cur = nxt->next;
                nxt = cur->next;
            }
        }
    
        cur->next = pre;
        pre->next = nxt;
        return head;
    }
};
