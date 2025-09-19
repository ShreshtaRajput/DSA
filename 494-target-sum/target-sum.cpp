class Solution {
private:
    int solve(vector<int> &nums, int index, int target, vector<vector<int>> &dp, int totSum){
        // Base case
        if(index < 0){
            if(target == 0)return 1;
            else return 0;
        }

        if(target < -totSum || target > totSum) return 0;

        if(dp[index][target + totSum] != -1) return dp[index][target + totSum];

        int add = solve(nums, index - 1, target + nums[index], dp, totSum);
        int sub = solve(nums, index - 1, target - nums[index], dp, totSum);

        return dp[index][target + totSum] = add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int totSum = 0;
        for(int num: nums){
            totSum += num;
        }

        vector<vector<int>> dp(n, vector<int>(2*totSum + 1, -1));

        return solve(nums, n-1, target, dp, totSum);
    }
};

// class Solution {
// private:
//     void helper(vector<int>& nums, int index, int target, int &ans){
//         // Base case
//         if(index == nums.size()){
//             if(target == 0){
//                 ans++;
//             }
//             return;
//         }

//         helper(nums, index + 1, target - nums[index], ans);
//         helper(nums, index + 1, target + nums[index], ans);
//     }

// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int ans = 0;

//         helper(nums, 0, target, ans);

//         return ans;
//     }
// };