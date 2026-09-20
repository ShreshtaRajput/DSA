class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int res = INT_MAX;
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        for(int right = 0; right < n; right++){
            sum += arr[right];

            while(sum > target){
                sum -= arr[left];
                left++;
            }

            if(sum == target){
                int len = right - left + 1;

                if(left > 0 && best[left-1] != INT_MAX){
                    // Len is the curr subarray sum
                    // Best[left-1] is the smallest subarray just before curr subarray
                    res = min(res, best[left - 1] + len);
                }

                best[right] = min(best[right], len);
            }

            // Carry forward
            if(right > 0){
                best[right] = min(best[right], best[right-1]);
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};

// class Solution {
// public:
//     int minSumOfLengths(vector<int>& arr, int target) {
//         int res = INT_MAX;
//         int n = arr.size();

//         vector<int> prefix(n);

//         prefix[0] = arr[0];
//         for(int i = 1; i < n; i++){
//             prefix[i] = arr[i] + prefix[i-1];
//         }

//         vector<int> suffix(n);
//         suffix[n-1] = arr[n-1];
//         for(int i = n-2; i >= 0; i--){
//             suffix[i] = arr[i] + suffix[i+1];
//         }

//         vector<int> left(n, INT_MAX), right(n, INT_MAX);
//         // Filling the left array
//         for(int i = 0; i < n; i++){
//             for(int j = i; j < n; j++){
//                 int sum1;
//                 if(i == 0) sum1 = prefix[j];
//                 else sum1 = prefix[j] - prefix[i-1];

//                 if(sum1 == target){
//                     int len = j-i+1;

//                     left[j] = min(left[j], len);
//                 }
//             }
//         }

//         // Carry forward, if we have INT_MAX still
//         for(int i = 1; i < n; i++){
//             left[i] = min(left[i], left[i-1]);
//         }

//         // Same for right using suffix array
//         for(int i = n-1; i >= 0; i--){
//             for(int j = i; j <n; j++){
//                 int sum2;
//                 if(j == n-1) sum2 = suffix[i];
//                 else sum2 = suffix[i] - suffix[j+1];

//                 if(sum2 == target){
//                     int len = j-i+1;

//                     right[i] = min(right[i], len);
//                 }
//             }
//         }

//         // Similarly carry forward
//         for(int i = n-2; i >= 0; i--){
//             right[i] = min(right[i], right[i+1]);
//         }

//         for(int i = 0; i < n-1; i++){
//             // right[i+1] because of no overlap
//             if(left[i] != INT_MAX && right[i+1] != INT_MAX){
//                 res = min(res, left[i] + right[i+1]);
//             }
//         }

//         return (res == INT_MAX) ? -1 : res;
//     }
// };