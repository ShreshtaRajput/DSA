class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int partition = n/2;

        // Sort only the first half
        sort(s.begin(), s.begin() + partition);

        // Copy the first half of the string to the second half
        for(int i = 0; i < partition; i++){
            s[n - i - 1] = s[i];
        }

        return s;
    }
};