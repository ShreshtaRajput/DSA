class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed,vector<int>& cost) {

        int n = source.size();
        const long long INF = 1e18;

        // 1. Group transformations by length
        unordered_map<int, vector<tuple<string,string,int>>> byLen;
        for (int i = 0; i < original.size(); i++) {
            int L = original[i].size();
            byLen[L].push_back({original[i], changed[i], cost[i]});
        }

        // 2. For each length, compute shortest paths using Dijkstra
        // distByLen[L][from][to] = min cost
        unordered_map<int, unordered_map<string, unordered_map<string, long long>>> distByLen;

        for (auto &[L, rules] : byLen) {
            unordered_set<string> nodes;
            unordered_map<string, vector<pair<string,int>>> adj;

            for (auto &[u, v, w] : rules) {
                nodes.insert(u);
                nodes.insert(v);
                adj[u].push_back({v, w});
            }

            // Run Dijkstra from each node
            for (auto &src : nodes) {
                unordered_map<string, long long> dist;
                priority_queue<pair<long long,string>, vector<pair<long long,string>>, greater<>> pq;

                dist[src] = 0;
                pq.push({0, src});

                while (!pq.empty()) {
                    auto [d, u] = pq.top();
                    pq.pop();
                    if (d > dist[u]) continue;

                    for (auto &[v, w] : adj[u]) {
                        long long nd = d + w;
                        if (!dist.count(v) || nd < dist[v]) {
                            dist[v] = nd;
                            pq.push({nd, v});
                        }
                    }
                }
                distByLen[L][src] = dist;
            }
        }

        // 3. DP over the string
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // If characters match, move one step
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Try all substring lengths
            for (auto &p : byLen) {
                int L = p.first;    
                if (i + L > n) continue;

                string sSub = source.substr(i, L);
                string tSub = target.substr(i, L);

                if (distByLen[L].count(sSub) &&
                    distByLen[L][sSub].count(tSub)) {

                    dp[i + L] = min(dp[i + L], dp[i] + distByLen[L][sSub][tSub]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
