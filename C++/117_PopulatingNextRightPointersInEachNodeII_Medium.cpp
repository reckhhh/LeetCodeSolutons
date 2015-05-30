/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

        1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

Tags: Tree, Depth-first Search
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur  = NULL;
        TreeLinkNode *pre  = NULL;
        TreeLinkNode *head = root;
        
        while(head != NULL) {
            cur  = head;
            pre  = NULL;
            head = NULL;
            
            while(cur != NULL) {
                if(cur->left != NULL) {
                    if(pre != NULL)
                        pre->next = cur->left;
                    else
                        head = cur->left;
                    pre = cur->left;
                }
                if(cur->right != NULL) {
                    if(pre != NULL)
                        pre->next = cur->right;
                    else
                        head = cur->right;
                    pre = cur->right;
                }
                cur = cur->next;
            }
        }
    }
};
