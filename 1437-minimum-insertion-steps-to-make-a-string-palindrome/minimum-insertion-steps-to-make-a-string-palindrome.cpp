class Solution {
public:
    int minInsertions(string s) {
        // The minimum number of additions will be total length of substring minus the
        // Length of the longest palindromic subsequence
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int len = dp[n][n];

        return n - len;
    }
};