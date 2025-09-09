class Solution {
    vector<int> dj = {-1, 0, 1};

private:
    int solve(vector<vector<int>>& grid, int row, int aCol, int bCol,
              vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (aCol >= n || aCol < 0 || bCol >= n || bCol < 0)
            return -1e9;

        // Base case
        if (row == m - 1) {
            if (aCol == bCol)
                return grid[row][aCol];
            else
                return grid[row][aCol] + grid[row][bCol];
        }

        if (dp[row][aCol][bCol] != -1)
            return dp[row][aCol][bCol];

        int maxi = -1e9;

        for (int del1 = 0; del1 < 3; del1++) {
            for (int del2 = 0; del2 < 3; del2++) {
                if (aCol == bCol) {
                    maxi = max(maxi, grid[row][aCol] +
                                         solve(grid, row + 1, aCol + dj[del1],
                                               bCol + dj[del2], dp));
                } else {
                    maxi = max(grid[row][aCol] + grid[row][bCol] +
                                   solve(grid, row + 1, aCol + dj[del1],
                                         bCol + dj[del2], dp),
                               maxi);
                }
            }
        }

        return dp[row][aCol][bCol] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1)));

        return solve(grid, 0, 0, n - 1, dp);
    }
};