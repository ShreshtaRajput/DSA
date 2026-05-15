class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        int res = e;

        // Basically a mountain array problem???
        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[mid] <= nums[res]){
                res = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }

        return nums[res];
    }
};