class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);

        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }

        int cnt = 0;

        for(int i = 0; i < n-1; i++){
            int sum1 = prefix[i];
            int sum2 = prefix[n-1] - prefix[i];

            int diff = abs(sum2 - sum1);
            if(diff % 2 == 0) cnt++;
        }

        return cnt;
    }
};