class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int val = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if(val > dist[x][y]) continue;

            if(x == m-1 && y == n-1) return dist[x][y] < health;

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n){
                    continue;
                }

                int newVal = val + grid[nx][ny];

                if(newVal < dist[nx][ny]){
                    dist[nx][ny] = newVal;
                    pq.push({newVal, {nx, ny}});
                }
            }
        }

        return false;
    }
};

// class Solution {
// private:
//     bool dfs(vector<vector<int>> &grid, int health, vector<vector<int>> &vis, int i, int j, int m, int n){
//         // Out of bounds
//         if(i < 0 || j < 0 || i >= m || j >= n){
//             return false;
//         }
//         // Already visited
//         if(vis[i][j]) return false;
        
//         health -= grid[i][j];

//         if(health <= 0) return false;
//         // Reached dest
//         if(i == m-1 && j == n-1) return true;

//         vis[i][j] = 1;
//         vector<int> dx = {0, 1, 0, -1};
//         vector<int> dy = {1, 0, -1, 0};
//         for(int x = 0; x < 4; x++){
//             if(dfs(grid, health, vis, i+dx[x], j+dy[x], m, n)){
//                 vis[i][j] = 0;  //Reset for each path
//                 return true;
//             }
//         }

//         vis[i][j] = 0;  //Reset for each path
//         return false;
//     }
// public:
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> vis(m, vector<int>(n, 0));

//         return dfs(grid, health, vis, 0, 0, m, n);
//     }
// };