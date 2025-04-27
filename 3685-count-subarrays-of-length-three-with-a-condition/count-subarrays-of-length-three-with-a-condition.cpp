class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;

        for(int left = 0; left < nums.size() - 2; left++){
            int right = left + 2;

            int temp = nums[left] + nums[right];
            if(2*temp == nums[left + 1]){
                count++;
            }
        }

        return count;
    }
};