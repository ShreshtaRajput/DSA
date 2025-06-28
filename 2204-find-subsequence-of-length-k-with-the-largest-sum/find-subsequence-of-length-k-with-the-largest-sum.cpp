class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        vector<int> auxArray = nums;

        if(k == nums.size()){
            return nums;
        }

        sort(auxArray.begin(), auxArray.end());

        for (int i = nums.size() - 1; i > nums.size() - k - 1; i--) {
            freq[auxArray[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (freq[nums[i]] > 0) {
                ans.push_back(nums[i]);
                freq[nums[i]]--;
            }
        }

        return ans;
    }
};