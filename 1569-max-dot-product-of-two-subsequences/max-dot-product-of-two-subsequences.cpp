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

        vector<vector<int>> dp(n, vector<int>(m, -1e9));

        return solve(0, 0, n, m,nums1, nums2, dp);
    }
};