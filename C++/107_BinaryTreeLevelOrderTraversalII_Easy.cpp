/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

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

Tags: Tree, Breadth-first Search
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
    vector<vector<int> > res;
    
    void buildVector(TreeNode *node, int level) {
        if(node == NULL)
            return;
            
        if(res.size() == level)
            res.push_back(vector<int>());
        
        res[level].push_back(node->val);
        buildVector(node->left,  level + 1);
        buildVector(node->right, level + 1);
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        int level = 0;
        buildVector(root, level);
        return vector<vector<int> > (res.rbegin(), res.rend());
    }
};
