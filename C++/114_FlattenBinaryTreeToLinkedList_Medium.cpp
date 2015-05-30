/*
 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

click to show hints.
Hints:

If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
            
        while(root != NULL) {
            if(root->left != NULL) {
                TreeNode *cur = root->left;
                while(cur->right != NULL)
                    cur = cur->right;
                cur->right  = root->right;
                root->right = root->left;
                root->left  = NULL;
            }
            root = root->right;
        }
    }
};
