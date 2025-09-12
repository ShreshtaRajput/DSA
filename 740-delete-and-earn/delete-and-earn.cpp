class Solution {
private:
    int solve(vector<int>& unique, unordered_map<int, int>& points, int index,
              vector<int>& dp) {
        // BASE CASE
        if (index < 0) {
            return 0;
        }

        if (index == 0)
            return points[unique[0]] * unique[0];

        if (dp[index] != -1)
            return dp[index];

        int skip = solve(unique, points, index - 1, dp);
        int take = unique[index] * points[unique[index]];
        if (unique[index] == unique[index - 1] - 1 ||
            unique[index] == unique[index - 1] + 1) {
            take += solve(unique, points, index - 2,
                          dp); // skip the previous numebr
        } else {
            take += solve(unique, points, index - 1, dp); // Take the number
        }

        return dp[index] = max(take, skip);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        // first we will need an array with all the unique elements
        // We can store all the points in a map
        unordered_map<int, int> points;

        for (auto it : nums) {
            points[it]++;
        }

        // Create a vector with all the unique items
        vector<int> unique;
        for (auto p : points) {
            unique.push_back(p.first);
        }
        sort(unique.begin(), unique.end());

        int n = unique.size();

        vector<int> dp(n, -1);

        // TABULATION
        dp[0] = points[unique[0]] * unique[0];

        for (int i = 1; i < n; i++) {
            int skip = dp[i - 1];
            int take = unique[i] * points[unique[i]];
            if ((unique[i] == unique[i - 1] - 1) ||
                (unique[i] == unique[i - 1] + 1)) {
                if (i >= 2) {
                    take += dp[i - 2]; // skip the previous number
                } else {
                    take += 0;
                }
            } else {
                take += dp[i - 1]; // Take the number
            }

            dp[i] = max(take, skip);
        }

        return dp[n - 1];

        // return solve(unique, points, n - 1, dp);
    }
};