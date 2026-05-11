class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        vector<int> res;

        string s = "";

        // Making the string
        for (auto chunk : chunks) {
            s += chunk;
        }

        unordered_map<string, int> mp;
        string curr = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                curr += s[i];
            } else if (s[i] == '-' && i > 0 && i < s.size() - 1 &&
                       (s[i - 1] >= 'a' && s[i] <= 'z') &&
                       (s[i + 1] >= 'a' && s[i + 1] <= 'z')) {
                curr += s[i];
            } else {
                if (!curr.empty()) {
                    mp[curr]++;
                    curr = "";
                }
            }
        }

        if (!curr.empty()) {
            mp[curr]++;
        }

        for (auto query : queries) {
            res.push_back(mp[query]);
        }

        return res;
    }
};