class Solution {
private:
    int solve(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        int n = matrix.size();
        // Base case
        if(col < 0 || col >= n) return 1e9;     //Out of bounds
        if(row == 0) return matrix[row][col];

        if(dp[row][col] != 1e9) return dp[row][col];

        // directly up
        int way1 = matrix[row][col] + solve(row - 1, col, matrix, dp);
        // left diagonal
        int way2 = matrix[row][col] + solve(row - 1, col - 1, matrix, dp);
        // Right diagonal
        int way3 = matrix[row][col] + solve(row - 1, col + 1, matrix, dp);

        return dp[row][col] = min(way1, min(way2, way3));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;

        for(int i = 0; i < n; i++){
            vector<vector<int>> dp(n, vector<int>(n, 1e9));
            int currSum = solve(n-1, i, matrix, dp);
            minSum = min(minSum, currSum);
        }

        return minSum;
    }
};