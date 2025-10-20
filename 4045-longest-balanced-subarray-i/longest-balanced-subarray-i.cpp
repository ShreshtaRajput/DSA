class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            set<int> evenStreak;
            set<int> oddStreak;

            for(int j = i; j < nums.size(); j++){
                if(nums[j] % 2 == 0){   //If even
                    evenStreak.insert(nums[j]);
                }else{      //If odd
                    oddStreak.insert(nums[j]);
                }
                
                // Update the max length if the number of distinct odd and even elements are same
                if(evenStreak.size() == oddStreak.size()){
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};