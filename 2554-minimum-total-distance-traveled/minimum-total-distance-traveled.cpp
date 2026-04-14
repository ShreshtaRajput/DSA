class Solution {
private:
    long long solve(int rIdx, int fIdx, int used, int n, int m, vector<int> &robot, vector<vector<int>> &factory, vector<vector<vector<long long>>> &dp){
        if(rIdx == n) return 0;     //All robots assigned
        if(fIdx == m) return 1e12;  //No factories left

        if(dp[rIdx][fIdx][used] != -1){
            return dp[rIdx][fIdx][used];
        }

        // Assign robot to current factory
        long long pick = 1e12;
        if(used < factory[fIdx][1]){
            pick = abs(factory[fIdx][0] - robot[rIdx]) + solve(rIdx+1, fIdx, used+1, n, m, robot, factory, dp);
        }

        // Skip the current factory
        long long skip = solve(rIdx, fIdx+1, 0, n, m, robot, factory, dp);

        return dp[rIdx][fIdx][used] = min(pick, skip);
    }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        long long res = 0;

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(101, -1)));

        return solve(0, 0, 0, n, m, robot, factory, dp);
    }
};