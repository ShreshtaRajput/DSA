class Solution {
private:
    string invert(string s){
        for(char &ch: s){
            if(ch == '0') ch = '1';
            else ch = '0';
        }

        return s;
    }

    string generateString(int n){
        // Base case
        if(n == 1) return "0";

        string temp = generateString(n-1);

        string inverted = invert(temp);
        reverse(inverted.begin(), inverted.end());

        return temp + '1' + inverted;
    }

public:
    char findKthBit(int n, int k) {
        // If size is 1, the string is S1
        if(n == 1) return '0';

        string s = generateString(n);
        cout << s << endl;

        return s[k-1];
    }
};