class Solution {
private:
    int solve(int n, vector<int> &dp){
        // Base case
        if(n == 1){
            return 1;
        }

        if(dp[n] != -1) return dp[n];

        int max_val = 0;
        for(int i = 1; i < n; i++){
            // i*(n-1) =>   either we stop at i and n-i
            // i*(solve(n-1,dp)) => or we split further more
            max_val = max(max_val, max(i*(n-i), i*solve(n-i, dp)));
        }

        return dp[n] = max_val;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};