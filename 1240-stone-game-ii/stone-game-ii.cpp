class Solution {
private:
    int solve(int index, int m, vector<int> &piles, vector<vector<int>> &dp){
        int n = piles.size();

        if(index >= n){
            return 0;
        }

        if(dp[index][m] != -1){
            return dp[index][m];
        }

        int ans = 0;
        int stones = 0;

        int totalRemaining = 0;
        for(int j = index; j < n; j++){
            totalRemaining += piles[j];
        }

        for(int i = 1; i <= 2*m && index + i <= n; i++){
            stones += piles[index + i - 1];

            int opp = solve(index + i, max(m, i), piles, dp);
            ans = max(ans, totalRemaining - opp);
        }

        return dp[index][m] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, 1, piles, dp);
    }
};