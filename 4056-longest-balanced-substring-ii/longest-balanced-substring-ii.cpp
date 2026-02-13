class Solution {
private:
    int solo(string s){
        int count = 1;
        int res = 1;

        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i+1]) count++;
            else count = 1;
            res = max(res, count);
        }

        return res;
    }

    int duo(string s, char c1, char c2){
        map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        int diff = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] != c1 && s[i] != c2){   //A third char has appeared
                // Reset everything
                mp.clear();
                mp[0] = i;  //This acts as a new starting point
                diff = 0;
                continue;
            }
            if(s[i] == c1) diff++;
            else diff--;

            if(mp.find(diff) != mp.end()){
                ans = max(ans, i-mp[diff]);
            }else{
                mp[diff] = i;
            }
        }

        return ans;
    }

    int trio(string s){
        vector<int> freq(3);
        map<vector<int>, int> mp;
        mp[{0, 0}] = -1;
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;

            vector<int> key = {freq[1] - freq[0], freq[2] - freq[0]};

            if(mp.find(key) != mp.end()){
                res = max(res, i-mp[key]);
            }else{
                mp[key] = i;
            }
        }

        return res;
    }
public:
    int longestBalanced(string s) {
        return max(solo(s), max(duo(s, 'a', 'b'), max(duo(s, 'a', 'c'), max(duo(s, 'b', 'c'), trio(s)))));
    }
};