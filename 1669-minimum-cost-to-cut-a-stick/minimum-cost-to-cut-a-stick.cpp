class Solution {
private:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
        // Base case
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;

        for(int k = i; k <= j; k++){
            int cost = (arr[j+1] - arr[i-1]) + solve(arr, i, k-1, dp) + solve(arr, k+1, j, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);

        // making the cuts array as -> {0, 1, 3, 4, 5, 7}

        sort(cuts.begin(), cuts.end());

        int cnt = cuts.size();

        vector<vector<int>> dp(cnt, vector<int>(cnt, 0));


        // TABULALTION
        for(int i = cnt - 2; i > 0; i--){
            for(int j = i; j <= cnt - 2; j++){
                int mini = 1e9;
                for(int k = i; k <= j; k++){
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][cnt - 2];
        // return solve(cuts, 1, cnt - 2, dp);
    }
};