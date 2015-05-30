/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Tags: Backtracking
*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> temp;
        
        int start = 1, size = 0;
        help(result, temp, start, size, n, k);
        return result;
    }
    void help(vector<vector<int> > &result, vector<int> &temp, int start, int size, int n, int k) {
        if(size == k) {
            result.push_back(temp);
            return;
        }
        for(int i = start; i <= n; ++i) {
            temp.push_back(i);
            help(result, temp, i+1, size+1, n, k);
            temp.pop_back();
        }
    }
};
