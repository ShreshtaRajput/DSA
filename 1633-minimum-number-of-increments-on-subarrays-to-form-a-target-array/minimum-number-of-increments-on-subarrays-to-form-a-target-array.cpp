// Okay so recursion gave TLE and DP gave MLE so this is the last option ig
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int n = target.size();

        ans = target[0];
        for (int i = 0; i < n - 1; i++) {
            if (target[i + 1] - target[i] >= 0) {
                ans += target[i + 1] - target[i];
            }
        }

        return ans;
    }
};

// class Solution {
// private:
//     int solve(int left, int right, vector<int>& target, int base,
//     vector<vector<int>> &dp) {
//         // Base case
//         if (left > right) {
//             // Array khatam
//             return 0;
//         }

//         if(dp[left][right] != -1) return dp[left][right];

//         //The 'base' variable keeps the track of the element that we just increased the array with
//         // Find the minimum element in the range [L,R] and the index of
//         minimum
//         // value
//         int mini = 1e9;
//         int index = -1;
//         for (int i = left; i <= right; i++) {
//             if (target[i] < mini) {
//                 mini = target[i];
//                 index = i;
//             }
//         }

//         int count = (mini - base) + solve(left, index - 1, target, mini,
//         dp) +
//                     solve(index + 1, right, target, mini, dp);

//         return dp[left][right] = count;
//     }

// public:
//     int minNumberOperations(vector<int>& target) {
//         int n = target.size();
//         vector<vector<int>> dp(n, vector<int> (n, -1));
//         return solve(0, n-1, target, 0, dp);
//     }
// };