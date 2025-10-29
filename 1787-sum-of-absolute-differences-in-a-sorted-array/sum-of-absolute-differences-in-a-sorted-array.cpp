class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        // First we will make a prefix and suffix array that will store the leftsum and rightsum resp
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] += prefix[i-1] + nums[i];
        }

        suffix[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            suffix[i] += suffix[i+1] + nums[i];
        }

        // Now we can split in two parts
        // LeftPart -> carries the sum of absolute differences from left of the element
        // RightPart -> carries the sum of absolute differences from the right of the element

        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int leftSum = 0;    //We can get the leftSum from the prefix array
            int rightSum = 0;   //Similarly the rightSum from the suffix array

            if(i != 0){
                leftSum = prefix[i-1];
            }
            if(i != n-1){
                rightSum = suffix[i+1];
            }

            int leftPart = (nums[i] * i) - leftSum;
            int rightPart = rightSum - (nums[i] * (n-i-1));

            res[i] = leftPart + rightPart;
        }

        return res;
    }
};