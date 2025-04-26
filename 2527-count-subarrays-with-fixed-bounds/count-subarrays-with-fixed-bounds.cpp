class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lastMin = -1, lastMax = -1, badIndex = -1;
        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            if (nums[i] > maxK || nums[i] < minK) {
                badIndex = i;
            }

            count += max(0, min(lastMin, lastMax) - badIndex);
        }

        return count;
    }
};