class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);

        int prev = 1;
        int prev2 = 0;

        for(int i = 1; i <= n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;

        // return solve(n, dp);
    }
};