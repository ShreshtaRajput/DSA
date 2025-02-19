class Solution {
public:
    char tolowerCase(char ch){
        if(ch >= 'a' && ch <= 'z'){
            return ch;
        }else{
            return ch - 'A' + 'a';
        }
    }

    bool isValidCharacter(char ch){
        return( (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ( ch >= 'A' && ch <= 'Z'));
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            while(i < j && !isValidCharacter(s[i])){
                i++;
            }
            while(i < j && !isValidCharacter(s[j])){
                j--;
            }
            if(tolowerCase(s[i]) != tolowerCase(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};