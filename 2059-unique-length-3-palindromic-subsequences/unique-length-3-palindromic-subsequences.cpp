class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {     //If previously not occupied
                first[idx] = i;
            }
            last[idx] = i;      //Else allocate the last index
        }
        
        for(int i = 0; i < 26; i++){
            if(first[i] != -1){
                // set to get all the distinct characters between the first and last element
                unordered_set<char> unique_chars;
                for (int k = first[i] + 1; k < last[i]; k++) {
                    unique_chars.insert(s[k]);
                }

                res += unique_chars.size();     //Each unique character will form a new palindrome of length 3
            }
        }

        return res;
    }
};