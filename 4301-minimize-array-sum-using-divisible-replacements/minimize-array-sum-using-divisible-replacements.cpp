class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long res = 0;

        sort(nums.begin(), nums.end());

        unordered_map<int, bool> isPresent;
        for(int num: nums){
            isPresent[num] = true;
        }

        int maxVal = nums[nums.size() - 1];

        vector<int> replacement(maxVal + 1, 0);

        for(int num: nums){
            // If the number has not been assigned any smaller divisor yet
            if(replacement[num] == 0){
                replacement[num] = num;

                // Now we iterate through its multiples
                for(int i = num*2; i <= maxVal; i += num){
                    if(isPresent[i] && replacement[i] == 0){
                        replacement[i] = num;
                    }
                }
            }
        }

        for(int num: nums){
            res += replacement[num];
        }

        return res;
    }
};