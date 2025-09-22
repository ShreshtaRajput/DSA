class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;

        for(auto num: nums){
            if(num % 2 == 0){
                res = res | num;
            }
        }

        return res;
    }
};