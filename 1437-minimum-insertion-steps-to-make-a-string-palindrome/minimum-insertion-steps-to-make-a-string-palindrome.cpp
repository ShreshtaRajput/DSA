class Solution {
public:
    int minInsertions(string s) {
        // The minimum number of additions will be total length of substring minus the
        // Length of the longest palindromic subsequence
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int i = 0; i <= n; i++){
            prev[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        int len = prev[n];

        return n - len;
    }
};