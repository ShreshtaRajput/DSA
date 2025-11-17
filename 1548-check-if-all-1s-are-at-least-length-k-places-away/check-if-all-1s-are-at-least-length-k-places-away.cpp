class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool flag = true;
        int preIndex = 0;

        for(int i = 0; i < nums.size(); i++){
            if(flag && nums[i] == 1){
                flag = false;
                preIndex = i;
                continue;
            }
            if(nums[i] == 1){
                if(i - preIndex - 1 >= k){
                    preIndex = i;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};