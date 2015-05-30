/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
    TreeNode *buildBST(vector<int> &num, int left, int right) {
        if(left > right)
            return NULL;
            
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left  = buildBST(num, left, mid - 1);
        node->right = buildBST(num, mid + 1, right);
        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size() - 1);
    }
};
