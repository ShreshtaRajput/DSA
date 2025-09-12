class Solution {
private:
    int solve(vector<int> &unique, unordered_map<int, int> &points, int index, vector<int> &dp){
        // BASE CASE
        if(index < 0){
            return 0;
        }

        if(index == 0) return points[unique[0]] * unique[0];

        if(dp[index] != -1) return dp[index];

        int skip = solve(unique, points, index - 1, dp);
        int take = unique[index] * points[unique[index]];
        if(unique[index] == unique[index - 1] - 1 || unique[index] == unique[index - 1] + 1){
            take += solve(unique, points, index - 2, dp);   //skip the previous numebr
        }else{
            take += solve(unique, points, index - 1, dp);   //Take the number
        }


        return dp[index] = max(take, skip);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        // first we will need an array with all the unique elements
        // We can store all the points in a map
        unordered_map<int, int> points;

        for(auto it: nums){
            points[it]++;
        }

        // Create a vector with all the unique items
        vector<int> unique;
        for(auto p: points){
            unique.push_back(p.first);
        }
        sort(unique.begin(), unique.end());

        int n = unique.size();

        vector<int> dp(n, -1);

        return solve(unique, points, n-1, dp);
    }
};