class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int ans = 0;
        int len = s.length();
        int left = 0, right = 0;

        while(right < len){
            char curr = s[right];
            freq[curr - 'a']++;

            while(hasAllChar(freq)){
                ans += len - right;
                
                char leftChar = s[left];
                freq[leftChar - 'a']--;
                left++;
            }

            right++;
        }
        

        return ans;
    }

private:
    bool hasAllChar(vector<int>& freq){
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
};