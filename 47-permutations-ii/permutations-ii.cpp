class Solution {
private:
    void helper(vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp, int n, vector<int> &freq){
        if(temp.size() >= n){
            ans.push_back(temp);
            return;
        }

        int lastRemoved = INT_MAX;
        for(int i = 0; i < n; i++){
            if(!freq[i] && nums[i] != lastRemoved){
                freq[i] = 1;
                temp.push_back(nums[i]);
                helper(nums, ans, temp, n, freq);
                lastRemoved = nums[i];
                temp.pop_back();
                freq[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(n, 0);

        helper(nums, ans, temp, n, freq);

        return ans;
    }
};