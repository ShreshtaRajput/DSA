class Solution {
private:
    int solve(int i, int j, int n, int m,vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(i >= n || j >= m){
            return -1e9;
        }

        if(dp[i][j] != -1e9){
            return dp[i][j];
        }

        int take = (nums1[i] * nums2[j]) + solve(i+1, j+1, n, m, nums1, nums2, dp);
        int skip1 = solve(i+1, j, n, m, nums1, nums2, dp);
        int skip2 = solve(i, j+1, n, m, nums1, nums2, dp);
        int stop = nums1[i] * nums2[j];

        return dp[i][j] = max(take, max(stop, max(skip1, skip2)));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1e9));

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int take = (nums1[i] * nums2[j]) + dp[i+1][j+1];
                int skip1 = dp[i+1][j];
                int skip2 = dp[i][j+1];
                int stop = nums1[i] * nums2[j];

                dp[i][j] = max(take, max(stop, max(skip1, skip2)));
            }
        }

        return dp[0][0];
        // return solve(0, 0, n, m,nums1, nums2, dp);
    }
};