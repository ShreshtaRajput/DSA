class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int bin = 0;
        for(int i = 0; i < nums.size(); i++){
            bin = ((bin << 1) + nums[i]) % 5;
            ans.push_back(bin == 0);
        }

        return ans;
    }
};