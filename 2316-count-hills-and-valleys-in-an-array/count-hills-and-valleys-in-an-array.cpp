class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        vector<int> removeDupes;

        // Store all the elements without their duplicates
        // As it will be easier to get hills and valleys without duplicates
        removeDupes.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                removeDupes.push_back(nums[i]);
            }
        }
    
        for (int i = 1; i < removeDupes.size() - 1; i++) {
            if ((removeDupes[i] > removeDupes[i - 1] && removeDupes[i] > removeDupes[i + 1]) ||
                (removeDupes[i] < removeDupes[i - 1] && removeDupes[i] < removeDupes[i + 1])) {
                ans++;
            }
        }

        return ans;
    }
};