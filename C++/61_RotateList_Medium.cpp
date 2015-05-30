/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Tags: Linked List, Two Pointers
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        int cnt = 0;
        while(cnt < k) {
            if(fast == NULL)
                fast = head;
            fast = fast->next;
            ++cnt;
        }
        if(fast == NULL)
            return head;
        
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }
};
