class Solution {
private:
    int solve(int i, bool bCount, string s, vector<vector<int>> &dp){
        int n = s.size();
        if(i == n){
            return 0;
        }

        if(dp[i][bCount] != -1){
            return dp[i][bCount];
        }

        // We have the option to keep the character or delete the character
        // If B has started, we need to delete all the As coming forward to maintain the balance
        int keep = INT_MAX;
        int del = 1 + solve(i+1, bCount, s, dp);
        if(s[i] == 'a'){
            // If B has not started yet, we can keep the A
            if(bCount == 0) keep = solve(i+1, 0, s, dp);
        }else{
            keep = solve(i+1, 1, s, dp);
        }

        return dp[i][bCount] = min(keep, del);
    }
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            // bCount = 0
            dp[i][0] = 1 + dp[i + 1][0]; // delete
            if (s[i] == 'a') {
                dp[i][0] = min(dp[i][0], dp[i + 1][0]); // keep
            } else {
                dp[i][0] = min(dp[i][0], dp[i + 1][1]); // keep 'b'
            }

            // bCount = 1
            dp[i][1] = 1 + dp[i + 1][1]; // delete
            if (s[i] == 'b') {
                dp[i][1] = min(dp[i][1], dp[i + 1][1]); // keep
            }
        }

        return dp[0][0];
        // return solve(0, 0, s, dp);
    }
};