class Solution {
private:
    bool isValid(string s, int n){
        for(int i = 1; i < n; i++){
            if(s[i] == '1' && s[i-1] == '1'){
                return false;
            }
        }

        return true;
    }

    void solve(string &str, int n, int k, vector<string> &res){
        if(str.size() == n){
            int cost = 0;
            for(int i = 0; i < n; i++){
                if(str[i] == '1'){
                    cost += i;
                }
            }

            if(isValid(str, n) && cost <= k){
                res.push_back(str);
            }
            return;
        }

        // Add zero
        str.push_back('0');
        solve(str, n, k, res);
        str.pop_back();

        // Add one
        str.push_back('1');
        solve(str, n, k, res);
        str.pop_back();
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string str;
        solve(str, n, k, res);

        return res;
    }
};