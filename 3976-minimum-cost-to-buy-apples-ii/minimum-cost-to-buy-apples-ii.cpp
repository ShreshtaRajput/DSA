#define ll long long
const ll INF = 2e18;

class Solution {
private:
    vector<ll> dijkstra(int source, int n, vector<vector<pair<int, ll>>> &graph){
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<ll> dist(n, INF);

        dist[source] = 0;
        pq.push({dist[source], source});

        while(!pq.empty()){
            pair<ll, int> top = pq.top();
            int node = top.second;
            ll dis = top.first;
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto &it: graph[node]){
                ll weight = it.second;
                int adjNode = it.first;

                if(dis + weight < dist[adjNode]){
                    dist[adjNode] = dis + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        // We will use a two graph strategy
        // One graph for normal travel and one for return journey
        vector<vector<pair<int, ll>>> graph(n);
        vector<vector<pair<int, ll>>> returnGraph(n);

        for(auto &road: roads){
            int u = road[0];
            int v = road[1];
            int cost = road[2];
            int tax = road[3];

            graph[u].push_back({v, cost});
            graph[v].push_back({u, cost});

            returnGraph[u].push_back({v, 1ll * cost * tax});
            returnGraph[v].push_back({u, 1ll * cost * tax});
        }

        vector<ll> ans(n, INF);  // compute in ll to avoid overflow

        // Apply Dijkstra for all the elements
        for(int i = 0; i < n; i++){
            vector<ll> forward = dijkstra(i, n, graph);
            vector<ll> backward = dijkstra(i, n, returnGraph);

            for(int j = 0; j < n; j++){
                if(forward[j] != INF && backward[j] != INF){
                    ll totalCost = forward[j] + backward[j] + prices[j];
                    ans[i] = min(ans[i], totalCost);
                }
            }
        }

        // Convert to int only at the very end for the judge
        return vector<int>(ans.begin(), ans.end());
    }
};