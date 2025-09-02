class Solution {
private:
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
        // Base case
        if(row == 0 && col == 0){
            return grid[row][col];
        }

        if(row < 0 || col < 0) return 1e9;

        if(dp[row][col] != -1) return dp[row][col];

        int way1 = grid[row][col] + solve(row - 1, col, grid, dp);
        int way2 = grid[row][col] + solve(row, col - 1, grid, dp);

        return dp[row][col] = min(way1, way2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // TABULATION
        vector<vector<int>> dp(m, vector<int>(n, -1));

        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                else{
                    int way1 = grid[i][j];
                    if(i > 0) way1 += dp[i-1][j];
                    else way1 += 1e9;

                    int way2 = grid[i][j];
                    if(j > 0) way2 += dp[i][j-1];
                    else way2 += 1e9;

                    dp[i][j] = min(way1, way2);
                }
            }
        }

        return dp[m-1][n-1];

        // return solve(m-1, n-1, grid, dp);
    }
};