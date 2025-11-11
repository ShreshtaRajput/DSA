class Solution {
private:
    int solve(vector<string>& strs, int index, int m, int n, vector<vector<vector<int>>> &dp){
        // Base case
        if(index >= strs.size()){
            return 0;
        }

        if(dp[index][m][n] != -1) return dp[index][m][n];

        int numZeroes = 0;
        int numOnes = 0;
        for(int i = 0; i < strs[index].size(); i++){
            if(strs[index][i] == '0') numZeroes++;
            else numOnes++;
        }

        int notPick = solve(strs, index + 1, m, n, dp);
        int pick = 0;
        if(numOnes <= n && numZeroes <= m){
            pick = 1 + solve(strs, index+1, m - numZeroes, n - numOnes, dp);
        }

        return dp[index][m][n] = max(pick, notPick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // vector<vector<vector< int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        // return solve(strs, 0, m, n, dp);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string &s : strs) {
            int numZeroes = 0, numOnes = 0;
            for (char c : s) {
                if (c == '0') numZeroes++;
                else numOnes++;
            }

            // Traverse backward to prevent using the same string multiple times
            for (int i = m; i >= numZeroes; i--) {
                for (int j = n; j >= numOnes; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - numZeroes][j - numOnes]);
                }
            }
        }

        return dp[m][n];
    }
};