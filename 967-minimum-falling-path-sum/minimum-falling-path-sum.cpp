class Solution {
private:
    int solve(int row, int col, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        int n = matrix.size();
        // Base case
        if (col < 0 || col >= n)
            return 1e9; // Out of bounds
        if (row == 0)
            return matrix[row][col];

        if (dp[row][col] != 1e9)
            return dp[row][col];

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

        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        // TABULATION
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int way2 = INT_MAX, way3 = INT_MAX;
                // directly up
                int way1 = matrix[i][j] + dp[i-1][j];
                // left diagonal
                if(j > 0) way2 = matrix[i][j] + dp[i-1][j-1];
                // Right diagonal
                if(j < n-1) way3 = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(way1, min(way2, way3));
            }
        }

        for(int i = 0; i < n; i++){
            minSum = min(minSum, dp[n-1][i]);
        }

        return minSum;
    }
};