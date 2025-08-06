class DisjointSet{
    public:
        vector<int> parent, size;

        DisjointSet(int n){
            parent.resize(n); size.resize(n);
            for(int i = 0; i < n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node){
            if(parent[node] == node){
                return node;
            }

            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int up_u = findUltimateParent(u);
            int up_v = findUltimateParent(v);

            if(up_u == up_v) return;

            if(size[up_u] > size[up_v]){
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            }else{
                parent[up_u] = up_v;
                size[up_v] += size[up_u];                
            }
        }
};

class Solution {
private:
    bool isValid(int row, int col, int n){
        return row < n && row >= 0 && col < n && col >= 0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // In this loop we are connecting the components
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                // Skip all the zeroes
                if(grid[row][col] == 0) continue;
                for(int i = 0; i < 4; i++){
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];
                    if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1){
                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;
                        ds.unionBySize(nodeNo, adjNodeNo);  //Join all the adjacent 1s
                    }
                }
            }
        }

        // In this loop, we are going for each 0 and checking if connecting it with adjacent cells
        // will give us the largest island or not
        int mx = 0;     //size of largest island
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                // Skip all the 1s
                if(grid[row][col] == 1) continue;
                set<int> components;   //Will store the ultimate parent of the connected components
                // Storing ultimate parents will make sure that we count one component only once
                for(int i = 0; i < 4; i++){
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];
                    if(isValid(newRow, newCol, n)){
                        if(grid[newRow][newCol] == 1){
                            int adjNodeNo = newRow * n + newCol;
                            components.insert(ds.findUltimateParent(adjNodeNo));
                        }
                    }
                }
                int sizeTotal = 0;  //Total size after connecting the zero
                for(auto it: components){
                    sizeTotal += ds.size[it];
                }

                mx = max(mx, sizeTotal + 1);
            }
        }

        for(int cn = 0; cn < n * n; cn++){
            mx = max(mx, ds.size[ds.findUltimateParent(cn)]);
        }

        return mx;
    }
};