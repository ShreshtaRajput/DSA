class Solution {
private:
    void helper(vector<int>& nums, vector<int> &output, int index, vector<vector<int>> &ans){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        output.push_back(nums[index]);
        helper(nums, output, index + 1, ans);
        output.pop_back();
        while(index < nums.size() - 1 && nums[index] == nums[index + 1]){
            index += 1;
        }
        helper(nums, output, index + 1, ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;

        helper(nums, output, 0, ans);

        return ans;
    }
};