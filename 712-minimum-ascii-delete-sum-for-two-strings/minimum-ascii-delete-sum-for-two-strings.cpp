class Solution {
private:
    int solve(int index1, int index2, string &s1, string &s2, vector<vector<int>> &dp){
        // if(index1 < 0 || index2 < 0){
        //     return 0;
        // }

        // s1 is exhausted
        if(index1 < 0){
            int sum = 0;
            for(int i = 0; i <= index2; i++)
                sum += s2[i];
            return sum;
        }

        // s2 is exhausted
        if(index2 < 0){
            int sum = 0;
            for(int i = 0; i<= index1; i++){
                sum += s1[i];
            }
            return sum;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        if(s1[index1] == s2[index2]){
            return solve(index1-1, index2-1, s1, s2, dp);
        }

        int deleteFroms1 = s1[index1] + solve(index1-1, index2, s1, s2, dp);
        int deleteFroms2 = s2[index2] + solve(index1, index2-1, s1, s2, dp);

        return dp[index1][index2] = min(deleteFroms1, deleteFroms2);
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        return solve(n1 - 1, n2 - 1, s1, s2, dp);
    }
};