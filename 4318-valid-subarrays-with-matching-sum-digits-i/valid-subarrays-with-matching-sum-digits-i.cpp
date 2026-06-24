class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;
        vector<long long> prefix(n, 0);
        // Calc the prefix sum
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                long long sum = prefix[j] - (i > 0 ? prefix[i - 1] : 0);
                int lastDig = sum % 10;
                long long temp = sum;
                while(temp >= 10){
                    temp /= 10;
                }
                int firstDig = temp;

                if(firstDig == x && lastDig == x){
                    count++;
                }
            }
        }

        return count;
    }
};