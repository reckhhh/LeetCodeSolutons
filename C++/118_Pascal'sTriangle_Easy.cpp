/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Tags: Array
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > pascal;
        pascal.resize(numRows);
        
        if(numRows == 0)
            return pascal;
        else
            pascal[0].push_back(1);
        
        for(int i = 1; i < numRows; ++i) {
            pascal[i].resize(i + 1);
            pascal[i][0] = pascal[i][i] = 1;
            
            for(int j = 1; j < i; ++j)
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
        return pascal;
    }
};
