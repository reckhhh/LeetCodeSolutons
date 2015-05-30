/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.

Tags: Array, Binary Search
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(target < matrix[0][0])
            return false;
            
        int row = matrix.size();
        int col = matrix[0].size();
        int i, j;
        
        for(i = 0; i < row && matrix[i][col - 1] < target; ++i)
            ;
        if(i == row)
            return false;

        for(j = 0; j < col; ++j) {
            if(target == matrix[i][j])
                return true;
        }
        return false;
    }
};
