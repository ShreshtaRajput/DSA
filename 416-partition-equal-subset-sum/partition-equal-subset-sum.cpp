class Solution {
private:
    bool solve(vector<int>& nums, int index, int target,
               vector<vector<int>>& dp) {
        // Base case
        if (target == 0)
            return true;
        if (index == 0)
            return (target == nums[0]);

        if (dp[index][target] != -1)
            return dp[index][target];

        bool notTake = solve(nums, index - 1, target, dp);
        bool take = false;
        if (target >= nums[index]) {
            take = solve(nums, index - 1, target - nums[index], dp);
        }

        return dp[index][target] = notTake || take;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = 0;
        for (auto it : nums)
            totSum += it;

        if (totSum % 2 != 0)
            return false;

        int target = totSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // TABULATION
        // For every index where target = 0, we will return true
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = dp[i-1][j];
                bool take = false;
                if (j >= nums[i]) {
                    take = dp[i-1][j-nums[i]];
                }

                dp[i][j] = take || notTake;
            }
        }

        return dp[n-1][target];
        // return solve(nums, n - 1, target, dp);
    }
};