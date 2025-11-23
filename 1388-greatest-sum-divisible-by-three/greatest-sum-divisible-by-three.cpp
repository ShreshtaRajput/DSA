class Solution {
private:
    int solve(vector<int> &nums, int n, int index, int curr_rem, vector<vector<int>> &dp){
        if(index == n){
            if(curr_rem == 0) return 0;
            else return -1e9;
        }

        if(dp[index][curr_rem] != -1) return dp[index][curr_rem];

        int take = nums[index] + solve(nums, n, index + 1, (curr_rem + nums[index]) % 3, dp);
        int notTake = solve(nums, n, index + 1, curr_rem, dp);

        return dp[index][curr_rem] = max(take, notTake);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(3, -1));

        return solve(nums, n, 0, 0, dp);
    }
};