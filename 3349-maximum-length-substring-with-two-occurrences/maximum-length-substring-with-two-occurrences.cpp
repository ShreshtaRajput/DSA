class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = INT_MIN;

        unordered_map<char, int> mp;

        int l = 0;
        for(int r = 0; r < n; r++){
            mp[s[r]]++;
            while(mp[s[r]] > 2){
                mp[s[l]]--;
                l++;
            }

            res = max(res, r-l+1);
        }

        return res;
    }
};