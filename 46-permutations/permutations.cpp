class Solution {
private:
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<int> &freq, int n){
        if(temp.size() >= n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!freq[i]){
                freq[i] = 1;
                temp.push_back(nums[i]);
                helper(nums, ans, temp, freq, n);
                temp.pop_back();
                freq[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(n,0);

        helper(nums, ans, temp, freq, n);

        return ans;
    }
};

// class Solution {
// private:
//     void solve(vector<int> nums, vector<vector<int>>& ans, int i){
//         // Base case
//         if(i >= nums.size()){
//             ans.push_back(nums);
//             return;
//         }

//         for(int j = i; j < nums.size(); j++){
//             swap(nums[i], nums[j]);
//             solve(nums, ans, i+1);
//         }
//     }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int index = 0;
//         solve(nums, ans, index);
//         return ans;
//     }
// };