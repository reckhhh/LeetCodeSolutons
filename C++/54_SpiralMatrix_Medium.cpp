/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 

Tags: Array
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.size() == 0)
            return result;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > flag(m, vector<int> (n, 0));
        
        int k = m * n, i = 0, j = 0, dir = 0;
        
        while(k--) {
            result.push_back(matrix[i][j]);
            flag[i][j] = 1;
            if(dir == 0) {
                ++j;
                if(j == n  || flag[i][j] != 0) dir = 1, ++i, --j;
            }
            else if(dir == 1) {
                ++i;
                if(i == m  || flag[i][j] != 0) dir = 2, --i, --j;
            }
            else if(dir == 2) {
                --j;
                if(j == -1 || flag[i][j] != 0) dir = 3, --i, ++j;
            }
            else if(dir == 3) {
                --i;
                if(i == -1 || flag[i][j] != 0) dir = 0, ++i, ++j;
            }
        }
        return result;
    }
};
