class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = INT_MIN;
        
        for(int i = 0; i < s.size(); i++){
            unordered_map<char, int> mp;
            for(int j = i; j < s.size(); j++){
                mp[s[j]]++;

                int freq = mp[s[j]];
                bool flag = true;

                for(auto p: mp){
                    if(freq != p.second){
                        // Frequency not equal
                        flag = false;
                    }
                }

                if(flag){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }

        return maxLen;
    }
};