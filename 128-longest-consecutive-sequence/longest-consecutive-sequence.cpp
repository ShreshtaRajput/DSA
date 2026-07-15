class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        // Union by size
        if (size[px] < size[py])
            swap(px, py);

        parent[py] = px;
        size[px] += size[py];
    }

    int componentSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_map<int, int> mp;
        int n = 0;

        for (int num : nums) {
            if (!mp.count(num))
                mp[num] = n++;
        }

        DSU ds(n);

        for(auto p: mp){
            int num = p.first;
            int id = p.second;

            if(mp.count(num+1)){
                ds.unite(id, mp[num+1]);
            }
        }

        int ans = 1;

        for(int i = 0; i < n; i++){
            ans = max(ans, ds.componentSize(i));
        }

        return ans;
    }
};