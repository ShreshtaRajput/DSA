class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = 0;
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                int diff = abs(i - start);
                if(diff < mini){
                    mini = diff;
                    res = diff;
                }
            }
        }

        return res;
    }
};