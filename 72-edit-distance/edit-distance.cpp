class Solution {
private:
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp) {
        // Base case
        // If word1 gets exhausted, then then number of operations to convert
        // word1 to word2 is j + 1 operations
        if (i < 0)
            return j + 1;
        // similarly for word2, we get i + 1 operation
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        // If the chars match
        if (word1[i] == word2[j])
            return solve(word1, word2, i - 1, j - 1, dp);

        // f(i-1, j) -> deletion, f(i, j-1) -> insertion, f(i-1, j-1) ->
        // replacement
        return dp[i][j] = 1 + min(solve(word1, word2, i - 1, j, dp),
                                  min(solve(word1, word2, i, j - 1, dp),
                                      solve(word1, word2, i - 1, j - 1, dp)));
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(word1, word2, m-1, n-1, dp);
    }
};