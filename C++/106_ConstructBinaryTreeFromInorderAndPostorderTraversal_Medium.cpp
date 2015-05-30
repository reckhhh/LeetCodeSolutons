/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *help(vector<int> &inorder, vector<int> &postorder, int iStart, int iEnd, int pStart, int pEnd) {
        if(iStart > iEnd || pStart > pEnd)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pEnd]);
            
        int index;
        for(int i = iStart; i <= iEnd; ++i) {
            if(inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        root->left  = help(inorder, postorder, iStart,  index-1, pStart,              pStart-iStart+index-1);
        root->right = help(inorder, postorder, index+1, iEnd,    pStart-iStart+index, pEnd-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        return help(inorder, postorder, 0, n-1, 0, n-1);
    }
};
