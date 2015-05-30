/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL)    return head;
        
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        
        int length = 0;
        ListNode *index = head;
        while(index != NULL) {
            index = index->next;
            ++length;
        }
        int reverseTimes = length / k;
        
        ListNode *pre = NULL, *cur = head, *nxt = NULL, *end = NULL;
        if(reverseTimes > 0) {
            int group_length = k;
            end = cur;
            while(group_length-- > 0) {
                nxt = cur->next;
                cur->next = pre;
                
                pre = cur;
                cur = nxt;
            }
            dummy_head->next = pre;
            end->next = reverseKGroup(cur, k);
        }
        return dummy_head->next;
    }
};
