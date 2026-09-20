class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            int index = 26 - (s[i] - 'a');
            res += (index * (i+1));
        }

        return res;
    }
};