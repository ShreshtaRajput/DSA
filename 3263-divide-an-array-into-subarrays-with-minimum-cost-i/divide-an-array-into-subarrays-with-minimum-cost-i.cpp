class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();

        vector<int> copy;

        for(int i = 1; i < n; i++){
            copy.push_back(nums[i]);
        }

        sort(copy.begin(), copy.end());

        res += (copy[0] + copy[1]);

        return res;
    }
};