class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = n;
        int right = 0;

        for(int left = 0; left < n; left++){
            long long target = (long long)nums[left]*k;
            while(right < n && nums[right] <= target){
                right++;
            }
            ans = min(ans, n - (right - left));
        }

        return ans;

        // int maxLen = 0;

        // for(int i = 0; i < n; i++){
        //     long long limit = (long long)nums[i]*k;

        //     int s = i;
        //     int e = n - 1;
        //     int idx = i;

        //     while(s <= e){
        //         int mid = s + (e-s)/2;
        //         if(nums[mid] <= limit){
        //             idx = mid;
        //             s = mid + 1;
        //         }else{
        //             e = mid - 1;
        //         }
        //     }

        //     maxLen = max(maxLen, idx - i + 1);
        // }

        // return n - maxLen;
    }
};