/*
Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        ListNode *cur = head;
        while(cur != NULL) {
            pre = dummy;
            while(pre->next != NULL && pre->next->val < cur->val) {
                pre = pre->next;
            }
            ListNode *nxt = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = nxt;
        }
        return dummy->next;
    }
};
