class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int diff = 0;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(auto num: nums){
            maxi = max(maxi, num);
            mini = min(mini, num);

            diff = maxi - mini;
        }

        return (long long)k*diff;
    }
};