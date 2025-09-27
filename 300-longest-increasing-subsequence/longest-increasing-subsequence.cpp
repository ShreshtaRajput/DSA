class Solution {
private:
    int solve(vector<int> &nums, int index, int prev, vector<vector<int>> &dp, int n){
        // Base case
        if(index == n) return 0;

        if(dp[index][prev + 1] != -1) return dp[index][prev + 1];

        int len = solve(nums, index + 1, prev, dp, n);     //Not pick case
        if(prev == -1 || nums[index] > nums[prev]){
            len = max(len, 1 + solve(nums, index + 1, index, dp, n));      //Pick case
        }

        return dp[index][prev+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(nums, 0, -1, dp, n);
    }
};