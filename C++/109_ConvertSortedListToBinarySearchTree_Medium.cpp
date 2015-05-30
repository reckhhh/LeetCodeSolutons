/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Tags: Depth-first Search, Linked List
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBST(ListNode *&list, int start, int end) {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        
        TreeNode *leftChild = buildBST(list, start , mid-1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = buildBST(list, mid+1, end);
        return parent;
    }
    int listLength(ListNode *head) {
        int len = 0;
        while(head->next != NULL) {
            ++len;
            head = head->next;
        }
        return len;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)
            return 0;
        return buildBST(head, 0, listLength(head));
    }
};
