class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        int minCount = 1e9;

        int i = 1;
        while(i*i <= n){
            int square = i*i;
            int count = 1 + solve(n - square, dp);
            minCount = min(minCount, count);
            i++;
        }

        return dp[n] = minCount;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};