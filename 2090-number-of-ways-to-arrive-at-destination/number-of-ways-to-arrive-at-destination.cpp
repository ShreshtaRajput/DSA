class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        vector<pair<int, int>> adj[n];

        // Creating the adjacency list for bi-directional graph
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // {node, distance}
        priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);  //number of ways a node can be visited with minimum distance

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            pair<long long, int> front = pq.top();
            int node = front.second;
            long long dis = front.first;

            pq.pop();

            if (dis > dist[node]) {
                continue;
            }

            for(auto it: adj[node]){
                int adjNode = it.first;
                long long edgeWeight = it.second;

                // Coming to the node for the first
                // So the number of ways we reached that node is equal to that of it's parent node
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                // We reached the node before with the same minimum distance
                // The number of ways will increase by that of the parent node
                else if(dis + edgeWeight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
