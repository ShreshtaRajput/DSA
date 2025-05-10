class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;

        for(int i = 0; i < nums1.size(); i++){
            sum1 += nums1[i];
            if(nums1[i] == 0) zero1++;
        }

        for(int i = 0; i < nums2.size(); i++){
            sum2 += nums2[i];
            if(nums2[i] == 0) zero2++;
        }

        long long min_sum1 = sum1 + zero1, min_sum2 = sum2 + zero2;

        if(zero1 == 0 && zero2 == 0){
            // Both don't have zeroes
            if(sum1 == sum2){
                return sum1;
            }else{
                return -1;
            }
        }else if(zero1 == 0){
            // Only nums1 has zeroes
            if(min_sum2 <= sum1){
                return sum1;
            }else{
                return -1;
            }
        }else if(zero2 == 0){
            // Only nums2 has zeroes
            if(min_sum1 <= sum2){
                return sum2;
            }else{
                return -1;
            }
        }else{
            // Both have zeroes
            return max(min_sum1, min_sum2);
        }
    }
};