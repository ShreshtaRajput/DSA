class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Convert adj matrix to adj list
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && (i != j)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        // Created a visited array
        vector<int> vis(V, 0);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                count++;    //Add the count for every new starting node that is unvisited
                dfs(i, adj, vis);
            }
        }

        return count;
    }
};