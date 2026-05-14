class Solution {
public:
    bool isGood(vector<int>& nums) {
        int m = nums.size();

        sort(nums.begin(), nums.end());

        int maxEle = nums[m-1];

        if(m != maxEle + 1){
            return false;
        }

        unordered_map<int, int> mp;
        for(auto &num: nums){
            mp[num]++;
        }

        for(auto &p: mp){
            int ele = p.first;
            int freq = p.second;

            if(ele != maxEle && freq > 1){
                return false;
            }else if(ele == maxEle && freq != 2){
                return false;
            }
        }

        return true;
    }
};