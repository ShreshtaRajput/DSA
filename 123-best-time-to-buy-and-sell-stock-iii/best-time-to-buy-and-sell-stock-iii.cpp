class Solution {
private:
    int solve(vector<int>& prices, int index, int status, int transactions,
              vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        // Base case
        if (index == n || transactions == 2)
            return 0;

        int profit = 0;

        if(dp[index][transactions][status] != -1) return dp[index][transactions][status];

        if (status) {
            profit =
                max(-prices[index] + solve(prices, index + 1, 0, transactions, dp),
                    solve(prices, index + 1, 1, transactions, dp));
        } else {
            // We increment number of transactions only when we sell a stock,
            // since a transaction is considered complete only when we are able
            // to sell a stock
            profit = max(prices[index] +
                             solve(prices, index + 1, 1, transactions + 1, dp),
                         solve(prices, index + 1, 0, transactions, dp));
        }

        return dp[index][transactions][status] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));

        // TABULATE
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= 1; j++){
                dp[i][2][j] = 0;
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j <= 1; j++){
                dp[n][i][j] = 0;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k <= 1; k++){
                    int profit = 0;
                    if(k){
                        profit = max(-prices[i] + dp[i+1][j][0], dp[i+1][j][1]);
                    }else{
                        profit = max(prices[i] + dp[i+1][j+1][1], dp[i+1][j][0]);
                    }

                    dp[i][j][k] = profit;
                }
            }
        }

        return dp[0][0][1];
        // return solve(prices, 0, 1, 0, dp);
    }
};