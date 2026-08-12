class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MIN;

        unordered_map<int, int> mp;

        int l = 0;
        for(int r = 0; r < n; r++){
            mp[nums[r]]++;
            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                // res = max(res, r-l+1);
                l++;
            }
            // else{
            //     mp[nums[l]]--;
            //     l++;
            // }
            res = max(res, r-l+1);
        }

        return res;
    }
};