class Solution {
private:
    int solve(string s, string t, int i, int j, vector<vector<int>> &dp){
        // base case
        if(j < 0) return 1;     //t fully matched
        if(i < 0) return 0;     //s got exhausted but t did not match

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            dp[i][j] = solve(s, t, i-1, j-1, dp) + solve(s, t, i-1, j, dp);
        }else{
            dp[i][j] = solve(s, t, i-1, j, dp);
        }

        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(s, t, m-1, n-1, dp);
    }
};