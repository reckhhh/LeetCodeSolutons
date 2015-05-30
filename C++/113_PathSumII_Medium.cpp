/*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int> > result;
    void checkSum(TreeNode *root, int sum, vector<int> tmp) {
        if(root == NULL)
            return;
        tmp.push_back(root->val);
        if(sum == root->val && root->left == NULL && root->right == NULL) {
            result.push_back(tmp);
            return;
        }
        if(root->left  != NULL) checkSum(root->left,  sum - root->val, tmp);
        if(root->right != NULL) checkSum(root->right, sum - root->val, tmp);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> tmp;
        checkSum(root, sum, tmp);
        return result;
    }
};

