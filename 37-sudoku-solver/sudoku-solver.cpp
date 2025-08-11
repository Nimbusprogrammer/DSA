class Solution {
public:
    bool issafe(vector<vector<char>>& board, char val, int row, int col) {
        for (int k = 0; k < 9; k++) {
            if (board[row][k] == val) return false;
            if (board[k][col] == val) return false;
        }
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        // Base case: solved
        if (row == 9) return true;

        // Move to next row if col == 9
        if (col == 9) return helper(board, row + 1, 0);

        // Skip filled cells
        if (board[row][col] != '.') return helper(board, row, col + 1);

        // Try placing digits 1 to 9
        for (char ch = '1'; ch <= '9'; ch++) {
            if (issafe(board, ch, row, col)) {
                board[row][col] = ch;
                if (helper(board, row, col + 1)) return true;
                board[row][col] = '.'; // backtrack
            }
        }
        return false; // no valid number found
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
