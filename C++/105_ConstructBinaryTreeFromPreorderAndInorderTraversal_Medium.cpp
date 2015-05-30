/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 

Tags: Tree, Array, Depth-first Search
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
    TreeNode *help(vector<int> &preorder, vector<int> &inorder, int pStart, int pEnd, int iStart, int iEnd) {
        if(pStart > pEnd || iStart > iEnd)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pStart]);
        
        int index;
        for(int i = iStart; i <= iEnd; ++i) {
            if(inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        root->left  = help(preorder, inorder, pStart+1,              pStart-iStart+index, iStart,  index-1);
        root->right = help(preorder, inorder, pStart-iStart+index+1, pEnd,                index+1, iEnd);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        return help(preorder, inorder, 0, n-1, 0, n-1);
    }
};
