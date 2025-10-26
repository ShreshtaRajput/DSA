class Solution {
public:
    long long removeZeros(long long n) {
        string number = to_string(n);

        for(int i = 0; i < number.size(); i++){
            if(number[i] == '0'){
                number.erase(i, 1);
                i--;
            }
        }

        long long res = stoll(number);
        return res;
    }
};