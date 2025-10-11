class Solution {
private:
    bool solve(vector<int> &nums, int index, int n, vector<int> &dp){
        // Base case
        if(index == n-1){   //This is the last step
            return true;
        }

        if(dp[index] != -1) return dp[index];

        for(int i = 1; i <= nums[index]; i++){
            // jump = solve(nums, index + i, n);
            if(solve(nums, index + i, n, dp)){
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        // Mark the final step as true
        // dp[n-1] = true;

        if(solve(nums, 0, n, dp)){
            return true;
        }else{
            return false;
        }
    }
};