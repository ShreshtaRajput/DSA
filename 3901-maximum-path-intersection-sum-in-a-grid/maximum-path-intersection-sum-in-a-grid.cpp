class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = -1e9;

        // Check for row
        for(int i = 0; i < m; i++){
            int curr = -1e9;
            for(int j = 1; j < n; j++){
                int start_new = grid[i][j] + grid[i][j-1]; 
                int extend = curr + grid[i][j];
                curr = max(start_new, extend);
                res = max(res, curr);
            }
        }

        // Check for column
        for(int i = 0; i < n; i++){
            int curr = -1e9;
            for(int j = 1; j < m; j++){
                int start_new = grid[j][i] + grid[j-1][i]; 
                int extend = curr + grid[j][i];
                curr = max(start_new, extend);
                res = max(res, curr);
            }
        }

        // Check for individual cells
        for(int i = 1; i < m-1; i++){
            int curr = -1e9;
            for(int j = 1; j < n-1; j++){
                curr = max(curr, grid[i][j]);
                res = max(res, curr);
            }
        }

        return res;
    }
};