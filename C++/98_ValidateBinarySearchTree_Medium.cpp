/*
 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 

Tags: Tree, Depth-first-Search
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
    bool isValidBST(TreeNode *root) {
        if(root == NULL)
            return true;

        if(root->left != NULL) {
            TreeNode *pre = root->left;
            while(pre->right != NULL) {
                pre = pre->right;
            }
            if(pre->val >= root->val)
                return false;
        }
        if(root->right != NULL) {
            TreeNode *post = root->right;
            while(post->left != NULL) {
                post = post->left;
            }
            if(post->val <= root->val)
                return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
