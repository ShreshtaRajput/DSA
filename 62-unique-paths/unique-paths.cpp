class Solution {
private:
    int solve(int row, int col, vector<vector<int>> &dp){
        // Base case
        if(row == 0 || col == 0){
            return 1;
        }

        if(dp[row][col] != -1) return dp[row][col];

        int way1 = solve(row - 1, col, dp);
        int way2 = solve(row, col - 1, dp);

        return dp[row][col] = way1 + way2;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, dp);
    }   
};