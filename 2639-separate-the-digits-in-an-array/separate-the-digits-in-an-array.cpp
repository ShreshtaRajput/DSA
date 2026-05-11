class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;

        for(auto num: nums){
            vector<int> temp;
            while(num > 0){
                int digit = num % 10;
                num /= 10;
                temp.push_back(digit);
            }
            reverse(temp.begin(), temp.end());
            for(auto numb: temp){
                res.push_back(numb);
            }
        }

        return res;
    }
};