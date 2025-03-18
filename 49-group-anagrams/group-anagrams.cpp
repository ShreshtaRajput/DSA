class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> sign;

        for (string s : strs) {
            string signature = s;
            sort(signature.begin(), signature.end());

            bool flag = false;

            for (int i = 0; i < sign.size(); i++) {
                if (signature == sign[i]) {
                    ans[i].push_back(s);
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                sign.push_back(signature);
                ans.push_back({s});
            }
        }

        return ans;
    }
};