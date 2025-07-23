class Solution {
private: 
    int removePair(string &s, char first, char second, int num){
        int ans = 0;

        stack<char> st;

        // Score calculation after pair removal
        for(char ch: s){
            if(!st.empty() && st.top() == first && ch == second){
                st.pop();
                ans += num;
            }else{
                st.push(ch);
            }
        }

        // Modify the string after removing pair
        string modStr;
        while(!st.empty()){
            modStr += st.top();
            st.pop();
        }
        reverse(modStr.begin(), modStr.end());

        s = modStr;

        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        
        if(x > y){
            // check 'ab' first
            ans += removePair(s, 'a', 'b', x);
            ans += removePair(s, 'b', 'a', y);
        }else{
            // Check 'ba' first
            ans += removePair(s, 'b', 'a', y);
            ans += removePair(s, 'a', 'b', x);            
        }

        return ans;
    }
};