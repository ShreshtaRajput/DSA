class Solution {
private:
    void helper(vector<int>& nums, int index, int target, int &ans){
        // Base case
        if(index == nums.size()){
            if(target == 0){
                ans++;
            }
            return;
        }

        helper(nums, index + 1, target - nums[index], ans);
        helper(nums, index + 1, target + nums[index], ans);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;

        helper(nums, 0, target, ans);

        return ans;
    }
};