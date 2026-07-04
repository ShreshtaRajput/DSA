class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MIN;

        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        for(int i = 0; i < n; i++){
            if(i - k >= 0){
                res = max(res, prefixMax[i-k] + nums[i]);
            }
        }

        return res;
    }
};