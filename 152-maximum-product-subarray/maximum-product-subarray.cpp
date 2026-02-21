class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        if(n == 1) return nums[0];

        for(int i = 0; i < n; i++){
            int curr_prod = nums[i];
            res = max(res, curr_prod);
            for(int j = i+1; j < n; j++){
                curr_prod *= nums[j];
                res = max(res, curr_prod);
            }
        }

        return res;
    }
};