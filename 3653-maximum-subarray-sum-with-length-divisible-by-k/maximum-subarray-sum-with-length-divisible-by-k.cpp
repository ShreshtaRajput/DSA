class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // long long best = INT_MIN;

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         int length = j - i + 1;
        //         if (length % k == 0) {
        //             long long currSum = prefix[j + 1] - prefix[i];
        //             best = max(best, currSum);
        //         }
        //     }
        // }
        // return best;
        
        // We will track the smallest prefix sum seen for each remainder (0 to k-1)
        vector<long long> minPrefix(k, LLONG_MAX);

        long long best = LLONG_MIN;

        // Go through all prefix indices L = 0..n
        for (int L = 0; L <= n; L++) {
            int r = L % k;  // remainder of the prefix index

            // If we have seen a previous prefix with the same remainder
            // then prefix[L] - minPrefix[r] is a valid subarray whose length is divisible by k
            if (minPrefix[r] != LLONG_MAX) {
                best = max(best, prefix[L] - minPrefix[r]);
            }

            // Update minimum prefix for this remainder class
            minPrefix[r] = min(minPrefix[r], prefix[L]);
        }

        return best;
    }
};