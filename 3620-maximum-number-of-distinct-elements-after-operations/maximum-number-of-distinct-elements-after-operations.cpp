class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int count = 0;
        int prev = -1e9;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            int curr = max(nums[i] - k, prev + 1);
            // At any index, the max range we have is {nums[i] - k, nums[i] + k}
            if(curr <= nums[i] + k){
                count++;
                prev = curr;
            }
        }

        return count;
    }
};