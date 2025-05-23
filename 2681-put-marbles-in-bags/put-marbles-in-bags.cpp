class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pw(n-1,0);

        for(int i = 0; i < n - 1; ++i){
            pw[i] += weights[i] + weights[i+1];
        }

        sort(pw.begin(), pw.end());
        long long ans = 0;
        for(int i = 0; i < k - 1; ++i){
            ans += pw[n - 2 - i] - pw[i];
        }

        return ans;
    }
};