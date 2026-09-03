class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int small_even = INT_MAX;
        int small_odd = INT_MAX;

        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] % 2 == 0){
                small_even = min(small_even, nums1[i]);
            }else{
                small_odd = min(small_odd, nums1[i]);
            }
        }

        // All nnumbers are in same parity
        if(small_even == INT_MAX || small_odd == INT_MAX) return true;

        if(small_even < small_odd) return false;

        return true;
    }
};