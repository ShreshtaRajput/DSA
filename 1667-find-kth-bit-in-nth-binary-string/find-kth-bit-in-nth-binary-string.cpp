class Solution {
public:
    char findKthBit(int n, int k) {
        // '1' will always be in the middle of the string, acc to the problem
        // Length of the string will be 2^n - 1 (by observation)
        // if k == n/2, return '1'
        // We only need to look at the first or the second half of the string

        if(n == 1) return '0';

        int len = pow(2, n) - 1;
        int mid = (len/2) + 1;

        if(k == mid) return '1';

        if(k < mid){
            return findKthBit(n-1, k);
        }else{
            // k > mid
            int idx = len - k;
            char req = findKthBit(n-1, idx+1);
            return (req == '1') ? '0' : '1';
        }
    }
};

// class Solution {
// private:
//     string invert(string s){
//         for(char &ch: s){
//             if(ch == '0') ch = '1';
//             else ch = '0';
//         }

//         return s;
//     }

//     string generateString(int n){
//         // Base case
//         if(n == 1) return "0";

//         string temp = generateString(n-1);

//         string inverted = invert(temp);
//         reverse(inverted.begin(), inverted.end());

//         return temp + '1' + inverted;
//     }

// public:
//     char findKthBit(int n, int k) {
//         // If size is 1, the string is S1
//         if(n == 1) return '0';

//         string s = generateString(n);
//         cout << s << endl;

//         return s[k-1];
//     }
// };