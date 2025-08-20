class Solution {
private:
    void helper(int k, int n, vector<vector<int>> &ans, vector<int> temp, int total, int start){
        if(temp.size() == k && total == n){
            ans.push_back(temp);
            return;
        }
        // Use a start variable to stop redundant values to be pushed in temp
        // And no duplicate elements are there
        for(int i = start; i <= 9; i++){
            temp.push_back(i);
            helper(k, n, ans, temp, total + i, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(k, n, ans, temp, 0, 1);

        return ans;
    }
};