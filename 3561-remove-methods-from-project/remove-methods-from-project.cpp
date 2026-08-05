class Solution {
private:
    void dfs(int i, vector<bool> &sus, vector<vector<int>> &adj){
        // Mark it sus
        sus[i] = true;

        for(auto& it: adj[i]){
            if(!sus[it]) dfs(it, sus, adj);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto& i: invocations){
            int a = i[0];
            int b = i[1];

            adj[a].push_back(b);
        }

        vector<bool> sus(n, false);
        dfs(k, sus, adj);

        vector<int> ans;
        
        for(auto& edge: invocations){
            int a = edge[0];
            int b = edge[1];

            // In this case return all the nodes as it is
            if(!sus[a] && sus[b]){
                for(int i = 0; i < n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        // Else return the non sus nodes
        for(int i = 0; i < n; i++){
            if(!sus[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};