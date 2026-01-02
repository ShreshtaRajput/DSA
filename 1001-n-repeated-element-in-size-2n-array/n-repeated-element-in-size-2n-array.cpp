class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();
        int n = len/2;

        unordered_map<int, int> mp;
        for(auto &num: nums){
            mp[num]++;
        }

        for(auto &p: mp){
            if(p.second == n){
                return p.first;
            }
        }

        return 0;
    }
};