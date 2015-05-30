/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 

Tags: Tree, Depth-first Search, Breadth-first Search
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

    void levelOrderTraversal(TreeNode *root, int level, int* current_max_level) {
        if(root == NULL)  return;
    
        if(*current_max_level < level) {
            *current_max_level = level;
            res.push_back(root->val);
        }
    
        levelOrderTraversal(root->right, level+1, current_max_level);
        levelOrderTraversal(root->left, level+1, current_max_level);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        int level = 1;
        int current_max_level = 0;
        levelOrderTraversal(root, level, &current_max_level);
        return res;
    }
};
