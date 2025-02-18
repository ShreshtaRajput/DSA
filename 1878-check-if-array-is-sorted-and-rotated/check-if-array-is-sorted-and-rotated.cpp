class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> nums2(nums);

        for(int i = 0 ;i < nums.size(); i++){
            nums2[i] = nums[i];
        }

        sort(nums.begin(),nums.end());

        for(int rotation = 0; rotation < nums.size(); rotation++) {
            bool isMatch = true;
            
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] != nums2[(i + rotation) % nums.size()]) {
                    isMatch = false;
                    break;
                }
            }
            
            if(isMatch) return true;
        }

        return false;
    }
};