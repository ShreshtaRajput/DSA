class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& vis) {
        int n = graph.size();
        queue<int> q;
        q.push(start);

        vis[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
                if(vis[it] == -1){  //Not yet coloured
                    vis[it] = !vis[node];
                    q.push(it);
                }else if(vis[node] == vis[it]){
                    // The node has already been colored by some other node such 
                    // that it is breaking the bipartite property
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!check(i, graph, vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};