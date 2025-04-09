class Solution {
private:
    void addSolution(vector<vector<string>>& ans, vector<vector<char>>& board,
                     int n) {
        vector<string> temp;

        for (int i = 0; i < n; i++) {
            string rowStr = "";
            for (int j = 0; j < n; j++) {
                rowStr += board[i][j];
            }
            temp.push_back(rowStr);
        }

        ans.push_back(temp);
    }

    bool isSafe(int row, int col, int n, vector<vector<char>>& board) {
        // Check for same row
       for (int y = 0; y < col; y++) {
            if (board[row][y] == 'Q') {
                return false;
            }
        }

        // Check for diagonal (Just the back diagonals)

        // Digonal above the element on the board
        for (int x = row, y = col; x >= 0 && y >= 0; x--, y--) {
            if (board[x][y] == 'Q') {
                return false;
            }
        }

        // Diagonal below the element on the board
        for (int x = row, y = col; x < n && y >= 0; x++, y--) {
            if (board[x][y] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans,
               vector<vector<char>>& board, int n) {
        // Base case
        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                // Backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));

        solve(0, ans, board, n);
        return ans;
    }
};