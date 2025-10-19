class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int mul = 1;

        while(mul > 0){
            if(mp.find(mul*k) == mp.end()){
                return mul*k;
            }
            mul++;
        }

        return 0;
    }
};