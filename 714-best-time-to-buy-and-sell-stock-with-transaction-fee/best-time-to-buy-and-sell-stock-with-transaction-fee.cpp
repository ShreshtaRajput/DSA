class Solution {
private:
    int solve(vector<int> &prices, int fee, int index, int status, vector<vector<int>> &dp){
        int n = prices.size();
        // Base case
        if(index == n) return 0;

        int profit = 0;

        if(dp[index][status] != -1) return dp[index][status];

        if(status){
            profit = max(-prices[index] + solve(prices, fee, index + 1, 0, dp),
                            solve(prices, fee, index + 1, 1, dp));
        }else{
            profit = max(prices[index] - fee + solve(prices, fee, index + 1, 1, dp),
                            solve(prices, fee, index + 1, 0, dp));
        }

        return dp[index][status] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2, -1));
        //TABULATE
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // SPACE OPTIMIZED
        vector<int> ahead(2, 0), curr(2, 0);

        // dp[n][0] = 0; dp[n][1] = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= 1; j++){
                int profit = 0;
                if(j){
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                }else{
                    profit = max(prices[i] - fee + ahead[1], ahead[0]);
                }
                curr[j] = profit;
            }
            ahead = curr;
        }

        return ahead[1];
        // return solve(prices, fee, 0, 1, dp);
    }
};