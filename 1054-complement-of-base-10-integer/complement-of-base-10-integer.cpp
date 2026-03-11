class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        string s = "";

        // Step 1: Convert to binary
        while(n > 0){
            s = char('0' + (n % 2)) + s;
            n /= 2;
        }

        // Step 2: Flip bits
        for(char &c : s){
            if(c == '0') c = '1';
            else c = '0';
        }

        // Step 3: Convert binary back to decimal
        int ans = 0;
        for(char c : s){
            ans = ans * 2 + (c - '0');
        }

        return ans;
    }
};