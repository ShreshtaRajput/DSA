#define MOD 1000000007

class Solution {
private:
    int power(int num, int pow){
        if(pow == 0) return 1;

        long long half = power(num, pow/2);

        long long result = (half * half) % MOD;

        if (pow % 2) {
            result = (result * num) % MOD;
        }

        return result;
    }

    int computeDepth(vector<vector<int>> &adj, int root, int parent){
        int depth = 0;

        for(auto &node: adj[root]){
            if(node == parent) continue;
            depth = max(1 + computeDepth(adj, node, root), depth);
        }

        return depth;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        // Create an adj list
        vector<vector<int>> adj(n+1);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Compute the max depth with 1 as the root node
        int maxDepth = computeDepth(adj, 1, -1);

        return power(2, maxDepth - 1);
    }
};