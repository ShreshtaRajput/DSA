class Solution {
private:
    int solve(vector<int> &arr, int d, int idx, vector<int> &dp){
        int n = arr.size();
        int res = 1;

        if(dp[idx] != -1) return dp[idx];

        // Look right
        for(int i = idx + 1; i <= min(idx + d, n-1); i++){
            if(arr[i] >= arr[idx]){
                break;
            }

            res = max(res, 1 + solve(arr, d, i, dp));
        }

        // Look left
        for(int i = idx - 1; i >= max(idx - d, 0); i--){
            if(arr[idx] <= arr[i]){
                break;
            }

            res = max(res, 1 + solve(arr, d, i, dp));
        }

        return dp[idx] = res;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int res = 0;

        for(int i = 0; i < n; i++){
            vector<int> dp(n, -1);
            int curr = solve(arr, d, i, dp);
            res = max(res, curr);
        }

        return res;
    }
};