
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long total = 0;
        long long high = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            high = max(high, diff[i]);
        }

        // Enough operations to make every difference zero
        if (k >= total) return 0;

        long long low = 0;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;

            for (long long d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // Reduce every difference to at most low
        long long remaining = k;
        for (long long& d : diff) {
            if (d > low) {
                remaining -= d - low;
                d = low;
            }
        }

        // Use leftover operations to reduce differences equal to low
        for (long long& d : diff) {
            if (remaining == 0) break;

            if (d == low && d > 0) {
                d--;
                remaining--;
            }
        }

        long long ans = 0;

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};


// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         long long res = 0;

//         int n = nums1.size();
//         int k = k1 + k2;

//         priority_queue<int> pq;

//         for(int i = 0; i < n; i++){
//             int diff = abs(nums1[i] - nums2[i]);
//             pq.push(diff);
//         }

//         // We have to minimize curr_sum by doing the operations
//         while(k > 0){
//             int maxDiff = pq.top();

//             pq.pop();

//             // Account for negative differences
//             if (maxDiff == 0) {
//                 pq.push(0);
//                 break;
//             }

//             maxDiff--;
//             pq.push(maxDiff);
//             k--;
//         }

//         while(!pq.empty()){
//             int val = pq.top();
//             pq.pop();

//             res += 1LL * val * val;
//         }

//         return res;
//     }
// };