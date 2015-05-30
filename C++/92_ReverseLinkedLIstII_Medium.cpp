/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int m1 = m;
        if(head == NULL || head->next == NULL || n == m)
            return head;
        n -= m;
        
        ListNode *cur = head;
        ListNode *pre = cur;
        ListNode *nxt = cur->next;
        ListNode *orz = NULL;
        
        while(--m) {
            pre = cur;
            cur = cur->next;
            nxt = cur->next;
        }
        
        while(n--) {
            orz = cur;
            cur = nxt;
            nxt = cur->next;
            
            cur->next = orz;
        }
        
        if(m1 == 1) {
            pre->next = nxt;
            return cur;
        }
        else {
            pre->next->next = nxt;
            pre->next = cur;
            return head;
        }
    }
};
