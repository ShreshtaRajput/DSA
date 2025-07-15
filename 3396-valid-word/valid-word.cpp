class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3){
            return false;
        }

        bool hasVowel = false;
        bool hasConso = false;

        for(char ch: word){
            ch = tolower(ch);
            if(isalpha(ch)){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    hasVowel = true;
                }else{
                    hasConso = true;
                }
            }else if(!isdigit(ch)){
                return false;
            }
        }

        return hasVowel && hasConso;
    }
};