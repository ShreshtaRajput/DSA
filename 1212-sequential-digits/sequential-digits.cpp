class Solution {
private:
    void solve(int low, int high, vector<int> &res, int curr){
        // Base case
        if(curr >= low && curr <= high){
            res.push_back(curr);
        }

        if(curr > high){
            return;
        }

        int last_dig = curr % 10;

        if(last_dig < 9){
            solve(low, high, res, (curr * 10) + last_dig + 1);
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        // solve(low, high, res, ??);
        for(int i = 1; i <= 9; i++){
            solve(low, high, res, i);
        }

        sort(res.begin(), res.end());

        return res;
    }
};