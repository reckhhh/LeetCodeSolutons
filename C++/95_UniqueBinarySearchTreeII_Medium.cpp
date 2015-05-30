/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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

Tags: Tree, Dynamic Programming
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
    vector<TreeNode *> generate(int beg, int end) {
        vector<TreeNode *> res;
        if(beg > end) {
            res.push_back(NULL);
            return res;
        }
        if(beg == end) {
            TreeNode *temp = new TreeNode(beg);
            res.push_back(temp);
            return res;
        }
        for(int i = beg; i <= end; ++i) {
            vector<TreeNode *> left  = generate(beg, i - 1);
            vector<TreeNode *> right = generate(i + 1, end);
            for(int l = 0; l < left.size(); ++l) {
                for(int r = 0; r < right.size(); ++r) {
                    TreeNode *root = new TreeNode(i);
                    root->left  = left[l];
                    root->right = right[r];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};
