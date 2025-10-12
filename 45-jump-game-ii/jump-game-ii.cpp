class Solution {
private:
    int solve(vector<int> &nums, int n, int index, vector<int> &dp){
        // Base case
        if(index == n-1){
            return 0;
        }

        if(dp[index] != -1) return dp[index];
        
        int jumps = 1e9;
        for(int i = 1; i <= nums[index]; i++){
            if(index + i < n){
                jumps = min(jumps, 1 + solve(nums, n, index + i, dp));
            }
        }

        return dp[index] = jumps;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(nums, n, 0, dp);
    }
};