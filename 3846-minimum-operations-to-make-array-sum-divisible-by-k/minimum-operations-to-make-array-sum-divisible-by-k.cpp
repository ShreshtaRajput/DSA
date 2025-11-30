class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;

        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }

        return totalSum % k;
    }
};