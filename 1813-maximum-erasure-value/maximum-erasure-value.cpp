class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int left = 0;
        unordered_set<int> seen;
        int sum = 0;

        for(int right = 0; right < nums.size(); right++){
            // Window contraction
            while(seen.find(nums[right]) != seen.end()){
                // If nums[right] is already in the set
                seen.erase(nums[left]);     //remove nums[left] from the set
                sum -= nums[left];          //subtract from the sum
                left++;     //Window contract
            }

            sum += nums[right];
            seen.insert(nums[right]);

            ans = max(ans, sum);
        }

        return ans;
    }
};