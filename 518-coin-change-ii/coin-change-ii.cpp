class Solution {
private:
    int solve(int amount, vector<int> &coins, int index, vector<vector<int>> &dp){
        // Base case
        if(amount == 0) return 1;

        if(amount < 0  || index == coins.size()) return 0;

        if(dp[amount][index] != -1) return dp[amount][index];

        // Take the coin => continue with same denomination
        int take = solve(amount - coins[index], coins, index, dp);
        // Skip the coin => move to next denomination
        int notTake = solve(amount, coins,index + 1, dp);

        return dp[amount][index] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(amount + 1, vector<unsigned long long>(n+1, 0));

        // TABULATION
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i <= amount; i++){
            for(int idx = n-1; idx >= 0; idx--){
                unsigned long long take = 0;
                if(i - coins[idx] >= 0) take = dp[i - coins[idx]][idx];
                unsigned long long notTake = dp[i][idx + 1];

                dp[i][idx] = take + notTake;
            }
        }

        return dp[amount][0];
        // return solve(amount, coins, 0, dp);
    }
};