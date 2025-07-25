class Solution {
private:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis,vector<int> &pathVis, vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 1;

        for(auto adjNodes: graph[node]){
            if(!vis[adjNodes]){
                if(dfs(adjNodes, graph, vis, pathVis, check)){
                    check[node] = 0;
                    return true;
                }
            }else if(pathVis[adjNodes]){
                check[node] = 0;
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Every node that is a part of a cycle cannot be a safe node
        // Every node that is connected to a cycle cannot be a safe node
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);

        vector<int> safeNodes;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for(int i = 0; i < n; i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};