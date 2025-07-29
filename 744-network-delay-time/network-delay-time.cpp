class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create the adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k});     //k is the source
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        // Dijkstra loop
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;

                if(edgeWeight + dis < dist[adjNode]){
                    dist[adjNode] = edgeWeight + dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Getting the max time
        int res = 0;
        for(int i = 1; i < n + 1; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            res = max(res, dist[i]);
        }

        return res;
    }
};