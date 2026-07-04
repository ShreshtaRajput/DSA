class DSU{
    private:
        vector<int> parent;
        vector<int> size;

    public:
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1);

            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findParent(int u){
            if(u == parent[u]){
                return u;
            }

            return parent[u] = findParent(parent[u]);
        }

        void unite(int u, int v){
            int parent_u = findParent(u);
            int parent_v = findParent(v);

            if(parent_u == parent_v) return;

            if(size[parent_u] >= size[parent_v]){
                parent[parent_v] = parent_u;
                size[parent_u] += size[parent_v];
            }else{
                parent[parent_u] = parent_v;
                size[parent_v] += size[parent_u];
            }
        }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU ds(n);
        int res = INT_MAX;

        for(auto e: roads){
            int u = e[0];
            int v = e[1];

            ds.unite(u, v);
        }

        for(auto e: roads){
            int u = e[0];
            int w = e[2];

            if(ds.findParent(u) == ds.findParent(1)){
                res = min(res, w);
            }
        }

        return res;
    }
};