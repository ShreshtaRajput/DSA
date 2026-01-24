class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = INT_MIN;

        int first = 0;
        int second = nums.size() - 1;

        while(first < second){
            int sum = nums[first] + nums[second];
            res = max(sum, res);

            first++;
            second--;
        }

        return res;
    }
};