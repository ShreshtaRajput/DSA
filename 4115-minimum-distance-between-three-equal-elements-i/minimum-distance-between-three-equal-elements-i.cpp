class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto& p: mp){
            int num = p.first;
            vector<int> inds = p.second;

            if(inds.size() >= 3){
                for(int i = 0; i + 2 < inds.size(); i++){
                    int a = inds[i], b = inds[i + 1], c = inds[i + 2];
                    int distance = abs(a-b) + abs(b-c) + abs(c-a);
                    ans = min(ans, distance);
                }
            }
        }

        if(ans == INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }
};