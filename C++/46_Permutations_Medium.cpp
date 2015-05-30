/*
 Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Tags: Backtracking
*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 0)
            return result;
        if(num.size() == 1) {
            result.push_back(num);
            return result;
        }
        for(int i = num.size() - 1; i >= 0; --i) {
            vector<int> tmp(num);
            int curNum = num[i];
            tmp.erase(tmp.begin() + i);
            vector<vector<int> > nextPermute = permute(tmp);
            for(int j = 0; j < nextPermute.size(); ++j) {
                nextPermute[j].push_back(curNum);
                vector<int> tmpResult = nextPermute[j];
                result.push_back(tmpResult);
            }
        }
        return result;
    }
};
