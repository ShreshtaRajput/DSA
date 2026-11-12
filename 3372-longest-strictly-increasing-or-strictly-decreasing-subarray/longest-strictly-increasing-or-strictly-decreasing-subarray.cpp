class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 0;

        int incLength = 1;
        int decLength = 1;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                incLength++;
            }else{
                res = max(res, incLength);
                incLength = 1;
            }

            if(nums[i] > nums[i+1]){
                decLength++;
            }else{
                res = max(res, decLength);
                decLength = 1;
            }
        }

        res = max(res, max(incLength, decLength));
        return res;
    }
};