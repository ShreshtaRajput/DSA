class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // so basically we have to find the longest subarray having the highest valued element
        int ans = 0;
        int subArrLen = 0;

        int maxVal = INT_MIN;

        for(auto num: nums){
            if(num > maxVal){
                maxVal = num;
                ans = subArrLen = 0;
            }
            if(num == maxVal){
                subArrLen++;
            }else{
                subArrLen = 0;
            }

            ans = max(ans, subArrLen);
        }

        return ans;
    }
};