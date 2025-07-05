class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            int visitedRow = q.front().first;
            int visitedColumn = q.front().second;
            q.pop();

            // Up
            if (visitedRow - 1 >= 0 &&
                grid[visitedRow - 1][visitedColumn] == '1' &&
                vis[visitedRow - 1][visitedColumn] == 0) {
                vis[visitedRow - 1][visitedColumn] = 1;
                q.push({visitedRow - 1, visitedColumn});
            }

            // Down
            if (visitedRow + 1 < n && grid[visitedRow + 1][visitedColumn] == '1' &&
                vis[visitedRow + 1][visitedColumn] == 0) {
                vis[visitedRow + 1][visitedColumn] = 1;
                q.push({visitedRow + 1, visitedColumn});
            }

            // Left
            if (visitedColumn - 1 >= 0 &&
                grid[visitedRow][visitedColumn - 1] == '1' &&
                vis[visitedRow][visitedColumn - 1] == 0) {
                vis[visitedRow][visitedColumn - 1] = 1;
                q.push({visitedRow, visitedColumn - 1});
            }

            // Right
            if (visitedColumn + 1 < m && grid[visitedRow][visitedColumn + 1] == '1' &&
                vis[visitedRow][visitedColumn + 1] == 0) {
                vis[visitedRow][visitedColumn + 1] = 1;
                q.push({visitedRow, visitedColumn + 1});
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};