class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        int res = 0;

        prefix[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }

        unordered_map<int, int> mp;
        mp[0] = 1;  //Initialize map

        for(int i = 0; i < n; i++){
            int curr = prefix[i];
            if(mp.find(curr - goal) != mp.end()){
                res += mp[prefix[i] - goal];
            }
            mp[curr]++;
        }

        return res;
    }
};