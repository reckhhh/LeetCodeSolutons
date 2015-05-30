/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 

Tags: Array, Backtracking
*/
class Solution {
public:
    vector<vector<int> > res;
    void solve(vector<int> &num, vector<int> &temp, int target, int index) {
        for(int i = index; i < num.size(); ++i) {
            if(num[i] < target) {
                temp.push_back(num[i]);
                solve(num, temp, target - num[i], i+1);
                temp.pop_back();
                while(i < num.size() - 1 && num[i] == num[i + 1])
                    ++i;
            }
            else if(num[i] == target) {
                temp.push_back(num[i]);
                res.push_back(temp);
                temp.pop_back();
                return;
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> temp;
        sort(num.begin(), num.end());
        solve(num, temp, target, 0);
        return res;
    }
};
