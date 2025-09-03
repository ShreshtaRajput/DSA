class Solution {
private:
    int solve(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        // Base case
        if(row == n-1){
            return triangle[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];

        int way1 = triangle[row][col] + solve(row + 1, col, triangle, dp);
        int way2 = triangle[row][col] + solve(row + 1, col + 1, triangle, dp);

        return dp[row][col] = min(way1, way2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // vector<vector<int>> dp(n, vector<int>(n, -1));

        vector<int> front(n, 0), curr(n, 0);

        for(int j = 0; j < n; j++){
            front[j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int way1 = triangle[i][j] + front[j];
                int way2 = triangle[i][j] + front[j+1];

                curr[j] = min(way1, way2);
            }

            front = curr;
        }

        return front[0];

        // TABULATION - since the memoization is top-down
        // the tabulation has to be it's opposite
        // for(int j = 0; j < n; j++){
        //     dp[n-1][j] = triangle[n-1][j];
        // }
        
        // for(int i = n-2; i >= 0; i--){
        //     for(int j = triangle[i].size() - 1; j >= 0; j--){
        //         int way1 = triangle[i][j] + dp[i+1][j];
        //         int way2 = triangle[i][j] + dp[i+1][j+1];

        //         dp[i][j] = min(way1, way2);
        //     }
        // }

        // return dp[0][0];
        // return solve(0, 0, triangle, dp);
    }
};