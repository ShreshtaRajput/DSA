class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Creating the adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int cityNo = 1e9;
        int minCityCount = 1e9;

        // Apply dijkstra algorithm for all the cities
        for(int i = 0; i < n; i++){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            vector<int> dist(n, 1e9);
            dist[i] = 0;
            pq.push({0, i});

            while(!pq.empty()){
                pair<int, int> front = pq.top();
                int node = front.second;
                int dis = front.first;

                pq.pop();

                for(auto it: adj[node]){
                    int adjNode = it.first;
                    int wt = it.second;

                    if(dis + wt > distanceThreshold){
                        continue;
                    }

                    if(dis + wt < dist[adjNode]){
                        dist[adjNode] = dis + wt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

            // After this, we will have the shortest distance from 'i' city to all the other cities
            // in the dist array

            int count = 0;      //Keep count of the cities have distance <= threshold

            for(auto d: dist){
                if(d <= distanceThreshold){
                    count++;
                }
            }

            if(count <= minCityCount){
                minCityCount = count;
                cityNo = i;
            }
        }

        return cityNo;
    }
};