class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        if (up_u == up_v)
            return;

        if (size[up_u] > size[up_v]) {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        } else {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size()) {
            return -1;
        }

        DisjointSet ds(n);
        int extraEdges = 0;
        int compo = 0;

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            // Both are already connected, means that there is an extra edge
            if (ds.findUltimateParent(u) == ds.findUltimateParent(v)) {
                extraEdges++;
            }

            ds.unionBySize(u, v);
        }

        for (int i = 0; i < n; i++) {
            // There is a component which is not connected
            if (ds.findUltimateParent(i) == i) {
                compo++;
            }
        }

        return compo - 1;
    }
};

// class Solution {
// private:
//     void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
//         vis[node] = 1;
//         for(auto it: adj[node]){
//             if(!vis[it]){
//                 dfs(adj, vis, it);
//             }
//         }
//     }
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         // Impossible case
//         if(n > connections.size() + 1){
//             return -1;
//         }

//         vector<vector<int>> adj(n);
//         vector<int> vis(n, 0);

//         for(auto it: connections){
//             int u = it[0];
//             int v = it[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         // Count of connected components
//         int components = 0;

//         for(int i = 0; i < n; i++){
//             if(!vis[i]){
//                 dfs(adj, vis, i);
//                 components++;
//             }
//         }

//         // To connect all components, we need at least (components - 1) extra
//         edges return components - 1;
//     }
// };