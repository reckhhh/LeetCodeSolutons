/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Tags: Backtracking
*/
class Solution {
public:
    vector<vector<string> > ans;
    int limit;
    vector<string> toString(vector<int> loc) {
        string s(loc.size(), '.');
        vector<string> temp(loc.size(), s);
        for(int i = 0; i < loc.size(); ++i) {
            temp[i][loc[i]] = 'Q';
        }
        return temp;
    }
    bool isSafe(vector<int> loc, int r, int c) {
        for(int row = r - 1, ldia = c - 1, rdia = c + 1; row >= 0; --row, --ldia, ++rdia) {
            int checkCol = loc[row];
            if(checkCol == c || checkCol == ldia || checkCol == rdia)
                return false;
        }
        return true;
    }
    void solve(vector<int> loc, int r, int c) {
        if(r == limit)
            ans.push_back(toString(loc));
        else {
            for(int col = c; col < limit; ++col) {
                loc[r] = col;
                if(isSafe(loc, r, col))
                    solve(loc, r + 1, 0);
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<int> loc(n, 0);
        limit = n;
        solve(loc, 0, 0);
        return ans;
    }
};
