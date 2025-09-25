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

        // vector<vector<vector<int>>> dp(
        //     n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        // TABULATE
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));

        for(int i = 0; i <= k; i++){
            dp[n][i][0] = 0;
            dp[n][i][1] = 0;
        }

        for(int i = 0; i <= n; i++){
            dp[i][k][0] = 0;
            dp[i][k][1] = 0;
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= k-1; j++){
                for(int m = 0; m <= 1; m++){
                    int profit = 0;
                    if(m){
                        profit = max(-prices[i] + dp[i+1][j][0], dp[i+1][j][1]);
                    }else{
                        profit = max(prices[i] + dp[i+1][j+1][1], dp[i+1][j][0]);
                    }

                    dp[i][j][m] = profit;
                }
            }
        }

        return dp[0][0][1];
        // return solve(prices, k, 0, 1, 0, dp);
    }
};