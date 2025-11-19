class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st(nums.begin(), nums.end());

        while(st.find(original) != st.end()){
            original *= 2;
        }

        return original;

        // sort(nums.begin(), nums.end());

        // for(int num: nums){
        //     if(num == original){
        //         original *= 2;
        //     }
        // }

        // return original;
    }
};