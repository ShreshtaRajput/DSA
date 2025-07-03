class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";

        while(str.size() < k){
            string temp = "";
            for(int i = 0; i < str.size(); i++){
                char ch = str[i];
                if(ch == 'z'){
                    temp += "a";
                }else{
                    temp += ch + 1;
                }
            }
            str += temp;
        }

        return str[k - 1];
    }
};