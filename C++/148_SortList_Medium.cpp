/*
Sort a linked list in O(n log n) time using constant space complexity.

Tags: Linked List, Sort
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
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *h2 = sortList(slow->next);
        slow->next = NULL;
        return merge(sortList(head), h2);
    }
    
    ListNode *merge(ListNode *h1, ListNode *h2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(h1 != NULL && h2 != NULL) {
            if(h1->val < h2->val) {
                 cur->next = h1;
                 h1 = h1->next;
            }
            else {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        if(h1 != NULL)  cur->next = h1;
        if(h2 != NULL)  cur->next = h2;
        return dummy->next;
    }
};
