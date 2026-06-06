class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), left(n), right(n);

        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] + nums[i];
            int j = n - 1 - i;
            right[j] = right[j + 1] + nums[j];
        }

        for(int i = 0; i < n; i++){
            ans[i] = abs(left[i] - right[i]);
        }

        return ans;
    }
};