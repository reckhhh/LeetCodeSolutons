/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

Tags: Backtracking
*/
class Solution {
public:
    int answer = 0;
    bool isSafe(vector<int> loc, int r, int c) {
        for(int row = r - 1, ldia = c - 1, rdia = c + 1; row >= 0; --row, --ldia, ++rdia) {
            int checkCol = loc[row];
            if(checkCol == c || checkCol == ldia || checkCol == rdia)
                return false;
        }
        return true;
    }
    void solve(vector<int> loc, int r, int c, int n) {
        if(r == n)
            ++answer;
        else {
            for(int col = c; col < n; ++col) {
                loc[r] = col;
                if(isSafe(loc, r, col))
                    solve(loc, r + 1, 0, n);
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> loc(n, 0);
        solve(loc, 0, 0, n);
        return answer;
    }
};
