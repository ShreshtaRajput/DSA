class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> arr;
        string temp;

        // Converting the string to vector
        for(char ch: preorder){
            if(ch == ','){
                arr.push_back(temp);
                temp = "";
            }else{
                temp += ch;
            }
        }
        arr.push_back(temp);

        stack<string> st;

        for(int i = 0; i < arr.size(); i++){
            st.push(arr[i]);

            while(st.size() >= 3){
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                string top3 = st.top();
                st.pop();
                
                // Leaf node encountered
                if(top1 == "#" && top2 == "#" && top3 != "#"){
                    st.push("#");
                }else{
                    st.push(top3);
                    st.push(top2);
                    st.push(top1);
                    break;
                }
            }
        }

        // In the end, we should have exactly one "#" left
        return (st.size() == 1 && st.top() == "#");
    }
};