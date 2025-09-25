class Solution {
private:
    int solve(vector<int>& prices, int index, int status,
              vector<vector<int>>& dp) {
        int n = prices.size();

        if (index >= n) return 0;

        int profit = 0;

        if (dp[index][status] != -1){
            return dp[index][status];
        }

        if (status) {
            profit = max(-prices[index] + solve(prices, index + 1, 0, dp),
                         solve(prices, index + 1, 1, dp));
        }
        else {
            profit = max(prices[index] + solve(prices, index + 2, 1, dp),
                         solve(prices, index + 1, 0, dp));
        }

        return dp[index][status] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};