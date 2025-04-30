class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            int digitCount = 0;
            while(nums[i] > 0){
                nums[i] = nums[i]/10;
                digitCount++;
            }
            if(digitCount%2 == 0){
                count++;
            }
        }

        return count;
    }
};