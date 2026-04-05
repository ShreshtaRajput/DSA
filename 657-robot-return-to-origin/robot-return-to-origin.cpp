class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> mp;

        for(char ch: moves){
            mp[ch]++;
        }

        if(mp['R'] == mp['L'] && mp['U'] == mp['D']){
            return true;
        }

        return false;
    }
};