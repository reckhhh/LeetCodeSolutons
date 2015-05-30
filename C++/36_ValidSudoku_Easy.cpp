/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 

Tags: Hash Table
*/
class Solution {
public:
    bool checkRows(vector<vector<char> > &board, int row_num) {
        vector<char> row(board[row_num]);
        return checkDupNum(row);
    }
    
    bool checkCols(vector<vector<char> > &board, int col_num) {
        vector<char> col(9, '.');
        for(int i = 0; i < 9; ++i)
            col[i] = board[i][col_num];
        return checkDupNum(col);
    }
    
    bool checkSquare(vector<vector<char> > &board) {
        vector<char> block;
        vector<vector<char> > block_array(9, block);
        for(int i = 0; i < 81; ++i) {
            int row = i / 9;
            int col = i % 9;
            int block_index = (row / 3) * 3 + (col / 3);
            block_array[block_index].push_back(board[row][col]);
        }
        for(int i = 0; i < 9; ++i) {
            if(!checkDupNum(block_array[i]))
                return false;
        }
        return true;
    }
    
    bool checkDupNum(vector<char> &vec) {
        if(vec.size() != 9)
            return false;
        int cntTime[9] = {0};
        for(int i = 0; i < 9; ++i) {
            if(vec[i] == '.')
                continue;
            int index = vec[i] - '1';
            if(index >= 0 && index < 9 && cntTime[index] == 0)
                cntTime[index] = 1;
            else
                return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < board.size(); ++i) {
            if(!checkRows(board, i))
                return false;
            if(!checkCols(board, i))
                return false;
        }
        return checkSquare(board);
    }
};
