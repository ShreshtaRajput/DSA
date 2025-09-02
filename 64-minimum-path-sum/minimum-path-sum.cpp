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

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, grid, dp);
    }
};