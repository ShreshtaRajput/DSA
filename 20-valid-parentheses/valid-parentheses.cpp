class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 == 1){
            return false;
        }

        stack<char> st;

        for(char ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }else if(ch == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    return false;
                }
            }else if(ch == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }else if(ch == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }

        return false;
    }
};