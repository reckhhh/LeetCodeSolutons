/*
 Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Tags: Array, Backtracking, Bit Manipulation
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        result.push_back(vector<int> ());
        
        for(int i = 0; i < S.size(); ++i) {
            int size = result.size();
            for(int j = 0; j < size; ++j) {
                vector<int> tmp = result[j];
                tmp.push_back(S[i]);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
