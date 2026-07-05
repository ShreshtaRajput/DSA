class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = INT_MIN;
        int res = 0;

        for(int n: nums){
            int maxi = INT_MIN;
            int mini = INT_MAX;

            int num = n;
            while(num > 0){
                int dig = num % 10;
                maxi = max(dig, maxi);
                mini = min(dig, mini);
                num /= 10;
            }

            maxRange = max(maxRange, maxi - mini);
        }

        for(int n: nums){
            int maxi = INT_MIN;
            int mini = INT_MAX;

            int num = n;
            while(num > 0){
                int dig = num % 10;
                maxi = max(dig, maxi);
                mini = min(dig, mini);
                num /= 10;
            }

            if(maxi - mini == maxRange){
                res += n;
            }
        }

        return res;
    }
};