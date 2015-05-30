'''
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
'''
class Solution:
    # @param {character[][]} grid
    # @return {integer}
    def numIslands(self, grid):
        if not grid: return 0
        
        self.dx, self.dy = [-1, 0,  0, 1], [ 0, 1, -1, 0]
        res = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[i])):
                if grid[i][j] == '1':
                    self.check(grid, i, j)
                    res += 1
        return res
    
    def check(self, grid, i, j):
        grid[i][j] = 'x'
        for k in xrange(len(self.dx)):
            if 0 <= i + self.dy[k] < len(grid) and  \
                0 <= j + self.dx[k] < len(grid[i]) and  \
                    grid[i+self.dy[k]][j+self.dx[k]] == '1':
                        self.check(grid, i+self.dy[k], j+self.dx[k])