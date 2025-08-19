class Solution {
private:
    void helper(string pattern, string& ans, vector<int>& vis, string temp,
                int index) {
        // base case
        if (index >= pattern.size() + 1) {
            // check for lexico smallest
            if (ans == "" || temp < ans) {
                ans = temp;
            }
            return;
        }
        // We will check for each number from 1 to pattern.size()+1
        // we took pattern.size()+1 because, there will be an extra element in the answer
        for (int i = 1; i <= pattern.size() + 1; i++) {
            if (!vis[i]) {
                if (index == 0) {
                    // We at initial state rn, so no restrictions here
                    vis[i] = 1;
                    temp.push_back('0' + i);
                    helper(pattern, ans, vis, temp, index + 1);
                    temp.pop_back();
                    vis[i] = 0;
                } else {
                    // No we will have to move according to pattern given
                    if ((pattern[index - 1] == 'I' && temp.back() < '0' + i) ||
                        (pattern[index - 1] == 'D' && temp.back() > '0' + i)) {
                        vis[i] = 1;
                        temp.push_back('0' + i);
                        helper(pattern, ans, vis, temp, index + 1);
                        temp.pop_back();
                        vis[i] = 0;
                    }
                }
            }
        }
    }

public:
    string smallestNumber(string pattern) {
        string ans = "";
        vector<int> vis(10, 0);
        string temp = "";
        helper(pattern, ans, vis, temp, 0);
        return ans;
    }
};