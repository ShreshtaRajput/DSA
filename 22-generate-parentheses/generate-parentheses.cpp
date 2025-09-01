class Solution {
private:
    void helper(int n, vector<string> &ans, string temp, int open, int close){
        // base case
        if(temp.size() == 2*n){
            ans.push_back(temp);
        }

        if(open < n){
            helper(n, ans, temp + '(', open + 1, close);
        }
        if(close < open){
            helper(n, ans, temp + ')', open, close + 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        helper(n, ans, temp,0, 0);

        return ans;
    }
};