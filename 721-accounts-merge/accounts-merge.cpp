class DisjointSet{
    vector<int> parent;
    vector<int> size;

    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n);
            for(int i = 0; i < n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node){
            if(parent[node] == node){
                return node;
            }

            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int up_u = findUltimateParent(u);
            int up_v = findUltimateParent(v);

            if(up_u == up_v) return;

            if(size[up_u] > size[up_v]){
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            }else{
                parent[up_u] = up_v;
                size[up_v] += size[up_u];                
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;

        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                // We did not find the mail in the map
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }else{
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto it: mapMailNode){
            int node = ds.findUltimateParent(it.second);
            string mail = it.first;
            mergedMail[node].push_back(mail);
        }

        for(int i = 0; i < n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};