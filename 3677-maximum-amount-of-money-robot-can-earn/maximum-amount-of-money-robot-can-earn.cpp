class Solution {
private:
    int solve(int i, int j, int k, int r, int c, vector<vector<int>> &coins, vector<vector<vector<int>>> &dp){
        // Base case
        if(i >= r || j >= c){
            return -1e9;
        }

        // Destination
        if (i == r - 1 && j == c - 1) {
            if (coins[i][j] < 0 && k < 2) return 0;
            return coins[i][j];
        }

        if(dp[i][j][k] != -1e9) return dp[i][j][k];

        int res = -1e9;

        int take = coins[i][j] + max(
            solve(i + 1, j, k, r, c, coins, dp),
            solve(i, j + 1, k, r, c, coins, dp)
        );
        res = max(res, take);

        if (coins[i][j] < 0 && k < 2) {
            int skip = max(
                solve(i + 1, j, k + 1, r, c, coins, dp),
                solve(i, j + 1, k + 1, r, c, coins, dp)
            );
            res = max(res, skip);
        }

        return dp[i][j][k] = res;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));

        return solve(0, 0, 0, n, m, coins, dp);
    }
};