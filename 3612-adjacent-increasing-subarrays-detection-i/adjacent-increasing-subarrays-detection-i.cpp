class Solution {
private:
    bool isStrictlyInc(vector<int> &nums, int index, int k){
        for(int i = index; i < index + k - 1; i++){
            if(nums[i] >= nums[i + 1]){
                return false;
            }
        }

        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // We need a window of size 2k, for both the subarrays
        for(int i = 0; i <= nums.size() - (2*k); i++){
            if(isStrictlyInc(nums, i, k)){
                if(isStrictlyInc(nums, i + k, k)){
                    return true;
                }
            }
        }

        return false;
    }
};