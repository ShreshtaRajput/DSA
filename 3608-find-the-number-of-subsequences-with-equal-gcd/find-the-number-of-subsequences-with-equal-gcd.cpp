#define MOD 1000000007

class Solution {
private:
    int solve(vector<int> &nums, int n, int i, int g1, int g2, vector<vector<vector<int>>> &dp){
        if(i == n){
            if(g1 > 0 && g1 == g2){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[i][g1][g2] != -1){
            return dp[i][g1][g2];
        }

        long long ways = 0;

        // Skip
        ways = (ways + solve(nums, n, i+1, g1, g2, dp)) % MOD;
        // seq1
        ways = (ways + solve(nums, n, i+1, gcd(g1, nums[i]), g2, dp)) % MOD;
        // seq2
        ways = (ways + solve(nums, n, i+1, g1, gcd(g2, nums[i]), dp)) % MOD;

        return dp[i][g1][g2] = ways;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MIN;

        for(int i = 0; i < n; i++){
            m = max(m, nums[i]);
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+1, vector<int>(m+1, -1)));

        return solve(nums, n, 0, 0, 0, dp);
    }
};