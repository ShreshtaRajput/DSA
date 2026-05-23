class Solution {
private:
    int findPivot(vector<int> &nums){
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s < e){
            int mid = s + (e-s)/2;

            if(nums[mid] > nums[e]){
                s = mid + 1;
            }else{
                e = mid;
            }
        }
        return s;
    }

    int search(vector<int> &nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int n = nums.size();

        if(pivot == 0) return search(nums, 0, n-1, target);
        if(target <= nums[pivot - 1] && target >= nums[0]){
            return search(nums, 0, pivot-1, target);
        }else{
            return search(nums, pivot, n-1, target);
        }
    }
};