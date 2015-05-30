/*
 Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Tags: Array, Backtracking
*/
class Solution {
private:
    vector<vector<char> > *board;
    string *word;
    bool  **used;
public:
    bool isInBoard(int i, int j) {
        return (i < 0 || j < 0 || i >= board->size() || j >= (*board)[i].size()) ? false : true;
    }
    bool check(int i, int j, int cnt) {
        if(cnt == word->size())
            return true;
        if(isInBoard(i, j)) {
            if(!used[i][j] && (*board)[i][j] == (*word)[cnt]) {
                used[i][j] = true;  // used
                bool ret = (check(i-1, j, cnt+1) || check(i+1, j, cnt+1) || check(i, j-1, cnt+1) || check(i, j+1, cnt+1)) ? true : false;
                used[i][j] = false; // unused
                return ret;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        int N = board.size();
        if(N == 0)
            return false;
            
        this->board = &board;
        this->word  = &word;
        
        used = new bool*[N];
        for(int i = 0; i < N; ++i) {
            used[i] = new bool[board[i].size()];
            for(int j = 0; j < board[i].size(); ++j)
                used[i][j] = false;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < board[i].size(); ++j)
                if(check(i, j, 0))
                    return true;
        }
        return false;
    }
};
