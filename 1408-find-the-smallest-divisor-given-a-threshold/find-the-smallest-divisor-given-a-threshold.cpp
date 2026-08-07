class Solution {
private:
    int compute(vector<int> &nums, int mid){
        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            res += ceil((double)nums[i]/mid);
        }

        return res;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = 0;
        for(int i = 0; i < n; i++){
            high = max(high, nums[i]);
        }

        while(low <= high){
            int mid = low + (high - low)/2;

            int divRes = compute(nums, mid);
            if(divRes > threshold){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return low;
    }
};