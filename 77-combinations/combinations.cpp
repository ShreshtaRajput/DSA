class Solution {
private:
    void helper(int n, int k, vector<vector<int>> &ans, vector<int> &temp, int start){
        // base case
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        for(int i = start; i < n + 1; i++){
            temp.push_back(i);
            helper(n, k, ans, temp, i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(n, k, ans, temp, 1);
        return ans;
    }
};