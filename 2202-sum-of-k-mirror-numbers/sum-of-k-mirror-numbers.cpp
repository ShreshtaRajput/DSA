class Solution {
private:
    // long long convertToK(int n, int k){
    //     vector<int> digits;
    //     long long ans = 0;

    //     while(n > 0){
    //         digits.push_back(n % k);
    //         n /= k;
    //     }

    //     reverse(digits.begin(), digits.end());

    //     for(int digit: digits){
    //         ans = (ans * 10) + digit;
    //     }

    //     return ans;
    // }

    string convertToK(long long n, int k) {
        string s = "";
        while (n > 0) {
            s += to_string(n % k);
            n /= k;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    bool isPalindrome(string n) {
        int left = 0;
        int right = n.size() - 1;

        while(left < right){
            if(n[left] != n[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
        // long long rev = 0;
        // long long temp = n;

        // while (temp != 0) {
        //     rev = (rev * 10) + (temp % 10);
        //     temp /= 10;
        // }

        // return temp == rev;
    }

public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        int count = 0;
        int length = 1;

        while (count < n) {
            // For odd palindromes
            for (int i = pow(10, length - 1); i < pow(10, length); i++) {
                string str = to_string(i);
                string rev = str.substr(
                    0, str.size() - 1); // The last number of str is not to be
                                        // included in reverse
                reverse(rev.begin(), rev.end());
                string main = str + rev;

                long long number = stoll(main);

                if (isPalindrome(convertToK(number, k))) {
                    ans += number;
                    count++;

                    if(count == n){
                        return ans;
                    }
                }
            }

            // For even palindromes
            for (int i = pow(10, length - 1); i < pow(10, length); i++) {
                string str = to_string(i);
                string rev = str;
                reverse(rev.begin(), rev.end());
                string main = str + rev;

                long long number = stoll(main);

                if (isPalindrome(convertToK(number, k))) {
                    ans += number;
                    count++;

                    if(count == n){
                        return ans;
                    }
                }
            }

            length++;
        }

        return ans;
    }
};