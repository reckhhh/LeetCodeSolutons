/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;
            
        ListNode* cur = head;
        ListNode* nxt = head;
        ListNode* tmp;
        while (nxt != NULL && n-- >= 0)
            nxt = nxt->next;
            
        if (n > 1)
            return head;
        if (n == 0)
        {
            tmp = head;
            head = head->next;
            free (tmp);
            return head;
        }
        else
        {
            while (nxt != NULL)
            {
                nxt = nxt->next;
                cur = cur->next;
            }
            tmp = cur->next;
            cur->next = cur->next->next;
            free (tmp);
            return head;
        }
    }
};
