class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long sum = 0, sqrSum = 0;

        long total = n*n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
                sqrSum += grid[i][j] * grid[i][j];
            }
        }

        long long sumDiff = (total * (total + 1)/2) - sum;
        long long sqrDiff = (total * (total + 1) * (2 * total + 1)/6) - sqrSum;

        long long repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        long long missing = (sqrDiff / sumDiff - sumDiff) / 2;

        vector<int> ans;
        ans.push_back(missing);
        ans.push_back(repeat);

        return ans;
    }
};