class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2;

        k = k % nums.size();

        if (k == 0)
            return;

        int i = nums.size() - k;

        for (i; i < nums.size(); i++) {
            nums2.push_back(nums[i]);
        }

        for (int j = 0; j < i; j++) {
            nums2.push_back(nums[j]);
        }

        for (int k = 0; k < nums.size(); k++) {
            nums[k] = nums2[k];
        }
    }
};