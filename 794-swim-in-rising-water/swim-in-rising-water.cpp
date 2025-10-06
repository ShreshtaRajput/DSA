class Solution {
private:
    bool isValid(vector<vector<int>> &grid, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        return (row >= 0 && row < n && col >= 0 && col < m);
    }

public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()){
            auto front = pq.top();
            int t = front.first;
            int row = front.second.first;
            int col = front.second.second;
            pq.pop();

            if(vis[row][col]) continue;

            vis[row][col] = 1;

            // When we reach the final block we return the current time
            if(row == n-1 && col == m-1) return t;

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isValid(grid, newRow, newCol) && !vis[newRow][newCol]){
                    // The new time will be the maximum time/elevation till the block
                    int newTime = max(t, grid[newRow][newCol]);
                    pq.push({newTime, {newRow, newCol}});
                }
            }
        }

        return -1;
    }
};