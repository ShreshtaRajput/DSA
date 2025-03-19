class Solution {
private:
    void flip(vector<int>& nums, int index) {
        if (index < nums.size()) {
            nums[index] = (nums[index] == 0) ? 1 : 0;
        }
    }

public:
    int minOperations(vector<int>& nums) {
        // vector<int> ans;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {

                if (i + 2 >= nums.size()) {
                    return -1;
                }

                nums[i] = 1;
                flip(nums, i + 1);
                flip(nums, i + 2);
                count++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                return -1;
            }
        }

        return count;
    }
};