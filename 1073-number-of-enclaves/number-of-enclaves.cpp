class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if (grid[n - 1][j] == 1) {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (grid[i][m - 1] == 1) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        while(!q.empty()){
            int row  = q.front().first;
            int col = q.front().second;
            q.pop();

            vector<int> delRow = {-1, 0, 1, 0};
            vector<int> delCol = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && grid[newRow][newCol] == 1){
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};