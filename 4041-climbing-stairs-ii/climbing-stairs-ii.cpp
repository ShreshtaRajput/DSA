class Solution {
private:
    int solve(int i, vector<int>& costs, int n, vector<int> &dp) {
        if(i == n) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int plusOne = INT_MAX;
        int plusTwo = INT_MAX;
        int plusThree = INT_MAX;

        if(i + 1 <= n) plusOne = costs[i] + 1 + solve(i + 1, costs, n, dp);
        if(i + 2 <= n) plusTwo = costs[i + 1] + 4 + solve(i + 2, costs, n, dp);
        if(i + 3 <= n) plusThree = costs[i + 2] + 9 + solve(i + 3, costs, n, dp);

        return dp[i] = min(plusOne, min(plusTwo, plusThree));
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n, -1);
        return solve(0, costs, n, dp);
    }
};