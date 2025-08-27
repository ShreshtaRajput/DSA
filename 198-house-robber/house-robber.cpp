class Solution {
private:
    int solve(vector<int> &nums, vector<int> &dp, int index){
        // Base case => if we reach at index 0, it means that we have not picked index 1
        // so we necessarily need to pick the index 1
        if(index == 0){
            return nums[index];
        }

        // Out of bounds edge case
        if(index < 0) return 0;

        if(dp[index] != -1) return dp[index];
        // Picking the current element, then skipping it's adjacent elements
        int pick = nums[index] + solve(nums, dp, index - 2);
        // Not picking the current element, moving to it's adjacent element
        int notPick = solve(nums, dp, index - 1);

        return dp[index] = max(pick, notPick);

        // this is same as recursion for subsets but with the use of dp
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);

        return solve(nums, dp, n-1);
    }
};