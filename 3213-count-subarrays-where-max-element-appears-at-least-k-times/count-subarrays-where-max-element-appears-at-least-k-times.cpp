class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        long long count = 0;
        int left = 0, right = 0;

        while(right < n){
            if(nums[right] == maxElement){
                count++;
            }

            while(count >= k){
                res += (n - right);
                if(nums[left] == maxElement){
                    count--;
                }
                left++;
            }
            right++;
        }

        return res;
    }
};