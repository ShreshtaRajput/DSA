class Solution {
private:
    long long sumLessThan(vector<int>& nums, int value){
        int left = 0, right = nums.size()-1;
        long long res = 0;

        sort(nums.begin(), nums.end());

        while(left < right){
            int temp = nums[left] + nums[right];

            if(temp < value){
                res += (right - left);
                left++;
            }else{
                right--;
            }
        }

        return res;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        
        sort(nums.begin(), nums.end());

        count = sumLessThan(nums, upper + 1) - sumLessThan(nums, lower);

        return count;
    }
};