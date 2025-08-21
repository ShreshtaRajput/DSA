class Solution {
private:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp,
                int index) {
        // base case
        if (temp.size() >= 2) { // minimum length of 2 is required
            ans.push_back(temp);
        }

        unordered_set<int> st; // to avoid duplicates

        for (int i = index; i < nums.size(); i++) {
            // If the element is repeated continue
            if (st.count(nums[i]))
                continue;
            // Condition for non-decreasing subsequence
            if (temp.empty() || nums[i] >= temp.back()) {
                st.insert(nums[i]);
                // Include case
                temp.push_back(nums[i]);
                helper(nums, ans, temp, i + 1);
                // Exclude case
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(nums, ans, temp, 0);

        return ans;
    }
};