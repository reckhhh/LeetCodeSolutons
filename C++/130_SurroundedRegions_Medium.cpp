/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Tags: Breadth-first Search
*/
class Solution {
public:
    void bfs(vector<vector<char> > &board, int r, int l) {
        int row = board.size();
        int col = board[0].size();
        deque<pair<int, int> > q;
        q.push_back(make_pair(r, l));
        board[r][l] = 'B';
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop_front();
            pair<int, int> adjs[4] = {
                {cur.first - 1, cur.second},
                {cur.first + 1, cur.second},
                {cur.first, cur.second - 1},
                {cur.first, cur.second + 1},
            };
            for(int i = 0; i < 4; ++i) {
                int adj_r = adjs[i].first;
                int adj_c = adjs[i].second;
                if(adj_r >= 0 && adj_r < row && adj_c >= 0 && adj_c < col && board[adj_r][adj_c] == 'O') {
                    q.push_back(make_pair(adj_r, adj_c));
                    board[adj_r][adj_c] = 'B';
                }
            }
        }
    }
    void solve(vector<vector<char> > &board) {
        int row = board.size();
        if(row == 0)    return;
        int col = board[0].size();
        if(col == 0)    return;
        
        for(int i = 0; i < col; ++i) {
            if(board[0][i]       == 'O')  bfs(board, 0, i);         // first row
            if(board[row - 1][i] == 'O')  bfs(board, row - 1, i);   // last  row
        }
        for(int i = 0; i < row; ++i) {
            if(board[i][0]       == 'O')  bfs(board, i, 0);         // first col
            if(board[i][col - 1] == 'O')  bfs(board, i, col - 1);   // last  col
        }
        for(int i = 0; i < row ; ++i) {
            for(int j = 0; j < col; ++j) {
                if      (board[i][j] == 'O')  board[i][j] = 'X';
                else if (board[i][j] == 'B')  board[i][j] = 'O';
            }
        }
    }
};
