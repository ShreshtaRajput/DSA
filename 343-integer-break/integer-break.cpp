class Solution {
private:
    int solve(int n, vector<int>& dp) {
        // Base case
        if (n == 1) {
            return 1;
        }

        if (dp[n] != -1)
            return dp[n];

        int max_val = 0;
        for (int i = 1; i <= n; i++) {
            // i*(n-1) =>   either we stop at i and n-i
            // i*(solve(n-1,dp)) => or we split further more
            max_val = max(max_val, max(i * (n - i), i * dp[n - i]));
        }

        return dp[n] = max_val;
    }

public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);

        dp[1] = 1;

        int maxVal = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                maxVal = max(maxVal, max(j * (i - j), j * dp[i - j]));

                dp[i] = maxVal;
            }
        }

        return dp[n];
        // return solve(n, dp);
    }
};