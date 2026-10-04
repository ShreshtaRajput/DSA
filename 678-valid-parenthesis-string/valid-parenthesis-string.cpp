class Solution {
private:
    bool solve(string s, int i, int open, int close,
               vector<vector<vector<int>>>& dp) {
        if (close > open)
            return false;

        if (i == s.size()) {
            return open == close;
        }

        if (dp[i][open][close] != -1)
            return dp[i][open][close];

        if (s[i] == '(')
            return dp[i][open][close] = solve(s, i + 1, open + 1, close, dp);
        if (s[i] == ')')
            return dp[i][open][close] = solve(s, i + 1, open, close + 1, dp);

        return dp[i][open][close] = solve(s, i + 1, open + 1, close, dp) ||
                                    solve(s, i + 1, open, close + 1, dp) ||
                                    solve(s, i + 1, open, close, dp);
    }

public:
    bool checkValidString(string s) {
        vector<vector<vector<int>>> dp(
            s.size(), vector<vector<int>>(s.size(), vector<int>(s.size(), -1)));
        return solve(s, 0, 0, 0, dp);
    }
};