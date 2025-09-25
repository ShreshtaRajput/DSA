class Solution {
private:
    int solve(vector<int>& prices, int k, int index, int status, int t,
              vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        // Base case
        if (index == n || t == k)
            return 0;

        int profit = 0;

        if (dp[index][t][status] != -1)
            return dp[index][t][status];

        if (status) {
            profit = max(-prices[index] + solve(prices, k, index + 1, 0, t, dp),
                         solve(prices, k, index + 1, 1, t, dp));
        } else {
            profit =
                max(prices[index] + solve(prices, k, index + 1, 1, t + 1, dp),
                    solve(prices, k, index + 1, 0, t, dp));
        }

        return dp[index][t][status] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        return solve(prices, k, 0, 1, 0, dp);
    }
};