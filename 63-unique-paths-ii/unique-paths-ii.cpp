class Solution {
private:
    int solve(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>> &dp){
        // Base case
        if(row < 0 || col < 0 || obstacleGrid[row][col] == 1) return 0;

        if(row == 0 && col == 0) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        int way1 = solve(obstacleGrid, row - 1, col, dp);
        int way2 = solve(obstacleGrid, row, col - 1, dp);

        return dp[row][col] = way1 + way2;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Edge case - first block is the obstacle
        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(obstacleGrid, m-1, n-1, dp);
    }
};