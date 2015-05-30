/*
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 

Tags: Array, Backtracking
*/
class Solution {
public:
    vector<vector<int> > res;
    void solve(vector<int> &candidates, vector<int> &temp, int target, int index) {
        for(int i = index; i < candidates.size(); ++i) {
            if(target > candidates[i]) {
                temp.push_back(candidates[i]);
                solve(candidates, temp, target-candidates[i], i);
                temp.pop_back();
            }
            else if(target == candidates[i]) {
                temp.push_back(candidates[i]);
                res.push_back(temp);
                temp.pop_back();
                return;
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, temp, target, 0);
        return res;
    }
};
