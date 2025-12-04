class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        stack<char> st;

        for(char ch: directions){
            if(ch == 'R'){
                st.push('R');
            }else if(ch == 'S'){
                if(st.empty() || st.top() == 'S' || st.top() == 'L'){
                    st.push('S');
                }else{      //st.top() == 'R'
                    while(!st.empty() && st.top() == 'R'){
                        st.pop();
                        res += 1;
                    }
                    st.push('S');
                }
            }else{      //ch == 'L'
                if(st.empty()) continue;
                else if(st.top() == 'L'){
                    st.push('L');
                }else if(st.top() == 'S'){
                    res += 1;
                }else{
                    int cntR = 0;
                    while(!st.empty() && st.top() == 'R'){
                        st.pop();
                        cntR++;
                    }

                    res += cntR + 1;
                    st.push('S');   //When R and L collide, they become S so we push S
                }
            }
        }

        return res;
    }
};