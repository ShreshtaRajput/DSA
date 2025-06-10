class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        int res;
        
        int min_even = INT_MAX;
        int max_odd = 0;

        for(char ch: s){
            mp[ch]++;
        }

        for(auto &i: mp){
            if(i.second % 2 == 0){
                min_even = min(min_even, i.second);
            }

            if(i.second % 2 != 0){
                max_odd = max(max_odd, i.second);
            }
        }

        res = max_odd - min_even;
        return res;
    }
};