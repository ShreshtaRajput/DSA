class Solution {
private:
    int solve(vector<int> &arr, int i, int k, vector<int> &dp){
        int n = arr.size();

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int len = 0;
        int maxi = 0;
        int maxAns = INT_MIN;

        for(int j = i; j < min(i + k, n); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + solve(arr, j + 1, k, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[i] = maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n, -1);

        return solve(arr, 0, k, dp);
    }
};