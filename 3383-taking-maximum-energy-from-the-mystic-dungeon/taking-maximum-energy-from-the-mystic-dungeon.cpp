class Solution {
private:
    int solve(vector<int> &energy, int k, int index, int n, vector<int> &dp){
        // Base case
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int totalEnergy = energy[index] + solve(energy, k, index + k, n, dp);

        return dp[index] = totalEnergy;
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = -1e9;

        vector<int> dp(n, -1);

        for(int i = 0; i < n; i++){
            int curr = solve(energy, k, i, n, dp);
            ans = max(ans, curr);
        }

        return ans;
    }
};   


// int notPick = solve(energy, k, index + 1, n);
// int pick = energy[index];
// if((index + k) < n){
//     pick += solve(energy, k, index + k, n);
// }

// return max(pick, notPick);