class Solution {
private:
    long long solve(int n, vector<vector<int>> &adj, vector<int> &baseTime){
        if(adj[n].empty()){
            // It is the leaf node
            return baseTime[n]; //Completion time of a leaf node
        }

        long long latest = 0;
        long long earliest = LLONG_MAX;

        for(auto el: adj[n]){
            long long childTime = solve(el, adj, baseTime);
            
            latest = max(latest, childTime);
            earliest = min(earliest, childTime);
        }

        long long ownDuration = (latest - earliest) + baseTime[n];
        return latest + ownDuration;
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        // Create a adj list
        vector<vector<int>> adj(n);

        for(auto ele: edges){
            int u = ele[0];
            int v = ele[1];

            adj[u].push_back(v);
        }

        long long res = solve(0, adj, baseTime);

        return res;
    }
};