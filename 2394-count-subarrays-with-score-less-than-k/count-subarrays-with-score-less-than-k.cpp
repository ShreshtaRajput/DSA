class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;

        int left = 0;
        vector<long long> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        for(int right = 0; right < nums.size(); right++){
            int length = right - left + 1;

            long long sum = prefixSum[right] - (left > 0 ? prefixSum[left - 1]: 0);

            // If the window is invalid
            while(sum * length >= k && left <= right){
                left++;
                sum = prefixSum[right] - (left > 0 ? prefixSum[left - 1]: 0);
                length = right - left + 1;
            }

            count += (right - left + 1);
        }

        return count;
    }
};