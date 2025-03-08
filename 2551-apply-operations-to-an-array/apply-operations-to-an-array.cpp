class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans = nums;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (ans[i] == ans[i + 1]) {
                ans[i] = 2 * ans[i];
                ans[i + 1] = 0;
            }
        }

        // Shifting zero to back
        vector<int> res;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != 0) {
                res.push_back(ans[i]);
            }
        }

        while (res.size() < ans.size()) {
            res.push_back(0);
        }

        return res;
    }
};