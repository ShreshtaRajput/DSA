class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans = 0;

        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        long long ele1 = nums[nums.size() - 1];
        long long ele2 = nums[nums.size() - 2];

        ans += ele1 * ele2 * 1e5;

        return ans;
    }
};