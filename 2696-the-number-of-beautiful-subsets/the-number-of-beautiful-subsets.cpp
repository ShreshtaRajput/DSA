class Solution {
private:
    void helper(vector<int>& nums, int k, vector<int> &temp, int& count,
                int index) {
        // Base case
        if (index == nums.size()) {
            if(!temp.empty()){
                count++;
            }
            return;
        }

        helper(nums, k, temp, count, index + 1);

        bool isValid = true;
        for(auto it: temp){
            if(abs(it - nums[index]) == k){
                isValid = false;
                break;
            }
        }

        if(isValid){
            temp.push_back(nums[index]);
            helper(nums, k, temp, count, index + 1);
            temp.pop_back();
        }

                // for (int i = index; i < nums.size(); i++) {
        //     bool isValid = true;
        //     for(auto it: temp){
        //         if(abs(it - nums[i]) == k){
        //             isValid = false;
        //             break;
        //         }
        //     }
        //     if(isValid){
        //         temp.push_back(nums[i]);
        //         count++;
        //         helper(nums, k, temp, count, i + 1);
        //         temp.pop_back();
        //     }
        // }
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        vector<int> temp;

        helper(nums, k, temp, count, 0);

        return count;
    }
};