class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto& p: mp){
            if(p.second > nums.size()/2){
                return p.first;
            }
        }

        return 0;
    }
};