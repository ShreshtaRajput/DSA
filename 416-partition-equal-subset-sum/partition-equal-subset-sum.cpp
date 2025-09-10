class Solution {
private:
    bool solve(vector<int> &nums, int index, int target, vector<vector<int>> &dp){
        // Base case
        if(target == 0) return true;
        if(index == 0) return (target == nums[0]);

        if(dp[index][target] != -1) return dp[index][target];

        bool notTake = solve(nums, index - 1, target, dp);
        bool take = false;
        if(target >= nums[index]){
            take = solve(nums, index - 1, target - nums[index], dp);
        }

        return dp[index][target] = notTake || take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = 0;
        for(auto it: nums) totSum += it;

        if(totSum % 2 != 0) return false;

        int target = totSum/2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // TABULATION
        // For every index where target = 0, we will return true
        // for(int i = 0; i < n; i++){
        //     dp[i][0] = 1;
        // }

        return solve(nums, n-1, target, dp);
    }
};