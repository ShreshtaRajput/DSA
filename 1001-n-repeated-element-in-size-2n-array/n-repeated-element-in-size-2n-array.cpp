class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 2; i++){
            // If the element is repeated n time for an array of size 2*n, then the element must be present
            // after every 1 or 2 elements
            if(nums[i] == nums[i+1] || nums[i] == nums[i+2]){
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
        // int len = nums.size();
        // int n = len/2;

        // unordered_map<int, int> mp;
        // for(auto &num: nums){
        //     mp[num]++;
        // }

        // for(auto &p: mp){
        //     if(p.second == n){
        //         return p.first;
        //     }
        // }

        // return 0;
    }
};