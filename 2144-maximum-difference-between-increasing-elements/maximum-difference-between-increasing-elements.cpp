class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int min_val = nums[0];
        int ans = -1;

        for(int i = 1; i < n; i++){
            if(nums[i] > min_val){
                ans = max(ans, nums[i] - min_val);
            }else{
                min_val = nums[i];
            }
        }

        return ans;
    }
};