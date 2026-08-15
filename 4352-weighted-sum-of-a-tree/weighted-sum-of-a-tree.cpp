class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> children(n);
        for(int i = 1; i < n; i++){
            children[parent[i]].push_back(i);
        }

        vector<int> depth(n, 0);
        depth[0] = 1;   //Depth of root node is 1

        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto child: children[node]){
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }

        // Get the height
        int h = 0;
        for(int i = 0; i < n; i++){
            h = max(h, depth[i]);
        }

        long long res = 0;
        for(int i = 0; i < n; i++){
            res += 1LL * nums[i] * (h - depth[i] + 1);
        }

        return res;
    }
};