class Solution {
private:
    void bfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &completeCompo){
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int front = q.front();
            q.pop();
            completeCompo.push_back(front);

            for(auto it: adj[front]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Convert the adj matrix to adj list
        vector<vector<int>> adj(n);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(edges[i][j] == 1 && (i != j)){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> completeCompo;
                bfs(i, adj, vis, completeCompo);
                bool isConnected = true;
                for(auto it: completeCompo){
                    if(adj[it].size() != completeCompo.size() - 1){
                        isConnected = false;
                        break;
                    }
                }

                if(isConnected){
                    count++;
                }
            }
        }

        return count;
    }
};