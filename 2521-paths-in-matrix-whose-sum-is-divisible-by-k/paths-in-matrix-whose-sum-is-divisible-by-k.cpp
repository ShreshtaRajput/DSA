#define MOD 1000000007

class Solution {
private:
    int solve(vector<vector<int>> &grid, int k, int row, int col, int rem, vector<vector<vector<int>>> &dp){
        int m = grid.size();
        int n = grid[0].size();

        if(row == m-1 && col == n-1){
            if(rem % k == 0) return 1;
            else return 0;
        }

        if(dp[row][col][rem] != -1) return dp[row][col][rem];

        long long ways = 0;

        if(col + 1 < n){
            int newRem = (rem + grid[row][col + 1]) % k;
            ways = (ways + solve(grid, k, row, col + 1, newRem, dp)) % MOD;
        }

        if(row + 1 < m){
            int newRem = (rem + grid[row + 1][col]) % k;
            ways = (ways + solve(grid, k, row + 1, col, newRem, dp)) % MOD;
        }

        return dp[row][col][rem] = ways;
    }
    // void solve(vector<vector<int>> &grid, int k, int &totalWays, int row, int col, int currSum){
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     if(row == m - 1 && col == n - 1){
    //         if(currSum % k == 0){
    //             totalWays = (totalWays + 1) % MOD; 
    //         }
    //         return;
    //     }

    //     // Traverse right and down
    //     if (col + 1 < n) {
    //         solve(grid, k, totalWays, row, col + 1, currSum + grid[row][col + 1]);
    //     }
    //     if (row + 1 < m) {
    //         solve(grid, k, totalWays, row + 1, col, currSum + grid[row + 1][col]);
    //     }
    // }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // int totalWays = 0;
        int m = grid.size(); int n = grid[0].size();
        // We will be storing [row][col][rem] in dp {rem = currSum % k}
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(grid, k, 0, 0, grid[0][0] % k, dp);

        // return totalWays;
    }
};