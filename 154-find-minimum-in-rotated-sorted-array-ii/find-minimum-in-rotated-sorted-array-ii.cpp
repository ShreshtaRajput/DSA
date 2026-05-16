class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        int res = e;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[mid] < nums[res]){
                res = mid;
                e = mid - 1;
            }else if(nums[mid] > nums[res]){
                s = mid + 1;
            }else{
                res = e;
                e--;
            }
        }

        return nums[res];
    }
};