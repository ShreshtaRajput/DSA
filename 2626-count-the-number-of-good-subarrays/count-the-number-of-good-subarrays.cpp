class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        long long result = 0;
        int left = 0;
        long long pairs = 0;
        int right = 0;

        while( right < n ){
            pairs += freq[nums[right]];
            freq[nums[right]]++;
            // Contracting the window
            while(pairs >= k){
                result += n - right;
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
            right++;
        }
        return result;
    }
};