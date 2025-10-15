class Solution {
private:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = -1e9;

        for (int k = i; k <= j; k++) {
            int sum = (nums[i - 1] * nums[k] * nums[j + 1]) +
                      solve(nums, i, k - 1, dp) + solve(nums, k + 1, j, dp);
            ans = max(ans, sum);
        }

        return dp[i][j] = ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        // Adding 1s at the front and back to remove the dependece of element on
        // each other and we get independent subproblems
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(nums, 1, n - 2, dp);
    }
};