class Solution {
private:
    void solve(int n, vector<string> &res, string temp, int open, int closed){
        if(temp.size() == 2*n){
            res.push_back(temp);
        }

        if(open < n){
            solve(n, res, temp + '(', open + 1, closed);
        }

        if(closed < open){
            solve(n, res, temp + ')', open, closed + 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";

        solve(n, res, temp, 0, 0);

        return res;
    }
};