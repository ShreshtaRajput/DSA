class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto num: nums){
            mp[num]++;
        }

        int n = nums.size();

        if(mp[nums[n/2]] == 1) return true;
        return false;
    }
};