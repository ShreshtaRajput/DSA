class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // hash map to store last occurence of character
        unordered_map<char, int> mp;
        int left = 0;

        int maxLen = 0;

        for(int right = 0; right < s.size(); right++){
            // If the character is new OR the character's prev pos is outside the current window
            if(mp.count(s[right]) == 0 || mp[s[right]] < left){
                mp[s[right]] = right;
                maxLen = max(maxLen, right-left + 1);
            }else{
                left = mp[s[right]] + 1;
                mp[s[right]] = right;
            }
        }

        return maxLen;
    }
};