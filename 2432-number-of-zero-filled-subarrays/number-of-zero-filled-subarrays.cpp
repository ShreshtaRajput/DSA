class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int cnt = 0;    //counts the strak of zero elements
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                cnt++;
                ans += cnt;     //Add all the current streak to the answer
            }else{
                cnt = 0;    //If any non-zero encountered, reset the streak
            }
        }

        return ans;
    }
};