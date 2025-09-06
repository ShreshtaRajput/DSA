class Solution {
    const int MOD = 1e9 + 7;

private:
    pair<long long, long long> solve(int row, int col,
                                     vector<vector<int>>& grid,
                                     vector<vector<pair<long, long>>>& dp) {
        // base case
        if (row == 0 && col == 0) {
            return {grid[row][col], grid[row][col]};
        }

        if (dp[row][col].first != LLONG_MIN &&
            dp[row][col].second != LLONG_MAX) {
            return dp[row][col];
        }

        long long maxProd = LLONG_MIN;
        long long minProd = LLONG_MAX;

        long long curr = grid[row][col];

        vector<long long> candidates;

        if (row > 0) {
            auto way1 = solve(row - 1, col, grid, dp);
            candidates.push_back(curr * way1.first);  // curr * max_from_top
            candidates.push_back(curr * way1.second); // curr * min_from_top
        }

        if (col > 0) {
            auto way2 = solve(row, col - 1, grid, dp);
            candidates.push_back(curr * way2.first);  // curr * max_from_left
            candidates.push_back(curr * way2.second); // curr * min_from_left
        }

        for (int i = 0; i < candidates.size(); i++) {
            maxProd = max(maxProd, candidates[i]);
            minProd = min(minProd, candidates[i]);
        }

        return dp[row][col] = {maxProd, minProd};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long, long>>> dp(
            m, vector<pair<long, long>>(n, {LLONG_MIN, LLONG_MAX}));

        //TABULATION
        dp[0][0] = {grid[0][0],grid[0][0]};

        // Fill the first row
        for(int j = 1; j < n; j++){
            long long prod = dp[0][j-1].first * grid[0][j];
            dp[0][j] = {prod, prod};
        }

        // Fill the first col
        for(int i = 1; i < m; i++){
            long long prod = dp[i-1][0].first * grid[i][0];
            dp[i][0] = {prod, prod};
        }

        // Fill the rest
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                long long curr = grid[i][j];
                vector<long long> candidates;

                candidates.push_back(curr * dp[i-1][j].first);
                candidates.push_back(curr * dp[i-1][j].second);

                candidates.push_back(curr * dp[i][j-1].first);
                candidates.push_back(curr * dp[i][j-1].second);

                long long maxProd = INT_MIN, minProd = INT_MAX;

                for(int k = 0; k < candidates.size(); k++){
                    maxProd = max(maxProd, candidates[k]);
                    minProd = min(minProd, candidates[k]);
                }

                dp[i][j] = {maxProd, minProd};
            }
        }

        // auto res = solve(m - 1, n - 1, grid, dp);
        auto res = dp[m-1][n-1];

        if (res.first < 0) {
            return -1;
        } else {
            return res.first % MOD;
        }
    }
};