class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), left(n), right(n);

        // Build left arr
        left[0] = nums[0];
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] + nums[i];
        }

        // Buil right arr
        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1] + nums[i];
        }

        for(int i = 0; i < n; i++){
            ans[i] = abs(left[i] - right[i]);
        }

        return ans;
    }
};