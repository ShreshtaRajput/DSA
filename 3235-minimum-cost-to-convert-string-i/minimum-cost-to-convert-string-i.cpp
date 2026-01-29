class Solution {
private:
    vector<long long> dijkstra(char s, vector<vector<pair<char, int>>> &adj){
        // Getting the shortest path from s to all the other nodes
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(26, 1e9);

        int start = s - 'a';

        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            int currCost = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            for(auto it: adj[u]){
                int v = it.first - 'a';
                long long w = it.second;

                if(dist[v] > currCost + w){
                    dist[v] = currCost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        // Creating the adjacency list
        vector<vector<pair<char, int>>> adj(26);

        for(int i = 0; i < n; i++){
            adj[original[i] - 'a'].push_back({changed[i], cost[i]});
        }

        // Finding the shortest path for the target
        int m = source.size();
        // storing the results for minimum cost to travel from u to v
        vector<vector<long long>> minCost(26, vector<long long>(26, -1));

        long long totalCost = 0;

        for(int i = 0; i < m; i++){
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if(minCost[s][0] == -1){
                minCost[s] = dijkstra(source[i], adj);
            }

            if(minCost[s][t] == 1e9) return -1; //Not reachable
            totalCost += minCost[s][t];
        }

        return totalCost;
    }
};