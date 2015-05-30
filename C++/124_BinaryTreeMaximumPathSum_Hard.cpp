/*
 Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 

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
    int res = INT_MIN;
    int maxPathSum(TreeNode *root) {
        return max(res, findPath(root));
    }
    int findPath(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left  = max(0, findPath(root->left));
        int right = max(0, findPath(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};
