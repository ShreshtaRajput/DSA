class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());

        // We just need to find the longest common subsequence in the string and the reversed string
        // The longest common subsequence will already be a palindrome

        int n = s.size();

        vector<int> prev(n+1, 0), curr(n+1, 0);
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        // Space optimized
        for(int i = 0; i <= n; i++){
            prev[0] = 0;
        }

        for(int i = 0; i <= n; i++){
            prev[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];

        // TABULATE
        // for(int i = 0; i <= n; i++){
        //     dp[i][0] = 0;
        // }

        // for(int i = 0; i <= n; i++){
        //     dp[0][i] = 0;
        // }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         if(s[i-1] == s2[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         }else{
        //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n][n]; 
    }
};