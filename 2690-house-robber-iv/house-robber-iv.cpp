class Solution {
private:
    bool isPossible(vector<int>& nums, int k, int midReward) {
        int n = nums.size();
        int count = 0;

        vector<bool> canRob(n, false);

        for(int i = 0; i < n; i++){
            if(nums[i] <= midReward){
                canRob[i] = true;
            }
        }

        int i = 0;
        while(i < n){
            if(canRob[i]){
                count++;
                i+=2;
            }else{
                i++;
            }
        }

        return count >= k;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossible(nums, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};