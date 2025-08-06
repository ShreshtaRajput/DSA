class DisjointSet{
    vector<int> parent;
    vector<int> size;
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n);
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
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();

        DisjointSet ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i, j);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(ds.findUltimateParent(i) == i){
                count++;
            }
        }

        return count;
    }
};

// class Solution {
// private:
//     void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
//         vis[node] = 1;
//         for(auto it: adj[node]){
//             if(!vis[it]){
//                 dfs(it, adj, vis);
//             }
//         }
//     }
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         // Convert adj matrix to adj list
//         int V = isConnected.size();
//         vector<vector<int>> adj(V);
//         for(int i = 0; i < V; i++){
//             for(int j = 0; j < V; j++){
//                 if(isConnected[i][j] == 1 && (i != j)){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
        
//         // Created a visited array
//         vector<int> vis(V, 0);
//         int count = 0;
//         for(int i = 0; i < V; i++){
//             if(!vis[i]){
//                 count++;    //Add the count for every new starting node that is unvisited
//                 dfs(i, adj, vis);
//             }
//         }

//         return count;
//     }
// };