/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Tags: Array
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
            
        for(int i = 0; i <= rowIndex; ++i) {
            res.push_back(1);
            for(int j = i - 1; j > 0; --j)
                res[j] += res[j - 1];
        }
        return res;
    }
};
