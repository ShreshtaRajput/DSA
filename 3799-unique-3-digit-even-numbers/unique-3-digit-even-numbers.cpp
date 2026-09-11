class Solution {
private:
    void solve(vector<int> &digits, vector<bool> &used, int pos, int curr, set<int> &ans){
        // Base case
        if(pos == 3){
            if(curr % 2 == 0){
                ans.insert(curr);
            }
            return;
        }

        for(int i = 0; i < digits.size(); i++){
            // First digit cannot be 0
            if(pos == 0 && digits[i] == 0) continue;
            if(!used[i]){
                used[i] = true;

                solve(digits, used, pos + 1, curr * 10 + digits[i], ans);

                used[i] = false;
            }
        }
    }
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<bool> used(n, false);
        set<int> ans;

        solve(digits, used, 0, 0, ans);

        return ans.size();
    }
};