/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
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

Tags: Tree, Breadth-first Search, Stack
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

    void reverseOddLine() {
        for(int i = 1; i < result.size(); i += 2)
           reverse(result[i].begin(), result[i].end());
    }
    
    void levelTraversal(TreeNode *root, int level) {
        if(root == NULL)
            return;
        if(result.size() == level)
            result.push_back(vector<int> ());
    
        result[level].push_back(root->val);
        levelTraversal(root->left,  level + 1);
        levelTraversal(root->right, level + 1);
    }
    
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        levelTraversal(root, 0);    // Level Traverse the whole tree
        reverseOddLine();           // Reverse the odd Line
        return result;
    }
};
