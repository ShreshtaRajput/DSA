class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        // Impossible case
        if(m < n) return "";

        // if(m == 1 && n == 1 && s[0] != t[0]) return "";

        // To keep the track of elements of t
        unordered_map<char, int> mp;
        for(char ch: t){
            mp[ch]++;
        }

        int left = 0;
        int minLen = INT_MAX;
        int charCount = 0;
        int startIndex = 0;
        
        for(int right = left; right < m; right++){
            if(mp.find(s[right]) != mp.end()){      //The character is present in 't'
                mp[s[right]]--;     //Reduce the frequency
                if(mp[s[right]] >= 0){
                    charCount++;
                }
            }

            // Once all the characters are in the substring
            while(charCount == n){
                // If smaller window is found
                if(right - left <= minLen){
                    minLen = right - left;
                    startIndex = left;  //Set starting index as left
                }

                char ch = s[left];
                if(mp.find(ch) != mp.end()){
                    mp[ch]++;

                    if(mp[ch] > 0){
                        charCount--;
                    }
                }

                left++;
            }
        }

        if(minLen == INT_MAX){
            return "";
        }else{
            return s.substr(startIndex, minLen + 1);
        }
    }
};