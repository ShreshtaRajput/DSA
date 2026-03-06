class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int changes = 0;

        int i = 0;
        while(i < n-1){
            if(s[i] != s[i+1]){
                changes++;
            }
            i++;
        }

        if(changes > 1){
            return false;
        }

        return true;
    }
};