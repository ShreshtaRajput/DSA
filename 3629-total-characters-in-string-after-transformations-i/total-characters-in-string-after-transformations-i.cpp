class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;

        vector<int> count(26);
        for(char ch : s){
            count[ch - 'a']++;
        }

        for(int round = 0; round < t; round++){
            vector<int> next(26);

            // Handling special case for character 'z'
            next[0] = count[25];
            next[1] = (count[0] + count[25])%MOD;

            // Handling general case
            for(int i = 2; i < 26; i++){
                next[i] = count[i - 1];
            }

            count = next;
        }

        int res = 0;
        for(int i = 0; i < 26; i++){
            res = (res + count[i])%MOD;
        }

        return res;
    }
};