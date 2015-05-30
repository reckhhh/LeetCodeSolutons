/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 

Tags: Array, Hash Table, Stack, Dynamic Programming
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0)
            return 0;
        int row = matrix.size(), col = matrix[0].size(), answer = 0;
        int height[col], left[col], right[col];
        fill_n(height, col, 0), fill_n(left, col, 0), fill_n(right, col, col);

        for(int i = 0; i < row; ++i) {
            int cur_left = 0, cur_right = col;
            // height
            for(int j = 0; j < col; ++j) {
                if(matrix[i][j] == '1')   height[j] += 1;
                else                      height[j]  = 0;
            }
            //left
            for(int j = 0; j < col; ++j) {
                if(matrix[i][j] == '1')   left[j] = max(left[j], cur_left);
                else                     {left[j] = 0, cur_left = j + 1;}
            }
            //right
            for(int j = col - 1; j >= 0; --j) {
                if(matrix[i][j] == '1')   right[j] = min(right[j], cur_right);
                else                     {right[j] = col, cur_right = j;}
            }
            //answer
            for(int j = 0; j < col; ++j)
                answer = max( answer, height[j] * (right[j]-left[j]) );
        }
        return answer;
    }
};
