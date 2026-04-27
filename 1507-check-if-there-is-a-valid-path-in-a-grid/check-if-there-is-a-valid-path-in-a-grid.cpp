class Solution {
private:
    bool dfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        // Base case
        if(r == n-1 && c == m-1){
            return true;
        }

        vis[r][c] = true;

        // Explore all paths
        for(auto dir: moves[grid[r][c]]){
            int delr = r + dir[0];
            int delc = c + dir[1];

            if (delr < 0 || delr >= n || delc < 0 || delc >= m) continue;
            if(vis[delr][delc]) continue;

            // Check is the path connects back
            bool connected = false;
            for(auto back: moves[grid[delr][delc]]){
                if (back[0] == -dir[0] && back[1] == -dir[1]) {
                    connected = true;
                    break;
                }
            }

            if(connected){
                if(dfs(delr, delc, n, m, grid, vis)){
                    return true;
                }
            }
        }

        return false;
    }

public:
    vector<vector<vector<int>>> moves = {
        {}, // dummy
        {{0,-1}, {0,1}},     // 1
        {{-1,0}, {1,0}},     // 2
        {{0,-1}, {1,0}},     // 3
        {{0,1}, {1,0}},      // 4
        {{0,-1}, {-1,0}},    // 5
        {{0,1}, {-1,0}}      // 6
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        return dfs(0, 0, n, m, grid, vis);
    }
};