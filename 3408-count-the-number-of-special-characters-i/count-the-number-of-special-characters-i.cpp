class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        unordered_set<char> st;

        for(char ch: word){
            st.insert(ch);
        }

        for(auto ch: st){
            if(isupper(ch)){
                if(st.find(tolower(ch)) != st.end()){
                    count++;
                }
            }else if(islower(ch)){
                if(st.find(toupper(ch)) != st.end()){
                    count++;
                }
            }
        }

        return count/2;
    }
};