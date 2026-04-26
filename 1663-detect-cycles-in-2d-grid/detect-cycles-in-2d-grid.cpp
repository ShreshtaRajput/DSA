class DSU{
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unite(int u, int v){
        int pu = findParent(u);
        int pv =findParent(v);

        if(pu == pv) return;

        if(size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU ds(n*m);

        for(int i= 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                
                int u = i*m + j;

                if(j+1 < m && grid[i][j] == grid[i][j+1]){
                    int v = i*m + (j+1);

                    if(ds.findParent(u) == ds.findParent(v)){
                        return true;
                    }

                    ds.unite(u,v);
                }

                if(i+1 < n && grid[i][j] == grid[i+1][j]){
                    int v = (i+1)*m + j;

                    if(ds.findParent(u) == ds.findParent(v)){
                        return true;
                    }

                    ds.unite(u,v);
                }
            }
        }

        return false;
    }
};

// class Solution {
// private:
//     bool detected(int row, int col, vector<vector<char>>& grid,
//                   vector<vector<int>>& vis) {
//         vis[row][col] = 1;
//         queue<pair<pair<int, int>, pair<int, int>>> q;

//         q.push({{row, col}, {-1, -1}});

//         while (!q.empty()) {
//             int child_x = q.front().first.first;
//             int child_y = q.front().first.second;
//             int parent_x = q.front().second.first;
//             int parent_y = q.front().second.second;
//             q.pop();

//             vector<int> delRow = {-1, 0, +1, 0};
//             vector<int> delCol = {0, +1, 0, -1};

//             for (int i = 0; i < 4; i++) {
//                 int adj_x = child_x + delRow[i];
//                 int adj_y = child_y + delCol[i];

//                 if (adj_x >= 0 && adj_x < grid.size() && adj_y >= 0 &&
//                     adj_y < grid[0].size() &&
//                     grid[adj_x][adj_y] == grid[child_x][child_y]) {
//                     if (!vis[adj_x][adj_y]) {
//                         vis[adj_x][adj_y] = 1;
//                         q.push({{adj_x, adj_y}, {child_x, child_y}});
//                     } else if (parent_x != adj_x && parent_y != adj_y) {
//                         return true;
//                     }
//                 }
//             }
//         }

//         return false;
//     }

// public:
//     bool containsCycle(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (!vis[i][j] && detected(i, j, grid, vis)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };