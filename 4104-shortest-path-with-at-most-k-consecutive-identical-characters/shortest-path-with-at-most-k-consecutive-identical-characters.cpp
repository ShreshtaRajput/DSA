#define INF 1e18

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &e: edges){
           int u = e[0];
           int v = e[1];
           int w = e[2];

           adj[u].push_back({v,w});
        }

        vector<vector<long long>> dist(n, vector<long long>(k+1, INF));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[0][1] = 0;
        pq.push({0, {0, 1}});

        while(!pq.empty()){
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();

            int cost = top.first;
            int u = top.second.first;
            int count = top.second.second;

            if(cost > dist[u][count]){
                continue;
            }

            if(u == n-1){
                return cost;
            }

            for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                int newCount = 0;

                if(labels[u] == labels[v]){
                    newCount = count+1;
                }else{
                    newCount = 1;
                }

                if(newCount > k){
                    continue;
                }

                int newCost = cost + w;
                if(newCost < dist[v][newCount]) {
                    dist[v][newCount] = newCost;

                    pq.push({newCost, {v, newCount}});
                }
            }
        }

        return -1;
    }
};