class Solution {
private:
    int getMax(vector<int> &nums){
        int n = nums.size();
        if(n == 0) return 0;

        int prev = nums[0];
        int prev2 = 0;
        int curr = 0;

        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;

            int notPick = prev;

            curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;

        if(nums.size() == 1) return nums[0];

        // if(nums.size() == 2) return 0;

        for(int i = 0; i < nums.size(); i++){
            if(i != 0){
                temp2.push_back(nums[i]);
            }
            if(i != nums.size() - 1){
                temp1.push_back(nums[i]);
            }
        }

        return max(getMax(temp1), getMax(temp2));
    }
};