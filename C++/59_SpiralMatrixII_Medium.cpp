/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

Tags: Array
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int> (n, 0));
        if(n == 0)
            return matrix;
        int i = 0, j = 0, value = 1, dir = 0;
        
        while(value <= n * n) {
            matrix[i][j] = value++;
            if(dir == 0) {
                ++j;
                if(j == n  || matrix[i][j] != 0)  dir = 1, ++i, --j;
            }
            else if(dir == 1) {
                ++i;
                if(i == n  || matrix[i][j] != 0)  dir = 2, --i, --j;
            }
            else if(dir == 2) {
                --j;
                if(j == -1 || matrix[i][j] != 0)  dir = 3, --i, ++j;
            }
            else if(dir == 3) {
                --i;
                if(i == -1 || matrix[i][j] != 0)  dir = 0, ++i, ++j;
            }
        }
        return matrix;
    }
};
