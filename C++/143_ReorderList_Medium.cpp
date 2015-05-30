/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 

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
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return;
        
        // find the middle location
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the right half list
        ListNode *pre = slow->next; // the start location of the right half list
        ListNode *cur = pre->next;
        ListNode *second = pre;     // remember the start location of the right half list
        while(cur != NULL) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        second->next  = NULL;  // the end of the right half list should be NULL
        slow->next = NULL;     // the end of the left  half list should be NULL
        
        // merge two list
        cur = pre;  // cur point to the start location of the right half list
        pre = head; // pre point to the start location of the left  half list
        while(cur != NULL) {
            ListNode *temp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = pre->next->next;
            cur = temp;
        }
    }
};
