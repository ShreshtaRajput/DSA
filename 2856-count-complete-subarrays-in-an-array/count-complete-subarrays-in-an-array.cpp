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
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int> windowMap;
            for (int j = i; j < nums.size(); j++) {
                windowMap[nums[j]]++;
                if (windowMap.size() == distinctElement) {
                    count++;
                }
            }
        }

        return count;
    }
};