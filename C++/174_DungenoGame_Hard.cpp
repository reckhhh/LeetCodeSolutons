/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
-2 (K) 	-3 	3
-5 	-10 	1
10 	30 	-5 (P)

Notes:

    The knight's health has no upper bound.
    Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

Tags: Dynamic Programming, Binary Search
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        int A[row][col];
    
        // 1. when the knight reached the bottom right corner
        A[row-1][col-1] = (dungeon[row-1][col-1] > 0) ? 1 : (1 - dungeon[row-1][col-1]);
    
        // 2. in the last column, bottom-up;
        for(int i = row - 2; i >= 0; --i) {
            int aboveValue = A[i+1][col-1] - dungeon[i][col-1];
            A[i][col-1]  = aboveValue > 0 ? aboveValue : 1;
        }
    
        // 3. in the last row, from right to left
        for(int j = col - 2; j >= 0; --j) {
            int leftValue = A[row-1][j+1] - dungeon[row-1][j];
            A[row-1][j]  = leftValue > 0 ? leftValue : 1;
        }
    
        // 4. in other areas, from bottom-right to upper-left
        for(int i = row - 2; i >=0; --i) {
            for(int j = col - 2; j >= 0; --j) {
                int rightValue = (A[i][j+1]-dungeon[i][j] > 0) ? A[i][j+1]-dungeon[i][j] : 1;
                int belowValue = (A[i+1][j]-dungeon[i][j] > 0) ? A[i+1][j]-dungeon[i][j] : 1;
                A[i][j] = min(rightValue, belowValue);
            }
        }
        return A[0][0];
    }
};
