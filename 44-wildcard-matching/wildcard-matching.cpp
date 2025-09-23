class Solution {
private:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        // Base cases
        if (i < 0 && j < 0) return true;    // both exhausted
        if (i < 0 && j >= 0) return false;  // pattern exhausted but string remains
        if (j < 0 && i >= 0) {
            // If s got exhausted -> it is an empty string
            // For matching, there has to be only "*" in p
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        }
        if (p[i] == '*') {
            // '*' matches empty sequence or one/more chars
            return dp[i][j] = solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp);
        }

        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s, p, m - 1, n - 1, dp);
    }
};
