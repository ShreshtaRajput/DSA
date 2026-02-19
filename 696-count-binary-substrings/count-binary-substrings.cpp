class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();

        vector<int> groups;
        int left = 0;
        while(left < n){
            char ch = s[left];
            int count = 0;

            while(left < n && s[left] == ch){
                count++;
                left++;
            }

            groups.push_back(count);
        }

        int res = 0;

        for(int i = 0; i < groups.size()-1; i++){
            res += min(groups[i], groups[i+1]);
        }

        return res;
    }
};