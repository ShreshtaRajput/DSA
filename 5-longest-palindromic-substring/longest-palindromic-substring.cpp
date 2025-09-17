class Solution {
public:
    string longestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();
        string ans = "";

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    // ans = max(ans, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }

        int maxLen = 0;
        int endIndex = 0;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if (dp[i][j] > maxLen && (n - j) == (i - dp[i][j])){
                    maxLen = dp[i][j];
                    endIndex = i-1;
                }
            }
        }

        ans = s.substr(endIndex - maxLen + 1,maxLen);

        return ans;
    }
};

// class Solution {
// private:
//     bool isPalindrome(const string& str) {
//         int left = 0;
//         int right = str.length() - 1;
//         
//         while (left < right) {
//             if (str[left] != str[right]) {
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true; 
//     }

// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         string longest = "";

//         for (int len = n; len > 0; len--) {
//             for (int i = 0; i <= n - len; i++) {
//                 string temp = s.substr(i, len);
//                 if (isPalindrome(temp)) {
//                     return temp; // return early for longest palindrome
//                 }
//             }
//         }

//         return longest;
//     }
// };

// class Solution {
// private:
//     bool isPalindrome(const string& str) {
//         int left = 0;
//         int right = str.length() - 1;
        
//         while (left < right) {
//             if (str[left] != str[right]) {
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true; 
//     }

// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         string longest = "";

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 string temp = s.substr(i, j - i + 1);
//                 if (isPalindrome(temp) && temp.length() > longest.length()) {
//                     longest = temp;
//                 }
//             }
//         }

//         return longest;
//     }
// };