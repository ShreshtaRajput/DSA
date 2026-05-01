class Solution {
private:
    int solve(int r, int c, int currCost, int n, int m, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &dp){
        // Out of bounds
        if(r >= n || c >= m){
            return INT_MIN;
        }

        int cost = (grid[r][c] == 0 ? 0 : 1 );
        currCost += cost;

        if(currCost > k) return INT_MIN;

        if(r == n-1 && c == m-1) return grid[r][c];

        if(dp[r][c][currCost] != -2) return dp[r][c][currCost];

        int right = solve(r, c+1, currCost, n, m, grid,k, dp);
        int down = solve(r+1, c, currCost, n, m, grid, k, dp);

        int best = max(right, down);;

        if(best == INT_MIN){
            return dp[r][c][currCost] = INT_MIN;
        }

        return dp[r][c][currCost] = best + grid[r][c];
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // Using -2 for unvisited paths
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -2)));

        int ans = solve(0, 0, 0, n, m, grid, k, dp);

        return (ans == INT_MIN ? -1 : ans);
    }
};