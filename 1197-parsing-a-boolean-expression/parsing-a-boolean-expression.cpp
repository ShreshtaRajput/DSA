class Solution {
private:
    char eval(char op, vector<char> &exp){
        if(op == '!'){
            if(exp[0] == 't'){
                return 'f';
            }else{
                return 't';
            }
        }

        // If even a single value is false, the answer will be false
        if(op == '&'){
            for(char value: exp){
                if(value == 'f'){
                    return 'f';
                }
            }
            return 't';
        }

        // If even a single value is true, the answer will be true
        if(op == '|'){
            for(char value: exp){
                if(value == 't'){
                    return 't';
                }
            }
            return 'f';
        }

        return 't';
    }
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char curr: expression){
            if(curr == ')'){    //closed paranthesis
                vector<char> exp;
                
                // Collect the expression inside the pranathesis
                while(st.top() != '('){     //Jab tak opening paranthesis nhi aata
                    exp.push_back(st.top());
                    st.pop();
                }

                st.pop();   //Popping the ')'
                // After traversing the expression in the paranthesis we will have an operator
                char op = st.top();
                st.pop();

                char res = eval(op, exp);
                st.push(res);
            }else if(curr != ','){
                st.push(curr);
            }
        }

        return st.top() == 't';
    }
};