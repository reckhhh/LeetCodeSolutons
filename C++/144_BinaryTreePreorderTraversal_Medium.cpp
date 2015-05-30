/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Tags: Tree, Stack
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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode *root) {
        printTree(root);
        return res;
    }
    void printTree(TreeNode *node) {
        if (node) {
            res.push_back(node->val);
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }
};
