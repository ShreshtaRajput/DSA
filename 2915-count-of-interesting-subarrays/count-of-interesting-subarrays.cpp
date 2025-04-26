class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        long long ans = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % modulo == k)
                cnt++;
            int need = (cnt - k + modulo) % modulo;
            ans += mp[need];
            mp[cnt % modulo]++;
        }
        return ans;
    }
};