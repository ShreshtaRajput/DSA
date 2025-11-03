class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int smallest = nums[0];
        int largest = nums[nums.size() - 1];

        vector<int> res;

        int j = 0;

        for(int i = smallest; i <= largest; i++){
            if(j < nums.size() && nums[j] == i){
                j++;
            }else{
                res.push_back(i);
            }
        }

        return res;
    }
};