/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 

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
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* pre = head;
        ListNode* cur = head->next;
        
        while (cur != NULL)
        {
            if (pre->val != cur->val)
            {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
            else
                cur = cur->next;
        }
            
        pre->next = NULL;
        
        return head;
    }
};
