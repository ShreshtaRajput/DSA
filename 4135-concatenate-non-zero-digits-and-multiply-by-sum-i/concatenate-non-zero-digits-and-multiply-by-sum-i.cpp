class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        string s = to_string(n);

        for(char ch: s){
            int dig = ch - '0';
            sum += dig;
            if(dig > 0){
                x = x*10 + dig;
            }
        }

        return x * sum;
    }
};