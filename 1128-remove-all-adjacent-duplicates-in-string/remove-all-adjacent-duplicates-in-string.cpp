class Solution {
public:
    string removeDuplicates(string s) {
        while(s.length() > 1){
            bool erased = false;
            for(int i = 0 ; i < s.length() - 1; i++){
                if(s[i] == s[i+1]){
                    s.erase(i,2);
                    erased = true;
                    i--;
                    break;
                }
            }
            if(!erased) break;
        }
        return s;
    }
};