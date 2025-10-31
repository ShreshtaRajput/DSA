class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;

        unordered_map<int, int> mp;

        for(auto num: nums){
            mp[num]++;
        }

        for(auto p: mp){
            if(p.second > 1){
                res.push_back(p.first);
            }
        }

        return res;
    }
};