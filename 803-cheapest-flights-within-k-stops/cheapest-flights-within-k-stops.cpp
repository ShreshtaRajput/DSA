class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        // Creating the adjacency list
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        // {stops, {node, price}}
        queue<pair<int, pair<int, int>>> q;
        vector<int> price(n, 1e9);

        price[src] = 0;
        q.push({0, {src, 0}});

        while(!q.empty()){
            pair<int, pair<int, int>> front = q.front();
            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second;
            q.pop();

            if(stops > k) continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;

                if(cost + edgeWeight < price[adjNode] && stops <= k){
                    price[adjNode] = cost + edgeWeight;
                    q.push({stops + 1, {adjNode, price[adjNode]}});
                }
            }
        }

        if(price[dst] == 1e9){
            return -1;
        }

        return price[dst];
    }
};