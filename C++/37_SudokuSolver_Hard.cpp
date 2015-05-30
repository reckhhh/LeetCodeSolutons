/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red. 

Tags: Backtracking, Hash Table
*/
class Solution {
public:
    bool checkRows(vector<vector<char> > &board, int row_num, int val) {
        vector<char> row(board[row_num]);
        return checkDupNum(row, val);
    }
    bool checkCols(vector<vector<char> > &board, int col_num, int val) {
        vector<char> col(9, '.');
        for(int i = 0; i < 9; ++i) {
            col[i] = board[i][col_num];
        }
        return checkDupNum(col, val);
    }
    bool checkSquare(vector<vector<char> > &board, int row, int col, int val) {
        vector<char> block;
        int block_index = (row / 3) * 3 + (col / 3);
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(block_index == ((i / 3) * 3 + j / 3))
                    block.push_back(board[i][j]);
            }
        }
        return checkDupNum(block, val);
    }
    bool checkDupNum(vector<char> &vec, int val) {
        if(vec.size() != 9)
            return false;
        for(int i = 0; i < 9; ++i) {
            if(vec[i] == '.')
                continue;
            int index = vec[i] - '0';
            if(index == val)
                return false;
        }
        return true;
    }
    
    bool searchSolution(vector<vector<char> > &board) {
        int cell_filled = 0;
        int last_row = 0, last_col = 0;
        for(int row = 0; row < 9; ++row) {
            for(int col = 0; col < 9; ++col) {
                if(board[row][col] == '.') {
                    ++cell_filled;
                    last_row = row;
                    last_col = col;
                }
            }
        }
        
        if(cell_filled == 1) {
            for(int v = 1;  v <= 9; ++v) {
                if(checkRows(board, last_row, v) && checkCols(board, last_col, v) && checkSquare(board, last_row, last_col, v)) {
                    board[last_row][last_col] = v + '0';
                    return true;
                }
            }
            return false;
        }
        
        for(int row = 0; row < 9; ++row) {
            for(int col = 0; col < 9; ++col) {
                if(board[row][col] != '.')
                    continue;
                else {
                    bool found = false;
                    for(int v = 1;  v <= 9; ++v) {
                        if(checkRows(board, row, v) && checkCols(board, col, v) && checkSquare(board, row, col, v)) {
                            board[row][col] = v + '0';
                            if(searchSolution(board)) {
                                found = true;
                                break;
                            }
                        }
                    }
                    if(!found) {
                        board[row][col] = '.';
                    }
                    return found;
                }
            }
        }
    }
    void solveSudoku(vector<vector<char> > &board) {
        searchSolution(board);
    }
};
