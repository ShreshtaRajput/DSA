class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        int ans = 0;

        // To calculate  number of subsequence in a range
        // n = 2**(range)
        // This array will store the powers of 2
        vector<int> pow(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            pow[i] = (pow[i - 1] * 2) % mod;
        }

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            if(nums[left] + nums[right] <= target){
                ans = (ans + pow[right - left]) % mod;
                left++;
            }else{
                right--;
            }
        }

        return ans;
    }
};