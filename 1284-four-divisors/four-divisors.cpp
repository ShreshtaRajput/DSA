class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for(int n : nums){
            int cnt = 0;
            int divSum = 0;

            for(int j = 1; j*j <= n; j++){
                if (n % j == 0) {
                    int other = n / j;
                    
                    // j and other are divisors
                    if (j == other) {
                        cnt++;
                        divSum += j;
                    } else {
                        cnt += 2;
                        divSum += j + other;
                    }

                    // If >4 divisors, we can stop now
                    if (cnt > 4) break;
                }
            }

            if(cnt == 4) sum += divSum;
        }

        return sum;
    }
};

// vector<int> divisors;
// if(nums[i] >= 6){
//     6 is the smallest number with 4 divisors
//     for(int j = 1; j <= nums[i]; j++){
//         if(nums[i] % j == 0){
//             divisors.push_back(j);
//         }
//     }

//     if(divisors.size() == 4){
//         sum += accumulate(divisors.begin(), divisors.end(), 0);
//     }
// }