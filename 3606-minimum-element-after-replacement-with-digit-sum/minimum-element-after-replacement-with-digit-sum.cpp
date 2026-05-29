class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int curr = 0;
            while(num > 0){
                int dig = num%10;
                curr += dig;
                num /= 10;
            }

            nums[i] = curr;
        }

        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            res = min(res, nums[i]);
        }

        return res;
    }
};