class Solution {
private:
    pair<int, int> move(int i, int j, int dir, int m, int n, vector<vector<int>> &grid){
        while(i < m && j < n && grid[i][j] == 1){
            if(dir == 0){
                i++;
                dir = 1;
            }else{
                j++;
                dir = 0;
            }
        }

        return {i,j};
    }

    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= m || j >= n){
            return 0;
        }

        if(i == m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        pair<int, int> p1 = move(i, j+1, 0, m, n, grid);
        int right = solve(p1.first, p1.second, m, n, grid, dp);

        pair<int, int> p2 = move(i+1, j, 1, m, n, grid);
        int down = solve(p2.first, p2.second, m, n, grid, dp);

        return dp[i][j] = (right + down) % 1000000007;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, m, n, grid, dp);
    }
};