class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> mp1;

        // Calculate distinct elements in nums
        for (int i = 0; i < nums.size(); i++) {
            mp1[nums[i]]++;
        }

        int distinctElement = mp1.size();

        // Making subarrays with k distinct elements
        int left = 0;
        int distinctCount = 0;

        for (int right = 0; right < nums.size(); ++right) {
            unordered_map<int, int> windowMap;
            for (int i = right; i < nums.size(); i++) {
                windowMap[nums[i]]++;
                if (windowMap.size() == distinctElement) {
                    count++;
                }
            }
        }

        return count;
    }
};