class Solution {
private:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Impossible case
        if(n > connections.size() + 1){
            return -1;
        }

        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Count of connected components
        int components = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                components++;
            }
        }

        // To connect all components, we need at least (components - 1) extra edges
        return components - 1;
    }
};