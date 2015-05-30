/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 

Tags: Divide and Conquer, Linked List, Heap
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
    struct compare {
        bool operator() (ListNode *a, ListNode *b) {    return a->val > b->val;     }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail  = dummy;
        
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(auto i : lists) {   
            if(i)   q.push(i);   
        }
        
        while(!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            
            if(tail->next)  q.push(tail->next);
        }
        return dummy->next;
    }
};
