/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 

Tags: Backtracking
*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        unordered_map<int, int> exist;
        if(num.size() == 0)
            return result;
        if(num.size() == 1) {
            result.push_back(num);
            return result;
        }
        
        for(int i = num.size() - 1; i >= 0; --i) {
            vector<vector<int> > nextPermutition;
            vector<int> temp(num);
            if(exist.find(num[i]) != exist.end())
                continue;
            else
                exist[num[i]] = 1;
            temp.erase(temp.begin() + i);
            nextPermutition = permuteUnique(temp);
            for(int j = 0; j < nextPermutition.size(); ++j) {
                nextPermutition[j].push_back(num[i]);
                vector<int> temp_result = nextPermutition[j];
                result.push_back(temp_result);
            }
        }
        return result;
    }
};
