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
        vector<vector<int>> dp(amount + 1, vector<int>(n, -1));
        return solve(amount, coins, 0, dp);
    }
};