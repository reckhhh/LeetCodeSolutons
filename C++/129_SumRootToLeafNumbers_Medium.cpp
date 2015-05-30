/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 

Tags: Tree, Depth-first Search
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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            sum += root->val;
        if (root->left != NULL) {
            root->left->val += (root->val) * 10;
            sum += sumNumbers(root->left);
        }
        if (root->right != NULL) {
            root->right->val += (root->val) * 10;
            sum += sumNumbers(root->right);
        }
        return sum;
    }
};
