class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        char non_nine = 0, non_zero = 0;

        for(char ch: str){
            if(ch != '9'){
                non_nine = ch;
                break;
            }
        }

        for(char ch : str){
            if(ch != '0'){
                non_zero = ch;
                break;
            }
        }

        string t_max = str;
        string t_min = str;

        for (char& ch : t_max) {
            if (ch == non_nine) {
                ch = '9';
            }
        }

        for (char& ch : t_min) {
            if (ch == non_zero) {
                ch = '0';
            }
        }

        return stoi(t_max) - stoi(t_min);
    }
};