class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        unordered_map<char, int> mp;

        for(char ch: brokenLetters){
            mp[ch]++;
        }

        bool flag = false;

        for(int i = 0; i < text.size(); i++){
            // If we reach the end of a word
            if(text[i] == ' '){
                if(!flag) cnt++;    //If the word is not broken
                flag = false;
            }else{
                if(mp[text[i]]){
                    flag = true;    //The word is broken
                }
            }
        }

        if(!flag) cnt++;

        return cnt;
    }
};