#define SIZE 100000
#define MOD 1000000007

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();

        vector<long long> right_freq(SIZE + 1, 0);
        vector<long long> left_freq(SIZE + 1, 0);

        for(int i = 0; i < n; i++){
            right_freq[nums[i]]++;
        }

        for(int i = 0; i < n; i++){
            right_freq[nums[i]]--;

            int target = nums[i] * 2;

            if(target <= SIZE){     //Target should be less than size of the frequency arrays to prevent overflow
                if(left_freq[target] > 0 && right_freq[target] > 0){
                    long long left = left_freq[target];
                    long long right = right_freq[target];

                    res = (res + (left * right)) % MOD;
                }
            }

            left_freq[nums[i]]++;
        }

        // for(int i = 1; i < n; i++){
        //     int a = nums[i];
        //     int left = 0;
        //     int right = 0;
        //     for(int j = 0; j <= i-1; j++){
        //         if(nums[j] == a*2){
        //             left++;
        //         }
        //     }

        //     for(int k = i + 1; k < n; k++){
        //         if(nums[k] == a*2){
        //             right++;
        //         }
        //     }

        //     res += (left * right);
        // }

        return res;
    }
};