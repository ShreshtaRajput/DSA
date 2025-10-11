class Solution {
private:
    int findNextIndex(vector<int> &unique, int target) {
        int s = 0;
        int e = unique.size() - 1;
        int res = -1;

        while(s <= e){
            int mid = s + (e-s)/2;
            if(unique[mid] <= target){
                res = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }

        return res;
    }

    long long solve(vector<int> &unique, unordered_map<int, int> &points, int index, vector<long long> &dp){
        // This problem just like the 'delete and earn' but with some more conditions
        // so we can stick with that approach only
        // Base case
        if(index < 0){
            return 0;
        }

        if(index == 0){
            return 1LL * points[unique[0]] * unique[0];
        }

        if(dp[index] != -1) return dp[index];

        long long skip = solve(unique, points, index - 1, dp);
        long long take = unique[index] * points[unique[index]];
        int j = findNextIndex(unique, unique[index] - 3);
        // This while loop is very inefficient -> let's move to binary search
        // while (j >= 0 && abs(unique[j] - unique[index]) <= 2) {
        //     j--;
        // }

        take += solve(unique, points, j, dp);

        return dp[index] = max(skip, take);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> points;

        for(auto it: power){
            points[it]++;
        }

        vector<int> unique;
        for(auto p: points){
            unique.push_back(p.first);
        }

        int n = unique.size();

        vector<long long> dp(n, -1);

        sort(unique.begin(), unique.end());

        return 1LL * solve(unique, points, n-1, dp);
    }
};