class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> board,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && board[newRow][newCol] == 'O'){
                dfs(newRow, newCol, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse the first and last row
        for (int j = 0; j < m; j++) {
            // first row
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, board, vis);
            }
            // last row
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, board, vis);
            }
        }

        // Traverse the first and last column
        for(int i = 0; i < n; i++){
            // First column
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, vis);
            }
            // Last column
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, board, vis);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};