/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011

Answer: 3

Tags: Depth-first Search, Breadth-first Search
*/
class Solution {
public:
    vector<int> dx = {-1, 0,  0, 1};
    vector<int> dy = { 0, 1, -1, 0};
        
    int numIslands(vector<vector<char>> &grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int res = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '1') {
                    check(grid, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    
    void check(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = 'X';
        for(int k = 0; k < dx.size(); ++k) {
            if(0 <= i+dy[k] && i+dy[k] < grid.size()    &&   /* for y axis, up   and down  */
               0 <= j+dx[k] && j+dx[k] < grid[i].size() &&   /* for x axis, left and right */
               grid[i+dy[k]][j+dx[k]] == '1')
               check(grid, i+dy[k], j+dx[k]);
        }
    }
};
