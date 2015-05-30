/*
 Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Tags: Array, Backtracking
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        result.push_back(vector<int> ());
        
        int size = 0;
        for(int i = 0; i < S.size(); ++i) {
            int start = (i > 0 && S[i] == S[i - 1]) ? size : 0;
            size = result.size();
            for(int j = start; j < size; ++j) {
                vector<int> tmp = result[j];
                tmp.push_back(S[i]);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
