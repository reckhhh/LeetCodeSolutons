/*
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Tags: Array
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty())  return;
        
        int row = matrix.size();
        int col = matrix[0].size();
        bool firstRowHasZero = false, firstColHasZero = false;
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0)  firstRowHasZero = true;
                    if(j == 0)  firstColHasZero = true;
                }
            }
        }
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(firstRowHasZero) {
            for(int j = 0; j < col; ++j)
                matrix[0][j] = 0;
        }
        if(firstColHasZero) {
            for(int i = 0; i < row; ++i)
                matrix[i][0] = 0;
        }
    }
};
