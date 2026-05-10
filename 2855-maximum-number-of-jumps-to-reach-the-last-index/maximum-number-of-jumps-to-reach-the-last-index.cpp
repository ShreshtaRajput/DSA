class Solution {
private:
    int solve(int i, vector<int> &nums, int target, vector<int> &dp){
        if(i == nums.size() - 1){
            return 0;
        }

        if(dp[i] != INT_MIN){
            return dp[i];
        }

        int ans = -1;

        for(int j = i+1; j < nums.size(); j++){
            if(abs(nums[j] - nums[i]) <= target){
                int res = solve(j, nums, target, dp);

                if(res != -1){
                    ans = max(ans, 1+res);
                }
            }
        }

        return dp[i] = ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);

        return solve(0, nums, target, dp);
    }
};