class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int close = 0;
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(i+1 < s.size() && s[i+1] == ')'){
                    i++;
                }else{
                    close++;
                }

                if(!st.empty()){
                    st.pop();
                }else{
                    res++;
                }
            }
        }

        res += (2*st.size()) + close;

        return res;
    }
};