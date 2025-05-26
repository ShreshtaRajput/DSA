class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len = 0;
        int alreadyPalindrome = 0;

        unordered_map<string, int> count;

        for(string word: words){
            count[word]++;
        }

        for(auto& [word, freq] : count){
            string rev = word;
            reverse(rev.begin(), rev.end());

            if(word == rev){    //word is a palindrome
                len += (freq/2) * 4;    //if frequency is even
                if(freq % 2 != 0){  //if frequency is odd
                    alreadyPalindrome = 1;  // to be put in center
                }
            }else if(word < rev && count.count(rev)){
                // for non-palindromic strings
                // (word < rev) -> to avoid double counting of strings like "ab" and "ba" 
                // count.count(rev) -> if rev exist in the map
                len += min(freq, count[rev]) * 4;
            }
        }

        return len + alreadyPalindrome * 2;   
        //already palindrome will add a length of 2 to the final ans
    }
};