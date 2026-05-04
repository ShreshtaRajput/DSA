class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        int f = 0;  //Calculate f0
        for(int i = 0; i < n; i++){
            f += i * nums[i];
        }

        int res = f;
        for(int i = 1; i < n; i++){
            f = f + sum - (n) * nums[n-i];
            res = max(res, f);
        }

        return res;
    }
};