class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> lsum, rsum(n+1, 0);

        lsum.push_back(0);
        for(int i = 0; i < n; i++){
            lsum.push_back(lsum.back() + nums[i]);
        }

        int sum = 0;
        for(int i = n - 1; i >= 0; i--){
            rsum[i] = sum;
            sum += nums[i];
        }

        for(int i = 0; i < n; i++){
            ans.push_back(abs(lsum[i] - rsum[i]));
        }

        return ans;
    }
};