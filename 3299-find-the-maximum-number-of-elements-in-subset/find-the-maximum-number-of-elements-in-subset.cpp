class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;

        // Build the map
        for(auto num: nums){
            mp[num]++;
        }

        // Handle the case for 1
        if(mp.count(1)){
            if(mp[1] % 2 == 0){
                res = mp[1] - 1;
            }else{
                res = mp[1];
            }
        }

        for(auto p: mp){
            int num = p.first;

            if(num == 1) continue;

            long long curr = num;
            int len = 0;

            while(curr <= 1e9 && mp.count(curr) && mp[curr] >= 2){
                len += 2;
                curr *= curr;
            }
            if(curr <= 1e9 && mp.count(curr) && mp[curr] == 1){
                len++;
            }else{
                len--;
            }

            res = max(res, len);
        }

        return res;
    }
};